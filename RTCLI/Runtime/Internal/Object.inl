namespace RTCLI::System
{
    template<typename T>
    Object* new_object()
    {
        static_assert(std::is_base_of_v<Object, T>, "RTCLI::Runtime::new_object: must initialize an object derived from RTCLI::Object!");
        // malloc GC object.
        Object* object = new T();
       
        return object;
    }
}