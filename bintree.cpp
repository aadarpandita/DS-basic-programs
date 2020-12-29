#include<iostream>
#include<queue>
#include<stack>
#include<climits>
using namespace std;
class node
{
	public:

		int data;
		node* left; node* right;
		bool is_threaded;
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

node* copy(node* orig)
{
	
	if(orig)
	{
		node* temp = new node;
		temp->left=copy(orig->left);
		temp->right=copy(orig->right);
		temp->data=orig->data;
		return temp;
	}
	return NULL;
}

int equaltree(node* root1,node* root2)								// recursive method
{
	
	if(root1==NULL&&root2==NULL)									// both trees are empty..therefore equal..
		return 1;

	if(root1!=NULL&&root2!=NULL)
	{

		return(root1->data==root2->data && 
				equaltree(root1->left,root2->left) &&
				equaltree(root1->right,root2->right));

	}
											
	return 0;														// one tree is empty and other is not 
}

bool equal_tree(node* root1,node* root2)							// iterative method
{
	if(root1==NULL&&root2==NULL)									// both trees are empty..therefore equal..
		return true;

	if(root1!=NULL&&root2==NULL||root1==NULL&&root2!=NULL)			// one tree is empty and other is not 
		return false;

	queue<node* > q1,q2;

	q1.push(root1);
	q2.push(root2);

	while(!q1.empty() && !q2.empty())
	{
		node* n1 = q1.front();
		node* n2 = q2.front();

		if(n1->data!=n2->data)
			return false;

		q1.pop();
		q2.pop();	

		if(n1->left && n2->left)
		{
			q1.push(n1->left);
			q2.push(n2->left);
		}
		else if(n1->left || n2->left)
			return false;

		if(n1->right && n2->right)
		{
			q1.push(n1->right);
			q2.push(n2->right);
		}
		else if(n1->right || n2->right)
			return false;
		
	}

	return true;

}

node* left_most(node* root)
{
	while(root!=NULL && root->left!=NULL)
		root=root->left;
	return root;
}

node* create_threaded(node* root)										// returns rightmost child of the root
{
	
	if(root==NULL)														// empty tree
		return NULL;

	if(root->left==NULL && root->right==NULL)							// only root present in tree
		return root;

	
	if(root->left!=NULL)
	{
		node* temp = create_threaded(root->left); 						// rightmost child in left sub-tree

		temp->right = root;
		temp->is_threaded = true;
	}

	if(root->right==NULL)
		return root;

	return create_threaded(root->right);

}

void inOrder(node* root) 												// for threaded binary tree
{

	if(root==NULL)
		return;

	node* temp = left_most(root);

	while(temp!=NULL)
	{
		
		cout<<temp->data<<'\t';
		
		if(temp->is_threaded)
			temp=temp->right;
		else 
			temp=left_most(temp->right);
	}
}

int is_BST(node* root, int min, int max)
{
	if(root==NULL)
		return 1;

	if(root->data < min || root->data > max)  
        return 0;

	return
		is_BST(root->left, min, root->data - 1)
		&& is_BST(root->right, root->data + 1, max);
}

int isBST(node* root)
{
	return(is_BST(root,INT_MIN,INT_MAX)); 
}

int main()
{
	
	node* root=newNode(10);
	root->left=newNode(7);
	root->right=newNode(30);
	root->left->left=newNode(2);
	root->left->right=newNode(8);
	

	// node* temp=copy(root);			


	// node* temp=newNode(1);
	// temp->left=newNode(2);
	// temp->right=newNode(3);
	// temp->left->left=newNode(4);
	// temp->left->right=newNode(5);


	// inorder(temp);
	// cout<<endl;
	// inorder(root);
	// cout<<endl;


	// if(equal_tree(root,temp))
	// 	cout<<"Trees are equal.."<<endl;
	// else
	// 	cout<<"Trees are not equal.."<<endl;

	// create_threaded(root);
	// inOrder(root);
	// cout<<endl;

	if(isBST(root))
		cout<<"Tree is a BST.."<<endl;
	else
		cout<<"Not a BST.."<<endl;


	return 0;
}