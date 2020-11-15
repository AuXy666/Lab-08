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
	node* search(struct node* root, int key)
	{
		iCounter++;

		if (root == NULL || root->val == key)
			return root;

		if (root->val < key)
		{
			return search(root->right, key);
		}

		return search(root->left, key);
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
		cout << "Press 6 to find the smallest value" << endl;
		cout << "Press 7 to find the greatest value" << endl;
		cout << "Press 8 to end" << endl;
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
			b1.find_smallest(b1.root);
		}
		else if (loopInput == 7)
		{
			b1.find_largest(b1.root);
		}
		else if (loopInput == 8)
		{
			loopCounter = false;
		}
		
	}
}

