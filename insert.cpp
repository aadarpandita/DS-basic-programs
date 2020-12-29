#include<iostream>

using namespace  std;

void enternum(int arr[50],int size)
{
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	cout<<endl<<"Thanks "<<endl;
}

int newpos(int arr[50],int size,int num)
{
	int pos,i;

	if(arr[0]>num)
		pos=0;
	else
	{
		for(i=0;i<size;i++)
		{
			if(arr[i]<=num&&arr[i+1]>num)
			{
				pos=i+1;
				break;
			}
		}
		if(i==size||i==(size-1))
			pos=size;
	}

	return pos;
}

int main()
{
	int arr[50],size,num,i;
	char ch='y';

	cout<<"Enter size of array : "; cin>>size;
	cout<<endl<<"Enter elements in sorted order : "<<endl;
	
	enternum(arr,size);

	while(ch=='y'||ch=='Y')
	{
		cout<<"Enter number to be inserted : ";
		cin>>num;

		int index=newpos(arr,size,num);
		for(i=size;i>index;i--)
		{
			arr[i]=arr[i-1];
		}
		arr[index]=num;
		size++;
		cout<<"Would you like to insert another number : (y/n) ";
		cin>>ch;
	}
	cout<<endl<<endl<<"New array is : ";
	for(i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
} 