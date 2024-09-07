#include<iostream>
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

vector <vector<int>> ZigZag(Node* root)
{
    vector <vector<int>> ans;

    if(root == NULL)
        return ans;

    queue <Node*> q;
    q.push(root);
    bool LeftToRight = true;

    while(!q.empty())
    {
        int size = q.size();
        vector<int> level(size);
        for(int i = 0; i<size; i++)
        {
            Node* temp = q.front();
            q.pop();

            int index = (LeftToRight) ? i : size - i - 1;
            level[index] = temp->data;

            if(temp->left != NULL)
                q.push(temp->left);

            if(temp->right != NULL)
                q.push(temp->right);
            
        }
        ans.push_back(level);
        LeftToRight = !LeftToRight;
    }
    return ans;
}

int main()
{
    // Constructing the binary tree:
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Calling the ZigZag function
    vector<vector<int>> result = ZigZag(root);

    // Displaying the result
    cout << "Zigzag Level Order Traversal:" << endl;
    for(const auto& level : result)
    {
        for(int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}