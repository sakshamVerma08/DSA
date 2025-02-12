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

// Approach 1
Node *middleNode(Node *head)
{

    if (head->next == nullptr)
        return head;

    int length = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        length++;
        temp = temp->next;
    }

    int idx = length / 2;
    int i = 0;
    Node *middle = head;
    while (i != idx)
    {
        middle = middle->next;
        i++;
    }

    return middle;
}

// Use the Tortoise and Hare Algorithm to solve the problem in O(N/2) complexity
Node *middleNode2(Node *head)
{
    if (head->next == nullptr)
        return head;

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int arr2[] = {0, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    Node *head = arrayToLinkedList(arr, size);
    Node *head2 = arrayToLinkedList(arr2, size2);

    head = middleNode2(head);
    cout << head->data;

    return 0;
}