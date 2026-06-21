#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    using ll = long long;
    
    bool checkValid(ll sum, int &x){
        int lastDigit = sum % 10;
        int firstDigit;

        while(true){
            firstDigit = sum%10;
            sum/=10;
            if(!sum){
                break;
            }
        }

        if(firstDigit==x && lastDigit==x){
            
            return true;
        }
        return false;
    }
    
public:
    Solution(){
        
    }
    int countValidSubarrays(vector<int>& arr, int x) {
        int n = arr.size();
        int output = 0;
        
        vector<ll> prefix(n);
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + arr[i];
        }

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                ll sum=0;
                if(i==0){
                    sum=prefix[j];
                }
                else
                    sum=prefix[j] - prefix[i-1];

                bool flag = checkValid(sum,x);
                if(flag) output++;
            }
        }

        return output;

        
    }
};

int main(){
    vector<int> arr;
    int x;
    cin>> x;
    cin.ignore();
    string elem;
    getline(cin , elem);
    stringstream ss(elem);
    int num;
    while(ss >> num){
        arr.emplace_back(num);
    }
    Solution* s = new Solution();

    cout<<"Ans = "<< s->countValidSubarrays(arr,x)<<endl;

    return 0;

}