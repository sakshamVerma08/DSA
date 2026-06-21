#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        Solution(){


        }

        vector<int> printMapping(vector<int> &arr){
            unordered_map<int,int> givers;
            for(int i = 0; i < arr.size(); i++){
                givers[i+1] = arr[i];
            }
            // [2,3,4,1]
            /*
            givers = {
            1: 2,
            2: 3,
            3: 4,
            4: 1
            }

            output = {
                1: 4,
                2: 1,
                3: 2,
                4: 3
            }
            */
            vector<int> ans(arr.size());
            auto st = givers.begin();
            auto end = givers.end();

            for(auto it = st; it!= end; it++){
                ans[it->second-1] = it->first;
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