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

void searchInLL(Node *head, int elem)
{

    Node *temp = head;
    bool isInLL = false;
    while (temp != nullptr)
    {
        if (temp->data == elem)
        {
            isInLL = true;
        }

        temp = temp->next;
    }

    if (isInLL == false)
    {
        cout << "false" << endl;
        return;
    }
    cout << "true" << endl;
}

int lengthOfLL(Node *head)
{

    if (head == nullptr)
    {
        return 0;
    }

    Node *temp = head;
    int cnt = 0;
    while (temp != nullptr)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

Node *arrayToLL(int arr[], int N)
{

    if (N == 0)
    {
        return nullptr;
    }

    Node *head = new Node(arr[0]);
    Node *x = head;

    for (int i = 1; i < N; i++)
    {
        Node *temp = new Node(arr[i]);
        x->next = temp;
        x = temp;
    }

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
    int arr[] = {1, 2, 3};

    Node *head = arrayToLL(arr, sizeof(arr) / sizeof(arr[0]));
    printLL(head);
    return 0;
}