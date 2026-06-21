#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    Solution(){

        
    }

    int maxIceCream(vector<int>& costs, int amount) {
        
        int output=0, n = costs.size() , maxElement = INT_MIN;
        for(int i=0;i<n;i++){
            if(costs[i] > maxElement)
                maxElement=costs[i];
        }
        
        vector<int> countArray(maxElement+1,0);

        for(int i =0; i<n; i++){
            countArray[costs[i]]++;
        }
        
        for(int i=1; i<= maxElement; i++){
            countArray[i] += countArray[i-1];// computing Prefix Sum.
        }

        vector<int> ans(n);

        for(int i= n-1; i>=0; i--){
            ans[countArray[costs[i]] - 1] = costs[i];
            countArray[costs[i]]--;
        }

        for(int i=0;i<n;i++){
            if(amount >= ans[i]){
                output++;
                amount-=ans[i];
            }
            else return output;
        }

        return output;
        
    }
};

int main(){
    int amount;
    cin>>amount;
    cin.ignore();

    string elem;
    getline(cin , elem);
    int num;
    vector<int> arr;

    stringstream ss(elem);

    while(ss >> num){
        arr.emplace_back(num);
    }

    Solution* s = new Solution();
    cout<<" Ans = "<< s->maxIceCream(arr, amount)<< endl;

    return 0;
}