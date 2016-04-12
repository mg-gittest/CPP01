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

	/* declaration for clients, defintion by inclusion of header in chapter17.cpp	*/
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper< 0>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper< 1>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper< 2>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper< 3>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper< 4>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper< 5>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper< 6>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper< 7>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper< 8>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper< 9>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<10>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<11>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<12>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<13>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<14>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<15>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<16>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<17>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<18>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<19>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<20>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<21>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<22>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<23>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<24>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<25>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<26>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<27>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<28>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<29>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<30>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<31>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<32>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<33>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<34>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<35>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<36>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<37>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<38>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<39>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<40>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<41>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<42>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<43>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<44>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<45>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<46>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<47>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<48>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<49>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<50>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<51>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<52>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<53>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<54>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<55>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<56>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<57>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<58>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<59>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<60>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<61>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<62>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<63>;
	CHAPTER17_TEMPLATE_EXPIMP template struct MinimumTypeHelper<64>;

}
