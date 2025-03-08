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

Node *firstNode(Node *head)
{
    if (head == nullptr)
        return head;

    Node *temp = head;
    map<Node *, int> m;
    m[head] = 1;
    temp = head->next;

    while (temp != nullptr)
    {

        if (m.find(temp) != m.end())
            return temp;

        m[temp] = 1;
        temp = temp->next;
    }

    return nullptr;
}

Node *firstNode2(Node *head)
{
    if (head == nullptr)
        return head;

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            break;
        }
    }

    if (fast == nullptr || fast->next == nullptr)
        return nullptr;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
int main()
{

    // Test on problem solving platform like Leetcode/ Code360 etc.
    return 0;
}