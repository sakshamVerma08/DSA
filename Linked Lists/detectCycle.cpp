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

// Brute Force Approach (Hashing)

bool detectCycle(Node *head)
{
    if (head == nullptr)
        return false;

    map<Node *, int> m;
    Node *temp = head;

    while (temp != nullptr)
    {

        if (m.find(temp) != m.end())
            return true;

        m[temp] = 1;
        temp = temp->next;
    }

    return false;
}
// This functions works on the assumption that there is an upper limit to the number of nodes present in the linked list.
bool detectCycle2(Node *head)
{
    if (head == nullptr)
        return false;

    int len = 0;
    Node *temp = head;

    while (temp != nullptr)
    {

        if (len > 10e6)
            return true;

        len++;
        temp = temp->next;
    }

    return false;
}

bool detectCycle3(Node *head)
{
    if (head == nullptr)
        return false;

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}
int main()
{
    // Run in a Problem solving platform like naukri360 or leetcode.
}