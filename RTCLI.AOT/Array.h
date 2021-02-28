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

	template<class T>
	ElementArray<T>& new_array(int numElements);

	RTCLI_API Array& new_array(const Type& objectType, int numElements);

	template<class T>
	void ArraySet(ElementArray<T>& array, Int32 index, const T& value);

	template<class T>
	T& ArrayGet(ElementArray<T>& array, Int32 index);
}

namespace RTCLI
{
	using System::ArraySet;
	using System::ArrayGet;
	using System::new_array;
}