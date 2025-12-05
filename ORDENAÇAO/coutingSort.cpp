#include <bits/stdc++.h>

using namespace std;

void printVetor(int V[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", V[i]);
    cout << endl;   
}

/*
COUNTING SORT
Given an array of n integers where each integer is in the range 0 to k,
sort the array in ascending order using counting sort algorithm.

*/

void countingSort(int V[], int n, int k){
    int C[k+1];
    int B[n];
    for(int i=0;i<k+1;i++) C[i] = 0;
    for(int i=0;i<n;i++) B[i] = 0;
    for(int i=0;i<n;i++) C[V[i]]++;
    for(int i=1;i<k+1;i++) C[i] += C[i-1];
    for(int i=n-1; i>=0;i--){
        C[V[i]]--;
        B[C[V[i]]] = V[i];
    }
    for(int i=0;i<n;i++) V[i] = B[i];

}
// Complexidade: O(n + k)

int main(){
    
    int V[] = {7, 6, 2, 4, 1};
    countingSort(V, 5, 7);
    printVetor (V, 5);
    
    
}