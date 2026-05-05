#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
private:
    vector<int> rotateArr(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++)
        {
            // looping from [0,n-1].
            res[(i + k) % n] = arr[i];
        }
        return res;
    }

public:
    Solution()
    {
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;

        vector<int> arr1;

        ListNode *tmp = head;
        while (tmp)
        {
            arr1.emplace_back(tmp->val);
            tmp = tmp->next;
        }

        auto arr2 = rotateArr(arr1, k);
        int n = arr2.size();

        ListNode *newHead = new ListNode(arr2[0]);
        tmp = newHead;

        for (int i = 1; i < n; i++)
        {
            // looping from [1, n-1].
            ListNode *node = new ListNode(arr2[i]);
            tmp->next = node;
            tmp = tmp->next;
        }

        return newHead;
    }
};

int main()
{
}