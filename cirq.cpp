#include<iostream>

using namespace std;


class Queue     							// Queue implementation through array
{	
	class Node
	{
		public:
			
		int data;
		Node *next;
	};

	
	Node* temp = NULL;
	Node* tail = NULL;
	Node* head = NULL;
	Node* ptr = NULL;

	Node* new_node(int num)
	{
		Node *temp = new Node;
		temp->data=num;
		temp->next=head;
		return temp;
	}

	public:

		void enq(int num)
		{
			if(head==NULL)
			{
				head=new_node(num);
				tail=head;
			}
			else
			{	
				temp=new_node(num);
				tail->next=temp;
				tail=tail->next;	
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
			tail->next=head->next;
			head=head->next;
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
			if(tail==NULL)
				return -1;

			return tail->data;
		}

};

int main()
{
	Queue q;

	q.enq(1);
	q.enq(2);
	q.enq(3);
	q.enq(4);
	q.enq(5);

	cout<<q.get_front()<<endl;
	cout<<q.deq()<<endl;
	cout<<q.get_front()<<endl;
	cout<<q.deq()<<endl;
	cout<<q.get_rear()<<endl;
	cout<<q.deq()<<endl;
	cout<<q.deq()<<endl;

	return 0;
}