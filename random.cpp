#include<cstdio>
#include<iostream>
#include<cstdlib>

using namespace std;

int randomInRange(int low, int high){
    //Return a random number between low and high both inclusive
    int diff = high - low + 1;
    srand(time(NULL));
    return (low + (rand()%diff));
}

int main(){
    int low = 123;
    int high = 456;
    int r = randomInRange(low,high);
    printf("Random number between %d and %d is : %d\n",low,high,r);
    return 0;
}
