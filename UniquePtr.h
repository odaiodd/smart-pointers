#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H
#include <stddef.h>

template<typename T>
class UniquePtr
{
public:
    explicit UniquePtr(T* ptr);
    ~UniquePtr();

    T* operator->() const;
    T& operator*()  const;
	operator bool() const;
	UniquePtr& operator=(T*);
    T* get() const;

private:
    // Prevent coping 
    UniquePtr(UniquePtr const&);
    UniquePtr& operator=(UniquePtr const&);
    T* m_ptr;
};

#include "UniquePtr.tpp"

#endif
