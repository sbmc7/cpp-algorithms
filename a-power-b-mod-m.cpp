#include<iostream>
#include<cstdio>

using namespace std;

int modularPower(int base, int exp, int mod){
	// Time Complexity
	// Space Complexity
	int result = 1;
	base %= mod; //Take mod of base
	
	while(exp > 0){
		if(exp & 1){ // If exp is odd
			result = (result * base) % mod;
		}
		base = (base * base) % mod;
		exp = exp >> 1; //Divide the exp by 2
	}
	return result;
}

int main(){
	int b = 6;
	int e = 3;
	int m = 100;
	int ans = modularPower(b,e,m);
	printf("modularPower(%d,%d,%d) = %d\n",b,e,m,ans);
	return 0;
}
