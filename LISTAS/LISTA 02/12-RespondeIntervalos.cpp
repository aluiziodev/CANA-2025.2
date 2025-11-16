#include <bits/stdc++.h>

using namespace std;

void printVetor(int V[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", V[i]);
    cout << endl;   
}


int C[1000000]; //ARRAY DE PRE PROCESSAMENTO DECLARADO DE FORMA GLOBAL
void preProcessamento(int V[], int n, int k){
    for(int i=0;i<k+1;i++) C[i] = 0;
    for(int i=0;i<n;i++) C[V[i]]++;
    for(int i=1;i<k+1;i++) C[i] += C[i-1];

}

int consulta(int a, int b){
    if(a==0) return C[b];
    else return C[b] - C[a-1];
}


int main(){
    int V[] = {1, 6, 7, 2, 1, 4, 3, 9, 10, 2, 4, 6, 12, 14, 20};
    int n = sizeof(V)/sizeof(V[0]);
    preProcessamento(V, n, 20);
    

    // TESTE DE INTERVALO
    // TESTE 1) a = 0, b = 6
    cout << "Teste 1)\n" << consulta(0, 6) << endl; // R = 9
    // TESTE 2) a = 19, b = 20
    cout << "Teste 2)\n" << consulta(19, 20) << endl; // R = 1
    // TESTE 3) a = 5, b = 10
    cout << "Teste 3)\n" << consulta(5, 10) << endl; // R = 4
    
}