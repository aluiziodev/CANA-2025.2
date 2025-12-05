#include <bits/stdc++.h>

using namespace std;

/*
K-th Smallest Element - Median of Medians Algorithm
Given an unsorted array, find the k-th smallest element in the array.

*/

int particiona(int V[], int i, int f, int pivo){
    for(int k = i; k<=f; k++){
        if(V[k] == pivo){
            swap(V[k], V[f]);
            break;
        }
    }
    int it = i-1;
    int j = i;
    while(j<f){
        if(V[j]<=pivo){
            it++;
            swap(V[it], V[j]);
        }
        j++;
    }
    swap(V[it+1], V[f]);
    return it+1;
}


int selecao(int V[],int k, int i, int f){
    int n = f - i + 1;
    if(i==f) return V[i];

    int tamgp = n/5;
    int medianas[tamgp+1];   
    for(int g = 0; g<tamgp+1; g++){
        vector<int> grupo;
        for(int j = i+(5*g);(j<(i+(5*g))+5 && j<=f); j++){ 
            grupo.push_back(V[j]); 
        }
        sort(grupo.begin(), grupo.end());
        medianas[g] = grupo[grupo.size()/2];
    }
    int pivo = selecao(medianas, tamgp/2, 0, tamgp-1);
    int q = particiona(V, i, f, pivo);
    if(q - i + 1 == k) return V[q];
    else if(q - i + 1 < k) return selecao(V,  k-(q -i + 1), q+1, f);
    else return selecao(V, k, i, q-1);
} 
// Complexidade: O(n)



int main(){
    int V[] = {7, 10, 4, 3, 20, 15};
    int n = 6;
    int k = 3;
    cout << "K-esimo menor elemento é " << selecao(V, k, 0, n-1) << endl;
    return 0;
}