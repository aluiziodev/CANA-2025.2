#include <bits/stdc++.h>

using namespace std;

void printVetor(int V[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", V[i]);
    cout << endl;   
}


void coutingSort(int V[], int bit, int n){
    int C[n];
    int B[n];
    for(int i=0;i<n;i++) C[i] = 0;
    for(int i=0;i<n;i++) B[i] = 0;
    for(int i=0;i<n;i++) C[(V[i] / bit) % n]++;
    for(int i=1;i<n;i++) C[i] += C[i-1];
    for(int i=n-1; i>=0;i--){
        C[(V[i] / bit) % n]--;
        B[C[(V[i] / bit) % n]] = V[i];
    }
    for(int i=0;i<n;i++) V[i] = B[i];
}

void radixSort(int V[], int n){
    int bit = 1;
    while(bit < pow(n, 3)){
        coutingSort(V, bit, n);
        bit *= n;
    }
}


int main(){
    
    int V[] = {231, 300, 23, 12, 56, 123, 89}; // DADO N=7, APENAS VALORES ENTRE 7^3 - 1 = 342
    radixSort(V, 7);
    printVetor (V, 7);
    
    
}
