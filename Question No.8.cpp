#include<iostream>
#include <stack>
using namespace std;

bool searchChecker = false;
int leafCount = 0;
int hCounter = 0;
class node
{
public:
	int val;
	node* left;
	node* right;
};

class binarySearch_Tree
{
public:
	node* root;
	int iCounter;
	binarySearch_Tree()
	{
		root = NULL;
		iCounter = 0;
	}
	node* newNode(int item)
	{
		node* temp = new node;
		temp->val = item;
		temp->left = temp->right = NULL;
		return temp;
	}
	void rootInsert(int temp)
	{
		if (root == NULL)
		{
			root = newNode(temp);
		}
	}
	node* insert(node* temp1, int temp2) //root,value
	{

		if (temp1 == NULL)
		{
			temp1 = newNode(temp2);
			return temp1;
		}

		if (temp2 < temp1->val)
		{
			temp1->left = insert(temp1->left, temp2);
		}
		else if (temp2 > temp1->val) //5 //6
		{
			temp1->right = insert(temp1->right, temp2);
		}

		return temp1;
	}
	void inorder(node* temp)
	{
		stack<node*> s;
		while (temp != NULL || s.empty() == false)
		{
			
			while (temp != NULL)
			{
				
				s.push(temp);
				temp = temp->left;
			}

			
			temp = s.top();
			s.pop();

			cout << temp->val << " ";

			
			temp = temp->right;

		} 
	}
	void preorder(node *root)
	{
		if (root == NULL)
			return;

		stack<node*> s;
		s.push(root);

		while (s.empty() == false)
		{
			node* temp2 = s.top();
			s.pop();
			cout << temp2->val << " ";

			
			if (temp2->right)
			{
				s.push(temp2->right);
			}
			if (temp2->left)
			{
				s.push(temp2->left);
			}
		}
	}
	void postorder(node* root)
	{
		stack<node*> s1;
		stack<node*> s2;

		s1.push(root);
		while (s1.empty() == false)
		{
			node* temp2 = s1.top();
			s1.pop();
			s2.push(temp2); 

			if (temp2->left)
				s1.push(temp2->left); 
			if (temp2->right)
				s1.push(temp2->right); 
		}

		while (s2.empty() == false)
		{
			node* temp3 = s2.top();
			s2.pop();
			cout <<temp3->val  << " ";
			
		}
	}

	

};


int main()
{
	binarySearch_Tree b1;
	bool loopCounter = true;
	int loopInput;
	int input;
	while (loopCounter)
	{
		cout << "Press 1 to enter Root of Binary Search Tree" << endl;
		cout << "Press 2 to insert into Binary Search tree" << endl;
		cout << "Press 3 to inorder traversal using stacks" << endl;
		cout << "Press 4 to Preorder traversal using stacks" << endl;
		cout << "Press 5 to Postorder traversal using stacks" << endl;
		cout << "Press 6 to end" << endl;
		cin >> loopInput;
		system("cls");
		if (loopInput == 1)
		{
			cout << "Enter Value = ";
			cin >> input;
			b1.rootInsert(input);
			cout << endl;
			system("pause");
		}
		else if (loopInput == 2)
		{
			cout << "Enter Value = ";
			cin >> input;
			b1.insert(b1.root, input);
			cout << endl;
			system("pause");
		}
		else if (loopInput == 3)
		{
			b1.inorder(b1.root);
			cout << endl;
			system("pause");
		}
		else if (loopInput == 4)
		{
			b1.preorder(b1.root);
			cout << endl;
			system("pause");
		}
		else if (loopInput == 5)
		{
			b1.postorder(b1.root);
			cout << endl;
			system("pause");
		}
		else if (loopInput == 6)
		{
			loopCounter = false;
		}
	}
}

