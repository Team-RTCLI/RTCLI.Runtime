namespace RTCLI::System
{

    template<typename T, typename... Args>
    T* new_object(Args&&... args)
    {
        static_assert(std::is_base_of_v<Object, T>, "RTCLI::Runtime::new_object: must initialize an object derived from RTCLI::Object!");
        
        // malloc GC object.
        T* object = new T();
        // call construct of allocated object.
        object->Constructor(std::forward<Args>(args)...);

        return object;
    }

}