#pragma once

// Chapter17_protected.h :
// Declares the protected data structure used by Chapter17 and derived classes
// Only need to include in the implementation of base and derived classes
//

#include "chapter17.h" // need to include this to see the initial declaration

namespace mg_cpp14 {

	struct Chapter17::BData {
		const int base_val;
		BData(int val) : base_val(val) {}
	};

}

