#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    using ll = long long;
    ll ans = 0;
public:
Solution(){}

    long long maxTotalValue(vector<int>& arr, int k) {
        auto max_it = max_element(arr.begin(),arr.end());
        auto min_it = min_element(arr.begin(),arr.end());

        // Getting the index position of maximum and minimum element.
        int max_idx = max_it-arr.begin();
        int min_idx = min_it-arr.begin();

        ll temp = arr[max_idx] - arr[min_idx];
        ans = temp * k;
        return ans;

    }
};

int main(){

    Solution* s = new Solution();
    vector<int> arr;
    int num,k;
    cout<<"Enter k"<<endl;
    cin>>k;
    cin.ignore();
    string elem;
    getline(cin, elem);
    stringstream ss(elem);

    while(ss >> num){
        arr.emplace_back(num);
    }

    long long ans = s->maxTotalValue(arr,k);

    cout<<"Answer = "<< ans<<endl;

    return 0;
}