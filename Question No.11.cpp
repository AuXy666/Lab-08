#include<iostream>
using namespace std;

class node
{
public:

    int val;
    struct node* left;
    struct node* right;
    node()
    {
        val = 0;
        left = NULL;
        right = NULL;
    }
    node* create(int data)
    {
        struct node* temp = new node;
        temp->val = data;
        temp->left = temp->right = NULL;
        return temp;
    }
};


class monks_binaryTree
{
public:
    node* root;
    monks_binaryTree()
    {
        root = NULL;
    }
    void rootInsert(int x)
    {
        root = new node;
        root->val = x;
        root->left = NULL;
        root->right = NULL;

    }
    void insert(node* temp, int data)
    {

        if (data > temp->val)
        {
            if (temp->right == NULL)
            {
                temp->right = new node;
                temp->right->val = data;
            }
            else
                insert(temp->right, data);
        }
        else
        {
            if (temp->left == NULL)
            {
                temp->left = new node;
                temp->left->val = data;
            }

            else
                insert(temp->left, data);
        }
    }

    int height(node* temp, int count)
    {
        if (temp != NULL)
        {
            count++;
            int h1 = height(temp->left, count);
            int h2 = height(temp->right, count);
            if (h2 > h1)
            {
               return h2;
            }
            return h1;
        }
        return count;
    }
};



int main()
{
    monks_binaryTree mb1;
    int noOfElements;
    int element;
    cout << "Enter Number of array Elements = ";
    cin >> noOfElements;
    cout << "Enter Element = ";               //first element will be the root
    cin >> element;
    mb1.rootInsert(element);
    for (int i = 1; i < noOfElements; i++)    // as 1 node is already set as root
    {
        cout << "Enter Element = ";
        cin >> element;
        mb1.insert(mb1.root, element);
    }
    cout << endl;
    cout <<"Height = "<< mb1.height(mb1.root, 0) << endl;

}

