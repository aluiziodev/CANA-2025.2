#include <bits/stdc++.h>

using namespace std;

void printVetor(int V[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", V[i]);
    cout << endl;   
}

// ORDENAÇAO PELO MENOR

void ordenaMenor(int V[], int n){
    for(int i =0; i<n; i++){
        int menor = i;
        for(int j = i+1; j<n; j++){
            if(V[menor]>V[j]){
                menor = j;
            }
        }
        int aux = V[i];
        V[i] = V[menor];
        V[menor] = aux;
    }
}

// Complexidade:  O(N^2)


// BUBBLE SORT


void bubbleSort(int V[], int n){
    for(int i=0; i<n;i++){
        for(int j = n-1; j>i; j--){
            if(V[j]<V[j-1]){
                swap(V[j], V[j-1]);
            }
        }
    }
}

// Complexidade:  O(N^2)


// INSERTIONSORT

void insertionSort(int V[], int n){
    for(int i = 0; i<n; i++){
        int j = i;
        while(j>0 && V[j]<V[j-1]){
            swap(V[j], V[j-1]);
            j--;
        }
    }
}

// Complexidade:  O(N^2)






int main(){
    int V[] = {7, 6, 2, 4, 1};
    insertionSort(V, 5);
    printVetor (V, 5);

}
