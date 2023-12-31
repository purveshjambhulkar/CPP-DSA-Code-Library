#include <iostream>
using namespace std;

// This is code to reverse a linked list

class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void InsertionAtTail(int data, Node *&tail)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

// This function reverses the linked list and return the head of the reversed linked list
Node *ReveseLinkedList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    cout << "Head of the reversed Linked list is : " << prev->data << endl;
    return prev;
}

// Recursive attempt
Node *ReveseLinkedList(Node *prev, Node *curr, Node *forward)
{

    // base case
    if (curr == NULL)
    {
        cout << "Rev Head : " << prev->data << endl;
        return prev;
    }

    // Processing
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;

    // Recursive Call
    ReveseLinkedList(prev, curr, forward);
}

void print(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    InsertionAtTail(20, tail);
    InsertionAtTail(30, tail);
    InsertionAtTail(40, tail);
    InsertionAtTail(50, tail);
    print(head);

    cout << "Reversing by Iteration (Loops)\n";
    head = ReveseLinkedList(head);
    print(head);

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    cout << "Reversing by Recursion\n";
    Node *NewNode = ReveseLinkedList(prev, curr, forward);
    print(NewNode);
}