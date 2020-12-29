#include<iostream>

using namespace std;

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
			swap(arr[j],arr[i]);
		}
	}
	swap(arr[i+1],arr[r]);

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
	int a[5]={10,20,1,6,15};

	//mergeso(a,0,4);
	quick(a,0,4);
	for(int i=0; i<5; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}