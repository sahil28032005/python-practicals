#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
Node *createFirstNode(int data, Node *head)
{
    Node *node = new Node(data);
    head = node;
    return head;
}
Node *insertAtTail(Node *head, int data)
{
    Node *node = new Node(data);
    if (head == NULL)
    {
        return createFirstNode(data, node);
    }
    else
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
        //  cout<<head->data<< endl;
        head->next = node;
    }
}
void traverseList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node *insertAtBeginning(Node *head, int data)
{
    Node *node = new Node(data);
    if (head == NULL)
    {
        return createFirstNode(data, node);
    }
    else
    {
        node->next = head;
        head = node;
    }
    return head;
}
int findLength(struct Node *head)
{
    int counter = 0;
    while (head != NULL)
    {
        counter++;
        head = head->next;
    }
    return counter;
}
Node *insertAtIndex(int index, int data, Node *head)
{
    Node *node = new Node(data);
    if (index == 0)
    {
        return insertAtBeginning(head, data);
    }
    else if (index == findLength(head))
    {
        cout << "insert via use of insertAtLast function" << endl;
        insertAtTail(head, data);
    }
    else
    {
        int counter = 0;
        while (counter < index - 1)
        {
            head = head->next;
            counter++;
        }
        node->next = head->next;
        head->next = node;
    }
}
void searchNode(Node *head, int key)
{
    while (head->next != NULL)
    {
        if (head->data == key)
        {
            cout << "your entered number is found in linked list" << endl;
            return;
        }
        head = head->next;
    }
    cout << "Your entered number is not found in linked list" << endl;
}
void sortLinkedList(Node *head)
{
    for (int i = 0; i < findLength(head); i++)
    {
        // cout << "outer";
        for (Node *i = head; i->next != NULL; i = i->next)
        {
            // cout << "inner";
            if (i->data > i->next->data)
            {
                int temp = i->data;
                i->data = i->next->data;
                i->next->data = temp;
            }
        }
    }
}
int main()
{
    Node *head = NULL;
    head = insertAtTail(head, 12); // 56 12 17
    traverseList(head);
    head = insertAtTail(head, 17);
    traverseList(head);
    head = insertAtBeginning(head, 56);
    insertAtIndex(3, 455, head); // 56 12 17 455
    insertAtIndex(2, 43, head);  // 56 12 43 17 455
    insertAtIndex(1, 495, head); // 56 495 12 43 17 455
    cout << "before sortings..." << endl;
    traverseList(head);
    cout << "after sortings..." << endl;
    sortLinkedList(head);
    traverseList(head);
    // searchNode(head, 495);

    return 0;
}