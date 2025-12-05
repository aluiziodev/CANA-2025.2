#include <bits/stdc++.h>

using namespace std;

void printVetor(int V[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", V[i]);
    cout << endl;   
}

/*
RADIX SORT
Given an array of n integers where each integer is in the range 0 to d digits,
sort the array in ascending order using radix sort algorithm.
*/

void coutingSort(int V[], int bit, int n){
    int C[10];
    int B[n];
    for(int i=0;i<10;i++) C[i] = 0;
    for(int i=0;i<n;i++) B[i] = 0;
    for(int i=0;i<n;i++) C[(V[i] / bit) % 10]++;
    for(int i=1;i<10;i++) C[i] += C[i-1];
    for(int i=n-1; i>=0;i--){
        C[(V[i] / bit) % 10]--;
        B[C[(V[i] / bit) % 10]] = V[i];
    }
    for(int i=0;i<n;i++) V[i] = B[i];
}

void radixSort(int V[], int n, int d){
    int bit = 1;
    while(bit < pow(10, d)){
        coutingSort(V, bit, n);
        bit *= 10;
    }
}
// Complexidade: O(d*n)


int main(){
    
    int V[] = {44, 1234, 55, 399, 267, 903, 657};
    radixSort(V, 7, 4);
    printVetor (V, 7);
    
    
}

