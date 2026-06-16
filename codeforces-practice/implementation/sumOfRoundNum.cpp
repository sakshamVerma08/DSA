#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int n;

        Solution(int n){
            this->n=n;

        }

        bool checkRound(){
            if(n>=1 && n <= 9)
                return true;

            int copy = n;
            string s = to_string(copy);

            for(int i = 1; i < s.size(); i++){
                if(s[i] != '0')
                    return false;
            }
            return true;
        }

        

        vector<int> sum_round_num(){
            if(n>=1 && n <= 9)
                return vector<int>{n};


            bool flag = checkRound();

            if(flag){
                return vector<int>{n};
            }

            vector<int> ans;
            
            // break down a number into it's ones, tens, thousands and ten-thousands components.

            int mult = 1;

            while(n){
                int digit = n%10;
                digit*=mult;
                if(digit)
                    ans.emplace_back(digit);

                mult*=10;
                n/=10;
            }

            return ans;
            
        }

};


int main(){
    int t;
    cin>>t;

    int n;

    for(int i =0;i<t;i++){
        cin>>n;


        Solution*s = new Solution(n);
        auto ans = s->sum_round_num();

         cout << ans.size() << '\n';

        for (int x : ans) {
            cout << x << " ";
        }
        cout << '\n';
    }

    return 0;
}