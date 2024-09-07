#include<iostream>
#include<vector>
#include<queue>
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
            this->right = nullptr;
            this->left = nullptr;
        }
};

vector <vector<int>> levelOrder(Node* root) //takeUforward
{
    vector<vector<int>> ans;

    if(root == NULL)
        return ans;

    queue <Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        vector<int> level;

        for(int i = 0; i < size; i++)
        {
            Node* temp = q.front();
            q.pop();

            if(temp->left != NULL)
                q.push(temp->left);
            
            if(temp->right != NULL)
                q.push(temp->right);

            level.push_back(temp->data);
        }
        ans.push_back(level);
    }

    return ans;
}

void levelOrder_queue(Node* root)
{
    if(root == NULL)
        return;

    queue <Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty())
    {
        Node* temp = Q.front();
        Q.pop();

        if(temp == NULL)
        {
            cout << endl;
            if(!Q.empty())
                Q.push(NULL);
        }

        else
        {
            cout << temp->data << " ";

            if(temp->left != NULL)
                Q.push(temp->left);

            if(temp->right != NULL)
                Q.push(temp->right);
        }
    }
}


int main()
{   
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Perform level order traversal
    vector<vector<int>> result = levelOrder(root);

    cout << "Level order traversal using vector-based method:" << endl;
    // Print the result
    for (const auto& level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    // Perform level order traversal using queue-based method
    cout << "Level order traversal using queue-based method:" << endl;
    levelOrder_queue(root);
    
    return 0;

}
