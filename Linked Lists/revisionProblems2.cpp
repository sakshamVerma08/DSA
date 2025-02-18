#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

Node *arrayToDLL(int arr[], int size)
{
    if (size == 0)
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < size; i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
    return head;
}

void printDLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

Node *reverseDLL(Node *head)
{
    if (head == nullptr || (head->prev == nullptr && head->next == nullptr))
        return head;

    stack<int> st;
    Node *temp = head;
    while (temp != nullptr)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while (!st.empty() && temp != nullptr)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

Node *reverseDLL2(Node *head)
{
    if (head == nullptr || (head->prev == nullptr && head->next == nullptr))
        return head;

    Node *temp = head;
    Node *temp2 = head;

    int i = 0, j = 0;

    while (temp->next != nullptr)
    {
        temp = temp->next;
        i++;
    }

    int data = 0;

    while (i > j)
    {
        data = temp2->data;

        temp2->data = temp->data;
        temp->data = data;
        temp = temp->prev;
        temp2 = temp2->next;
        i--;
        j++;
    }

    return head;
}

Node *reverseDLL3(Node *head)
{
    if (head == nullptr || (head->prev == nullptr && head->next == nullptr))
        return head;

    Node *current = head;
    Node *last = nullptr;

    while (current != nullptr)
    {
        last = current->prev;
        current->prev = current->next;
        current->next = last;
        current = current->prev;
    }

    return last->prev;
}

int main()
{

    int arr1[] = {8, 7, 6, 5, 4};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    Node *head = arrayToDLL(arr1, size1);
    head = reverseDLL3(head);
    printDLL(head);
    return 0;
}