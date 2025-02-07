#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node

{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

Node *insertAtEnd(Node *head, int x)
{
    Node *newNode = new Node(x);
    if (head == nullptr)
    {
        head = newNode;
        return head;
    }

    Node *temp = head;

    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

void printLL(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    int x = 6;

    Node *head = new Node(arr[0]);

    
    return 0;
}