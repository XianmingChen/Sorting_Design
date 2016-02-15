#ifndef _SORT_H
#define _SORT_H

#include<iostream>
#include<ctime>
#include<stack>

using namespace std;
const int Range=100;
const int DataLength=15;

template <typename DataType>
class Sort
{
private:
	DataType* data;
	//DataType data[10];
	int length;

public:
	Sort();
	Sort(int size);
	~Sort();

	void Print();
	void BubbleSort();
	void SelectSort();

	void InsertSort();
	void InsertSort2();

	void ShellSort();
	void ShellSort2();
	void ShellSort3();

	void HeapSort();
	void HeapBuild();
	void HeapAdjust(int index, int len);

	void MergeSort();
	void MergeSort(DataType* input, int start, int end);
	void Merge(DataType* input,int start,int mid,int end);

	int Partition(DataType* input, int start, int end);
	void QuickSort();
	void QuickSort(DataType* input, int start, int end);
	void QuickSort2(DataType* input, int start, int end);

	void RadixSort();
	int GetDigit(int input,int digital);
};

#endif 
