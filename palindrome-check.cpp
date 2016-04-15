#include<cstdio>
#include<iostream>

using namespace std;

int isIntPalindrome(int x)
{
	//Time Complexity : O(logx)
	//Space Complexity : O(1)
	if (x < 0)
		return 0;
	int div = 1;
	while (x / div >= 10)
	{
		div *= 10;
	}

	while (x != 0)
	{
		int l = x / div;
		int r = x % 10;
		if (l != r){
			return 0;
		}
		x = (x % div);
		x= x/10;
		div /= 100;
	}
	return 1;
}


int main()
{
	int n = 10021;
	int ans = isIntPalindrome(n);
	if(ans == 1){
		printf("%d is a palindrome",n);
	}else{
		printf("%d is not a palindrome",n);
	}
	return 0;
}
