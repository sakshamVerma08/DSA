#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int n,k,l,c,d,p,nl,np;
        Solution(int n, int k, int l, int c, int d, int p, int nl, int np){
            this->n=n;
            this->k=k;
            this->l=l;
            this->c=c;
            this->d=d;
            this->p=p;
            this->nl=nl;
            this->np=np;

        }

        int returnToast(){ 
            int totalDrink = (k*l);
            totalDrink/=(n*nl);

            int totalLimes = c*d;
            totalLimes/=n;

            int totalSalt = p;
            totalSalt/=(n*np);

            return min(min(totalDrink,totalSalt),totalLimes);


        }
};

int main(){

    string elem;

    getline(cin,elem);
    stringstream ss(elem);
    vector<int> arr;
    int num;

    while(ss>>num){
        arr.push_back(num);
    }

    Solution* s = new Solution(arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7]);
    cout<<s->returnToast()<<endl;

    return 0;
}