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

Node *removeNthFromBehind(Node *head, int n)
{
    if (n == 1 && head->next == nullptr)
        return nullptr;

    if (head == nullptr)
        return head;

    Node *temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }

    temp = head;
    int index = cnt - n + 1;
    int i = 1;

    if (index == 1)
    {
        Node *next = head->next;
        delete head;
        return next;
    } // delete head

    else if (index == cnt)
    {
        Node *tail = head;
        while (tail->next->next != nullptr)
        {
            tail = tail->next;
        }

        Node *node = tail->next;
        tail->next = nullptr;
        delete node;
        return head;
    }

    while (i != index - 1)
    {
        i++;
        temp = temp->next;
    }

    Node *node = temp->next;
    temp->next = temp->next->next;
    delete node;
    return head;
}

Node *removeNthFromBehind2(Node *head, int n)
{

    if (n == 1 && head->next == nullptr)
        return nullptr;

    if (head == nullptr)
        return nullptr;

    Node *slow = head;
    Node *fast = head;

    int i = n;

    while (i > 0)
    {
        fast = fast->next;
        i--;
    }

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // delete head
    if (fast == nullptr)
    {
        head = head->next;
        delete slow;
        return head;
    }

    Node *node = slow->next;
    slow->next = slow->next->next;
    delete node;
    return head;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int arr2[] = {1, 2};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    Node *head = arrayToLinkedList(arr, size);

    Node *head2 = arrayToLinkedList(arr2, size2);

    head = removeNthFromBehind2(head, 5);
    head2 = removeNthFromBehind2(head2, 2);

    cout << "Test Case 1:\n";
    printLinkedList(head);
    cout << "\nTest Case 2:\n";
    printLinkedList(head2);

    return 0;
}