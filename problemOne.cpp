#include <bits/stdc++.h>
using namespace std;
/* Q1	Implement the following Operations for a Doubly Linked List using the template code taught in Modules 17, 18, and 19. */

class DoublyNode
{
public:
    int value;
    DoublyNode *Prev;
    DoublyNode *Next;

    // Creating Constractor
    DoublyNode(int val)
    {
        value = val;
        Prev = NULL;
        Next = NULL;
    }
};

struct Test
{
    int arr[1000];
};

// Function Initialization
void display(DoublyNode *n);
int countLength(DoublyNode *&head);
void insertAtHead(DoublyNode *&head, int value);
void insertAtTail(DoublyNode *&head, int value);
void insertAtSpecificPosition(DoublyNode *&head, int position, int value);
int searchByValueUnique(DoublyNode *&head, int value);
Test searchByValueDuplicateReturn(DoublyNode *&head, int value);
void insertAfterSpecificValueUnique(DoublyNode *&head, int target, int value);
void insertionAfterSpecificValueDuplicate(DoublyNode *&head, int key, int newValue);
void deletionAtHead(DoublyNode *&head);
void deletionAtTail(DoublyNode *&head);
void deletionAtSpecificPosition(DoublyNode *&head, int pos);
void deletionByValueUnique(DoublyNode *&head, int target);
void deletionByValueDuplicate(DoublyNode *&head, int target);

// Function Making
void display(DoublyNode *n)
{
    while (n != NULL)
    {
        cout << n->value;
        if (n->Next != NULL)
            cout << " -> ";
        n = n->Next;
    }
    cout << endl
         << endl;
}

int countLength(DoublyNode *&head)
{
    int count = 0;
    DoublyNode *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->Next;
    }
    return count;
}

void insertAtHead(DoublyNode *&head, int value)
{
    DoublyNode *newNode = new DoublyNode(value);
    head->Prev = newNode;
    newNode->Next = head;
    head = newNode;
}

