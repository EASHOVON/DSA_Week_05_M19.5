#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    // কনস্ট্রাক্টর বানালাম
    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};

// ডিসপ্লে ফাংশন তৈরি। Making Display Function
void display(Node *n)
{
    if (n == NULL)
    {
        cout << "The Linked List is Empty" << endl;
        return;
    }

    while (n != NULL)
    {
        cout << n->value;
        if (n->Next != NULL)
            cout << " --> ";
        n = n->Next;
    }
    cout << endl
         << endl;
}

// ইনসার্ট এট টেইল ফাংশন তৈরি insertAtTail Function Makiong
void insertAtTail(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }

    temp->Next = newNode;
}

int main()
{
    int n;
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        insertAtTail(head, value);
    }

    return 0;
}