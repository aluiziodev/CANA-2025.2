#include <bits/stdc++.h>

using namespace std;


void printVetor(int V[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", V[i]);
    cout << endl;   
}

void parimparSort(int V[], int n){
    for(int i = 0; i<n; i+=2){
        int j = i;
        while(j>0 && V[j]<V[j-2]){
            swap(V[j], V[j-2]);
            j -= 2;
        }
    }
    for(int i = 1; i<n; i+=2){
        int j = i;
        while(j>1 && V[j]<V[j-2]){
            swap(V[j], V[j-2]);
            j -= 2;
        }
    }
}

// Complexidade: O(n^2)

int main(){
    int V[] = {3, 2, 1, 5, 6, 8, 12, 4};
    parimparSort(V, 8);
    printVetor(V, 8);
}