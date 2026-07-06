#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
        using ll = long long;
        ll num;

    public:
        Solution(ll num){
            this->num = num;
        }

        bool check_nearly_lucky(){
            unordered_map<int,int> mpp;
            int cnt=0;

            while(num){
                int digit = num%10;
                num/=10;
                if(digit == 4 || digit == 7){
                    cnt++;
                    mpp[digit]++;
                }
            }

            /*
            if( (mpp.find(7)==mpp.end() && mpp.find(4) != mpp.end()) && (mpp[4] == 4 || mpp[4] == 7)){
                return true;
            }
            else if ( (mpp.find(4) == mpp.end() && mpp.find(7) != mpp.end()) && (mpp[7] == 4 || mpp[7] == 7)){
                return true;
            }
            else if ((mpp.count(4) == 4 || mpp.count(4) == 7) && (mpp.count(7) == 4 || mpp.count(7) == 7))
                return true;

            return false;
            */
            if(cnt == 4 || cnt == 7)
                return true;
            return false;
        }
};

int main(){
    long long num;
    cin>>num;

    Solution* s = new Solution(num);
    bool ans =  s->check_nearly_lucky();

    if(ans)cout<<"YES"<<endl;

    else
        cout<<"NO"<<endl;
    return 0;
}