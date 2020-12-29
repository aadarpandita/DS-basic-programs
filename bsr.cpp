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
	int arr[50],size,num;

	cout<<"Enter size of array : "; cin>>size;

	int ub=(size-1),lb=0;
	int mid=(ub+lb)/2;

	cout<<endl<<"Enter elements in sorted order : "<<endl;
	
	enternum(arr,size);
	
	cout<<"Enter the number to be searched : "; cin>>num;
	cout<<endl<<endl;

	int index=binser(arr,size,num);

	if(index!=-1)
	{
		cout<<"Location is index = "<<index<<endl<<"Position is "<<(index+1)<<endl;
	}
	else
		cout<<index<<endl<<endl<<"Unsuccessful search..Number not found"<<endl;

	return 0;
}