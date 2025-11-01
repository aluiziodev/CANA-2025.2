#include <bits/stdc++.h>

using namespace std;


int buscaBinaria(int V[], int i, int f, int k){
    if (i==f) return i;
    else{
        int meio = (i+f)/2;
        if(V[meio]>=k) return buscaBinaria(V, i, meio, k);
        else  return buscaBinaria(V,meio+1, f, k);
    }
}

// Complexidade O(log(n))


int main(){
    int V[] = {1, 2, 4, 4, 4, 7 ,9};
    cout << buscaBinaria(V, 0, 6, 3) << endl;

}