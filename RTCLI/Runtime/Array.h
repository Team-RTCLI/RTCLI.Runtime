#pragma once
#include "Object.h"

namespace RTCLI::System
{
	struct RTCLI_API Array : public Object
	{
		int numElements;
	};

	template<class T>
	struct ElementArray : public Array
	{
		
	};

	template<typename T>
	ElementArray<T>* new_array(int numElements);

	RTCLI_API Array* new_array(const Type& objectType, int numElements);
}