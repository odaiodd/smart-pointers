#ifndef SHAREDPTR_H
#define SHAREDPTR_H
#include <stddef.h>

template<typename T>
class SharedPtr
{
public:
    SharedPtr(T* ptr);
    SharedPtr(const SharedPtr&);
    ~SharedPtr();

    T* operator->() const;
    T& operator*()  const;
	operator bool() const;
	SharedPtr& operator=(T*);
    SharedPtr& operator=(const SharedPtr&);
    T* get() const;
    void check_delete();
    size_t get_count();

private:
    T* m_ptr;
    size_t* m_count_ptr;
};

#include "SharedPtr.tpp"

#endif
