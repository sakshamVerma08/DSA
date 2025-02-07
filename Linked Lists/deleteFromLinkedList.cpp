#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

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

Node *deleteHeadOfLL(Node *head)
{

    if (head == nullptr)
        return head;
    Node *temp = head->next;

    head->next = nullptr;
    delete head;
    return temp;
}

Node *deleteTailOfLL(Node *head)
{
    if (head == nullptr)
        return head;

    Node *temp = head;

    while (temp->next && temp->next->next)
    {
        temp = temp->next;
    }

    if (temp->next == nullptr)
    {
        head = nullptr;
        delete temp;
        return head;
    }

    delete temp->next;
    temp->next = nullptr;
    return head;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node *head = arrayToLinkedList(arr, size);
    head = deleteTailOfLL(head);
    printLinkedList(head);
    return 0;
}