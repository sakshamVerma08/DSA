#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{

	private:

    void putString(string &str1, string &str2, int start, int end){
        char ch = 'a';

        for(int i=start; i <= end;i++){
            str1[i] = ch;
            it++;
        }
    }

public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string res(n+m-1);

        for(int i = 0; i < n; i++){
            // Runs from 0th position to n-1th position in str1.
            char &c = str1[i];

            if(c=='T'){
                // We try to put str2 in word.substr(0,m)
                if(i+m-1 < n){
                    putString(str1,str2,i, i + m-1);
                }
                else return "";
            }
            else{
                // We try to put 'something else' in word.substr(0,m)
            }
        }
    }	

};
