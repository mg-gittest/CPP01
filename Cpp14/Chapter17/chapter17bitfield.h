#pragma once

#include "decl_chapter17.h"
#include "chapter17minimumTypeHelper.h"

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
			type val1 = inVal & Mask; // extract the bits we want from input
			type val2 = val1 << Index; // shift to store
			value = val2;
			return *this;
		}

		// return the field in relevant type with all bits shifted down to LSB
		operator type() const { return (value >> Index) & Mask; }

		// return true if any bits in field are set
		explicit operator bool() const { return value & (Mask << Index) }
		
		BitField() {
			// to stop compiler complaining 'condition expression is constant'
			type bits = Bits;
			if (bits >= 64) {
				Mask = type(-1);
			}
			else {
				type tmp(1u);
				tmp <<= bits;
				Mask = tmp - 1;
			}
		}

	private:
		// stores appropriate minimum sized uint to map field size at relevant offset.		
		type value{}; // initialised to all clear
		// mask with low Bit bits set
		type Mask;
	};



	// specialization for bool
	template <size_t Index>
	class BitField<Index, 1> {
	public:
		using type = typename MinimumTypeHelper<Index + 1>::type;
	
		// assign the input to relevant bit
		BitField &operator=(bool inVal) {
			value = inVal ? (1u << Index) : 0;
			return *this;
		}

		// return true if relevant bit is set
		explicit operator bool() const { 
			return !!(value & (Mask << Index));
		}

	private:
		// stores appropriate minimum sized uint to map field size at relevant offset.		
		type value {}; // initialised to all clear
		// mask with low Bit set
		const type Mask = 0x01;
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

			// return the field as T
			operator type() const { return value; }

			// return true if any bits in field are set
			explicit operator bool() const { return !!value; }

		private:
			// stores value
			type value = 0u; 
			// mask with all bits set
			static const type Mask = 0xFFFFFFFFFFFFFFFF;
		};
	}
