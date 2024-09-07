#include<iostream>
#include<map>
#include<queue>
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

vector <int> bottomView(Node *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    map<int, int> map;
    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        map[hd] = frontNode->data;

        if (frontNode->left != NULL)
            q.push(make_pair(frontNode->left, hd - 1));

        if (frontNode->right != NULL)
            q.push(make_pair(frontNode->right, hd + 1));
    }
    for (auto i : map)
        ans.push_back(i.second);

    return ans;
}

int main()
{
    // Constructing the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    /*
        The binary tree looks like this:
                1
              /   \
             2     3
            / \   / \
           4   5 6   7
    */

    // Testing the bottomView function
    vector<int> result = bottomView(root);

    // Printing the bottom view
    cout << "Bottom View of Binary Tree: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
