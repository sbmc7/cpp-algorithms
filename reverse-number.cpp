#include<cstdio>
#include<iostream>

using namespace std;

int reverseInt(int num){
        //Need to check of the overflow of reversed number
        //Time Complexity : O(logn)
        //Space Complexity : O(1)
        if(num < 0){
                return 0;
        }
        int rev = 0;
        while (num != 0)
        {
                rev = rev * 10 + num % 10;
                num /= 10;
        }
        return rev;
}


int main(){
        int n = 92343;
        int ans = reverseInt(n);
        printf("Reversed number of %d is %d\n",n,ans);
        return 0;
}

