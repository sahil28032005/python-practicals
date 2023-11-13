#include <iostream>
using namespace std;
class Node
{
public:
    string studentName;
    Node(string name)
    {
        this->studentName = name;
    }
} *head;

class SetOperations
{
public:
    void takeInput(int noOfstudents);
    void unionOfsets(Node *head1, Node *head2);
    void intersection(Node *head1, Node *head2);
    void differenceOfsets(Node *head1, Node *head2);
};

void SetOperations::takeInput(int NoOfstudents)
{
    string name;
   for(int i=0; i<NoOfstudents; i++){
      cout << "enter the name of student to add in database" << i+1 << endl;
      cin>>name;
      Node *student=new Node(name);
      if(i==0){head=student;}
      
      
   }
}

int main()
{
    head = NULL;
    cout << head;

    return 0;
}