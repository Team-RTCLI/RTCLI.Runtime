namespace RTCLI
{
namespace System
{
    // *******************  Managed<T>  *************************//
    template<typename T>
    RTCLI_FORCEINLINE Managed<T>::Managed() RTCLI_NOEXCEPT
        :object(const_cast<System::Object*>(&RTCLI::nullObject))
    {

    }
    template<typename T>
    RTCLI_FORCEINLINE Managed<T>::Managed(nullref_t null) RTCLI_NOEXCEPT
        :object(const_cast<System::Object*>(&RTCLI::nullObject))
    {

    }
    
    template<typename T>
    RTCLI_FORCEINLINE Managed<T>::Managed(const System::Object& object_) RTCLI_NOEXCEPT
    {
        if (object_.isNull()) {
            object = const_cast<System::Object*>(&RTCLI::nullObject);
        }
        else
        {
            object = const_cast<System::Object*>(&object_);
        }
    }

    template<typename T>
    RTCLI_FORCEINLINE T& Managed<T>::Get() RTCLI_NOEXCEPT
    {
        return *static_cast<T*>(object);
    }

    template<typename T>
    RTCLI_FORCEINLINE const T& Managed<T>::Get() const RTCLI_NOEXCEPT
    {
        return *static_cast<const T*>(object);
    }

    template<typename T>
    RTCLI_FORCEINLINE Managed<T>& Managed<T>::operator=(const System::Object& object_) RTCLI_NOEXCEPT
    {
        if(this->object == &object_)
        {
            return *this;
        }
        if (object_.isNull()) {
            object = const_cast<System::Object*>(&RTCLI::nullObject);
        }
        else
        {
            object = const_cast<System::Object*>(&object_);
        }
        return *this;
    }
}
}