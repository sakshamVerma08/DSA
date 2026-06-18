#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int hour,minutes;
    
    // each movement from 12 to 1,1 to 2 causes 30 degree increment.
        
    Solution(int hour, int minutes){
        this->hour=hour;
        this->minutes=minutes;
    }


    double angleClock() {
        double x = hour + minutes / 60.0;
        double diff = fmod(11.0 * x, 12.0);
        return min(diff, 12.0 - diff) * 30.0;
    }
};

int main(){
    int hour,minutes;
    cin>>hour>>minutes;

    Solution* s = new Solution(hour,minutes);
    cout<<"Ans = "<< s->angleClock()<<endl;

    return 0;
}