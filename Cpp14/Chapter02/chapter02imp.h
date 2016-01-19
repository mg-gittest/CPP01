#pragma once

#if !defined(MG_CPP14_CHAPTER02_IMP)
#define MG_CPP14_CHAPTER02_IMP

#include "chapter02.h"

namespace mg_cpp14 {

	class CHAPTER02_DLL Chapter02imp : public Chapter02
	{
	public:
		Chapter02imp();

		Chapter02imp(int a, float b, const char * c);

		virtual ~Chapter02imp();

		Chapter02imp(std::tuple<int, float>);

		Chapter02imp(int, float);

		virtual const std::vector<long> & getVec();

		virtual void incVec_for_each();

		virtual void incVec_for();

		bool operator== (const Chapter02& rhs) const;

	private:
		#pragma warning( push )
		#pragma warning( disable : 4251) 
		std::vector<long> vec;
		#pragma warning( pop )

	};

	inline std::wstring ToString(const Chapter02imp& tf) {
		return tf.toString();
	}

}

#endif