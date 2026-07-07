#include <bits/stdc++.h>
using namespace std;


class Solution{        

    public:
        Solution(){}

        int min_cap(vector<vector<int>>&data){
            int total=0;
            int temp = total;

            for(auto v : data){
                // running from 0th stop to the last stop.
                int ai=v[0],bi=v[1];
                temp-=ai;
                temp+=bi;
                total=max(temp,total);
            }

            return total;
        }

};

int main(){
    int n;
    cin>> n;
    cin.ignore();

    vector<vector<int>> data;

    for(int i = 0; i<n;i++){
        int ai,bi;
        cin>>ai>>bi;
        data.push_back(vector<int>{ai,bi});
    }
    Solution*s = new Solution();

    cout<<s->min_cap(data)<<endl;

    return 0;


}