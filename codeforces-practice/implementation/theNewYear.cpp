#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int x1,x2,x3;

        Solution(int x1, int x2, int x3){
            this->x1=x1, this->x2=x2, this->x3=x3;
        }

        int returnMinDist(){

            // take x1 as target.
            int dist1,dist2,dist3;
            dist1 = abs(x2-x1) + abs(x3-x1);
            dist2 = abs(x1-x2) + abs(x3-x2);
            dist3 = abs(x3-x1) + abs(x3-x2);

            return min(min(dist1,dist2),dist3);
        }
};

int main(){
    string line;
    getline(cin,line);

    stringstream ss(line);

    vector<int> arr;
    int num;
    while(ss>>num){
        arr.push_back(num);
    }
    Solution* s = new Solution(arr[0],arr[1],arr[2]);

    cout<< s->returnMinDist()<<endl;
    return 0;
}