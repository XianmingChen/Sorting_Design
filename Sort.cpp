#include "Sort.h"

template<typename DataType>
void Swap(DataType& A,DataType& B)
{
	DataType tmp=A;
	A=B;
	B=tmp;
}

template <typename DataType>
Sort<DataType>::Sort()
{
	data=NULL;
	length=0;
}

template <typename DataType>
Sort<DataType>::Sort(int size)
{
	int i;
	int tmp;

	data=new DataType[size];
	length=size;

	srand((unsigned)time(NULL));
	for (i=0;i<size;i++)
	{
		tmp=rand()%Range;
		data[i]=(DataType)tmp;
	}
}

template <typename DataType> 
Sort<DataType>::~Sort()
{
	delete[] data;
}

template <typename DataType>
void Sort<DataType>::Print()
{
	int i;

	for (i=0;i<length;i++)
	{
		cout<<data[i]<<" ";
	}
	cout<<endl;
}

template <typename DataType> 
void Sort<DataType>::BubbleSort()
{
	int i,j;

	for(i=1;i<length;i++)
	{
		for(j=0;j<length-i;j++)
		{
			if(data[j]>data[j+1])
			{
				Swap(data[j],data[j+1]);
			}
		}
	}
}

template<typename DataType>
void Sort<DataType>::SelectSort()
{
	int i,j;
	int TmpMax,index;

	for(i=0;i<length-1;i++)
	{
		TmpMax=data[0];
		index=0;
		for(j=1;j<length-i;j++)
		{
			if(data[j]>TmpMax)
			{
				TmpMax=data[j];
				index=j;
			}
		}
		Swap(data[index],data[length-i-1]);
	}
}

template <typename DataType> 
void Sort<DataType>::InsertSort()
{
	int i,j;
	DataType key;

	for(i=1;i<length;i++)
	{
		key=data[i];
		j=i-1;
		while((j>=0)&&(data[j]>key))
		{
			data[j+1]=data[j];
			j--;
		}
		data[j+1]=key;
	}
}

template <typename DataType> 
void Sort<DataType>::InsertSort2()
{
	int i,j;
	DataType key;

	for(i=1;i<length;i++)
	{
		key=data[i];
		for(j=i-1;j>=0;j--)
		{
			if(key<data[j])
			{
				data[j+1]=data[j];
			}
			else
				break;
		}
		data[j+1]=key;
	}
}

template<typename DataType>
void Sort<DataType>::ShellSort()
{
	int i,j;
	int step,group;

	DataType key;

	for(step=length/2;step>0;step=step/2)
	{
		for(group=0;group<step;group++)
		{
			for(i=step+group;i<length;i=i+step)
			{
				key=data[i];
				j=i-step;
				while((key<data[j])&&(j>=0))
				{
					data[j+step]=data[j];
					j=j-step;
				}
				data[j+step]=key;
			}
		}
	}
}

template<typename DataType>
void Sort<DataType>::ShellSort2()
{
	int i,j;
	int step;
	DataType key;

	for(step=length/2;step>0;step=step/2)
	{
		for(i=step;i<length;i++)
		{
			key=data[i];
			j=i-step;
			while((key<data[j])&&(j>=0))
			{
				data[j+step]=data[j];
				j=j-step;
			}
			data[j+step]=key;
		}
	}

}

template<typename DataType>
void Sort<DataType>::ShellSort3()
{
	int i,j;
	int step;
	//DataType key;

	for(step=length/2;step>0;step=step/2)
	{
		for(i=step;i<length;i++)
		{
			for(j=i-step;j>=0&&data[j]>data[j+step];j=j-step)
				Swap(data[j],data[j+step]);
		}
	}
}

template<typename DataType>
void Sort<DataType>::HeapAdjust(int index, int len)
{
	int lchild,rchild,largest;

	while(index<len)
	{
		lchild=2*index;
		rchild=2*index+1;

		if((lchild<len)||(rchild<len))
		{
			if(data[index]<data[lchild])
			{
				largest=lchild;
				if((rchild<len)&&(data[lchild]<data[rchild]))
					largest=rchild;
			}
			else
			{
				largest=index;
				if((rchild<len)&&(data[index]<data[rchild]))
					largest=rchild;
			}
			if(largest==index)
				break;
			else
			{
				swap(data[index],data[largest]);
				index=largest;
			}
		}
		else
			break;
	}
}

