namespace RTCLI::System
{

    template<typename T, typename... Args>
    Managed<T> new_object(Args&&... args)
    {
        static_assert(std::is_base_of_v<Object, T>, "RTCLI::Runtime::new_object: must initialize an object derived from RTCLI::Object!");
        
        Managed<Object> res = RTCLI::null;
        std::cerr << "new_object unimplemented!" << std::endl;
        return res;

        return object;
    }

}