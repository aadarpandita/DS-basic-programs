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

node* newNode(int data) 
{ 
    node *temp = new node; 
    temp->data = data;
    temp->left = temp->right = NULL; 
    return temp; 
} 

int* search(node* root, int num)
{

	if(root == NULL)
	{
		cout<<"No such element found..!"<<endl;		
		return NULL;
	}


	if(num == root->data)
		return &(root->data);

	
	if(num < root->data)
	{
		return search(root->left,num);
	}
	

	return search(root->right,num);

}

int* itersearch(node* root, int num)
{
	while(root)
	{
		if(num == root->data)
			return &(root->data);

		if(num < root->data)
			root = root->left;
		else
			root = root->right;

	}
	cout<<"No such element found..!"<<endl;
	return NULL;
}

node* insert(node* root, int num)
{
	if(root==NULL)
		root = newNode(num);

	if(num < root->data)
		root->left = insert(root->left, num);
	else if(num > root->data)
		root->right = insert(root->right, num);

	return root;
}

node* left_most(node* root)
{
	while(root!=NULL && root->left!=NULL)
		root=root->left;
	return root;
}

node* deletion(node* root, int num)
{
	if(root==NULL)
		return NULL;

	if(num < root->data)
		root->left = deletion(root->left, num);

	else if(num > root->data)
		root->right = deletion(root->right, num);

	else															// num = root
	{
		if(root->left == NULL)
		{
			node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			node* temp = root->left;
			free(root);
			return temp;
		}

		node* temp = left_most(root->right);

		root->data=temp->data;

		root->right = deletion(root->right, temp->data);				// updating the right subtree having the node which transfered its (inorder succ) data 
	}																	// to its inorder pred(node to be deleted)
	return root;
}

void postorder(node* ptr)
{
	
	if(ptr==NULL)
		return;

		postorder(ptr->left);
		postorder(ptr->right);
		cout<<ptr->data<<'\t';
}

int height(node* root)
{
	
	if(root==NULL)
		return 0;

	else
	{
		int left_height = height(root->left);
		int right_height = height(root->right);

		if(left_height > right_height)
			return left_height+1;
		else 
			return right_height+1;
	}

}

node* three_way_join(node* root1, int key, node* root2)
{
	node* root = newNode(key);
	root->left = root1;
	root->right = root2;

	return root;
}

node* two_way_join(node* root1, node* root2)
{
	


}

void split(node* root , int key)
{



}

int main()
{
	// node* root=newNode(8);
	// root->left=newNode(5);
	// root->right=newNode(10);
	// root->left->left=newNode(2);
	// root->left->right=newNode(7);

	// int* num=search(root,9);

	// int* num=itersearch(root,1);

	// cout<<*num<<endl;

	node* root=NULL;

	root = insert(root,8);
	insert(root, 3); 
    insert(root, 1); 
    insert(root, 6); 
    insert(root, 4); 
    insert(root, 7); 
    insert(root, 10);
    insert(root, 14);
    insert(root, 12);
    insert(root, 11);

    deletion(root, 12);
    deletion(root, 8);
    deletion(root, 10);
    root = deletion(root, 14);
	postorder(root);
	cout<<endl;
	cout<<height(root);
	cout<<endl;


	return 0;
}