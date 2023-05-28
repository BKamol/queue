#include <fstream>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

struct Queue
{
    int size;
    Node* first;
    Node* last;
};

bool isEmpty(Queue* Q)
{
    return Q->first == Q->last;
}

Queue* create_queue()
{
    Queue* Q = new Queue;
    Q->first = new Node;
    Q->first->next = NULL;
    Q->last = Q->first;
    Q->size = 0;
    return Q;
}

void add(Queue* Q, int elem)
{
    Q->last->next = new Node;
    Q->last = Q->last->next;
    Q->last->data = elem;
    Q->last->next = NULL;
    Q->size++;
    cout << "\nElement is added to queue. \n";
}

int pop(Queue* Q)
{
    Node* q = Q->first;
    int data = q->next->data;
    Q->first = Q->first->next;
    delete q;
    Q->size--;
    return data;
}

int peek(Queue* Q)
{
    return Q->first->next->data;
}

int size(Queue* Q)
{
    return Q->size;
}

void tests(Queue* &Q)
{
    char number;
    int value;
    do
    {
        cout << "1. Add element" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Print first element" << endl;
        cout << "4. Print length of queue" << endl;
        cout << "0. Exit" << endl;
        cout << "Number > ";
        cin >> number;
        cout << endl;
        switch (number)
        {
        case '1':
            cout << "Input value: " << endl;
            cin >> value;
            add(Q, value);
            break;

        case '2':
            if (isEmpty(Q)) cout << "Empty queue\n";
            else
            {
                value = pop(Q);
                cout << endl << "Element " << value << " deleted.\n\n";
            }
            break;

        case '3':
            if (isEmpty(Q)) cout << "Empty queue\n";
            else
            {
                cout << "First elemen: " << peek(Q) << endl;
            }
            break;

        case '4':
            if (isEmpty(Q)) cout << "Empty queue\n";
            else
            {
                cout << "Queue size: " << size(Q) << endl << endl;
            }
            break;

        case '0': break;

        default:
            cout << "Wrong command\n\n";
            break;
        }
    } while (number != '0');
}

int main()
{
    Queue* Q = create_queue();
    
}


