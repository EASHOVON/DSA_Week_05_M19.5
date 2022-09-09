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

int cnt = 0;
Node *reverseRecursive(Node *head, int position)
{
    cnt++;
    if (cnt == position)
    {
        return head;
    }
    Node *newHead = reverseRecursive(head->next, position);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main()
{
    int n, q;
    cin >> n >> q;
    Node *head = NULL;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        insertionAtTail(head, value);
    }

    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        head = reverseRecursive(head, x);
        displayList(head);
        cout << endl;
    }

    return 0;
}
