#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void Pattern1()
    { /*  -->   * * * * *
       * * * * *
       * * * * *
       * * * * *
       * * * * *
       */

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << " * ";
            }

            cout << '\n';
        }
    }

    void Pattern2(){
        /*  
        *
        * * 
        * * * 
        * * * * 
        * * * * * 
        
        */

       for (int i = 0; i < 5; i ++){
        for (int j = 0; j <=i; j ++){
            cout<< " * ";
        }

        cout<< endl;
       }
    }

    void Pattern3(){

        for (int i = 0; i < 5; i ++){
            for (int j = 0; j <=i; j ++){
                cout<<(j+1);
            }

            cout<<endl;
        }
    }

    void Pattern4(){
        for (int i = 0; i < 5; i ++){
            
        }
    }

};

int main()
{

    Solution s;
    s.Pattern3();
    return 0;
}