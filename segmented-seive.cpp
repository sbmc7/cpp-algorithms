#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

vector<int> simpleSieve(int n){
	//Sieve of Eratosthenes |
	//Time Complexity :
	//Space Complexity : O(n)
	
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

vector< vector<int> > segmentedSieve(int n){
	//Segmented Sieve
	//Time Complexity :
	//Space Complexity : O(sqrt(n))
	int limit = floor(sqrt(n))+1;
	vector< vector<int> > primes; // [][] array form primes for each segment
	vector<int> firstSegPrime; // temp [] for a single segment
	firstSegPrime = simpleSieve((limit));
	/*printf("Sieve for %d to %d\n",1,limit);
	for(int i=0; i<firstSegPrime.size(); ++i){
		printf("%d ",firstSegPrime[i]);
	}
	printf("\n");*/
	primes.push_back(firstSegPrime);
	
	int low = limit;
	int high = limit<<1;
	
	while(low < n){
		//printf("Sieve for %d to %d\n",low+1,high);
		bool mark[limit+1];
		memset(mark, true, sizeof(mark));
		for(int i=0; i<firstSegPrime.size(); ++i){
			// Find the minimum number in [low..high] that is
       	    // a multiple of prime[i] (divisible by prime[i])
			int lowMin = floor((low/firstSegPrime[i]) * firstSegPrime[i]);
			if(lowMin < low){
				lowMin += firstSegPrime[i]; // In case if lowLimit becomes 0
			}
			for(int j=lowMin; j<high; j+=firstSegPrime[i]){
				mark[j-low] = false;
			}	
		}
		
		// Numbers which are not marked as false are prime
		vector<int> temp;
		for(int i=low; i<high; ++i){
			if(mark[i-low] == true){
				temp.push_back(i);
				//printf("%d ",i);
			}
		}
		//printf("\n");
		
		primes.push_back(temp);
		
		low += limit;
		high += limit;
        if(high > n){
        	high = n;
		}
	}
	
	return primes;
}

int main(){
	int n = 100;
	vector< vector<int> > primes;
	primes = segmentedSieve(n);
	printf("Here are primes below %d.\n",n);
	for(int i=0; i<primes.size(); ++i){
		for(int j=0; j<primes[i].size(); ++j){
			printf("%d ",primes[i][j]);
		}
		printf("\n");
	}
	return 0;
}
