#include<iostream>
#include<vector>
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
            this->left = nullptr;
            this->right = nullptr;
        }
};

void traverseLeft(Node* root, vector<int> &ans)
{
    if((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    ans.push_back(root->data);

    if(root->left != NULL)
        traverseLeft(root->left,ans);
    
    else
        traverseLeft(root->right,ans);
}

void traverseLeaf(Node* root, vector<int> &ans)
{
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL)
    {
         ans.push_back(root->data);
         return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node* root, vector<int> &ans)
{
    if((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    if(root->right != NULL)
        traverseRight(root->right, ans);

    else
        traverseRight(root->left, ans);

    ans.push_back(root->data);
}

vector<int> BoundaryTraversal(Node* root)
{
    vector <int> ans;

    if(root == NULL)
        return ans;

    ans.push_back(root->data);

    // Print left part excluding leaf node
    traverseLeft(root->left, ans);

    // Print all leaf roots
    traverseLeaf(root->left, ans);  // from left subtree

    traverseLeaf(root->right, ans);  // from right subtree
    
    // Print right part in reverse order exclusing leaf node
    traverseRight(root->right, ans);

    return ans;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->right->left->left = new Node(10);
    root->right->left->right = new Node(11);

    // Calling the BoundaryTraversal function
    vector<int> result = BoundaryTraversal(root);

    // Displaying the result
    cout << "Boundary Traversal of the binary tree:" << endl;
    for(int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}