#include<iostream>
#include<cstdio>

using namespace std;

int gcdExtended(int a, int b, int *x, int *y){
	//Extended Euclidean algorithm : a*x + b*y = gcd(a,b)
	//Time Complexity : O(log(MIN(a,b)))
	//Space Complexity : 
	
	//Base Case
	if(a == 0){
		*x = 0;
		*y = 1;
		return b;
	}
	
	int x1,y1;
	int gcd = gcdExtended(b%a, a, &x1, &y1);
	
	//Update x and y using recursive call
	*x = y1 - (b/a)*x1;
	*y = x1;
	
	return gcd;	
}
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

int inverseByExtendedEuclid(int a, int m){
	//work only if gcd(a,m) = 1 (co-prime)
	//Time Complexity : 
	//Space Complexity : 
	
	int x,y;
	gcdExtended(a,m,&x,&y);
	
	//Handle the -ve value  and range[0,m) of x
	int res = (x%m + m) % m;
	return res;
}

int inverseByFermatLittleTheorem(int a, int m){
	//m must be prime
	// a^(m-1) = 1(mod m) --->   a^(m-2) = a^-1 (mod m)
	//Time Complexity : 
	//Space Complexity :
	 
	//According fermat's little theorem Just calculate a^(m-2)%m
	int mi = modularPower(a, m-2, m);
	return mi;
}

int inverseByEulerTheorem(int a, int m){
	//Generalized form of Fermat's theorem | m may not be prime
}

int main(){
	int a = 5;
	int m = 29;
	int mi;
	mi = inverseByExtendedEuclid(a,m);
	printf("Multiplicative Inverse of (a = %d, m = %d) By Extended Euclid is %d\n",a,m,mi);
	mi = inverseByFermatLittleTheorem(a,m);
	printf("Multiplicative Inverse of (a = %d, m = %d) By Fermat's Little Theorem is %d\n",a,m,mi);
	return 0;
}
