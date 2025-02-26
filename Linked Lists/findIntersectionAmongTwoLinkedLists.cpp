#include <iostream>
#include <map>
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

// Brute Force Approach
Node *findIntersection(Node *firstHead, Node *secondHead)
{

    if (firstHead == nullptr || secondHead == nullptr)
        return nullptr;

    Node *temp1 = firstHead;
    Node *temp2 = secondHead;

    map<Node *, int> m;

    while (temp1 != nullptr)
    {
        m[temp1] = 1;
        temp1 = temp1->next;
    }

    while (temp2 != nullptr)
    {
        if (m.find(temp2) != m.end())
            return temp2;

        temp2 = temp2->next;
    }

    return nullptr;
}
// *********************************************************

// Better Approach
Node *collisionPoint(Node *head1, Node *head2, int d)
{
    // head1 is the smaller linked list, head2 is the larger linked list

    while (d != 0)
    {
        head2 = head2->next;
        d--;
    }

    while (head1 != head2)
    {
        head1 = head1->next;
        head2 = head2->next;
    }

    return head1;
}

Node *findIntersection2(Node *firstHead, Node *secondHead)
{
    if (firstHead == nullptr || secondHead == nullptr)
        return nullptr;

    Node *temp1 = firstHead;
    Node *temp2 = secondHead;

    int n1 = 0;
    int n2 = 0;

    int d;

    while (temp1 != nullptr)
    {
        n1++;
        temp1 = temp1->next;
    }

    temp1 = firstHead;

    while (temp2 != nullptr)
    {
        n2++;
        temp2 = temp2->next;
    }

    temp2 = secondHead;

    if (n1 > n2)
    {
        d = n1 - n2;
        Node *ans = collisionPoint(temp2, temp1, d);
        return ans;
    }

    else
    {
        d = n2 - n1;
        Node *ans = collisionPoint(temp1, temp2, d);
        return ans;
    }
}

// ***********************************************************

// Optimized Approach
Node *findIntersection3(Node *firstHead, Node *secondHead)
{
    if (firstHead == nullptr || secondHead == nullptr)
        return nullptr;

    Node *t1 = firstHead;
    Node *t2 = secondHead;

    while (t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;

        if (t1 == t2)
            return t1;

        if (t1 == nullptr)
            t1 = secondHead;

        if (t2 == nullptr)
            t2 = firstHead;
    }
    return t1;
}
int main()
{

    // Run the code on a practice platform (Code360, Leetcode etc.)
}