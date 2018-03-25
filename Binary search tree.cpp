#include <iostream>
using namespace std;

struct varun
{
	int data;
	varun *parent;
	varun *left;
	varun *right;
	varun()
	{
		data = 0;
		parent=left=right=NULL;
		
	}
};

class btree
{   
    public:
	varun *root;
	btree()
	 {
	 	root=NULL;
	 }
	 
	void insert(int x)
	{
		varun *temp = new varun;
		varun *current = new varun;
		temp->data=x;
		temp->parent=temp->left=temp->right=NULL;
		current = root;
		
	if(root==NULL)
	{
		root=temp;
	}
	else 
	{
	while(1)
	{
	if( current->data > x)
	{   
	    
		if(current->left==NULL)
		{
		    temp->parent=current;
		    current->left=temp;
		    break;
		} 
		else 
		{
			current= current->left;
		}
	}
	else
	{
		if(current->right==NULL)
		{
		    temp->parent=current;
		    current->right=temp;
		    break;
		} 
		else 
		{
			current= current->right;
		}
	}
	}
	}
	}
	
	void display(varun *temp)
	{
		if(temp==NULL)
		return;
		display(temp->left);
		cout<<temp->data;
	    display(temp->right);
	    
	}
    
	
};

int main()
{
	btree a;
	a.insert(4);
	a.insert(6);
	a.insert(7);
	a.insert(12);
	a.display(a.root);
}
