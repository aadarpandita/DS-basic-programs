#include<iostream>
 
using namespace std;



int linser(int arr[50],int size,int num)
{
	int index=-1;


	for(int i=0;i<size;i++)
	{
		if(arr[i]==num)
		{
			cout<<"Number found.."<<endl;
			index=i;
		}
	}


	return index;
}

void enternum(int array[50],int size)
{
	for(int i=0;i<size;i++)
	{
		cin>>array[i];
	}
	cout<<endl<<"Thanks "<<endl;
}


int main()
{

	int arr[50],size,num;

	cout<<"Enter size of array : "; cin>>size;
	cout<<endl<<"Enter elements : "<<endl;
	
	enternum(arr,size);
	
	cout<<"Enter the number to be searched : "; cin>>num;
	
	cout<<endl<<endl;
	int index=linser(arr,size,num);
	if(index!=-1)
	{
		cout<<"Location is index = "<<index<<endl<<"Position is "<<(index+1)<<endl;
	}
	else
		cout<<index<<endl<<endl<<"Unsuccessful search..Number not found"<<endl;
	
	return 0;
}