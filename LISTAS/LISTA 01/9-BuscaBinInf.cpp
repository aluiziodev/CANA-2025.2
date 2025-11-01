#include <bits/stdc++.h>
#include <algorithm>

#define MAX 2.147483647e9


using namespace std;

int buscaBinaria(vector<int> V, int i, int f, int k){
    if (i<=f){
        int meio = (i+f)/2;
        if(V[meio]==k) return meio;
        else if(V[meio]>k) return buscaBinaria(V, i, meio-1, k);
        else  return buscaBinaria(V,meio+1, f, k);
    }
    return -1;
}

int buscaInfinita(vector<int> V, int x){
    int i = 0;
    if(V[i]==x) return i;
    i++;
    while(V[i] < x) i *= 2;
    if(V[i]==x) return i;
    return buscaBinaria(V, i/2 + 1, i, x);
}

int main(){
    vector<int> V; 

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> d(0, 1000);

    for(int i = 0; i<30; i++){
            V.push_back(d(gen));
    }

    V[15] = 500;

    sort(V.begin(), V.end());
    for (int i = 0; i < 100; i++){
        V.push_back(MAX);
    }


    cout << buscaInfinita(V, 500) << "\n";


    
}
