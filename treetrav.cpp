#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node
{
	public:

		int data;
		node* left;
		node* right;		
};

void inorder(node* ptr)
{
	
	if(ptr==NULL)
		return;
	
		inorder(ptr->left);
		cout<<ptr->data<<'\t';
		inorder(ptr->right);
}

void preorder(node* ptr)
{
	
	if(ptr==NULL)
		return;

		cout<<ptr->data<<'\t';
		preorder(ptr->left);
		preorder(ptr->right);
}

void postorder(node* ptr)
{
	
	if(ptr==NULL)
		return;

		postorder(ptr->left);
		postorder(ptr->right);
		cout<<ptr->data<<'\t';
}

void levelorder(node* ptr)
{

	if(ptr==NULL)
		return;

	
	queue<node* > q;

	q.push(ptr);

	while(q.empty()==false)
	{
		node* temp=q.front();
		cout<<temp->data<<'\t';
		q.pop();

		if(temp->left!=NULL)
			q.push(temp->left);

		if(temp->right!=NULL)
			q.push(temp->right);
	}

}

void in_order(node* ptr)
{
	stack<node* > s;
	node* temp=ptr;

	while(temp!=NULL||s.empty()==false)
	{
		while(temp!=NULL)
		{
			s.push(temp);
			temp=temp->left;
		}

		temp=s.top();
		s.pop();

		cout<<temp->data<<'\t';
		temp=temp->right;

	}

}

node* newNode(int data) 
{ 
    node *temp = new node; 
    temp->data = data;
    temp->left = temp->right = NULL; 
    return temp; 
} 

int main()
{
	node* root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);

	// cout<<"preorder : "<<endl;
	// preorder(root);
	// cout<<endl<<"inorder : "<<endl;
	// inorder(root);
	// cout<<endl<<"postorder : "<<endl;
	// postorder(root);
	// cout<<endl<<"levelorder : "<<endl;
	// levelorder(root);
	// cout<<endl;
	cout<<endl<<"inorder without recursion : "<<endl;
	in_order(root);
	cout<<endl;

	return 0;
}