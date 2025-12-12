#include <bits/stdc++.h>
#define Lmax 1000
#define Kmax 100

int memo[Kmax][Lmax][Lmax];

using namespace std;

void init(){
    for(int k=0; k<Kmax; k++)
        for(int l1=0; l1<Lmax; l1++)
            for(int l2=0; l2<Lmax; l2++)
                memo[k][l1][l2] = -1;
}

int balsa(int A, int B, queue<int> &fila, int k){
    if(memo[k][A][B] != -1) return memo[k][A][B];
    else{
        if(fila.empty()) return memo[k][A][B] = k;
        else{
            int carro = fila.front();
            if(carro > A && carro > B){
                return memo[k][A][B] = k;
            }
            else{
                fila.pop();
                int op1 = -1, op2 = -1;
                if(carro <= A){
                    op1 = balsa(A - carro, B, fila, k + 1);
                }
                if(carro <= B){
                    op2 = balsa(A, B - carro, fila, k + 1);
                }
                memo[k][A][B] = max(op1, op2);
                fila.push(carro);
                return memo[k][A][B];
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int L, K;
    cin >> L >> K;
    init();
    queue<int> fila;
    for(int i=0; i<K; i++){
        int carro;
        cin >> carro;
        fila.push(carro);
    }
    cout << balsa(L, L, fila, 1) << "\n";
    

    return 0;
}