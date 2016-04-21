#pragma once

#include "decl_chapter17.h"
#include "chapter17minimumTypeHelper.h"
#include <iosfwd>

namespace mg_cpp14 {

	// TODO consider extern templates for this
	template <size_t Index, size_t Bits>
	class BitField {
	public:
		// establish the smallest possible uint type for the required field
		using type = typename MinimumTypeHelper<Index + Bits>::type;

		// assignment from relevant types
		template <class T>
		BitField &operator=(T inVal) {
			type val1 = inVal & LowMask; // extract the bits we want from input
			type val2 = val1 << Index; // shift to relevant location
			value = (value & ~IndMask) // clear the filed bits
				   | val2;             // set the new value
			return *this;
		}

		// return the field in relevant type with all bits shifted down to LSB
		operator type() const { return (value >> Index) & LowMask; }

		// return true if any relevant bits in field are set
		explicit operator bool() const { return value & IndMask; }

	private:
		// stores appropriate minimum sized uint to map field size at relevant offset.		
		type value; // do not init to allow unions on the same type

		// mask with 'Bits' low bits set
		const static type LowMask = (type(0x01) << Bits) - 1u;
		// mask with 'Bits' set at relevant index
		const static type IndMask = LowMask << Index;
	};

	// specialization for bool
	template <size_t Index>
	class BitField<Index, 1> {
	public:
		using type = typename MinimumTypeHelper<Index + 1>::type;
	
		// assign the input to relevant bit, leaving other bits unchanged
		BitField& operator=(bool inVal) {
			if (inVal) {
				value |= Mask;
			}
			else {
				value &= ~Mask;
			}
			return *this;
		}

		// return true if relevant bit is set
		explicit operator bool() const { 
			return !!(value & Mask);
		}

	private:
		// mask with relevant single Bit set
		static const type Mask = type(0x01) << Index;

		// stores appropriate minimum sized uint to map field size at relevant offset.		
		type value; // do not init to allow unions on the same type
	};

	// specialization for 64 bit, can not be indexed
	template <>
	class BitField<0, 64> {
		public:
			// establish the smallest possible uint type for the required field
			using type = typename MinimumTypeHelper<64>::type;

			// assignment from relevant types
			template <class T2>
			BitField &operator=(T2 inVal) {
				value = inVal & Mask; // preserve unsigned nature
				return *this;
			}

			// return the field as relevant type
			operator type() const { return value; }

			// return true if any bits in field are set
			explicit operator bool() const { return !!value; }

		private:
			// Mask with all bits set
			static const type Mask = 0xFFFFFFFFFFFFFFFF;

			// stores value, no mask needed to acces values
			type value; // do not init to allow unions on the same type
		};
	}
