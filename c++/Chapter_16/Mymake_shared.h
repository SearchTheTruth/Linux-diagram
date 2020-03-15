#include <memory>
#include <iostream>
#include <utility>


template <typename T, typename ... Args>
std::shared_ptr<T> make_shared(Args&& ... args)
{
    return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}
