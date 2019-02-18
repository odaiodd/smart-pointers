#include <iostream>
using std::cout;
using std::endl;

template<typename T>
UniquePtr<T>::UniquePtr(T* ptr)
	:m_ptr(ptr)
{

}

template<typename T>
UniquePtr<T>::~UniquePtr()
{
	cout<< "~UniquePtr" << endl;
	delete m_ptr;
	m_ptr = NULL;
}


template<typename T>
T* UniquePtr<T>::operator->() const
{
	return m_ptr;
}


template<typename T>
T& UniquePtr<T>::operator*()  const
{
	return *m_ptr;
}
	

template<typename T>
UniquePtr<T>::operator bool() const
{
	if(m_ptr == NULL) return true;
	return false;
}
	 

template<typename T>
UniquePtr<T>& UniquePtr<T>::operator=(T* ptr)
{
	delete m_ptr;
	m_ptr = ptr;
	return *this;
}

    
template<typename T>
T* UniquePtr<T>::get() const
{
	return m_ptr;
}



