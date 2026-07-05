#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	Solution(){}

	int return_total_faces(vector<string> &arr){
		int total = 0;
		unordered_map<string,int> mpp;
		mpp["Tetrahedron"] = 4;
		mpp["Cube"] = 6;
		mpp["Octahedron"] = 8;
		mpp["Dodecahedron"] = 12;
		mpp["Icosahedron"] = 20;

		for(const auto &s: arr){
			total+=mpp[s];
		}
		return total;
	}
};

int main(){
	Solution* s = new Solution();
	int n;
	cin>>n;
	cin.ignore();

	vector<string> arr;
	for(int i =0;i<n;i++){
		string str;
		cin>>str;
		arr.emplace_back(str);
	}

	cout<<s->return_total_faces(arr)<<endl;
	return 0;

}
