#include <iostream>
#include <bits/stdc++.h>
using namespace std;

unordered_set<string> countDistinctSubstrings(string &s)
{
    unordered_set<string> ans;
    ans.insert("");

    string temp;

    for (int i = 0; i < s.size(); i++)
    {

        temp = "";

        for (int j = i; j < s.size(); j++)
        {

            temp += s[j];
            ans.insert(temp);
        }
    }

    return ans;
}

void printSet(unordered_set<string> &set)
{

    for (auto it = set.begin(); it != set.end(); it++)
    {

        cout << *it << " ";
    }
    cout << endl;
}

/*
    Time Complexity: O(N^2)
    Space Complexity: O(N^2)

    Where 'N' is the length of the given string.
*/
#include <bits/stdc++.h>
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;

    ~TrieNode()
    {
        for (unordered_map<char, TrieNode *>::iterator i = children.begin(); i != children.end(); i++)
        {
            delete i->second;
        }
    }
};

void insert(string s, int i, TrieNode *head)
{

    TrieNode *temp = head;
    int n = s.size();

    while (i < n)
    {

        char ch = s[i];

        if (temp->children[ch - 'a'] == nullptr)
        {
            // Create a new children

            temp->children[ch - 'a'] = new TrieNode();
        }

        temp = temp->children[ch - 'a'];
        i++;
    }
}

int countNodes(TrieNode *root)
{

    int subtreeNodes = 1;

    if (root == nullptr)
        return 0;

    for (auto it = root->children.begin(); it != root->children.end(); it++)
    {

        subtreeNodes += countNodes(it->second);
    }

    return subtreeNodes;
}

int countDistinctSubstrings2(string &s)
{

    int n = s.size();

    TrieNode *head = new TrieNode();

    for (int i = 0; i < n; i++)
    {
        insert(s, i, head);
    }

    int totalNodes = countNodes(head);

    delete head;

    return totalNodes;
}

int main()
{

    string s1 = "saksham";

    cout << "ans = " << countDistinctSubstrings2(s1) << endl;

    return 0;
}