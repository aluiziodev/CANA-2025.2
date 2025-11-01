#include <bits/stdc++.h>

using namespace std;


int buscaLinear(int V[], int n, int i, int target){
    if(i>=n) return n+1;
    else if(V[i]==target) return i;
    else return buscaLinear(V,n,i+1, target);
    
}
// Complexidade: O(n)


/* CORRETUDE

LEMA: buscaLinear(V, k, i) retorna um valor i tal que:

se k pertence a V, entao A[i] 'e a primeira ocorrencia de k em V.
se k nao pertence a V, i = n+1.

PROVA (INDUÇAO EM i):

BASE:

se i >= n, entao i pecorreu todo o vetor ja que V{0, ..., n-1}, e retorna n+1.
caso contrario, ou V[i]==k e sera retornado i, 
ou sera chamada a funçao buscaLinear(V, k, i+1), 
que sera chamada ate V[i]==k (retorna i) ou i>=n (retorna n+1).

PASSO:

seja a HI: a funçao buscaLinear funciona para i+1, retornando i+1 se V[i+1]==k ou 
n+1 se i+1>=n.
ao chamarmos buscaLinear(V, k, i), temos:
i, se V[i]==k. correto
n+1, se i>= n. correto
ou buscaLinear(V, k, i+1), que pela HI, esta correta!

logo, buscaLinear funciona!







*/