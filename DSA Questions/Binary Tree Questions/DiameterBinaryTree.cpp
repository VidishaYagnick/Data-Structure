/*
Diameter of a Binary Tree : The diameter/width of a tree is defined as the number of nodes on the longest path between any two nodes.
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

int diameter(Node* root) // Complexity : O(n2)
{
    if(root == NULL)
        return 0;

    int opt1 = diameter(root->left);
    int opt2 = diameter(root->right);
    int opt3 = height(root->left) + height(root->right) + 1;

    int ans = max(opt1, max(opt2,opt3));
    return ans;
}

pair <int,int> fastDiameter(Node* root)
{
    if(root == NULL)
    {
        pair<int, int> p = make_pair(0,0);
        return p;
    }

    pair <int,int> left = fastDiameter(root->left);
    pair <int,int> right = fastDiameter(root->right);

    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(opt1,max(opt2,opt3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int main()
{
    // Creating a simple binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);

    // Calculate diameter using the O(n^2) approach
    int treeDiameter = diameter(root);
    cout << "Diameter of the tree (O(n^2) approach): " << treeDiameter << endl;

    // Calculate diameter using the optimized O(n) approach
    pair<int, int> result = fastDiameter(root);
    cout << "Diameter of the tree (O(n) approach): " << result.first << endl;

    return 0;
}