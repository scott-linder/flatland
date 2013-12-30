namespace std {

/// Userspace implementation for use until C++14 standard is widely adopted
/** Create new object wrapped in a unique_ptr.
 */
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

} /* namespace std */
