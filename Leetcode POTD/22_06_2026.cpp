#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	Solution(){

	}
    int maxNumberOfBalloons(string text) {
        if(text.size()==1)
            return 0;

        unordered_map<char,int> singleRequired;
        unordered_map<char,int> doubleRequired;
        int n =text.size();

        for(int i =0; i<n; i++){
            if(text[i] == 'b' || text[i] == 'a' || text[i]=='n'){
                singleRequired[text[i]]++;
            }
            else if (text[i] == 'l' || text[i] == 'o'){
                doubleRequired[text[i]]++;
            }
        }


        if(singleRequired.count('b')==0 || singleRequired.count('a')==0|| singleRequired.count('n')==0 || doubleRequired.count('l')==0 || doubleRequired.count('o')==0)
            return 0;


        int minVal=INT_MAX;

        for(auto it = doubleRequired.begin(); it!= doubleRequired.end(); it++){
            if(it->second< minVal)
                minVal = it->second;
        }

        minVal/=2;

        int minVal2 = INT_MAX;
        for(auto it = singleRequired.begin(); it!=singleRequired.end(); it++){
            if(it->second < minVal2)
                minVal2=it->second;
        }

        return min(minVal,minVal2);

    }
};


int main(){

	string s;
	cin>> s;
	Solution* obj = new Solution();
	cout<<"Ans = "<< obj->maxNumberOfBalloons(s)<<endl;

	return 0;

}
