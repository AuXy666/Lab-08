#include<iostream>
using namespace std;
int i1;
class binarytree
{
    public:
    int tree[100];
    
    binarytree()
    {
        i1 = -1;
        for (int i = 0; i < 100; i++)
        {
            tree[i] = 1;
        }
    }

int insert(int temp1, int val)    
{
    i1++;

    if (tree[temp1] == 1)        
    {
        tree[temp1]=val;
        return 1;
    }

    if (val < tree[temp1])               
    {
        tree[(2 *i1)+1] = insert((2 * i1) + 1, val);
    }
    else if (val > tree[temp1]) 
    {
        tree[(2 * i1) + 2] = insert((2 * i1) + 2, val);
    }

    return 1;
}


    int root(int val)
    {
        tree[0] = val;
        return 0;
    }



    int postOrder()
    {
        cout << endl;
        for (int i = 0; i < 100; i++)
         {  
            if (tree[i] != 1)
            {
             cout << tree[i] << " ";
            }
        }
        return 0;
    }

};
int main()
{
    int counter = 0;
    binarytree b1;
    b1.root(5);
    i1 = -1;
    b1.insert(0, 2);
    i1 = -1;
    b1.insert(0, 10);
    i1 = -1;
    b1.insert(0, 9);
    i1 = -1;
    b1.insert(0, 12);
    i1 = -1;
    cout << "Post Order Traversal";
    b1.postOrder();
    cout << endl;
    return 0;
}

