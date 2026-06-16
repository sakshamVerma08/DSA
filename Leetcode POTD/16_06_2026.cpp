#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
Solution(){

}
    string processStr(string s) {
        int n = s.size();
        string result="";

        for(int i = 0; i < n; i++){
            char ch = s[i];

            if(ch >= 'a' && ch <= 'z'){
                result.push_back(ch);
            }

            else if (ch=='*' && !result.empty()){
                result.pop_back();
            }

            else if (ch=='#'){
                result+=result;
            }

            else{
                reverse(result.begin(),result.end());
            }
        }
        return result;
    }
};

int main(){
    string input;
    cin>>input;

    Solution *s = new Solution();

    cout<< s->processStr(input)<<endl;

    return 0;
}