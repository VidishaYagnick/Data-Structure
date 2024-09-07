#include<iostream>
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
            this->left = nullptr;
            this->right = nullptr;
        }
};

void LevelOrderTraversal(Node* root)
{
    queue<Node*> q; 
    q.push(root);
    q.push(NULL);

    while(q.empty() == false)
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout << endl;
            if(q.empty() == false)
                q.push(NULL);
        }

        else
        {
            cout << temp->data << " ";

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }
    }
}

void InOrderTraversal(Node* root)
{
    // base case
    if(root == NULL)
        return;

    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

void PreOrderTraversal(Node* root)
{
    if(root == NULL)
        return;

    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal(Node* root)
{
    if(root == NULL)
        return;

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}

Node* Construct(Node* root)
{
    int data;
    cout << "Enter the data " << endl;
    cin >> data;

    root = new Node(data);

    if(data == -1)
        return NULL;

    cout << "Enter the data to insert in left of " << data << endl;
    root->left = Construct(root->left);

    cout << "Enter the data to insert in right of " << data << endl;
    root->right = Construct(root->right);

    return root;
}

int main()
{
    Node* root = nullptr;
    root = Construct(root); // creating a binary tree  
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "Level Order Traversal " << endl;
    LevelOrderTraversal(root);

    cout << "In Order Traversal " << endl;
    InOrderTraversal(root);
    cout << endl;

    cout << "Pre Order Traversal " << endl;
    PreOrderTraversal(root);
    cout << endl;

    cout << "Post Order Traversal " << endl;
    PostOrderTraversal(root);
    cout << endl;

    return 0;
}