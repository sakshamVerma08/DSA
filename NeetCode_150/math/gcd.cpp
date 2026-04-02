#include <iostream>
using namespace std;


int gcd(int a, int b){

	if(b%a==0)
		return a;

	int rem = b%a;
	return gcd(rem,a);


}


int main(){

	cout<< gcd(10,5)<<endl;
	cout<<gcd(12,8)<<endl;
	cout<<gcd(12,18)<<endl;
	cout<<gcd(7,3)<<endl;

	return 0;

}
