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

Node *deleteKthNode(Node *head, int k)
{
    if (head == nullptr)
        return head;

    if (k == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;
    Node *prev = nullptr;
    int cnt = 0;

    while (temp != nullptr)
    {

        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete temp;
            return head;
        }

        prev = temp;
        temp = temp->next;
        cnt++;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node *head = arrayToLinkedList(arr, size);
    Node *head2 = arrayToLinkedList(arr, size);
    Node *head3 = arrayToLinkedList(arr, size);
    int k1 = 0;
    int k2 = 4;
    int k3 = 2;

    head = deleteKthNode(head, k1);
    head2 = deleteKthNode(head2, k2);
    head3 = deleteKthNode(head3, k3);
    cout << "Test case 1: ";
    printLinkedList(head);
    cout << "test case 2: ";
    printLinkedList(head2);
    cout << "test case 3: ";
    printLinkedList(head3);
    return 0;
}