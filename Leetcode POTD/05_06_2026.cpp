#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int main(){

    Solution * s = new Solution();
    int num1,num2;
    cout<<"Enter num1 & num2"<<endl;
    cin>>num1>>num2;
    cout<<"Ans = "<< s->totalWaviness(num1,num2)<<endl;
    
    return 0;
}