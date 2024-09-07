#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* right;
        Node* left;

        Node(int data)
        {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

int FindHeight(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int left = FindHeight(root->left);
    int right = FindHeight(root->right);

    return (max(left,right) + 1);

}

int main()
{   // Creating a simple binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Finding the height of the binary tree
    int height = FindHeight(root);
    cout << "Height of the binary tree is: " << height << endl;


    return 0;
}

// Time Complexity: O(N)
// Auxiliary Space: O(N)