namespace RTCLI::System
{
    template<class T>
    void initialize_object(IntPtr address);
    {
        new((void*)address) T();
    }
}