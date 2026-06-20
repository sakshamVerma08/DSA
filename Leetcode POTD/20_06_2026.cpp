#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        /* WILL GIVE TLE FOR 10^9 operations.

        If restrictions exist for ith building:
            height of ith building = min(h[i-1] + 1 , restrictions[i])

        If restrictions don't exist for ith building:
            If restrictions exist for i+1th building:
                height of ith building = min(h[i-1]+1, restrictions[i+1]+1)

            Else:
                h[i] = h[i-1]+1;

        */
        restrictions.emplace_back(vector<int>{1,0});
        sort(restrictions.begin(),restrictions.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];// Sort by building's index.
        });

        for(int i = 0; i < restrictions.size()-1; i++){
            auto &b1 = restrictions[i];
            auto &b2 = restrictions[i+1];
            int distance = b2[0]-b1[0];

            int maxHeight = b1[1] + distance;

            b2[1] = min(maxHeight, b2[1]);
        }

        for(int i = restrictions.size()-1; i>0; i--){
            auto &b1 = restrictions[i], &b2 = restrictions[i-1];
            int distance = b1[0]-b2[0];
            int maxHeight = distance + b1[1];
            b2[1] = min(b2[1], maxHeight);
        }

        int output=0;

        for(int i = 0; i < restrictions.size()-1; i++){
            auto &b1 = restrictions[i], &b2 = restrictions[i+1];
            int distance = b2[0]-b1[0];
            int maxHeight = (b1[1] + b2[1] + distance)/2;
            output = max(output,maxHeight);
        }

        int temp = restrictions[restrictions.size()-1][1] + (n-restrictions[restrictions.size()-1][0]);
        output = max(temp, output);
        return output;









    }
};



