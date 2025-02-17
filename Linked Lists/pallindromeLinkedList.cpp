#include <iostream>

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

Node *reverseList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *newHead = reverseList(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

bool isPallindrome(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *temp = head;
    Node *newHead = reverseList(slow);

    Node *temp2 = newHead;
    bool ans = true;
    while (temp != nullptr && temp2 != nullptr)
    {
        if (temp->data != temp2->data)
        {
            ans = false;
            return ans;
        }

        temp = temp->next;
        temp2 = temp2->next;
    }
    reverseList(newHead);
    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int arr2[] = {1, 2, 3, 3, 2, 1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    Node *head = arrayToLinkedList(arr, size);
    Node *head2 = arrayToLinkedList(arr2, size2);

    bool ans1, ans2;

    ans1 = isPallindrome(head);
    ans2 = isPallindrome(head2);
    if (ans1)
    {
        cout << "ans1 = true" << endl;
    }

    else
    {
        cout << "ans1 = false" << endl;
    }

    if (ans2)
    {
        cout << "ans2 = true" << endl;
    }

    else
        cout << "ans2 = false" << endl;

    return 0;
}