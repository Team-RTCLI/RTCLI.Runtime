namespace RTCLI::System
{
    template<class T>
    void initialize_object(T& address);
    {
        new((void*)&address) T();
    }
}