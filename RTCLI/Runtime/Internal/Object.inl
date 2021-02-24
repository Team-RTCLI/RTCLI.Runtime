namespace RTCLI::System
{
    // *******************  nullref_t  *************************//
    template <typename T>
    RTCLI_FORCEINLINE nullref_t::operator T&() const
    {
        union TypeSafetyBreaker {
            std::reference_wrapper<const Object> nullRef;
            // see https://stackoverflow.com/questions/38691282/use-of-union-with-reference
            std::reference_wrapper<T> ref; 
        };
        TypeSafetyBreaker ptr = {.nullRef = nullObject};

        // unwrap the reference
        return ptr.ref.get();
    }

    // *******************  Object  *************************//
    RTCLI_FORCEINLINE Object::Object(const struct Type* t_, RC rc_, Flags flags_)
        :type(t_), rc(rc_), flags(flags_)
    {

    }

    // null
    RTCLI_FORCEINLINE Object::Object(const nullref_t null)
        :type(nullptr), rc(1), flags(EObjectFlagBits::Null)
    {

    }
    RTCLI_FORCEINLINE Object& Object::operator=(const nullref_t null) RTCLI_NOEXCEPT
    {
        return const_cast<Object&>(RTCLI::nullObject);
    }

    RTCLI_FORCEINLINE bool Object::operator==(const Object& other) const RTCLI_NOEXCEPT
    {
            if(this == &other)
            {
                return true;
            }
            if(flags & EObjectFlagBits::Null)
            {
                return (other.flags & EObjectFlagBits::Null);
            }
            return false;
    }

    template<typename T, typename... Args>
    T& new_object(Args&&... args)
    {
        static_assert(
            std::is_base_of_v<Object, T>,
            "RTCLI::Runtime::new_object: must initialize an object derived from RTCLI::Object!"
        );
        
        T* result = new T(std::forward<Args>(args)...);

        return *result;
    }


}