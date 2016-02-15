#include "Sort.h"
#include "Sort.cpp"

int main()
{
	Sort<int> Test(DataLength);
	Test.Print();
	Test.RadixSort();
	Test.Print();

	system("pause");
	return 1;
}