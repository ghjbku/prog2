#include <iostream>
#include <limits>
#include <memory>
#include <vector>
#include <string>

template<class T>
class TrackingAllocator
{
public:
    using value_type = T;

    using pointer = T *;
    using const_pointer = const T *;

    using size_type = size_t;

    TrackingAllocator() = default;

    template<class U>
    TrackingAllocator(const TrackingAllocator<U> &other) {}

    ~TrackingAllocator() = default;

    pointer allocate(size_type numObjects)
    {
        mAllocations += numObjects;
        return static_cast<pointer>(operator new(sizeof(T) * numObjects));
    }

    void deallocate(pointer p, size_type numObjects)
    {
        operator delete(p);
    }

    size_type get_allocations() const
    {
        return mAllocations;
    }

private:
    static size_type mAllocations;
};

template<class T>
typename TrackingAllocator<T>::size_type TrackingAllocator<T>::mAllocations = 0;

int main()
{
    std::vector<std::string, TrackingAllocator<std::string>> v(3);
    std::cout << "allokált memóriahelyek száma:"<< v.get_allocator().get_allocations() << std::endl;
    std::cout << "allokált memóriahelyek címe:"<< std::endl;
    for(auto i=0;i<=v.size();++i){

        std::cout << &v[i] << std::endl;
    }
    

    return 0;
}

