#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

bool isIdentical(Node* root1, Node* root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;

    if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
        return false;

    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);

    bool val = (root1->data == root2->data);

    if((left && right && val) == true)
        return true;

    else
        return false;  
}

int main()
{
    // Creating first sample binary tree
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
     root1->left->right->left = new Node(6);


    // Creating second sample binary tree
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    // Check if the two trees are identical
    if(isIdentical(root1, root2))
        cout << "The trees are identical." << endl;
    else
        cout << "The trees are not identical." << endl;   

    return 0;
}