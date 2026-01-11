#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> Matriz;
typedef pair<int,int> pii;



// alg 1 (recursivo)
int alg1(int n){
    if (n>=0 && n<=10) return n; 
    else{
        int resp = 7*n;
        for(int k =0; k<=5; k++){
            resp += alg1((n/2) + k);
        }

        return resp;
    }
}
// Complexidade: caso 1 teorema mestre -> O(n^log2(6)) ~ O(n^2.585)


// alg 2 (Programação Dinâmica - iterativo)

int alg2(int n){
    int memo[n+1];
    for(int i = 0 ;i<=10;i++) memo[i] = i;
    for(int i = 11; i<=n; i++){
        int resp = 7*i;
        for(int k =0; k<=5; k++){
            resp += memo[(i/2) + k];
        }
        memo[i] = resp;
    }
    return memo[n];
    
}
// Complexidade: O(n)

int memo[1000005];
void init_memo(){
    memset(memo, -1, sizeof(memo));
}
// alg 3 (Programação Dinâmica - memoization)
int alg3(int n){
    if(memo[n] != -1) return memo[n];
    if (n>=0 && n<=10) return memo[n] = n; 
    else{
        int resp = 7*n;
        for(int k =0; k<=5; k++){
            resp += alg3((n/2) + k);
        }

        return memo[n] = resp;
    }
}
// Complexidade: O(n)