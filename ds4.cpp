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

// node* merge_2in1_alt(node* head1,node* head2)
// {
	



// }

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

// node* first;					// experimentation with recursion
// node* mid;
// int a=0;
// int b=3;

// void func(node* head)
// {
// 	if(head==NULL)
// 		return;
	
// 	func(head->next);
// 	b++;
// 	if(first == NULL)
// 		return;
	
// 	cout<<first->data<<"\t";
// 	cout<<head->data<<endl;
	
// 	if(head == mid)
// 	{
// 		first = NULL;
// 		return;
// 	}
// 	a++;
// 	first = first->next;
// }

int main()
{
	
	node *temp=NULL, *temp1=NULL, *head1=NULL, *head2=NULL, *head=NULL;
	int size1,size2,size,num,n;

	cout<<"Enter the size of the list : ";
	cin>>size;
	// size = 6;
	head=create_list(size);									//create list

	// temp=find_middle(head,size);

	// temp=reverse_list(temp);

	// merge_alt(head,temp,);


	//mid = find_middle(head,size);							//recursion experiment
	// first = head;
	// func(head);
	// cout<<a<<"\t"<<b<<endl;


	return 0;

}