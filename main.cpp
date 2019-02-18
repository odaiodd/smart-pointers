#include "SharedPtr.h"
#include <assert.h>  

void test_first_def()
{
	SharedPtr<int> p1 = new int(5);
	assert(p1.get_count() == 1);
	cout<<"test_first_def passed" <<endl;
}

void test_shared_four()
{
	SharedPtr<int> p1 = new int(5);
	SharedPtr<int> p2 = p1;
	SharedPtr<int> p3 = p1;
	SharedPtr<int> p4 = p1;
	assert(p1.get_count() == 4);
	assert(p2.get_count() == 4);
	assert(p3.get_count() == 4);
	assert(p4.get_count() == 4);
	cout<<"test_shared_four passed" <<endl;
}


void test_helper_1(SharedPtr<int> p1,SharedPtr<int> p2)
{
	assert(p1.get_count() == 4);
}


void test_shared_four_destruct_two()
{
	SharedPtr<int> p1 = new int(5); 
	SharedPtr<int> p2 = p1;
	test_helper_1(p1, p2);
	assert(p1.get_count() == 2);
	cout<<"test_shared_four_destruct_two passed" <<endl;

}

int main()
{
	test_first_def();
	test_shared_four();
	test_shared_four_destruct_two();
	
	return 0;
}