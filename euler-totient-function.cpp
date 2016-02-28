#include<iostream>
#include<cstdio>

using namespace std;

int phi(int n){
	//Euler Theroem | Euler's Totient Function
	//phi(n) = n *(1-1/p1)*(1- wheher p is a prime factor of n
	//Time Complexity : 
	//Space Complexity : 
	int result = n;
	for(int p=2; p*p<=n; ++p){
		if(n%p == 0){
			while(n%p == 0){
				n /= p;
			}
			
			result -= (result/p);
		}
	}
	
	if(n > 1){
		result -= (result/n);
	}
	
	return result;
}

int main(){
	int n = 8;
	printf("phi(%d) =  %d\n",n,phi(n));
	return 0;
}
