#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> subStrings(const string &password, int k)
{

    vector<string> vec;

    for (int i = 0; i < password.size(); i++)
    {
        string temp = "";
        for (int j = i; j < password.size(); j++)
        {

            temp.push_back(password[j]);
            vec.emplace_back(temp);
        }
    }

    return vec;
}

void printVector(vector<string> &arr)
{

    for (auto &ch : arr)
    {

        cout << ch << " ";
    }
    cout << "\n";
}
int main()
{

    string s1 = "ababa";

    vector<string> vec = subStrings(s1, 3); 

    printVector(vec);

    return 0;
}