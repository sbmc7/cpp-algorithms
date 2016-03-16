#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

void printBasicCombinations(){
   //print all combinations for n=10 and r=3
   for(int i=1; i<=8; ++i){
    for(int j=i+1; j<=9; ++j){
        for(int k=j+1; k<=10; ++k){
            printf("%02d %02d %02d\n",i,j,k);
        }
    }
   }
}

void combinationsByPermutation(char s[],int n,int r){

}


int main(){
    int n=10,r=3;
    printBasicCombinations();
    return 0;
}
