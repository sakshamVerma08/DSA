#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int sum = 0;

    int findWaviness(int num){
        string s = to_string(num);

        if(s.size() < 3)
            return 0;
        
        int peak=0,valley=0;

        for(int i = 0; i < s.size(); i++){

            if(i == 0 || i == s.size()-1)
                continue;

            int digit = s[i] - '0';
            int left = s[i-1] - '0';
            int right = s[i+1] - '0';

            if(digit > left && digit > right)
                peak++;

            else if (digit < left && digit < right)
                valley++;

        }

        return (peak + valley);
    }

public:
    int totalWaviness(int num1, int num2) {
        
        for(int i = num1; i <= num2; i++){
            // looping from [num1,num2].

            sum += findWaviness(i);
            
        }
        return sum;
    }
};


int main(){

    int num1, num2;
    cin>>num1>>num2;
    Solution * s = new Solution();

    cout<< s->func(num1,num2)<<endl;

    return 0;
}


