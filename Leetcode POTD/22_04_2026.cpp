#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
Solution(){

}


    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        unordered_set<string> spp;
        // storing all dict words in the set, for constant lookup.

        for(int i = 0; i < dictionary.size();i++){
            // looping from i = 0 to dict.size()-1 (inclusive).
            spp.insert(dictionary[i]);
        }

        for(int i = 0; i < queries.size(); i++){
            // looping from 0 to queries.size()-1 (inclusive). left->right.
            string &word = queries[i];

            // Loop for words in dictionary.
            for(auto it = spp.begin();it!=spp.end();it++){
                auto &target = *it;
                if(target==word){
                    res.push_back(word);
                    break;
                }

                int cnt = 0;
                for(int i = 0; i < target.size(); i++){
                    if(word[i] != target[i])
                        cnt++;
                }

                if(cnt<=2){
                    res.push_back(word);
                    break;
                }

            }
        }

        return res;

    }

	
};

int main(){

	vector<string> queries,dictionary;
	Solution* s = new Solution();
	int size1,size2;
	cin>>size1;
	cin.ignore();

	string words;
	getline(cin,words);
	stringstream ss(words);
	string w;
	while(ss >> w){
		queries.push_back(w);
	}
	string dict;
	cin>>size2;
	cin.ignore();

	getline(cin,dict);
	stringstream ss2(dict);
	string w2;
	while(ss2 >> w2){

		dictionary.push_back(w2);
	}

	auto ans = s->twoEditWords(queries,dictionary);
	
	for(const string &s: ans){
		cout<< s << ", ";
	}
	cout<< endl;

	return 0;

}
