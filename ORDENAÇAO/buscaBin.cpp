#include <bits/stdc++.h>

using namespace std;


// BUSCA BINARIA

int buscaBinaria(int V[], int inicio, int fim, int target){
    if(fim>=inicio){
        int meio = (inicio+fim)/2;
        if(V[meio]==target) return V[meio];
        else if(V[meio<target]) return buscaBinaria(V, inicio, meio-1, target);
        else return buscaBinaria(V, meio+1, fim, target);
    }
    return -1;
}
// Complexidade: O(Log(n))


int main(){
    int V[] = {7, 6, 2, 4, 1};
    cout << buscaBinaria(V, 0, 4, 7) << endl;

}
