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

vector<int> verticalOrder(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();

        Node *frontNode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;
        q.pop();

        nodes[hd][level].push_back(frontNode->data);

        if (frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left, make_pair(hd - 1, level + 1)));
        }

        if (frontNode->right != NULL)
        {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, level + 1)));
        }
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main()
{ 
    // Constructing the binary tree
    Node *root = new Node(1);
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

    // Testing the verticalOrder function
    vector<int> result = verticalOrder(root);

    // Printing the vertical order traversal
    cout << "Vertical Order Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}