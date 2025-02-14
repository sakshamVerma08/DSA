#include <iostream>

using namespace std;

// Define the Node structure
struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to convert an array to a linked list
Node *arrayToLinkedList(const int arr[], int size)
{
    if (size == 0)
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *current = head;

    for (int i = 1; i < size; ++i)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

// Function to print the linked list
void printLinkedList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// The function below uses 'Data Replacement' which is Brute Force method .
Node *segregate(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    Node *temp = head;

    while (temp != nullptr)
    {

        if (temp->data == 0)
            cnt0++;

        else if (temp->data == 1)
            cnt1++;

        else
            cnt2++;

        temp = temp->next;
    }

    temp = head;

    while (temp != nullptr)
    {

        if (cnt0)
        {
            temp->data = 0;
            cnt0--;
        }

        else if (cnt1)
        {
            temp->data = 1;
            cnt1--;
        }

        else
        {
            temp->data = 2;
            cnt2--;
        }

        temp = temp->next;
    }

    return head;
}

Node *segregate2(Node *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);

    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;

    Node *temp = head;

    while (temp != nullptr)
    {

        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }

        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }

        else
        {
            two->next = temp;
            two = two->next;
        }

        temp = temp->next;
    }

    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;

    one->next = twoHead->next;
    two->next = nullptr;

    Node *newHead = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}
int main()
{
    int arr[] = {2, 0, 0, 2, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    int arr2[] = {0, 1, 2, 2, 1, 0};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    Node *head = arrayToLinkedList(arr, size);
    Node *head2 = arrayToLinkedList(arr2, size2);
    head = segregate2(head);
    head2 = segregate2(head2);
    cout << "Test Case 1:\n";
    printLinkedList(head);
    cout << "\nTestCase 2:\n";
    printLinkedList(head2);
    return 0;
}