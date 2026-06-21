#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
        int n,m;
        Solution(int n, int m){
            this->n=n;
            this->m=m;
        }


        void drawSnake(){
            
            bool flag=true;
            for(int i = 0; i< n; i++){
                
                if(i%2==0){
                    cout<< string(m,'#')<<"\n";
                }
                else{

                    string s(m,'.');

                    if(flag){
                        s[m-1] = '#';
                        
                    }
                    else{
                        s[0] ='#';
                    }

                    for(int i = 0; i < m; i++){
                        cout<< s[i]; 
                    }
                    cout<<"\n";
                    flag=!flag;
                }

            }
        }

        
};

int main(){

    int n,m;
    cin>>n >> m;

    Solution* s = new Solution(n,m);
    s->drawSnake();

    return 0;
}