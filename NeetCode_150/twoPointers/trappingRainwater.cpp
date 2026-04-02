#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
         int res=0, st=0;
         int end;

         while(st < height.size()-1){

            if(st==0 && height[st]==0){
                st++;
                continue;
            }

            end = st+1;

            while(end < height.size() && height[end] <= height[st]){
                end++;
            }

            if(end==height.size()){
                st++;
                continue;
            }

            res+=(end-st-1);
            st=end;
         }

         return res;
    }
};
