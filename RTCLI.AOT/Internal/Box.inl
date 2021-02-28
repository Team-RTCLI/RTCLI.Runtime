namespace RTCLI
{
    template<class T>
    RTCLI_IL_FUNC T& Box(const typename T::ValueType& value)
    {
        T& object = new_object<T>();
        object.value = value;
        return object;
    }

    template<class T>
    RTCLI_IL_FUNC typename T::ValueType UnBox(const System::Object& object)
    {
        return ((const T&)object).value;
    }
}