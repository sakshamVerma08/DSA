#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        Solution(){

        }

        long long returnInverted(long long num){
            if(num<10 && (num>=5 && num <= 9))
                return num;

            string s="";

            while(num){
                int lastDigit=num%10;
                num/=10;
                int invertedDigit = 9 - lastDigit;

                if(lastDigit >=5){
                    // protect against leading zeroes.
                    if(num==0 && lastDigit==9){
                        s+=to_string(9);
                    }

                    else
                        s+=to_string(invertedDigit);

                }

                else
                    s+=to_string(lastDigit);
            }

            reverse(s.begin(),s.end());

            long long ans = stoll(s);
            return ans;

        }

        
};


int main(){
    long long num;
    cin>>num;

    Solution* s = new Solution();
    cout<< s->returnInverted(num)<<endl;
    return 0;
}