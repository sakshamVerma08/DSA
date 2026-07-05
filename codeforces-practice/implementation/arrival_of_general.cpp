#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        Solution(){

        }

        int returnMin(vector<int> &arr){
            auto max_it = max_element(arr.begin(),arr.end());
            auto min_it = min_element(arr.begin(),arr.end());
            int n = arr.size();

            int max_elem = *max_it;
            int min_elem = *min_it;

            int max_pos = 0, min_pos=0;

            // Find out the position of an element whose value == max_element and is closest to 0th index.
            for(int i = 0; i < n; i++){
                if(arr[i] == max_elem){
                    max_pos=i;
                    break;
                }
            }
            
            // Find out the position of an element whose value == min_element and is closest to (n-1)th index.
            for(int i = n-1; i>=0;i--){
                if(arr[i] == min_elem){
                    min_pos=i;
                    break;
                }
            }

            int totalTime=0;
            
            if(max_pos > min_pos){
                totalTime += (max_pos) + (n-1-min_pos - 1);
            }
            else{
                totalTime = max_pos + (n-1)-min_pos;
            }

            return totalTime;
        }


};

int main(){
    int n;
    cin>>n;
    cin.ignore();
    vector<int> arr;
    int number;
    
    string elem;
    getline(cin,elem);
    stringstream ss(elem);    

    while(ss >> number){
        arr.emplace_back(number);
    }
    Solution* s = new Solution();
    cout<< s->returnMin(arr)<<endl;

    return 0;
}