
#include <iostream>
using namespace std;

class Node
{

private:
	int val;
	Node *next;

public:
	Node(int val)
	{
		this->val = val;
		this->next = nullptr;
	}
} Node *tortoise_hare_algo(Node *head)
{

	Node *slow = new Node(head);
	Node *fast = new Node(head);

	while (fast != nullptr && fast->next != nullptr)
	{

		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			return slow;
	}
}