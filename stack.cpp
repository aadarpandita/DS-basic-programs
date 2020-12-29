#include<iostream>

using namespace std;


class MyStack 										// Stack implementation through array
{
	int stack[20];
	int size;
	int top;

	public:

		MyStack(int size) 
		{
			this->size = size;
			top = -1;
		}

		int push(int num)
		{
			if(top==size-1)
			{
				cout<<"Stack Overflow..! No more insertions can take place.."<<endl;
				return -1;
			}
		
			top++;
			stack[top]=num;
			return 0;
		}

		int pop()
		{
			if(top==-1)
			{
				cout<<"Stack Underflow..! No more deletions can take place.."<<endl;
				return -1;
			}
		
			int del = stack[top];
			top--;

			return del;
		}

		int getTop()
		{
			if(top==-1)
				return -1	;
			
			return stack[top];
		}

};

	

class MyStack2											// Stack implementation through linked lists
{
	
	class Node
	{
		public:
				
			int data;
			Node *next;
	};
	
	Node* head = NULL;
	Node* ptr = NULL;

	Node* new_node(int num)
	{
		Node *temp = new Node;
		temp->data=num;
		temp->next=NULL;
		return temp;
	}

		
	public:

		void push(int num)
		{
			Node* temp;
			if(head==NULL)
			{
				head=new_node(num);
			}
			else
			{
				temp=new_node(num);
				temp->next=head;
				head=temp;
			}	
		}

		int pop()
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

		int getTop()
		{
			if(head==NULL)
				return -1;

			return head->data;
		}

};


// int main()
// {
// 	// MyStack *m = new MyStack(5);
// 	// m->push(1);	
// 	// cout<< m->getTop()<<endl;

// 	MyStack stack(5);
// 	stack.push(1);
// 	stack.push(2);
// 	stack.push(3);
// 	stack.push(4);
// 	cout<<stack.pop()<<endl;
// 	cout<<stack.pop()<<endl;
// 	cout<<stack.getTop()<<endl;

// 	return 0;
// }

int main()
{
	// MyStack *m = new MyStack(5);
	// m->push(1);	
	// cout<< m->getTop()<<endl;

	MyStack2 stack;
	stack.push(1);
	stack.push(2);
	//stack.push(head,3);
	//stack.push(head,4);
	cout<<stack.pop()<<endl;
	//cout<<stack.pop(head)<<endl;
	cout<<stack.getTop()<<endl;

	return 0;
}