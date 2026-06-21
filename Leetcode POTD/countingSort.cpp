#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        Solution(){

        }

        vector<int> countingSort(vector<int> &arr){
            int maxElement;
            int n = arr.size();

            auto max_it = std::max_element(arr.begin(),arr.end());
            maxElement= *(max_it);

            vector<int> countArray(maxElement+1,0);
            
            // Create the Frequency / Count Array.
            for(int i = 0; i < n; i++){
                countArray[arr[i]]++;
            }

            // Create the Prefix array from the frequency array.
            for(int i = 1; i <= maxElement; i++){
                countArray[i] += countArray[i-1];
            }

            vector<int> ans(n);

            for(int i = n-1; i >= 0; i--){
                ans[countArray[arr[i]]-1] = arr[i];
                countArray[arr[i]]--;
            }
            return ans;

        }
};

int main(){

    string elem;
    vector<int> arr;
    int num;
    getline(cin , elem);

    stringstream ss(elem);

    while(ss>>num){
        arr.emplace_back(num);
    }

    Solution * s = new Solution();
    auto ans = s->countingSort(arr);

    for(const int &n: ans){
        cout<< n << " ";
    }

    return 0;
}
