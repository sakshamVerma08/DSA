#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
Solution(){

}
    vector<int> pivotArray(vector<int>& arr, int pivot) {
        int n = arr.size();

        vector<int> smaller;
        vector<int> larger;
        vector<int> equal;

        for(int i = 0; i < n; i++){
            if(arr[i] < pivot)
                smaller.emplace_back(arr[i]);
            else if (arr[i] == pivot)
                equal.emplace_back(arr[i]);
            else
                larger.emplace_back(arr[i]);
        }

        int pos = 0;

        for(int i = 0; i < smaller.size(); i++){
            arr[pos] = smaller[i];
            pos++;
        }
        for(int i = 0; i < equal.size(); i++){
            arr[pos] = equal[i];
            pos++;
        }
        for(int i = 0; i < larger.size(); i++){
            arr[pos] = larger[i];
            pos++;
        }
        return arr;
        
    }
};

int main(){

    
    Solution* s = new Solution();
    vector<int> arr;
    int pivot;
    int num;
    cout<<"Enter pivot element:"<<endl;
    cin>>pivot;
    string elem;
    cin.ignore();
    getline(cin,elem);

    stringstream ss(elem);
    while(ss >> num){
        arr.emplace_back(num);
    }

    auto ans = s->pivotArray(arr,pivot);
    for(const int &n: ans){
        cout<< n << ", ";
    }

    return 0;

}