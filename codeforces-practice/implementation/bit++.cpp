#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        Solution(){

        }

        int executeProgram(int n,vector<string> &arr){

            int output = 0;

            for(string &s: arr){
                int length = s.size();
                int i = 0;

                while(i<length){
                    // looping from 0 to length-1.

                    if(s[i] == '+'){
                        output++;
                        i+=2;                        
                    }
                    else if (s[i] == '-'){
                        output--;
                        i += 2;
                    }

                    else{
                        i++;
                    }
                }
            }

            return output;
        }
};

int main(){
    int n;
    cin>>n;
    cin.ignore();
    vector<string> arr;
    
    for(int i = 0; i < n; i++){
        string elem;
        getline(cin,elem);
        arr.push_back(elem);
    }

    Solution * s = new Solution();
    int ans = s->executeProgram(n,arr);
    cout<< ans << endl;

    return 0;
}