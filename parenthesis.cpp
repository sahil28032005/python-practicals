#include <iostream>
using namespace std;
template <class t>
class Stack
{
public:
    int size, top;
    t *arr;
    Stack(int size)
    {
        top = -1;
        this->size = size;
    }
};
class StackOperations
{
public:
    Stack<char> *s;
    void createStack(int size);
    void pushIntoStack(char element);
    void popFromStack();
    bool isEmpty();
    bool isFull();
    void viaSualizeStack();
    bool isWellParenthesized(string expression);
};
void StackOperations::createStack(int size)
{
    s = new Stack<char>(size);
    // cout << s->size;
    s->arr = new char[s->size]; // i thin this will allocate dynamic mempory another approach using malloc
}
bool StackOperations::isEmpty()
{
    return s->top == -1 ? true : false;
}
bool StackOperations::isFull()
{
    return s->top == s->size - 1 ? true : false;
}
void StackOperations::pushIntoStack(char element)
{
    if (isFull())
    {
        cout << "stack overflow!" << endl;
        return;
    }
    s->top++;
    s->arr[s->top] = element;
}
void StackOperations::viaSualizeStack()
{
    for (int i = 0; i <= s->top; i++)
    {
        cout << "|" << s->arr[i] << "|" << endl;
    }
}
void StackOperations::popFromStack()
{
    if (isEmpty())
    {
        cout << "stack underFlow!" << endl;
        return;
    }
    s->top--;
}
bool ::StackOperations::isWellParenthesized(string exp)
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            pushIntoStack(exp[i]);
        }
        else if (((s->top) >= 0) && (s->arr[s->top] == '(' && exp[i] == ')' || s->arr[s->top] == '[' && exp[i] == ']' || s->arr[s->top] == '{' && exp[i] == '}'))
        {
            //    cout<<"fould closing"<<endl;
            if (isEmpty())
            {
            }
            else
            {
                popFromStack();
            }
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            pushIntoStack(exp[i]);
        }
    }
    if (isEmpty())
    {
        cout << "tuze expression well parenthesized ahe..." << endl;
    }
    else
    {
        cout << "tuze expression well parenthesized nahi" << endl;
    }
}

int main()
{
    StackOperations stp;
    stp.createStack(12);
    // stp.pushIntoStack('c');
    // stp.pushIntoStack('d');
    // stp.pushIntoStack('g');
    stp.isWellParenthesized("");
    stp.viaSualizeStack();

    return 0;
}