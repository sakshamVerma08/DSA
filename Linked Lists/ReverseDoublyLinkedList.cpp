#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        prev = nullptr;
        next = nullptr;
        data = 0;
    }
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

// This is the function that uses brute force method to reverse a DLL.
Node *reverseDLL(Node *head)
{
    if (head->prev == nullptr && head->next == nullptr)
        return head;

    Node *temp = head;

    stack<int> st;

    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while (temp)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

// This method uses the optimized approach to reverse a DLL.

Node *reverseDLL2(Node *head)
{
    if (head->prev == nullptr && head->next == nullptr)
        return head;

    Node *last;
    Node *temp = head;
    while (temp != nullptr)
    {
        last = temp->prev;
        temp->prev = temp->next;
        temp->next = last;
        temp = temp->prev;
    }

    return last->prev;
}


Node *reverseDLL3(Node *head)
{
    if (head == nullptr || (head->prev == nullptr && head->next == nullptr))
        return head;

    Node *temp = head;
    Node *temp2 = head;

    int i = 0,j=0;

    while (temp->next != nullptr)
    {
        temp = temp->next;
        i++;
    }

    int data=0;
    

    while (i>j)
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

int main()
{
    int arr[] = {75, 122, 59, 196};
    int arr2[] = {2};

    int size1 = sizeof(arr) / sizeof(arr[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    Node *head = arrayToDLL(arr, size1);
    head = reverseDLL2(head);
    printDLL(head);
    return 0;
}