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
class linklist
{ 
	public:
	node* head;
	linklist()
	{
		head = NULL;
	}
	void add(int x)
	{
		node* temp = new node;

		temp->val = x;


		temp->right = head;
		temp->left = NULL;

		if (head != NULL)
			head->left = temp;
		head = temp;

	}
	int middleElementOutput()
	{
		node* temp = head;
		node* TwoStepsTemp = head;
		if (temp != NULL)
		{

			while (TwoStepsTemp->right != NULL && TwoStepsTemp->right->right != NULL)
			{
				TwoStepsTemp = TwoStepsTemp->right->right;
				temp = temp->right;

			}

		}
		return temp->val;
	}
	node* middleNodeReturn()
	{
		node* temp = head;
		node* TwoStepsTemp = head;
		if (head != NULL)
		{

			while (TwoStepsTemp->right != NULL && TwoStepsTemp->right->right != NULL)
			{
				TwoStepsTemp = TwoStepsTemp->right->right;
				temp = temp->right;

			}

		}
		return temp;
	}
	void sortList()
	{
		node* temp = new node;
		temp = head;
		node* temp2 = new node;
		temp2 = NULL;

		if (head == NULL)
		{
			cout << "Underflow occured" << endl;
			return;
		}
		else {
			while (temp != NULL)
			{
				temp2 = temp->right;

				while (temp2 != NULL)
				{
					if (temp->val > temp2->val)
					{
						swap(temp->val, temp2->val);
					}
					temp2 = temp2->right;
				}
				temp = temp->right;
			}
		}

	}


	void display()
	{
		node* temp = new node;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->val << endl;
			temp = temp->right;
		}
	}
};
linklist l1;

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
	
	void add_toList(node* temp)
	{
		if (temp == NULL)
		{
			return;
		}

		add_toList(temp->left);
		l1.add(temp->val);
		add_toList(temp->right);

	}

};


int main()
{
	binarySearch_Tree b1;
	binarySearch_Tree b2;
	binarySearch_Tree b3;
	bool loopCounter = true;
	int loopInput;
	int input;
	while (loopCounter)
	{
		cout << "Press 1 to enter Root of Binary Search Tree" << endl;
		cout << "Press 2 to insert into Binary Search tree" << endl;
		cout << "Press 3 to enter Root of second Binary tree" << endl;
		cout << "Press 4 to insert into second Binary tree" << endl;
		cout << "Press 5 to inorder traversal" << endl;
		cout << "Press 6 to Preorder traversal" << endl;
		cout << "Press 7 to Postorder traversal" << endl;
		cout << "Press 8 to merge the trees" << endl;
		cout << "Press 9 to print merged Tree" << endl;
		cout << "Press 10 to end" << endl;
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
			b2.rootInsert(input);
			cout << endl;
		}
		else if (loopInput == 4)
		{
			cout << "Enter Value = ";
			cin >> input;
			b2.insert(b2.root, input);
			cout << endl;
		}
		else if (loopInput == 5)
		{
			int orderInput;
			cout << "Press 1 to print inorder of tree 1" << endl;
			cout << "Press 2 to print inorder of tree 2" << endl;
			cout << "Press 3 to print inorder of tree 3" << endl;
			cin >> orderInput;
			if (orderInput == 1)
			{
				b1.inorder(b1.root);
				cout << endl;
			}
			if (orderInput == 2)
			{
				b2.inorder(b2.root);
				cout << endl;
			}
			if (orderInput == 3)
			{
				b3.inorder(b3.root);
				cout << endl;
			}
			
		}
		else if (loopInput == 6)
		{
			int orderInput;
			cout << "Press 1 to print preorder of tree 1" << endl;
			cout << "Press 2 to print preorder of tree 2" << endl;
			cout << "Press 3 to print preorder of tree 3" << endl;
			cin >> orderInput;
			if (orderInput == 1)
			{
				b1.preorder(b1.root);
				cout << endl;
			}
			if (orderInput == 2)
			{
				b2.preorder(b2.root);
				cout << endl;
			}
			if (orderInput == 3)
			{
				b3.preorder(b3.root);
				cout << endl;
			}
		}
		else if (loopInput == 7)
		{
			int orderInput;
			cout << "Press 1 to print postorder of tree 1" << endl;
			cout << "Press 2 to print postorder of tree 2" << endl;
			cout << "Press 3 to print postorder of tree 3" << endl;
			cin >> orderInput;
			if (orderInput == 1)
			{
				b1.postorder(b1.root);
				cout << endl;
			}
			if (orderInput == 2)
			{
				b2.postorder(b2.root);
				cout << endl;
			}
			if (orderInput == 3)
			{
				b3.postorder(b3.root);
				cout << endl;
			}
		}
		else if (loopInput == 8)
		{
			b1.add_toList(b1.root);
			b2.add_toList(b2.root);
			l1.sortList();
			l1.display();
			cout << endl;
			int mid;
			mid = l1.middleElementOutput();
			cout << "Middle = " << mid << endl;
			b3.rootInsert(l1.middleElementOutput());
			node* temp = l1.middleNodeReturn();
			temp = temp->left;
			while (temp != NULL)
			{
				b3.insert(b3.root, temp->val);
				temp = temp->left;
			}
			cout << endl;
			node* temp2 = l1.middleNodeReturn();
			temp2 = temp2->right;
			while (temp2 != NULL)
			{
				b3.insert(b3.root, temp2->val);
				temp2 = temp2->right;
			}
		}
		else if (loopInput == 9)
		{
		int orderInput;
		cout << "Press 1 to print inorder of tree " << endl;
		cout << "Press 2 to print preorder of tree " << endl;
		cout << "Press 3 to print postorder of tree " << endl;
		cin >> orderInput;
		if (orderInput == 1)
		{
			b3.inorder(b3.root);
			cout << endl;
		}
		if (orderInput == 2)
		{
			b3.preorder(b3.root);
			cout << endl;
		}
		if (orderInput == 3)
		{
			b3.postorder(b3.root);
			cout << endl;
		}
		}
		else if (loopInput == 10)
		{
			loopCounter=false;
		}
		
	}
}
