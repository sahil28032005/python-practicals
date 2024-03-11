#include <iostream>
using namespace std;
#include <queue>
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    bool isRight;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->isRight = false;
    }
};
Node *createTbt(Node *root, int data)
{
    // case where root of tree made
    if (data == -1)
    {
        return root;
    }
    Node *prev = root;
    if (prev == NULL)
    {
        Node *n = new Node(data);
        return n; // returned root of tree
    }

    while (prev != NULL)
    {

        if (data < prev->data)
        {
            if (prev->left == NULL)
            {
                Node *n = new Node(data);
                prev->left = n;
                if (prev->left->isRight == false)
                {
                    prev->left->right = prev;
                    prev->left->isRight = true;
                    break;
                }
            }
            else
            {
                prev = prev->left;
            }
        }
        else
        {
            if (prev->right == NULL || prev->isRight)
            {
                Node *n = new Node(data);
                if (prev->isRight)
                {

                }
                prev->right = n;
                prev->isRight = false;
                cout << "added at right" << endl;
                break;
            }
            else
            {
                prev = prev->right;
            }
        }
    }
    return root;
}
Node *levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {

        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << temp->isRight;
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right && temp->isRight == false)
            {
                q.push(temp->right);
            }
        }
    }
}
Node *deleteFromTbt(Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        // case where deleting simple leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root; // memory of that node gets freed and avaliable for reallocation
            return NULL;
        }
        // case where i am deleting node having right inorder predessor value
        if (root->left == NULL && root->isRight)
        {
        }
    }
    else
    {
        if (data > root->data)
        {
            root->right = deleteFromTbt(root->right, data);
        }
        else
        {
            root->left = deleteFromTbt(root->left, data);
        }
    }
}
int main()
{
    Node *first = nullptr;
    int opt;

    while (true)
    {
        cout << "enter your choise" << endl;
        cout << "1)insert into TBT" << endl;
        cout << "2)perform inorder traversal" << endl;
        cin >> opt;
        switch (opt)
        {
        case /* constant-expression */ 1:
            /* code */
            cout << "enter data to insert" << endl;
            int data;
            cin >> data;
            first = createTbt(first, data);
            cout << "added data" << endl;
            break;
        case 2:
            levelOrderTraversal(first);
            break;
        default:
            break;
        }
    }

    return 0;
}
//another way to pass dynamic root and actual root to handle some cases where getting right end child problemm