#include<iostream>
#include<cstdio>
#include<cstdlib>

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

bool noobTest(int n){
    if (n <= 1){
    	return false;
    }
    if (n <= 3){
    	return true;	
	}
 
    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0){
    	return false;
	}
	
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0){
			return false;        	
		}
		
    return true;
}

bool proTest(int n, int k){
	// Algorithm : Fermat's Little Theorem
	// If n is a prime number, then for every a, 1 <= a < n,
	// a^(n-1) % n = 1
	// Time : O(k*log(n))
	// Space : 
	if(n<=1 || n==4){
		return false;
	}
	
	if(n<=3){
		return true;
	}
	
	while(k > 0){
	   // Pick a random number in [2..n-2]        
       int a = 2 + rand()%(n-4);  
 
       // Fermat's little theorem
       if (modularPower(a, n-1, n) != 1){
       		return false;
	   } 
       k--;
	}
	
	return true;
}

int main(){
	int n = 101;
	int k = 50;
	printf("noobTest(%d) = %s\n",n,noobTest(n)?"true":"false");
	printf("proTest(%d) = %s\n",n,proTest(n,k)?"true":"false");
	return 0;
}
