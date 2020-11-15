#include<iostream>
using namespace std;
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
	
	
	int find_smallest(node* temp)
	{

		if (temp->left == NULL)
		{
			return temp->val;
		}
		find_smallest(temp->left);


	}
	int find_largest(node* temp)
	{
		if (temp->right == NULL)
		{
			return temp->val;
		}
		find_largest(temp->right);
	}

	
	bool binarySearchTree_Check(node* temp)
	{
		if (temp == NULL)
			return true;

		if (temp->left != NULL && find_largest(temp->left) > temp->val)
			return false;

		
		if (temp->right != NULL && find_smallest(temp->right) < temp->val)
			return false;

		
		if (!binarySearchTree_Check(temp->left) || !binarySearchTree_Check(temp->right))
			return false;

		
		return true;
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
		cout << "Press 3 to check if it is BST or not" << endl;
		cout << "Press 4 to end" << endl;
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
			if (b1.binarySearchTree_Check(b1.root) == true)
			{
				cout << "It is binary search tree" << endl;
			}
			else
			{
				cout << "It is not binary search tree" << endl;
			}
			system("pause");
		}
		else if (loopInput == 4)
		{
			loopCounter = false;
		}
	}
}

