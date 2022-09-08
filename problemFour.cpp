#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

// Insert Node at Tail
void insertionAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print Linked List
void displayList(Node *head)
{
    if (head == NULL)
    {
        cout << "The Linked List is Empty!" << endl;
        return;
    }
    while (head != NULL)
    {
        cout << head->value;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
}

int findMid(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty!" << endl;
        return -1;
    }

    Node *temp1 = head;
    Node *temp2 = head;
    while (temp2 != NULL && temp2->next != NULL)
    {
        temp1 = temp1->next;
        temp2 = temp2->next->next;
    }

    return temp1->value;
}

int main()
{
    Node *head = NULL;

    for (int i = 1; i <= 5; i++)
    {
        insertionAtTail(head, i);
    }

    displayList(head);
    cout << endl;

    int mid = findMid(head);
    cout << "Middle position = " << mid << endl;

    return 0;
}
