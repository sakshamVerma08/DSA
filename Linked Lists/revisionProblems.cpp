#include <iostream>
#include <stack>

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
        i++;
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

Node *deleteAtKth(Node *head, int k)
{
    if (k == 1)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        Node *forward = head->next;
        delete head;
        return forward;
    }

    int i = 1;
    Node *temp = head;

    while (i != k - 1)
    {
        temp = temp->next;
        i++;
    }
    Node *node = temp->next;
    Node *forward = node->next;

    temp->next = forward;
    delete node;
    return head;
}

// Delete a node withoout having access to the head of the list,just the node.
// Leetcode Problem Link : https://leetcode.com/problems/delete-node-in-a-linked-list/

void deleteNode(Node *node)
{

    Node *forward = node->next;
    node->data = forward->data;
    node->next = forward->next;
}

Node *reverseLL(Node *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    stack<int> nodeData;
    Node *temp = head;

    while (temp != nullptr)
    {
        nodeData.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    int value;
    while (temp != nullptr)
    {
        value = nodeData.top();
        temp->data = value;
        nodeData.pop();
        temp = temp->next;
    }

    return head;
}

Node *reverseLL2(Node *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    Node *temp = head;
    Node *prev = nullptr;
    Node *forward;

    while (temp != nullptr)
    {
        forward = temp->next;
        temp->next = prev;
        prev = temp;
        temp = forward;
    }

    return prev;
}

Node *reverseLL3(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *temp = head->next;
    Node *newHead = reverseLL3(head->next);
    temp->next = head;
    head->next = nullptr;
    return newHead;
}
int main()
{

    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {3, 2, 1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    Node *head1 = arrayToLinkedList(arr1, size1);
    Node *head2 = arrayToLinkedList(arr2, size2);

    head2 = reverseLL3(head2);
    head1 = reverseLL3(head1);
    printLinkedList(head2);
    printLinkedList(head1);
    return 0;
}