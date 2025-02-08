#include <iostream>

using namespace std;

// Define the Node structure
struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next)
    {
        data = x;
        this->next = next;
    }
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
    Node *newNode = new Node(x);
    if (head == nullptr)
    {
        return newNode;
    }

    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    tail->next = newNode;
    return head;
}
Node *insertAtHead(Node *head, int x)
{
    Node *newNode = new Node(x);
    newNode->next = head;
    return newNode;
}

Node *insertAtKthPosition(Node *head, int k, int val)
{
    if (head == nullptr && k == 0)
    {
        return new Node(val);
    }

    else if (head == nullptr && k != 0)
    {
        cout << "Not Possible\n";
        return head;
    }

    if (k == 0)
        return new Node(val, head);

    else
    {

        Node *newNode = new Node(val);
        Node *prev = nullptr;
        Node *temp = head;

        int idx = 0;

        while (idx <= k - 1)
        {
            prev = temp;
            temp = temp->next;
            idx++;
        }

        prev->next = newNode;
        newNode->next = temp;
        return head;
    }
}
int main()
{
    int arr[] = {3, 1, 5, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node *head = arrayToLinkedList(arr, size);
    head = insertAtKthPosition(head, 0, 25);
    printLinkedList(head);
    return 0;
}