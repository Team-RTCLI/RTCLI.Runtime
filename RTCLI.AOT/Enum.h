#include "ValueType.h"
#include "IComparable.h"
#include "IConvertible.h"

namespace RTCLI::System
{
	class [[CLR, Abstract]] Enum : public ValueType, public IComparable, public IConvertible//, public IFormattable
	{

	};
}