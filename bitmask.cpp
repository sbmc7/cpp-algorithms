#incluce<cstdio>
#include<iostream>

using namespace std;

int isBitSet(int x, int bit){
    return ((x >> bit) & 1);
}

int unsetBit(int x, int bit){
    return (x & ~(1 << bit))
}

int main(){
    /*Bit mask is a very powerfull paradigm to represent set by small data sets
    by using bits manipulations technique.
    Generally we count bit numbering from right to left.
    for o to (n-1) use x=(1<<n)
    */
    return 0;
}
