#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
    typedef struct limits{
        int s,e;
    } limits;
void nestedForloop(int n,limits l[]){
    //n nested loops and l[] is array of start and end of each loop
    while(l[0].e > l[1].s){
        for(i=0;i<n;++i){
            printf("%d ",l[i].s);
        }
        printf("\n")
    }
}

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
    limits l[3];
    l[0].s=0;
    l[0].e=2;
    l[1].s=0;
    l[1].e=3;
    l[2].s=0;
    l[2].e=4;
    nestedForloop(3,l);
    return 0;
}
