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

	int size = 6, arr[6]={-1,10,5,2,8,20};

	heap_sort(arr,size);

	for(int j=1;j<=size;j++)
		cout<<arr[j]<<'\t';

	return 0;
}
