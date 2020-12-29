#include<iostream>

using namespace std;


class node
{
	public:

	int data;
	node *next;
};
	
node* create_list(int size)
{
	node* head, *temp;

	head= new node;
	head->next=NULL;
	head->data=1;
	temp=head;

	for(int i=1;i<size;i++)
	{
		temp->next=new node;
		temp=temp->next;
		temp->data=i+1;
	}

	temp->next=head->next;
	
	return head;
}

void traversal(node* temp)		    		//temp=head;
{
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}

int find_middle(node* head,int size)
{	
	node* temp,*temp1;
	int count=1;
	
	temp=head; temp1=head;

	if(size%2==0)
	{
		while(temp1!=NULL)
		{
			temp=temp->next;
			count++;
			temp1=temp1->next->next;
		}
	}
	else
	{
		while(temp1->next!=NULL)
		{
			temp=temp->next;
			count++;
			temp1=temp1->next->next;
		}
	}
	

	return count;
}

int find_n_from_last(node* head,int n)
{
	node* temp, *temp1;
	temp=head;
	temp1=head;
	int count=1;

	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
		count++;
		if(count>n)
		{
			temp=temp->next;
		}
	}
	return temp->data;
}

int detect_cycle(node* head)
{
	node* temp,* temp1;
	temp=head;
	temp1=head;
	int count=0;

	while(temp1!=NULL)
	{
		temp=temp->next;
		temp1=temp1->next->next;
		if(temp==temp1)
		{
			count=1;
			return count;
		}
	}

	return count;
}

int main()
{
	node *temp, *head;
	int size,num,n;

	cout<<"Enter the size of the list : ";
	cin>>size;

	head=create_list(size);


	//int count=find_middle(head,size);
	//cout<<endl<<endl<<"The middle position is :  "<<count<<endl;


	// cout<<endl<<"Enter the nth position from last you want to see : ";
	// cin>>n;
	// num=find_n_from_last(head,n);
	// cout<<endl<<endl<<"The nth number from last is : "<<num<<endl<<endl;


	// int cycle=detect_cycle(head);
	// 	if(cycle==0)
	// 		cout<<endl<<"Cycle not found..!"<<endl;
	// 	else
	// 		cout<<endl<<endl<<"Cycle found..!"<<endl<<endl;


	temp=head;
	traversal(temp);

	return 0;

}