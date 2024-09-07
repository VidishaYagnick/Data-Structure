/*
A balanced binary tree is a type of binary tree where the height (or depth) of the left and right subtrees of every node differs by at most one.
| height(left_subtree(n)) - height(right_subtree(n)) | <= 1
*/

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

int height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return (max(left,right) + 1);
}

bool isBalanced(Node* root)
{
    if(root == NULL)
        return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = (abs(height(root->left) - height(root->right)) <= 1);

    if(left && right && diff)
        return true;

    else
        return false;
}

pair <bool, int> fastIsBalanced(Node* root)
{
    if(root == NULL)
    {
        pair <bool,int> p = make_pair(true,0);
        return p;
    }

        pair <bool,int> left = fastIsBalanced(root->left);
        pair <bool,int> right = fastIsBalanced(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        bool diff = (abs(left.second - right.second) <= 1);

        pair <bool,int> ans;
        ans.second = max(left.second, right.second) + 1;

        if((leftAns && rightAns && diff) == true)
            ans.first = true;

        else
            ans.first = false;

        return ans;
}

int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);
    root->right = new Node(5);

    // Check if the tree is balanced using the basic approach
    if(isBalanced(root))
        cout << "The tree is balanced (basic method)." << endl;
    else
        cout << "The tree is not balanced (basic method)." << endl;

    // Check if the tree is balanced using the optimized approach
    pair<bool, int> result = fastIsBalanced(root);
    if(result.first)
        cout << "The tree is balanced (optimized method)." << endl;
    else
        cout << "The tree is not balanced (optimized method)." << endl;

  return 0;
}
