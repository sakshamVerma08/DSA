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

// This function iteratively reverses the given LL
Node *reverseLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *prev = nullptr;
    Node *temp = head;
    Node *next = temp->next;

    while (next != nullptr)
    {
        temp->next = prev;
        prev = temp;
        temp = next;
        next = next->next;
    }

    // For Tail Node.
    if (temp)
    {
        temp->next = prev;
    }

    return temp;
}

// This function uses recursion to reverse the given LL.
Node *recursionFunction(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *newHead = recursionFunction(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
Node *reverseLL2(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *newHead = recursionFunction(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int arr2[] = {3, 4};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    Node *head = arrayToLinkedList(arr, size);
    Node *head2 = arrayToLinkedList(arr2, size2);

    head = reverseLL2(head);
    head2 = reverseLL2(head2);
    cout << "test case 1:" << endl;
    printLinkedList(head);
    cout << "test case 2:" << endl;
    printLinkedList(head2);

    return 0;
}