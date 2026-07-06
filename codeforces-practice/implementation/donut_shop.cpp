#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution{
    ll a, b, c;

    public:
        Solution(ll a, ll b, ll c){
            this->a=a, this->b=b,  this->c=c;
        }

        void printValue(){
            ll out1,out2;
            
                // Check whether buying 'x' donuts from shop1 is already equal to buying one pack from shop2. Because if 
                // such is the case, then when we go to buy higher quantity from shop1, it exceeds the price compared to shop2.
                // so we take out1 = -1;
                if(a >= c){
                    out1 = -1;
                }
                else
                    out1 = 1;

                // for the second output value , if 'd' < b, then also we will have to buy one box of price 'c'. So we can compare if the price of buying d = 1 or 'b' pack is less or not. If for a single pack also it's not less that buying 'd' donuts from shop1, then no value exists, so out2 = -1.
                
                // Otherwise, we buy ceil(d/b) packs.
                if(c<a*b)
                    out2=b;
                else
                    out2=-1;

                cout<< out1<<" "<< out2<<endl;
        }

};

int main(){
    ll t;
    cin>>t;
    cin.ignore();
    ll val;
    string elem;
    
    for (ll i = 0; i < t; i++) {
    ll a, b, c;
    cin >> a >> b >> c;

    Solution s(a, b, c);
    s.printValue();
}

    return 0;
}