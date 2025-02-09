#include <iostream>

using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;

    Node()
    {
        prev = nullptr;
        data = 0;
        next = nullptr;
    }

    Node(int data)
    {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

Node *arrayToLinkedList(const int arr[], int size)
{
    if (size == 0)
    {
        cout << "Nullptr";
        return nullptr;
    }

    Node *head = new Node(arr[0]);
    int idx = 1;
    Node *temp = head;

    while (idx < size)
    {
        Node *node = new Node(arr[idx]);
        temp->next = node;
        node->prev = temp;
        temp = node;
        idx++;
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

Node *deleteHeadFromDoublyLL(Node *head)
{
    if (head == nullptr)
        return nullptr;

    if (head->next == nullptr && head->prev == nullptr)
        return nullptr;

    Node *prev = head;
    head = head->next;
    head->prev = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node *head = arrayToLinkedList(arr, size);
    head = deleteHeadFromDoublyLL(head);
    printLinkedList(head);

    return 0;
}