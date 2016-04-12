#pragma once

#include "decl_chapter17.h"
#include "chapter17minimumTypeHelper.h"

namespace mg_cpp14 {

	// TODO consider extern templates for this
	template <size_t Index, size_t Bits = 1>
	class BitField {
	private:
		// establish the smallest possible uint type for the required field
		typedef typename MinimumTypeHelper<Index + Bits>::type T;

		enum : T {
			 // mask with requested number of lower bits set
			 Mask = (1u << Bits) - 1u
			 // mask moved to cover relevant part of uint
			,MaskIndexed = (Mask << Index)
		};

	public:
		// allow callers to access the type being used for value_
		using type = T; 

		// assignment from relevant types
		template <class T2>
		BitField &operator=(T2 value) {
			value_ =  (value_ & ~(MaskIndexed))  // turn off all bits in the field, other value_ bits unchanged
				    | ((value & Mask) << Index); // turn on the bits requested in the value
			return *this;
		}

		// return the field in relevant type with all bits shifted down to LSB
		operator T() const { return (value_ >> Index) & Mask; }

		// return true if any bits in field are set
		explicit operator bool() const { return value_ & MaskIndexed; }

		// pre increment
		BitField &operator++() { return *this = *this + 1; }
		// post increment
		T operator++(int) { T r = *this; ++*this; return r; }
		// pre decrement
		BitField &operator--() { return *this = *this - 1; }
		// post decrement
		T operator--(int) { T r = *this; ++*this; return r; }

	private:
		// stores appropriate minimum sized uint to map field to relevant offset.
		T value_ {}; // into to zero
	};


	// specialization for bool
	template <size_t Index>
	class BitField<Index, 1> {
	private:
		enum {
			Bits = 1,
			Mask = 0x01
		};

		typedef typename MinimumTypeHelper<Index + Bits>::type T;
	public:
		// assign the input to relevant bit
		BitField &operator=(bool value) {
			value_ =   (value_ & ~(Mask << Index)) // turn off the bit
				     | (value << Index);           // set bit to input value
			return *this;
		}

		// return true if relevant bit is set
		explicit operator bool() const { 
			return !!(value_ & (Mask << Index));
		}

	private:
		// stores appropriate minimum sized uint to map field size at relevant offset.		
		T value_ {}; // initialised to all clear
	};
}
