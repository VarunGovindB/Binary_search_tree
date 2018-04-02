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
	
	varun* search(varun *current,int x)
	{
		if(current!=NULL)
		{
        if(current->data==x)
        return current;
        else if(current->data > x)
        return search(current->left,x);
		else
		return search(current->right,x);
	    }
	    else
	    {
	    return NULL;
	    }
	}
	
	void deletenode(int key)
	{   
		varun* k;
		k=search(root,key);
		if(k==NULL)
		{
		    cout<<"KEY NOT FOUND";	
		}
		else
		{
		    if(k->left==NULL&&k->right==NULL)
			{
			    varun *temp;
			    temp=k->parent;
			    if(temp->data < k->data)
			    {
				temp->right=NULL;
			    k->parent=NULL;
			    }
			    else if(temp->data > k->data)
			    {
			    temp->left=NULL;
			    k->parent=NULL;	
				}
		    }
		    
		    else if(k->left==NULL)
		    {
		    	varun *temp;
		    	temp=k->parent;
		    	if(temp->data < k->data)
		    	{
		    	temp->right=k->right;
		    	k->parent=NULL;
		        }
		        else if(temp->data > k->data)
		        {
		    	temp->left=k->right;
		    	k->parent=NULL;
		        }
			}
			
			else if(k->right==NULL)
			{
				varun *temp;
				temp=k->parent;
				if(temp->data < k->data)
				{
				temp->right=k->left;
				k->parent=NULL;
			    }
			    else if(temp->data > k->data)
			    {
			    temp->left=k->left;
				k->parent=NULL;	
				}
			}
			
			else
			
			
		}
	}
};

int main()
{
	btree a;
	a.insert(4);
	a.insert(6);
	a.insert(7);
	a.insert(3);
	a.insert(5);
	a.insert(12);
	a.insert(2);
	a.search(a.root,7);
	a.display(a.root);
	a.deletenode(7);
	a.display(a.root);
}
