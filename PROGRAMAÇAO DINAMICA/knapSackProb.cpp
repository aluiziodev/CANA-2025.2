#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;


/* 0/1 Knapsack Problem
Given weights and values of n items, put these items in a knapsack of capacity W 
to get the maximum total value in the knapsack. In other words, 
given two integer arrays val[0..n-1] and wt[0..n-1] which represent 
values and weights associated with n items respectively. 
Also given an integer W which represents knapsack capacity, 
find out the maximum value subset of val[] such that sum of the weights of 
this subset is smaller than or equal to W.
*/


int PD[500][500];
void init(){
    for(int i =0; i<500; i++){
        for (int j=0; j<500; j++){
            PD[i][j] = -1;
        }
    }
}

vi pesos;
vi valor;

int backpackProblem(int w, int i){
    if(PD[w][i]!= -1){
        return PD[w][i];
    }
    else if(w==0 || i==0){
        return PD[w][i] = 0;
    }
    else if(pesos[i-1] > w){
        return PD[w][i] = backpackProblem(w, i -1);
    }
    else{
        return PD[w][i] = max(backpackProblem(w, i-1), valor[i-1] + backpackProblem(w - pesos[i-1], i-1));
    }
}

int main(){
    init();
    int n; cin >> n;
    int aux, aux2;
    pesos.assign(n, 0); valor.assign(n, 0);
    for(int i=0; i<n; i++) {
        cin >> aux >> aux2;
        pesos[i] = aux;
        valor[i] = aux2;
    }
    int w; cin >> w;
    cout << backpackProblem(w, n); 
}
