#include<iostream>
#include<queue>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;
class node
{
	public:
		int data;
		node* left; 
		node* right;
};

node* newNode(int data) 
{ 
    node *temp = new node; 
    temp->data = data;
    temp->left = temp->right = NULL; 
    return temp; 
} 

void inorder(node* ptr)
{
	
	if(ptr==NULL)
		return;
	
		inorder(ptr->left);
		cout<<ptr->data<<'\t';
		inorder(ptr->right);
}

node* make_mirror(node* orig)					// opposite of copy method
{
	
	if(orig)
	{
		node* temp = new node;
		temp->right=make_mirror(orig->left);
		temp->left=make_mirror(orig->right);
		temp->data=orig->data;
		return temp;
	}
	return NULL;
}

void print_mirror(node* ptr)					// opposite of level order method
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
			q.push(temp->left);
	}

}

void mirror_tree(node* root)					// changing same tree to its mirror
{
	if(root==NULL)
		return;
	
	mirror_tree(root->left);
	mirror_tree(root->right);

	node* temp = root->left;
	root->left = root->right;
	root->right = temp;

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

void print_level(node* root, int level, int ltr)
{
	if(root==NULL)
		return;

	if(level==1)
		cout<<root->data<<'\t';

	else if(level>1)
	{
		if(ltr)
		{
			print_level(root->left,level-1,ltr);
			print_level(root->right,level-1,ltr);
		}
		else
		{
			print_level(root->right,level-1,ltr);
			print_level(root->left,level-1,ltr);	
		}
	}
}

void print_spiral(node* root)
{
	if(root==NULL)
		return;
	
	bool ltr = false;
	int h=height(root);
	

	for(int i=1;i<=h;i++)
	{
		print_level(root,i,ltr);
		ltr = !ltr;
	}
}

int kthsmallest(int arr[], int k, int size)
{
	sort(arr,arr+size);
	return arr[k-1];
}

void leftview(node* ptr, queue<node* > &q)
{
	
	if(ptr==NULL)
		return;

	q.push(ptr);

	q.push(NULL);

	while(q.empty()==false)
	{
		node* temp=q.front();

		if(temp)
		{
			cout<<temp->data<<'\t';
		
			while(q.front()!=NULL)
			{
				if(temp->left!=NULL)
					q.push(temp->left);

				if(temp->right!=NULL)
					q.push(temp->right);

				q.pop();

				temp = q.front();
			}
			q.push(NULL);
		}
		q.pop();
	}
}

void left_view(node* root)
{
	queue<node* > q;
	leftview(root,q);
}

node* find_LCA(node* root, int n1, int n2)
{
	if(root==NULL)
		return NULL;

	if(root->data == n1 || root->data == n2)
		return root;

	node* left_LCA = find_LCA(root->left,n1,n2);
	node* right_LCA = find_LCA(root->right,n1,n2);

	if(left_LCA && right_LCA)
		return root;
	return (left_LCA!=NULL) ? left_LCA : right_LCA;
}

int main()
{
	
	// node* root=newNode(10);
	
	// root->left=newNode(7);
	// root->right=newNode(30);
	// root->left->left=newNode(2);
	// root->left->right=newNode(8);
	
	// mirror_tree(root);
	// levelorder(root);
	// cout<<endl<<endl;
	// node* temp=copy(root);	
	// left_view(root);
	// cout<<endl<<endl;

	// print_spiral(root);
	// cout<<endl<<endl;


	// int arr[8]={10,18,24,59,11,63,34,25};
	// int k=3,size=8;
	// int small = kthsmallest(arr,k,size);
	// cout<<endl<<small<<endl;


 //    cout<<endl<< "LCA(4, 5) = " << find_LCA(root, 4, 5)->data; 

 //    cout<<endl<< "LCA(6, 7) = " << find_LCA(root, 6, 7)->data;

 //    cout<<endl<< "LCA(3, 7) = " << find_LCA(root, 3, 7)->data;

 //    cout<<endl<< "LCA(4, 7) = " << find_LCA(root, 4, 7)->data<<endl;   

	return 0;
}