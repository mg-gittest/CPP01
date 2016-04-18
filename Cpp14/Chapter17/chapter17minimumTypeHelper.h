#pragma once

#include "decl_chapter17.h"

#include <cstdint>
#include <cstddef>
#include <type_traits>


namespace mg_cpp14 {

	using std::uint8_t;
	using std::uint16_t;
	using std::uint32_t;
	using std::uint64_t;

	namespace {

		// helper that calculates relevant unit type for the required number of bits
		// guard against request for 0 or for more than 64 bits by making type void,
		// which will lead to compiler error when the type is used in BitField
		// would be nice to provide some more context here as problem will be obscured by noise
		// need to consider an error type that will break the compilation in this file.
		template <size_t LastBit>
		struct MinimumTypeHelper {
			typedef
				typename std::conditional<LastBit == 0, void,
				typename std::conditional<LastBit <= 8, uint8_t,
				typename std::conditional<LastBit <= 16, uint16_t,
				typename std::conditional<LastBit <= 32, uint32_t,
				typename std::conditional<LastBit <= 64, uint64_t,
				void>::type>::type>::type>::type>::type type;
		};

	}
}
