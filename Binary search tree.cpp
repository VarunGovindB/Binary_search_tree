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
		int s;
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
		    if(current->data>x)
			{
				if(current->left==NULL)
				{
					temp->parent=current;
					current->left=temp;
					break;
				}
				
				else
				{
					current=current->left;
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
					current=current->right;
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
				cout<<temp->data<<" ";
				display(temp->right);
		    	
			}
		
		varun* search(varun *current, int x)
		    {
		    	if(current!=NULL)
		    	{
		    		if(current->data==x)
		    		return current;
		    		else if(current->data>x)
		    		return search(current->left,x);
		    		else
		    		return search(current->right,x);
				}
				else
				{
					return NULL;
				}
			}
			
		void range(varun *temp, int k1, int k2)
		{
			if(temp==NULL)
			return;
			range(temp->left,k1,k2);
			if(temp->data>=k1 && temp->data<=k2)
		    {
		    cout<<temp->data<<" ";
		    }
		    range(temp->right,k1,k2);
		}
		
		int count(varun *temp)
		{
			if(temp==NULL)
			return 0;
			count(temp->left);
			s++;
			count(temp->right);
			return s;
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
				if(temp->data>k->data)
				{
					temp->left=NULL;
					k->parent=NULL;
				}
				else
				{
					temp->right=NULL;
					k->parent=NULL;
				}
			}
			
			else if(k->left==NULL && k->right!=NULL)
			{
			    varun *temp;
				temp=k->parent;
				if(temp->data>k->data)
				{
					temp->left=k->right;
					k->parent=NULL;
				}
				else
				{
					temp->right=k->right;
					k->parent=NULL;
				}
			}
			
			else if(k->left!=NULL && k->right==NULL)
			{
			    varun *temp;
				temp=k->parent;
				if(temp->data>k->data)
				{
					temp->left=k->left;
					k->parent=NULL;
				}
				else
				{
					temp->right=k->left;
					k->parent=NULL;
				}
			}
			
	    	else
	    	{
			varun *temp;
			varun *current;
			temp=k->parent;
			current=k->right;
			while(current->left!=NULL)
			{
				current=current->left;
			}
			    if(temp->data>k->data)
				{
					temp->left=current;
					current->parent=temp;
				}
				else
				{
					temp->right=current;
					current->parent=temp;
				}
	        }
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
	cout<<endl;
	a.s=0;
	cout<<a.count(a.root);
	cout<<endl;
	a.deletenode(6);
	a.display(a.root);
	cout<<endl;
	a.s=0;
	cout<<a.count(a.root);
	cout<<endl;
	a.range(a.root,3,12);
	cout<<endl;
	a.s=0;
	cout<<a.count(a.root);
	a.deletenode(12);
	cout<<endl;
	a.display(a.root);
}
