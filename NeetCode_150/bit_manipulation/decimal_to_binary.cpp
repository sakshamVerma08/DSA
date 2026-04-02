#include <iostream>
using namespace std;
#include <algorithm>
#include <string>

string decimalToBinary(int &n){
	string ans = "";

	while(n % 2 != 1){
		ans += (n/2);
		n/=2;
	}

	ans += "1";
	return reverse(ans.begin(),ans.end());

}



int main(){


	int decimal1 = 36;
	int decimal2 = 49;
	int decimal3 = 57;

	cout<<"36 = "<< decimalToBinary(36)<<endl;
	cout<<"49 = "<< decimalToBinary(49)<<endl;
	cout<<"57 = "<< decimalToBinary(57)<<endl;

	return 0;

}
