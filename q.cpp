#include<iostream>

using namespace std;


class Queue     							// Queue implementation through array
{	
	
	int queue[20];
	int size;
	int front;
	int rear;

public:

	Queue(int size)
	{
		this->size=size;
		front=0;
		rear=0;
	}

	void enq(int num)
	{
		if(size==rear)
		{
			cout<<"Queue is full..! No more insertions can take place.."<<endl;
			return;
		}
		else
		{
			queue[rear]=num;			
			rear++;
		}
		return;
	}

	int deq()
	{
		if(front==rear)
		{
			cout<<"Queue is empty..! No more deletions can take place.."<<endl;

			return -1;
		}

		int del=queue[front];
		
		for(int i=0;i<rear-1;i++)
		{
			queue[i]=queue[i+1];
		}
		rear--;

		return del;
	}

	int get_front()
	{
		if(front==rear)
		{
			cout<<"Queue is empty..!"<<endl;
			return -1;
		}
		return queue[front];
	}

	int get_rear()
	{
		if(front==rear)
		{
			cout<<"Queue is empty..!"<<endl;
			return -1;
		}
		return queue[rear];
	}

};

// int main()
// {
// 	Queue q(5);

// 	q.enq(1);
// 	q.enq(2);
// 	q.enq(3);
// 	q.enq(4);
// 	//q.enq(5);

// 	cout<<q.get_front()<<endl;
// 	cout<<q.deq()<<endl;
// 	cout<<q.get_front()<<endl;
// 	cout<<q.deq()<<endl;
// 	cout<<q.get_rear()<<endl;
// 	cout<<q.deq()<<endl;
// 	cout<<q.deq()<<endl;
// 	cout<<q.get_front()<<endl;
// 	cout<<q.get_rear()<<endl;


// 	return 0;
// }



class Queue2 								// Queue implementation through linked lists
{

	class Node
	{
		public:
			
		int data;
		Node *next;
	};

	Node* head = NULL;
	Node* temp = NULL;
	
	Node* new_node(int num)
	{
		Node *temp = new Node;
		temp->data=num;
		temp->next=NULL;
		return temp;
	}

	public:

		void enq(int num)
		{
			if(head==NULL)
			{
				head=new_node(num);
			}
			else
			{	
				temp=new_node(num);
				Node* ptr=head;

				while(ptr->next!=NULL)
				{
					ptr=ptr->next;
				}
				ptr->next=temp;
			}
		}

		int deq()
		{
			Node* temp;
			if(head==NULL)
			{
				cout<<"Stack Underflow..! No more deletions can take place.."<<endl;
				return -1;
			}
			temp=head;
			int del = temp->data;
			head=head->next;
			temp->next=NULL;
			free(temp);

			return del;
		}

		int get_front()
		{
			if(head==NULL)
				return -1;

			return head->data;
		}

		int get_rear()
		{
			temp=head;

				if(temp==NULL)
					return -1;

				while(temp->next!=NULL)
				{
					temp=temp->next;
				}

				return temp->data;
		}
};

int main()
{
	Queue2 q;

	q.enq(1);
	q.enq(2);
	q.enq(3);
	q.enq(4);
	//q.enq(5);

	cout<<q.get_front()<<endl;
	cout<<q.deq()<<endl;
	cout<<q.get_front()<<endl;
	cout<<q.deq()<<endl;
	cout<<q.get_rear()<<endl;
	cout<<q.deq()<<endl;
	cout<<q.deq()<<endl;

	return 0;
}