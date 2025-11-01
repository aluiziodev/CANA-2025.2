#include <bits/stdc++.h>

using namespace std;

int pai(int i){
    return ceil(i/2);
}

int fEsq(int i){
    return 2*i +1;
}

int fDir(int i){
    return 2*i + 2;
}


void printVetor(int V[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", V[i]);
    cout << endl;   
}

// HEAPSORT


void descer(int V[], int n, int i){
    int j = fEsq(i);
    if(j<=n-1){
        if(j<n-1){
            if(V[j]<V[j+1]) j++;
        }
        if(V[i]<V[j]){
            swap(V[i], V[j]);
            descer(V, n, j);
        }
    }
}
// Complexidade = O(Log(n))

void constroiHeap(int V[], int n){
    for(int i = n/2; i>=0; i--){
        descer(V,n, i);
    }
} 
// Complexidade = O(n)

void heapSort(int V[], int n){
    constroiHeap(V, n);
    int m = n-1;
    while(m>0){
        swap(V[0], V[m]);
        m--;
        descer(V, m, 0);
    }
}
// Complexidade = O(Log(n)*n)

int main(){
    int V[] = {7, 6, 2, 4, 1};
    heapSort(V, 5);
    printVetor (V, 5);

}







