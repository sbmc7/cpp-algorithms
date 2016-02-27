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

int main(){
	int a = 5;
	int b = 29;
	int x,y;
	int g = gcdExtended(a,b,&x,&y);
	printf("gcd(%d,%d) = %d | x=%d, y=%d\n",a,b,g,x,y);
	return 0;
}
