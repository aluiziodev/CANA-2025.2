#include <bits/stdc++.h>

using namespace std;

void printVetor(int V[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", V[i]);
    cout << endl;   
}

/*
QUICK SORT
Given an array, sort the array in ascending order using quick sort algorithm.

*/


int particiona(int V[], int i, int f, int pivo){
    int it = i-1;
    int j = i;
    while(j<=f){
        if(V[j]<=pivo){
            it++;
            swap(V[it], V[j]);
        }
        j++;
    }
    return it;
}


void quickSort(int V[], int i, int f){
    if(i<f){
        int pivot = V[f];
        int p = particiona(V, i, f, pivot);
        quickSort(V, i, p-1);
        quickSort(V, p+1, f);
    }
}
// Complexidade: O(n log n) no caso médio e O(n^2) no pior caso

int main(){
    
    int V[] = {7, 6, 2, 4, 1};
    quickSort(V, 0, 4);
    printVetor (V, 5);
    
    
}