template<typename DataType>
void Sort<DataType>::HeapBuild()
{
	int i;
	int start=length/2-1;

	for(i=start;i>=0;i--)
	{
		HeapAdjust(i,length);
	}
}

template<typename DataType>
void Sort<DataType>::HeapSort()
{
	int i;

	HeapBuild();
	for(i=0;i<length;i++)
	{
		swap(data[0],data[length-i-1]);
		HeapAdjust(0,length-i-1);
	}
}

template<typename DataType>
void Sort<DataType>::Merge(DataType* input,int start,int mid,int end)
{
	int i,index=0,len=end-start+1;
	DataType* temp=new DataType[len];
	int point1=start,point2=mid+1;

	while((point1<=mid)&&(point2<=end))
	{
		if(input[point1]<input[point2])
			temp[index++]=input[point1++];
		else
			temp[index++]=input[point2++];
	}

	if(point1>mid)
	{
		while(point2<=end)
			temp[index++]=input[point2++];
	}
	else
	{
		while(point1<=mid)
			temp[index++]=input[point1++];
	}

	for(i=0;i<len;i++)
		input[start+i]=temp[i];

	delete[] temp;
}

template<typename DataType>
void Sort<DataType>::MergeSort(DataType* input, int start, int end)
{
	int mid;
	if(start<end)
	{
		mid=(end+start)/2;
		MergeSort(input,start,mid);
		MergeSort(input,mid+1,end);
		Merge(input,start,mid,end);
	}
}

template<typename DataType>
void Sort<DataType>::MergeSort()
{
	MergeSort(data,0,length-1);
}

template<typename DataType>
int Sort<DataType>::Partition(DataType* input, int start, int end)
{
	int i;
	int pos=start;
	DataType pivot=input[end];

	for(i=start;i<end;i++)
	{
		if(input[i]<pivot)
		{
			swap(input[i],input[pos]);
			pos++;
		}
	}
	swap(input[end],input[pos]);
	return pos;
}

template<typename DataType>
void Sort<DataType>::QuickSort(DataType* input, int start, int end)
{
	int mid;
	if(start<end)
	{
		mid=Partition(input,start,end);
		QuickSort(input,start,mid-1);
		QuickSort(input,mid+1,end);
	}
}

template<typename DataType>
void Sort<DataType>::QuickSort2(DataType* input, int start, int end)
{
	stack<int> record;
	int mid;

	if(start<end)
	{
		mid=Partition(input,start,end);
		if(start+1<mid)
		{
			record.push(start);
			record.push(mid-1);
		}
		
		if(mid+1<end)
		{
			record.push(mid+1);
			record.push(end);
		}

		while(!record.empty())
		{
			end=record.top();
			record.pop();
			start=record.top();
			record.pop();

			mid=Partition(input,start,end);
			if(start+1<mid)
			{
				record.push(start);
				record.push(mid-1);
			}
		
			if(mid+1<end)
			{
				record.push(mid+1);
				record.push(end);
			}
		}
	}
}

template<typename DataType>
void Sort<DataType>::QuickSort()
{
	QuickSort2(data,0,length-1);
}

template<typename DataType>
int Sort<DataType>::GetDigit(int input,int digital)
{
	int i;

	for(i=0;i<digital;i++)
	{
		input=input/10;
	}
	return input%10;
}

template<typename DataType>
void Sort<DataType>::RadixSort()
{
	int i,j,k;
	int digital=3;
	//int **radix;
	int radix[10][DataLength+1];
	int DigitVal,num,new_order;

	//radix=new int *[10];
	//for(i=0;i<10;i++)
	//	radix[i]=new int(length+1); 

	for(i=0;i<digital;i++)
	{
		for(k=0;k<10;k++)  //Initialization
			radix[k][0]=0; //The first value stores the number of element

		for(j=0;j<length;j++) //Distribute
		{
			DigitVal=GetDigit(data[j],i);
			radix[DigitVal][0]++;
			num=radix[DigitVal][0];
			radix[DigitVal][num]=data[j];
		}

		new_order=0;
		for(j=0;j<10;j++) //Collection
		{
			num=radix[j][0];
			for(k=0;k<num;k++) 
			{
				data[new_order]=radix[j][k+1];
				new_order++;
			}
		}
	}

	//for(i=0;i<10;i++)
	//{
	//	delete []radix[i];
	//	radix[i]=NULL;
	//}
	//delete []radix;
	//radix=NULL;
}