void insertAtTail(DoublyNode *&head, int value)
{
    DoublyNode *newNode = new DoublyNode(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    DoublyNode *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
    newNode->Prev = temp;
}

void insertAtSpecificPosition(DoublyNode *&head, int position, int value)
{
    int i = 0;
    DoublyNode *newNode = new DoublyNode(value);
    DoublyNode *temp = head;
    while (i < position - 2)
    {
        temp = temp->Next;
        i++;
    }
    DoublyNode *save = temp->Next;
    temp->Next = newNode;
    newNode->Prev = temp;
    if (save != NULL)
        newNode->Next = save;
}

int searchByValueUnique(DoublyNode *&head, int value)
{
    DoublyNode *temp = head;
    int count = 1;
    if (head == NULL)
    {
        return -1;
    }
    while (temp->value != value)
    {
        if (temp->Next == NULL)
        {
            return -1;
        }
        temp = temp->Next;
        count++;
    }
    return count;
}

Test searchByValueDuplicateReturn(DoublyNode *&head, int value)
{
    DoublyNode *temp = head;
    Test T;
    int k = 1;
    int count = 1;
    while (temp != NULL)
    {
        if (temp->value == value)
        {
            T.arr[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    T.arr[0] = k;
    return T;
}

void insertAfterSpecificValueUnique(DoublyNode *&head, int target, int value)
{
    int position = searchByValueUnique(head, target);

    insertAtSpecificPosition(head, position + 1, value);
}

void insertionAfterSpecificValueDuplicate(DoublyNode *&head, int key, int newValue)
{
    Test positions;
    positions = searchByValueDuplicateReturn(head, key);
    if (positions.arr[0] == 0)
    {
        cout << "List is Empty!" << endl;
        return;
    }
    int len = positions.arr[0];
    for (int i = 1; i < len; i++)
    {
        insertAtSpecificPosition(head, positions.arr[i] + 1, newValue);
        for (int j = i; j < len; j++)
        {
            positions.arr[j]++;
        }
    }
}

void deletionAtHead(DoublyNode *&head)
{
    DoublyNode *temp = head;
    if (temp != NULL)
    {
        head = temp->Next;
        delete temp;
    }
    else
    {
        cout << "There is no value in the liked list!" << endl;
    }
}

void deletionAtTail(DoublyNode *&head)
{
    DoublyNode *temp = head;
    if (temp != NULL && temp->Next != NULL)
    {
        while (temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }
        DoublyNode *delNode = temp->Next;
        temp->Next = NULL;
        delete delNode;
    }
    else
    {
        if (temp == NULL)
        {
            cout << "There is no value in the linked list!" << endl;
        }
        else
        {
            deletionAtHead(head);
        }
    }
}

void deletionAtSpecificPosition(DoublyNode *&head, int pos)
{
    if (pos <= countLength(head))
    {
        if (pos == 1)
        {
            deletionAtHead(head);
        }
        else if (pos == countLength(head))
        {
            deletionAtTail(head);
        }
        else
        {
            DoublyNode *temp = head;
            int i = 1;
            while (i < pos - 1)
            {
                temp = temp->Next;
                i++;
            }
            DoublyNode *delNode = temp->Next;
            temp->Next = delNode->Next;
            delete delNode;
        }
    }
    else
    {
        cout << "Position Out of Bound!" << endl;
    }
}

void deletionByValueUnique(DoublyNode *&head, int target)
{
    int position = searchByValueUnique(head, target);
    if (position == -1)
    {
        cout << "Value Not Found in the linked list" << endl;
    }
    else
    {
        deletionAtSpecificPosition(head, position);
    }
}

void deletionByValueDuplicate(DoublyNode *&head, int target)
{
    Test positions;
    positions = searchByValueDuplicateReturn(head, target);
    if (positions.arr[0] == 0)
    {
        cout << "Linked List is empty!" << endl;
        return;
    }
    int len = positions.arr[0];
    for (int i = 1; i < len; i++)
    {
        deletionAtSpecificPosition(head, positions.arr[i]);
        for (int j = i; j < len; j++)
        {
            positions.arr[j]--;
        }
    }
}

int main()
{
    DoublyNode *head = NULL;
    int value, choice, position;
    cout << "Choice 1: Counting the Size" << endl
         << "Choice 2: Display List" << endl
         << "Choice 3: Insertion at Head" << endl
         << "Choice 4: Insertion at Tail" << endl
         << "Choice 5: Insertion at Specific Position" << endl
         << "Choice 6: Search a Value (Unique List)" << endl
         << "Choice 7: Search a Value (Duplication enabled List)" << endl
         << "Choice 8: Insertion after a specific value(Unique List)" << endl
         << "Choice 9: Insertion after a specific value (Duplication enabled List)" << endl
         << "Choice 10: Deletion at Head" << endl
         << "Choice 11: Deletion at Tail" << endl
         << "Choice 12: Deletion at a Specific Position" << endl
         << "Choice 13: Deletion by Value (Unique List)" << endl
         << "Choice 14: Deletion by Value(Duplication Enabled List)" << endl
         << "Choice 0: Exit" << endl
         << endl;
    cout << "Next Choice: ";
    cin >> choice;
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:

            cout << "Length of the Doubly Linked list: " << countLength(head) << endl;
            break;

        case 2:

            cout << endl
                 << "Linked List: ";
            display(head);
            break;

        case 3:
            cout << "Enter the Value: ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 4:
            cout << "Enter the Value: ";
            cin >> value;
            insertAtTail(head, value);
            break;

        case 5:
            cout << "Enter the Desired Position: ";
            cin >> position;
            cout << "Enter the Value: ";
            cin >> value;
            insertAtSpecificPosition(head, position, value);
            break;

        case 6:
            cout << "Enter the value to search: ";
            cin >> value;
            position = searchByValueUnique(head, value);
            if (position != -1)
            {
                cout << "The number is at position " << position << endl;
            }
            else
            {
                cout << "The number is not yet the list" << endl;
            }
            break;

        case 7:
            cout << "Enter the value to search: ";
            cin >> value;
            Test T;
            T = searchByValueDuplicateReturn(head, value);
            if (T.arr[0] == 1)
            {
                cout << "The Searched Value is not yet in the list" << endl;
            }
            else
            {
                int size = T.arr[0];
                cout << "The value is at position: ";
                for (int i = 1; i < size; i++)
                {
                    cout << T.arr[i];
                    if (i < size - 1)
                        cout << ",";
                }
                cout << endl;
            }
            break;

        case 8:
            cout << "Enter the value to Search: ";
            int searchValue;
            cin >> searchValue;
            cout << "Enter the value to insert: ";
            cin >> value;
            insertAfterSpecificValueUnique(head, searchValue, value);
            break;

        case 9:
            cout << "Enter the Search Value (Duplication Enabled): ";
            cin >> value;
            int newValue;
            cout << "Enter the new Value (Duplication Enabled): ";
            cin >> newValue;
            insertionAfterSpecificValueDuplicate(head, value, newValue);
            break;

        case 10:
            deletionAtHead(head);
            break;

        case 11:

            deletionAtTail(head);
            break;

        case 12:
            cout << "Enter the desired position: ";
            cin >> position;
            deletionAtSpecificPosition(head, position);
            break;
        case 13:
            cout << "Enter the value to delete: ";
            int delValue;
            cin >> delValue;
            deletionByValueUnique(head, delValue);
            break;
        case 14:
            cout << "Enter the Value you want to delete: ";
            cin >> delValue;
            deletionByValueDuplicate(head, delValue);
            break;

        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }

    return 0;
}