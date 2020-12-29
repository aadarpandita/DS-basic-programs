#include<iostream>

using namespace std;


void max_heapify(int arr[], int i, int size)
{
	int l = 2*i;
	int r = 2*i + 1;
	int largest;

	
	if(l<=size && arr[l]>arr[i])
		largest=l;
	else 
		largest=i;
	
	if(r<=size && arr[r]>arr[largest])
		largest=r;

	swap(arr[largest],arr[i]);
	if(largest!=i)
	{
		max_heapify(arr,largest,size);
	}
	
}

void build_max_heap(int arr[], int size)
{
	for(int i=size/2;i>=1;i--)
		max_heapify(arr,i,size);
}

int deletion(int arr[], int &size)
{
	if(size<1)
	{
		cout<<"Error..Underflow.."<<endl;
		return -1;
	}
	int max = arr[1];

	arr[1]=arr[size];
	size--;

	max_heapify(arr,1,size);
	return max;
}

void insert(int arr[],int &size, int num)
{
	size++;
	int i=size; 
	arr[i]=num;

	while(i>1 && arr[i]>arr[i/2])
	{
		swap(arr[i],arr[i/2]);
		i=i/2;
	}
}

void heap_sort(int arr[], int size)
{
	build_max_heap(arr,size);

	for(int i=size;i>=1;i--)
	{
		swap(arr[1],arr[size]);

		max_heapify(arr,i,size);
	}
}

int main()
{	
	int size,num;

	cout<<"Enter the number of elements in the tree..";
	
	cin>>size;

	int arr[size];


	cout<<endl<<endl<<"Enter the elements of the heap tree.."<<endl;


	for(int i=1;i<=size;i++)
	{
		cin>>arr[i];
	}

	// int del = deletion(arr,size);
	//cout<<endl<<del<<endl;

	heap_sort(arr,size);

	for(int j=1;j<=size;j++)
		cout<<arr[j]<<'\t';

	// cout<<endl<<endl<<"Enter a number to be inserted into the heap..";
	// cin>>num;

	// insert(arr,size,num);

	// for(int j=1;j<=size;j++)
	// 	cout<<arr[j]<<'\t';

	return 0;
}
