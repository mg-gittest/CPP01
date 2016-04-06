#pragma once

// Chapter16_protected.h : 
// Declares the protected data structure used by Chapter16 and derived classes
// Only need to include in the implementation of base and derived classes
//

#include "chapter16.h" // need to include this to see the initial declaration

namespace mg_cpp14 {

	struct Chapter16::BData {
		const int base_val;
		BData(int val) : base_val(val) {}
	};

}

