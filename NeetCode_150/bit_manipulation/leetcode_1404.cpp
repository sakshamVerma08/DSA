class Solution {

private:
    long long binary_to_decimal(string s){
        long long ans = 0;
        int p = 0;

        for(auto it = s.rbegin(); it != s.rend(); it++){

            if(*it == '1'){
                ans += (long long)pow(2,p);
            }

            p++;
        }

        return ans;
    }


    string decimal_to_binary(long long n){
        string ans = "";

        while(n != 1){
            ans += to_string(n % 2);
            n/=2;
        }

        ans += "1";
        reverse(ans.begin(),ans.end());
        return ans;
    }


    string addOne(string s){
        string ans = "";
        char carry = '1';

        for(auto it = s.rbegin(); it != s.rend(); it++){

            if(*it == '1'){

                if(carry == '0'){
                    ans += *it;
                }

                else{
                    ans += '0';
                    carry = '1';
                }
            }

            else{

                if(carry == '1'){
                    ans += carry;
                    carry = '0';
                }

                else
                    ans += *it;
            }
        }

        if(carry == '1') ans += carry;

        reverse(ans.begin(),ans.end());
        return ans;
    }

public:
    int numSteps(string s) {
        
        int n = s.size();
        int cnt = 0;
        long long num = binary_to_decimal(s);
        
        while(num!=1){
            
            cnt ++;
            n = s.size();
            char *LSB = &s[n-1];
            if(*LSB == '1'){
                // s is ODD.
                s = addOne(s);
                num++;
            }

            else{
                // s is EVEN.
                s = s.substr(0,n-1);
                num/=2;
            }
        }

        return cnt;
    }
}
