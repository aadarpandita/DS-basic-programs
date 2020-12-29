#include<iostream>

using namespace  std;

void enternum(int array[50],int size)
{
	for(int i=0;i<size;i++)
	{
		cin>>array[i];
	}
	cout<<endl<<"Thanks "<<endl;
}

int binser(int arr[50],int size,int num)
{
	int ub=(size-1),lb=0;
	int index=-1;

	while(lb<=ub)
	{
		int mid=(ub+lb)/2;
		if(arr[mid]==num)
		{
			cout<<"Number found "<<endl;
			index=mid;
			break;
		}
		else if(arr[mid]>num)
		{
			ub=(mid-1);		//ascending
			//lb=(mid+1);			//descending
		}
		else
		{
			lb=(mid+1);		//ascending
			//ub=(mid-1);			//descending
		}

	}
	return index;
}

int main()
{
	int arr[50],size,num,i,flag=0;
	char ch='y';

	cout<<"Enter size of array : "; cin>>size;

	int ub=(size-1),lb=0;
	int mid=(ub+lb)/2;

	cout<<endl<<"Enter elements in sorted order : "<<endl;
	
	enternum(arr,size);

	while(ch=='y'||ch=='Y')
	{
		cout<<"Enter number to be deleted : ";
		cin>>num;

		int index=binser(arr,size,num);

		if(index!=-1)
		{
			arr[index]=0;
			flag=1;
		}
		else
			cout<<"Number not found.."<<endl;

		if(flag==1)
		{
			for(i=index;i<size;i++)
			{
				arr[i]=arr[i+1];
			}
			size--;
		}
		cout<<"Would you like to delete another number : (y/n) ";
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
