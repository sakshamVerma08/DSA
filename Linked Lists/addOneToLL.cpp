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

Node *reverse(Node *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    Node *prev = nullptr;
    Node *temp = head;
    Node *next;

    while (temp != nullptr)
    {
        next = temp->next;

        temp->next = prev;
        prev = temp;
        temp = next;
    }

    return prev;
}

Node *addOne(Node *head)
{
    if (head == nullptr)
        return new Node(1);

    head = reverse(head);
    Node *temp = head;
    int carry = 1;

    while (temp != nullptr && carry == 1)
    {
        temp->data += carry;

        if (temp->data < 10)
            carry = 0;

        else
        {
            temp->data = 0;
            carry = 1;
        }

        temp = temp->next;
    }

    if (carry == 1)
    {
        head = reverse(head);
        Node *newH = new Node(1);
        newH->next = head;
        return newH;
    }

    head = reverse(head);
    return head;
}

int supportFunction(Node *head)
{
    if (head == nullptr)
        return 1;

    int carry = supportFunction(head->next);

    head->data += carry;

    if (head->data < 10)
        return 0;

    else
    {
        head->data = 0;
        return 1;
    }
}
Node *addOne2(Node *head)
{

    int carry = supportFunction(head);

    if (carry == 1)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        head = newNode;
        return head;
    }

    return head;
}
int main()
{
    int arr[] = {9,9,9};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node *head = arrayToLinkedList(arr, size);

    head = addOne2(head);

    printLinkedList(head);

    return 0;
}