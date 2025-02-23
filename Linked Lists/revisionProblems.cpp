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

// Most Optimized
void pallindromeList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        cout << "True" << endl;
        return;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    Node *temp = head;
    Node *temp2 = reverseLL2(slow);

    while (temp2 != nullptr)
    {
        if (temp->data != temp2->data)
        {
            cout << "false" << endl;
            return;
        }

        temp = temp->next;
        temp2 = temp2->next;
    }
    cout << "True" << endl;
    return;
}

void pallindromeList2(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        cout << "True" << endl;
        return;
    }

    stack<int> st;
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        st.push(slow->data);
        slow = slow->next;
    }

    while (slow != nullptr)
    {
        if (st.top() != slow->data)
        {
            cout << "False" << endl;
            return;
        }

        st.pop();
        slow = slow->next;
    }

    cout << "True" << endl;
    return;
}

void switchOdd(bool &odd)
{
    if (odd)
        odd = false;

    else
        odd = true;
}
Node *segregateOddEven(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *d1 = new Node(-1);
    Node *d2 = new Node(-1);

    Node *c1 = d1;
    Node *c2 = d2;

    Node *forward;
    Node *temp = head;
    bool odd = true;

    while (temp != nullptr)
    {

        if (odd)
        {
            forward = temp->next;
            temp->next = nullptr;
            c1->next = temp;
            c1 = c1->next;
            temp = forward;
            switchOdd(odd);
        }

        else
        {

            forward = temp->next;
            temp->next = nullptr;
            c2->next = temp;
            c2 = c2->next;
            temp = forward;
            switchOdd(odd);
        }
    }

    Node *newHead = d1->next;
    c1->next = d2->next;
    c2->next = nullptr;

    delete d1;
    delete d2;
    return newHead;
}

Node *removeNFromBack(Node *head, int n)
{
    if (head == nullptr)
        return head;

    if (n == 1 && head->next == nullptr)
        return nullptr;

    Node *temp = head;
    int len = 0;

    while (temp != nullptr)
    {
        len++;
        temp = temp->next;
    }

    if (n == len)
    {
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int index = len - n;
    int i = 1;
    temp = head;

    while (temp != nullptr && i != index)
    {
        i++;
        temp = temp->next;
    }

    Node *del = temp->next;
    temp->next = del->next;
    del->next = nullptr;
    delete del;
    return head;
}

Node *removeNFromBack2(Node *head, int n)
{
    if (head == nullptr)
        return head;

    if (n == 1 && head->next == nullptr)
        return nullptr;

    Node *fast = head;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    if (fast == nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *slow = head;

    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node *del = slow->next;
    slow->next = del->next;
    delete del;
    return head;
}
int main()
{

    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {1, 3};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    Node *head1 = arrayToLinkedList(arr1, size1);
    Node *head2 = arrayToLinkedList(arr2, size2);

    head1 = removeNFromBack2(head1, 3);
    printLinkedList(head1);

    return 0;
}