#include<iostream>
using namespace std;

bool searchChecker = false;
int leafCount = 0;
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
	node* insert(node* temp1, int temp2) 
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
		else if (temp2 > temp1->val) 
		{
			temp1->right = insert(temp1->right, temp2);
		}

		return temp1;
	}
	
	void inorder(node* temp)
	{
		if (temp == NULL)
		{
			return;
		}

		inorder(temp->left);

		cout << temp->val << " ";

		inorder(temp->right);
	}
	void preorder(node* temp)
	{
		if (temp == NULL)
		{
			return;
		}

		cout << temp->val << " ";

		preorder(temp->left);

		preorder(temp->right);
	}
	void postorder(node* temp)
	{
		if (temp == NULL)
			return;

		postorder(temp->left);

		postorder(temp->right);

		cout << temp->val << " ";
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
		cout << "Press 3 to inorder traversal" << endl;
		cout << "Press 4 to Preorder traversal" << endl;
		cout << "Press 5 to Postorder traversal" << endl;
		cout << "Press 6 to end" << endl;
		cin >> loopInput;
		system("cls");
		if (loopInput == 1)
		{
			cout << "Enter Value = ";
			cin >> input;
			b1.rootInsert(input);
			cout << endl;
		}
		else if (loopInput == 2)
		{
			cout << "Enter Value = ";
			cin >> input;
			b1.insert(b1.root, input);
			cout << endl;
		}
		else if (loopInput == 3)
		{
			b1.inorder(b1.root);
			cout << endl;
			
		}
		else if (loopInput == 4)
		{
			b1.preorder(b1.root);
			cout << endl;
			
		}
		else if (loopInput == 5)
		{
			b1.postorder(b1.root);
			cout << endl;
		}
		else if (loopInput == 6)
		{
			loopCounter = false;
			
		}
	}
}

