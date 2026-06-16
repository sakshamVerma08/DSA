#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        Solution(){

        }

        int makeMatrixBeautiful(vector<vector<int>> &matrix){
            int output=0;

            pair<int,int> pos; 

            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    if(matrix[i][j] == 1){
                        pos.first = i;
                        pos.second=j;
                        break;
                    }
                }
            }

            // check whether there's a need to wrap around to swap with zero.
            // Keep in mind that these are the extra swaps that are required to bring the only number one in 0th row/ 0th column.
            // And we will have to add more swaps to this to bring the only number one to (2,2).
            output = abs(2-pos.first) + abs(2-pos.second);           

            return output;
        

        }

};


int main(){
    vector<vector<int>> matrix;
    string elements;
    for(int i = 0; i < 5; i++){

        getline(cin, elements);
        stringstream ss(elements);
        vector<int> row;
        int num;

        while(ss>>num){
            row.push_back(num);
        }

        matrix.push_back(row);
    }

    Solution *s = new Solution();
    cout<< s->makeMatrixBeautiful(matrix)<<endl;

    return 0;
}