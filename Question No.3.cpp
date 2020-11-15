#include<iostream>
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
	node* searcher(node* temp, int search)
	{
		iCounter++;

		if (temp == NULL)
		{
			return temp;
		}
		if (temp->val == search)
		{
			searchChecker = true;
			return temp;
		}


		if (temp->val < search)
		{
			return searcher(temp->right, search);
		}

		return searcher(temp->left, search);
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
	void preorder(node* root)
	{
		if (root == NULL)
		{
			return;
		}

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
	node* find_smallest(node* temp)
	{

		if (temp->left == NULL)
		{
			return temp;
		}
		find_smallest(temp->left);


	}
	node* deleteNode(node* temp, int search)
	{
		if (temp == NULL)
			return temp;

		if (search < temp->val)
			temp->left = deleteNode(temp->left, search);

		else if (search > temp->val)
			temp->right = deleteNode(temp->right, search);

		else {
			
			if (temp->left == NULL)
			{
				node* temp3 = new node;
				temp3=temp->right;
				delete temp3;
				return temp3;
			}
			else if (temp->right == NULL) {
				node* temp3 = new node;
				temp3=temp->left;
				delete temp3;
				return temp3;
			}

			
			node* temp2 = new node;
			temp2=find_smallest(temp->right);
			temp->val = temp2->val;
			temp->right = deleteNode(temp->right, temp2->val);
		}
		return temp;
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
		cout << "Press 6 to delete a node" << endl;
		cout << "Press 7 to end" << endl;
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
			int value;
			cout << "Enter value = ";
			cin >> value;
			b1.searcher(b1.root, value);
			if (searchChecker == false)
			{
				cout << "Value not found, Please try again" << endl;
				continue;
			}
			b1.deleteNode(b1.root,value);
			cout << endl;
			cout << "Value Deleted" << endl;
			system("pause");
		}
		else if (loopInput == 7)
		{
			loopCounter = false;
		}
		
	}
}

