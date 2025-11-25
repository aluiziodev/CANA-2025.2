#include <bits/stdc++.h>

using namespace std;

void printVetor(int V[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", V[i]);
    cout << endl;   
}


// MERGESORT (RECURSIVO)



void merge(int V[], int i, int f){
    int meio = (i+f)/2;
    int n = f-i+1;
    int A[n];
    int l = 0;
    int it = i;
    int j = meio+1;
    while(it<=meio || j<=f){
        if(it>meio){
            A[l] = V[j];
            j++;
        }
        else if(j>f){
            A[l] = V[it];
            it++;
        }
        else if(V[it]>V[j]){
            A[l] = V[j];
            j++;
        }
        else{
            A[l] = V[it];
            it++;
        }
        l++;
    }
    l = 0;
    it = i;
    while(it<=f){
        V[it] = A[l];
        it++; l++;
    }


} 
// O(n) 

void mergeSort(int V[], int i, int f){
    if(i!=f){
        int meio = (i+f)/2;
        mergeSort(V, i, meio);
        mergeSort(V, meio+1, f);
        merge(V, i, f);
    }
}
// O(nlog(n))


int main(){
    
    int V[] = {7, 6, 2, 4, 1};
    mergeSort(V, 0, 4);
    printVetor (V, 5);
    
    
}
