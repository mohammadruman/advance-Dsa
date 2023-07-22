#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node *buildTree()
{
    int data;
    cout << "Enter the data " << endl;

    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    Node *newNode = new Node(data);
    cout << "Enter the data for left child" << endl;

    newNode->left = buildTree();
    cout << "Enter the data for right child" << endl;
    newNode->right = buildTree();
    return newNode;
}

void PreOrder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data;
    PreOrder(root->left);
    PreOrder(root->right);
}
void inOrder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            cout << front->data << " ";

            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)

                q.push(front->right);
        }
    }
}
int heightTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->right == NULL && root->left == NULL)
    {
        return 0;
    }
    int leftans = heightTree(root->left);
    int rightans = heightTree(root->right);
    return 1 + max(leftans, rightans);
}
int main()
{

    Node *root = NULL;
    root = buildTree();
    levelOrder(root);

    return 0;
}