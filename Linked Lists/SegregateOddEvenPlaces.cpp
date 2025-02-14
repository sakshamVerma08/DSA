#include <iostream>
#include <vector>

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

// This function represents the Brute Force method to solve this particular problem.
Node *oddEvenList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    vector<int> vec;
    Node *temp = head;

    while (temp != nullptr && temp->next != nullptr)
    {
        vec.push_back(temp->data);
        temp = temp->next->next;
    }

    if (temp)
        vec.push_back(temp->data);

    temp = head->next;

    while (temp != nullptr && temp->next != nullptr)
    {
        vec.push_back(temp->data);
        temp = temp->next->next;
    }

    if (temp)
        vec.push_back(temp->data);

    temp = head;
    int i = 0;
    while (temp != nullptr)
    {

        temp->data = vec[i];
        i++;
        temp = temp->next;
    }

    return head;
}

Node *oddEvenList2(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = head->next;

    while (even != nullptr && even->next != nullptr)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node *head = arrayToLinkedList(arr, size);
    head = oddEvenList2(head);
    printLinkedList(head);

    return 0;
}