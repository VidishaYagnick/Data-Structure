/*
Sum Tree : 
A Sum Tree is a special type of binary tree where the value of each node is equal to the sum of the values of its left and right subtrees. A leaf node is considered a Sum Tree by default.
*/

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
            this->right = NULL;
            this->left = NULL;
        }
};

pair <bool, int> isSumTree(Node* root)
{
    if(root == NULL)
        return {true,0};

    if(root->left == NULL && root->right == NULL) // leaf node
        return {true,root->data};

    pair <bool, int> left = isSumTree(root->left);
    pair <bool, int> right = isSumTree(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool condition = (root->data == left.second + right.second);

    pair <bool, int> ans;
    if ((leftAns && rightAns && condition) == true)
    {
        ans.first = true;
        ans.second = 2 * root->data; // same as root->data + left.second + right.second
    }

    else
        ans.first = false;    

    return ans;
}

int main()
{
    // Creating a sample binary tree
    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    // Check if the tree is a Sum Tree
    pair<bool, int> result = isSumTree(root);
    if(result.first)
        cout << "The tree is a Sum Tree." << endl;
    else
        cout << "The tree is not a Sum Tree." << endl;

    return 0;
}