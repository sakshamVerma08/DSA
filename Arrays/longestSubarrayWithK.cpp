#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    vector<int> v;
    int sum,count;

    for(int i = 0; i < a.size(); i ++){

        sum=0;
        count=0;

        for(int j = i; j < a.size();j++){

            sum += a[j];
            count ++;

            if(sum==k){
                v.push_back(count);
                break;
            }
            
            if(sum > k)
            break;

        }
    }

    int maxCnt = 0;

    for(auto &elem : v){
        if(elem > maxCnt)
        maxCnt = elem;
    }

    return maxCnt;
}


int main(){

    vector<int> tc1 = {8 ,15,17,0,11};
    int n1 = tc1.size();

    cout<<"tc1 : "<< longestSubarrayWithSumK(tc1,n1)<<endl;

    return 0;
}