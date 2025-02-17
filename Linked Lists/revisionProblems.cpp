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

Node *insertAtEnd(Node *head, int x)
{

    if (head == nullptr)
        return new Node(x);

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    Node *node = new Node(x);
    temp->next = node;
    return head;
}

Node *insertAtHead(Node *head, int x)
{
    if (head == nullptr)
        return new Node(x);

    Node *newHead = new Node(x);
    newHead->next = head;
    return newHead;
}
Node *insertAtKth(Node *head, int k, int val)
{
    if (k == 1)
    {
        if (head == nullptr)
            return new Node(val);

        head = insertAtHead(head, val);
        return head;
    }

    Node *temp = head;
    int i = 1;
    while (i != k - 1)
    {
        temp = temp->next;
    }

    if (temp->next == nullptr)
    {
        Node *node = new Node(val);
        temp->next = node;
        return head;
    }

    Node *front = temp->next;
    Node *node = new Node(val);
    temp->next = node;
    node->next = front;
    return head;
}

int main()
{

    return 0;
}