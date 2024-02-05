#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *findCorrectPos(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    else if (data >= (root->data))
    {
        root->right = findCorrectPos(root->right, data); //
        cout << "inserted at right position" << endl;
    }
    else
    {
        root->left = findCorrectPos(root->left, data);
        cout << "inserted at left position" << endl;
    }
    return root;
}
void takeInput(int data, Node *root)
{
    while (data != -1)
    {
        root = findCorrectPos(root, data);
        cout << "insert data to insert in BST" << endl;
        cin >> data;
    }
}

int main()
{
    Node *n = NULL;
    int choise = 0;
    while (true)
    {
        cout << "1)cretae binary search tree...\n2)insert data into BST...\n3)Display Binary search tree...\n4)Exit"
             << endl;
        cin >> choise;
        switch (choise)
        {
        case 1:
            cout << "enter data to insert into BST" << endl;
            int data;
            cin >> data;
            takeInput(data, n);
            break;

        case 4:
            break;
        default:
            cout << "h";
        }
    }

    return 0;
}