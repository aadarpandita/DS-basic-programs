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
		temp->data=1;
	}

	//temp->next=head->next;			// for cycled list at 2
	
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


node* find_middle(node* head,int size)
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
	

	return temp;
}

node* merge_alt(node* head1,node* head2,node* head3)
{
	node* temp1,*temp2,*temp3;
	temp1=head1;
	temp2=head2;
	temp3=head3;

	while(temp3!=NULL)
	{
		
		if(temp1!=NULL)
		{
			temp3->data=temp1->data;
			temp1=temp1->next;
			temp3=temp3->next;
		}

		if(temp2!=NULL)
		{
			temp3->data=temp2->data;
			temp2=temp2->next;
			temp3=temp3->next;
		}
	}

	return head3;
}

node* reverse_list(node* head)
{
	node *curr,*temp;
	temp=head;
	
	while(temp->next!=NULL)
	{
		curr=temp->next;
		temp->next=curr->next;
		curr->next=head;
		head=curr;
	}

	return head;
}

node* add_one(node* head)
{
	node* temp;
	
	head=reverse_list(head);

	temp=head;

	while(temp->data==9&&temp!=NULL)
	{
		temp->data=0;
		if(temp->next==NULL)
			break;
		temp=temp->next;
	}
	if(temp->next==NULL&&temp->data==0)
	{
		temp->next=new node;
		temp->next->next=NULL;
		temp->next->data=1;
	}
	else if(temp->data<9)
		temp->data++;

	head=reverse_list(head);			// reverse the reversed list to get back original list with addition of one

	return head;
}

void palindrome(node* head, int size)
{	
	node *temp=NULL, *temp1=NULL, *head1=NULL;

	head1=find_middle(head,size);
	head1=reverse_list(head1);

	temp1=head1;
	temp=head;

	while(temp1!=NULL)
	{
		if(temp->data==temp1->data)
		{
			temp=temp->next;
			temp1=temp1->next;
		}
		else 
		{
			cout<<endl<<"Not a palindrome.."<<endl;
			break;
		}
	}
	if(temp1==NULL)
		cout<<endl<<"List is a palindrome"<<endl;

	head1=reverse_list(head1);

}

int main()
{
	node *temp=NULL, *temp1=NULL, *head1=NULL, *head2=NULL, *head=NULL;
	int size1,size2,size,num,n;

	cout<<"Enter the size of the list : ";
	cin>>size;

	head=create_list(size);									//create list



	// cout<<"Enter the size of the list 1: ";				//merge list
	// cin>>size1;
	// cout<<"Enter the size of the list 2: ";
	// cin>>size2;

	//size=size1+size2;

	// head1=create_list(size1);
	// head2=create_list(size2);
	// head=create_list(size);

	//head=merge_alt(head1,head2,head);						//merge list


	//head=reverse_list(head);			// reverse list 


	//head=add_one(head);					// add one to list


	palindrome(head,size);
	
	return 0;

}