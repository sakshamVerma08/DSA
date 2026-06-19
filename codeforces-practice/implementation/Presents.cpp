#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        Solution(){


        }

        vector<int> printMapping(vector<int> &arr){
            vector<int> ans(arr.size(),-1);

            for(int i = 0; i < arr.size(); i++){
                ans[arr[i]-1] = i+1;
            }
            return ans;

        }

};

int main(){
    int n;
    cin>>n;
    cin.ignore();

    string elem;
    getline(cin, elem);
    stringstream ss(elem);
    vector<int> arr;

    int num;

    while(ss >> num){
        arr.emplace_back(num);
    }

    Solution* s = new Solution();
    auto ans = s->printMapping(arr);

    for(const int &n: ans){
        cout<< n << " ";
    }

    return 0;
}