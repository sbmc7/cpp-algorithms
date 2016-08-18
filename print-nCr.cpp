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

void printCombination(int *flag, int *a, int n){
    for(int i=0; i<n; ++i){
        if(flag[i]){
            printf("%02d ",a[i]);
        }
    }
    printf("\n");
}

void combinationsByPermutation(int a[],int n,int r){
    int flag[] = {1,1,1,0,0,0,0,0,0,0};
    do{
        printCombination(flag,a,n);
    }while(prev_permutation(flag,flag+10));
}

void combinationsByRecursion(){

}


int main(){
    int n=10,r=3;
    //printBasicCombinations();
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    combinationsByPermutation(a,10,3);
    return 0;
}
