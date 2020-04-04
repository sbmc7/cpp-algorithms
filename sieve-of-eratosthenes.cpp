#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>

using namespace std;

vector<int> sieveOfEratosthenes(int n){
	//Sieve of Eratosthenes
	//Time Complexity : O(n)
	//Space Complexity : O(n)
	
	bool flag[n+1];
	memset(flag, true, sizeof(flag));
	for(int p=2; (p*p)<=n; ++p){
		if(flag[p]){
			for(int i=(2*p); i<=n; i+=p){ 
				//mark all multiplier of p as false
				flag[i] = false;
			}	
		}
	}
	vector<int> primes;
	for(int i=2; i<=n; ++i){
		if(flag[i]){
			primes.push_back(i);
		}
	}
	return primes;
}

int main(){
	int n = 101;
	vector<int> primes;
	primes = sieveOfEratosthenes(n);
	printf("There are %d primes below %d.\n",primes.size(),n);
	for(int i=0; i<primes.size(); ++i){
		printf("%d ",primes[i]);
	}
	printf("\n");
	return 0;
}
