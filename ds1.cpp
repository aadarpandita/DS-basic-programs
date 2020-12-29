#include<iostream>


using namespace  std;

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

node* insert(int num,int pos, node* head)
{
	node* newptr=new node;
	node* temp;

	temp=head;

	if(pos==1)
	{
		newptr->next=temp;
		newptr->data=num;
		head=newptr;
	}
	else if(pos==-1)
	{

		while(temp->next!=NULL)
		{
			//cout<<temp->data<<endl;
			temp=temp->next;
			
		}
		temp->next=newptr;
		newptr->next=NULL;
		newptr->data=num;

	}
	else
	{
		for(int i=1;i<pos;i++)
		{
			temp=temp->next;
		}
		
		newptr->next=temp->next;
		temp->next=newptr;
		newptr->data=temp->data;

		temp->data=num;
	}
	
	return head;
}

node* delete_list(int pos, node* head)
{
	node* temp;
	temp=head;

		if(pos==1)
		{
			head=head->next;
		}
		else if(pos==-1)				//works for list greater than 1
		{
			while(temp->next->next!=NULL)
			{
				temp=temp->next;	
			}
			temp->next=NULL;
		}
		else							
		{
			for(int i=1;i<pos-1;i++)
			{
				temp=temp->next;
			}
			temp->next=temp->next->next;
		}

	return head;
}

int linser(node* head, int num)
{
	node* temp;
	int count=1;
	temp=head;

	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			return count;
		}
		temp=temp->next;
		count++;
	}
	
	return -1;

}

int main()
{
	node *temp, *head;
	int size,num;

	cout<<"Enter the size of the list : ";
	cin>>size;
	cout<<endl<<"Enter the number to be searched : ";
	cin>>num;

	head=create_list(size);

	//head=insert(13,-1,head);
	//head=delete_list(4,head);
	num=linser(head,num);
	temp=head;
	traversal(temp);
	if(num==-1)
		cout<<endl<<"Number not found..!"<<endl;
	else
		cout<<endl<<endl<<"Position of the number in the list is : "<<num<<endl<<endl;

	return 0;
} 