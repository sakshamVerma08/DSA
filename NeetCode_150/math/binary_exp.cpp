#include <iostream>
using namespace std;
// Using Binary Exponentiation to calculate a^b, when b is very large.

int power(int base, int p){

	if(p==0) return 1;

	int smallAns = power(base,p/2);
	int res = smallAns * smallAns;

	return p%2==0? res : res * base;

}

int main(){

	int a1 = 2;
	int p1 = 30;
	cout<< "tc1:"<< power(a1,p1)<<endl;

	int a2 = 46340;
	int p2 = 2;
	cout<< "tc2:"<<power(a2,p2)<<endl;

	return 0;
}
