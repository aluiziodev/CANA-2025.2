#include <bits/stdc++.h>

using namespace std;


// ALGORITMO

int Y(int A[], int p, int r){
    int m = (p+r)/2;
    if(p==r) return p;
    int u = Y(A, p, m);
    int v = Y(A, m+1, r);
    if(A[u] < A[v]) return u;
    else return v;
}

// a) Simulando a execuçao

int main(){
    int V[] = {5, 6, 5, 0, 6, 8};
    cout << Y(V, 0, 5) << "\n";
}

/*
    PASSO 1: m = 2
             Y(V, 0, 2) - retorna PASSO 2
             Y(V, 3, 5) - retorna PASSO 4
             retorna o indice do menor entre V[u] e V[v], logo 3

    PASSO 2 [Y(V, 0, 2)]:
            m = 1
            Y(V, 0, 1) - retorna PASSO 3
            Y(V, 2, 2) - retorna 2
            retorna o indice do menor entre V[u] e V[v], logo 2

    PASSO 3 [Y(V, 0, 1)]
            m = 0
            u = Y(V, 0, 0)  - retorna 0
            v = Y(V, 1, 1)  - retorna 1
            retorna o indice do menor entre V[u] e V[v], logo 1

    PASSO 4 [Y(V, 3, 5)]
            m = 4
            u = Y(V, 3, 4) - retorna PASSO 5
            v = Y(V, 5, 5) - retorna 5
            retorna o indice do menor entre V[u] e V[v], logo 3
    
    PASSO 5 [Y(V, 3, 4)]
            m = 3
            u = Y(V, 3, 3) - retorna 3
            v = Y(V, 4, 4) - retorna 4
            retorna o indice do menor entre V[u] e V[v], logo 3
    
    

ra queremos provar que o algoritmo é correto para um intervalo de tamanho 
*/

/* b) Retorna o indice cuja posiçao 'e o menor valor do vetor, a partir de uma
    a partir de uma estrategia de divisao e conquista (dividindo o vetor em duas metades).
*/

/*
   c) prova no caderno
*/