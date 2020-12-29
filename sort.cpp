#include<iostream>


using namespace  std;



void enternum(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	cout<<endl<<"Thanks.. "<<endl;
}

void swapnum(int &a, int &b)
{
	int temp;

	temp=a;
	a=b;
	b=temp;
}

void display(int arr[],int size)
{
	cout<<endl<<endl<<"Sorted array is : ";
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

}

void selso(int arr[],int size)
{
	int min,i,j;
	for(i=0;i<size;i++)
	{
		min=i;
		for(j=i+1;j<size;j++)
		{	
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		cout<<arr[i]<<" "<<arr[min]<<endl;
		swapnum(arr[i],arr[min]);
	}	
}



void inso(int arr[],int size)  
{  
	int i,j,temp;

	for(i=1;i<size;i++)
	{
		temp=arr[i];
		j=i-1;

		while(j>=0&&arr[j]>temp)
		{	
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}  

void merge(int arr[],int p,int q,int r)
{
	int i,j,k;
	int size1=q-p+1;
	int size2=r-q;
	int L[size1],R[size2];

	for(i=0;i<size1;i++)
	{
		L[i]=arr[p+i];
	}

	for(j=0;j<size2;j++)
	{
		R[j]=arr[q+1+j];
	}

	i=0;
	j=0;
	k=p;

	while(i<size1 && j<size2)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}

	
	while(i<size1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}

	while(j<size2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}

}

void mergeso(int arr[],int p,int r)
{
	if(p<r)
	{
		int q=p+(r-p)/2;

		mergeso(arr,p,q);
		mergeso(arr,q+1,r);

		merge(arr,p,q,r);
	}
}

int partition(int arr[],int p,int r)
{
	int i=p-1, x=arr[r];

	for(int j=p;j<r;j++)
	{
		if(arr[j]<=x)
		{
			i++;
			swapnum(arr[j],arr[i]);
		}
	}
	swapnum(arr[i+1],arr[r]);

	return (i+1);
}

void quick(int arr[],int p,int r)
{
	if(p<r)
	{
		int q=partition(arr,p,r);

		quick(arr,p,q-1);
		quick(arr,q+1,r);
	}
}

int main()
{
	int arr[100],size;

	cout<<"Enter size of array : "; cin>>size;
	
	cout<<endl<<"Enter elements to be sorted : "<<endl;
	
	enternum(arr,size);
	// selso(arr,size);
	//bubble(arr,size);
	// inso(arr,size);
	// mergeso(arr,0,size-1);
	quick(arr,0,size-1);
	display(arr,size);
	
	return 0;
} 
