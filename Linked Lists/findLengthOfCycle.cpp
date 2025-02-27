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
int lengthOfLoop(Node *head)
{
    if (head == nullptr)
        return 0;

    map<Node *, int> m;
    Node *temp = head;
    int timer = 1;

    while (temp != nullptr)
    {

        if (m.find(temp) != m.end())
        {
            int val = m[temp];
            return (timer - val);
        }

        m[temp] = timer;
        timer++;
        temp = temp->next;
    }

    return 0;
}

int findLength(Node *slow, Node *fast)
{

    int cnt = 1;
    fast = fast->next;

    while (slow != fast)
    {
        cnt++;
        fast = fast->next;
    }
    return cnt;
}

int lengthOfLoop2(Node *head)
{
    if (head == nullptr)
        return 0;

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return findLength(slow, fast);
    }

    return 0;
}

int main()
{
    // Test by running on a coding platform like Code360/ Leetcode etc.
}