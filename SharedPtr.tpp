#include <iostream>
using std::cout;
using std::endl;

template<typename T>
SharedPtr<T>::SharedPtr(T* ptr)
	:m_ptr(ptr), m_count_ptr(new size_t(1))
{
	// cout<<"T* constructor"<<endl;
}

template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& sp){
	// cout<<"copy constructor"<<endl;
	m_count_ptr = sp.m_count_ptr;
	m_ptr = sp.m_ptr;
	(*m_count_ptr)++;
}

template<typename T>
SharedPtr<T>::~SharedPtr()
{
	check_delete();
	// cout<<"destructor: "<< *(m_count_ptr)<<endl;
}


template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& sp)
{
	// cout<<"operator = for SharedPtr"<<endl;
	check_delete();
	m_count_ptr = sp.m_count_ptr;
	m_ptr = sp.ptr;
	(*m_count_ptr)++;
}

template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(T* ptr)
{
	// cout<<"operator = for T*"<<endl;
	check_delete();
	m_ptr = ptr;
	return *this;
}

template<typename T>
void SharedPtr<T>::check_delete()
{
	if(*m_count_ptr == 0)
	{
		delete m_ptr;
		m_ptr = NULL;
		delete m_count_ptr;
	}else{
		*m_count_ptr -= 1;
	}
}

template<typename T>
T* SharedPtr<T>::operator->() const
{
	return m_ptr;
}


template<typename T>
T& SharedPtr<T>::operator*()  const
{
	return *m_ptr;
}
	

template<typename T>
SharedPtr<T>::operator bool() const
{
	if(m_ptr == NULL) return true;
	return false;
}
	 
template<typename T>
T* SharedPtr<T>::get() const
{
	return m_ptr;
}

template<typename T>
size_t SharedPtr<T>::get_count()
{
	return *m_count_ptr;
}


