#include<iostream>
using namespace std;

bool searchChecker = false;
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
	node* search(node* temp, int key)
	{
		iCounter++;

		if (temp == NULL)
		{
			return temp;
		}
		if (temp->val == key)
		{
			searchChecker = true;
			return temp;
		}


		if (temp->val < key)
		{
			return search(temp->right, key);
		}

		return search(temp->left, key);
	}

	void iCounterDisplay()
	{
		cout << "Number of iterations = " << iCounter << endl;
	}

	void inorder(node* root)
	{
		if (root == NULL)
		{
			return;
		}

		inorder(root->left);

		cout << root->val << " ";

		inorder(root->right);
	}
	void preorder(node* root)
	{
		if (root == NULL)
			return;

		cout << root->val << " ";

		preorder(root->left);

		preorder(root->right);
	}
	void postorder(node* root)
	{
		if (root == NULL)
			return;

		postorder(root->left);

		postorder(root->right);

		cout << root->val << " ";
	}
	void find_smallest(node* temp)
	{

		if (temp->left == NULL)
		{
			cout << "smallest value is = " << temp->val << endl;
			return;
		}
		find_smallest(temp->left);


	}
	void find_largest(node* temp)
	{
		if (temp->right == NULL)
		{
			cout << "Largest value is = " << temp->val << endl;
			return;
		}
		find_largest(temp->right);
	}
	bool printAncestors(node* temp2, int ancester)
	{

		if (temp2 == NULL)
			return false;

		if (temp2->val == ancester)
			return true;

		if (printAncestors(temp2->left, ancester))
		{
			cout << temp2->val << " ";
			return true;
		}
		if (printAncestors(temp2->right, ancester))
		{
			cout << temp2->val << " ";
			return true;
		}


		return false;
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
		cout << "Press 3 to search Binary Search tree" << endl;
		cout << "Press 4 to inorder traversal" << endl;
		cout << "Press 5 to Preorder traversal" << endl;
		cout << "Press 6 to Postorder traversal" << endl;
		cout << "Press 7 to show to ancesters of a node"<< endl;
		cout << "Press 8 to end"<< endl;
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
			cout << "Enter Value = ";
			cin >> input;
			b1.search(b1.root, input);
			cout << endl;
		}
		else if (loopInput == 4)
		{
			b1.inorder(b1.root);
			cout << endl;
		}
		else if (loopInput == 5)
		{
			b1.preorder(b1.root);
			cout << endl;
		}
		else if (loopInput == 6)
		{
			b1.postorder(b1.root);
			cout << endl;
		}
		else if (loopInput == 7)
		{
			searchChecker = false;
			int aInput;
			cout << "Enter the node element to find its ancesters = ";
			cin >> aInput;
			b1.search(b1.root, aInput);
			if (searchChecker == false)
			{
				cout << endl;
				cout << "Value not found, please  try again" << endl;
				continue;
			}
			cout << endl;
			b1.printAncestors(b1.root, aInput);
			cout << endl;;
		}
		
		else if (loopInput == 8)
		{
			loopCounter = false;
		}
	}
}

