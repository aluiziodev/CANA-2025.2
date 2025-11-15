#include <bits/stdc++.h>

using namespace std;

void printVetor(int V[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", V[i]);
    cout << endl;   
}



void countingSort(int V[], int n, int k){
    int C[k+1];
    for(int i=0;i<k+1;i++) C[i] = 0;
    for(int i=0;i<n;i++) C[V[i]]++;
    int it = 0;
    int i = 0;
    while(it<n && i<k+1){ //EXISTEM DOIS LOOPS, POREM O PROGRAMA FARA MAX(K+1, N) Operaçoes
        while(C[i]!=0){
            V[it] = i;
            C[i]--;
            it++;
        }
        i++;
    }
}


int main(){
    
    int V[] = {7, 6, 2, 4, 1};
    countingSort(V, 5, 7);
    printVetor (V, 5);
    
    
}