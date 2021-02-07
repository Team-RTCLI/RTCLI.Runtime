namespace RTCLI::System
{
    template<typename T>
    T* new_object()
    {
        static_assert(std::is_base_of_v<Object, T>, "RTCLI::Runtime::new_object: must initialize an object derived from RTCLI::Object!");
        // malloc GC object.
        T* object = new T();
       
        return object;
    }
}