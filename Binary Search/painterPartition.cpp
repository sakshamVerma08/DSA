#include <bits/stdc++.h>
using namespace std;


bool isPossible(vector<int> &boards, int maxDistance, int k ){

    int currentDistance=0, fenceCount=1;

    for(int i = 0; i< boards.size();i++){

        if(currentDistance + boards[i] <= maxDistance) currentDistance+= boards[i];

        else{
            fenceCount++;
            currentDistance = boards[i];
        }
    }


    if(fenceCount<=k) return true;
    return false;
}

int findLargestMinDistance(vector<int> &boards, int k)
{

    

    int low = *(max_element(boards.begin(),boards.end()));
    int high = 0;

    for(auto &elem: boards){

        high += elem;
    }


    while(high >= low){

        int mid = low + (high-low)/2;

        if(isPossible(boards,mid,k)) high=mid-1;

        else low = mid + 1;
    }


    return low;
    
}

int main(){

	vector<int> b1 = {10,20,30,40};
	int k1 = 2;

	cout<< "tc1 = "<< findLargestMinDistance(b1,k1)<<endl;



	return 0;

}
