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

Node *deleteTailFromDoublyLL(Node *head)
{
    if (head == nullptr)
        return head;

    if (head->next == nullptr && head->prev == nullptr)
        return nullptr;

    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    Node *prev = tail->prev;
    tail->prev = nullptr;
    prev->next = nullptr;
    delete tail;

    return head;
}

Node *deleteKthElem(Node *head, int k)
{
    if (head == nullptr)
        return head;

    if (head->prev == nullptr && head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    if (k == 0)
    {
        Node *prev = head;
        head = head->next;
        prev->next = nullptr;
        head->prev = nullptr;
        delete prev;
        return head;
    }

    int cnt = 0;
    Node *temp = head;
    while (cnt != k)
    {
        temp = temp->next;
        cnt++;
    }

    Node *prevNode = temp->prev;
    Node *nextNode = temp->next;
    prevNode->next = nextNode;
    if (nextNode == nullptr)
    {
        prevNode->next = nullptr;
        delete temp;
        return head;
    }
    nextNode->prev = prevNode;
    delete temp;
    return head;
}

Node *insertBeforeHead(Node *head, int val)
{
    if (head == nullptr)
        return new Node(val);

    Node *node = new Node(val);
    node->next = head;
    head->prev = node;
    return node;
}

Node *insertBeforeTail(Node *head, int val)
{
    if (head == nullptr)
        return new Node(val);

    Node *temp = head;
    Node *node = new Node(val);

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        node->next = temp;
        temp->prev = node;
        head = node;
        return head;
    }

    Node *prevNode = temp->prev;
    node->prev = prevNode;
    node->next = temp;
    temp->prev = node;
    prevNode->next = temp;
    return head;
}

Node *insertBeforeKthElement(Node *head, int k, int val)
{
    if (head == nullptr && k == 0)
        return new Node(val);

    Node *elem = head;
    Node *node = new Node(val);
    int cnt = 0;
    while (cnt != k)
    {
        elem = elem->next;
        cnt++;
    }

    if (k == 0)
    {
        node->next = head;
        head->prev = node;
        head = node;
        return head;
    }

    Node *prevNode = elem->prev;
    node->prev = prevNode;
    node->next = elem;
    elem->prev = node;
    prevNode->next = node;
    return head;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node *head = arrayToLinkedList(arr, size);
    head = insertBeforeKthElement(head, 2, 0);
    printLinkedList(head);

    return 0;
}