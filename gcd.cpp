#include<iostream>
#include<cstdio>

using namespace std;

int gcd(int a, int b){
	//Euclidean algorithm
	//Time Complexity : O(log(MIN(a,b)))
	//Space Complexity : 
	return (b == 0 ? a : gcd(b,a%b));
}

int main(){
	int a = 5;
	int b = 29;
	int g = gcd(a,b);
	printf("gcd(%d,%d) = %d\n",a,b,g);
	return 0;
}
