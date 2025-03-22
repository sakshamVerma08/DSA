#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Used unordered sets (brute force)
// time complexity : O(n^2 * m)
// space complexity : O(sizeof(supplies))

vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
{
    unordered_set<string> st(supplies.begin(), supplies.end());
    vector<string> ans;
    int n = recipes.size();
    vector<bool> cooked(n, false);

    int count = n;

    while (count >= 0)
    {
        count--;

        for (int j = 0; j < n; j++)
        {
            if (cooked[j])
                continue;

            bool canMake = true;

            for (int k = 0; k < ingredients[j].size(); k++)
            {

                if (!st.count(ingredients[j][k]))
                {
                    canMake = false;
                    break;
                }
            }

            if (canMake)
            {
                st.insert(recipes[j]);
                ans.push_back(recipes[j]);
                cooked[j] = true;
            }
        }
    }

    return ans;
}



int main()
{

    return 0;
}