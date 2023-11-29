#include <iostream>
using namespace std;
class queue
{
public:
    int size;
    int front, rear;
    string *arr=new string[size];
    queue(int size)
    {
        // cout<<"size: "<<size<<endl;
        this->front = -1;
        this->rear = -1;

        this->size = size;
    }
};
class queueOperations
{
public:
    queue *q = new queue(10);
    void addJob(string job);
    void visualizeJobQueue();
    bool isFull();
    bool isEmpty();
    void dequeue();
};
void queueOperations::dequeue(){
  if(q->front==-1)
}
void queueOperations::addJob(string job)
{
    if (isFull())
    {
        cout << "queue full delete some jobs" << endl;
    }
    else if (q->front == -1 && q->rear == -1)
    {
        q->front++;
        q->arr[q->rear + 1] = job;
        q->rear++;
        cout << "job added" << endl;
    }
    else
    {
        q->arr[q->rear + 1] = job;
        q->rear++;
        cout << "job added" << endl;
    }
}
void queueOperations::visualizeJobQueue()
{
    for (int i = 0; i < q->size; i++)
    {
        cout << "|" << q->arr[i] << "|"
             << " ";
    }
}
bool queueOperations::isFull()
{
    return q->rear == q->size - 1 && q->front == 0 ? true : false;
}
bool queueOperations::isEmpty()
{
    return q->front == -1 && q->rear == -1 ? true : false;
}
int main()
{
    queueOperations qop;
    qop.addJob("print document");
    qop.addJob("request drivers");
    qop.addJob("request drivers");
    qop.addJob("request drivers");
    qop.addJob("request drivers");
    qop.addJob("request drivers");
    qop.addJob("request drivers");
    qop.addJob("request drivers");
    qop.addJob("request drivers");
    qop.addJob("request drivers");
    qop.addJob("request drivers");
    // qop.addJob("request drivers");
    qop.visualizeJobQueue();
    return 0;
}