#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>

using namespace std;

vector<int> sieveOfEratosthenes(int n){
	//Sieve of Eratosthenes |
	//Time Complexity :
	//Space Complexity :
	
	bool flag[n+1];
	memset(flag, true, sizeof(flag));
	//0 and 1 is not considered as prime number
	flag[0] = false;
	flag[1] = false;
	
	for(int p=2; (p*p)<=n; ++p){
		if(flag[p] == true){
			for(int i=(2*p); i<=n; i+=p){ 
				//mark all multiplier of p as false
				flag[i] = false;
			}	
		}
	}
	vector<int> primes;
	for(int i=0; i<=n; ++i){
		if(flag[i] == true){
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
