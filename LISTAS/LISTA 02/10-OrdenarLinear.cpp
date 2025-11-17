#include <bits/stdc++.h>

using namespace std;

void printVetor(int V[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", V[i]);
    cout << endl;   
}



void countingSort(int V[], int n, int min, int max){
    int m = max-min;
    int C[m+1];
    int B[n];
    for(int i=0;i<m+1;i++) C[i] = 0;
    for(int i=0;i<n;i++) B[i] = 0;
    for(int i=0;i<n;i++) C[V[i]-min]++;
    for(int i=1;i<m+1;i++) C[i] += C[i-1];
    for(int i=n-1; i>=0;i--){
        C[V[i]-min]--;
        B[C[V[i]-min]] = V[i];
    }
    for(int i=0;i<n;i++) V[i] = B[i];

}


int main(){
    
    int V[] = {7, 6, 2, 4, 1};
    countingSort(V, 5, 1, 7);
    printVetor (V, 5);
    
    
}