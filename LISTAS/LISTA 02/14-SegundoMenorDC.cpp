#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;







ii segundoMenorDC(int V[], int i, int f){
    if(i==f){
        return {V[i], 1e9+1}; /* POR PADRAO, USAMOS 1e9+1 ("INFINITO") 
                              PARA AUSENCIA DE SEGUNDO ELEMENTO, PARA FACILITAR NAS COMPARAÇOES*/
    }
    else{
        int meio = (i+f)/2;
        ii p1 = segundoMenorDC(V, i, meio);
        ii p2 = segundoMenorDC(V, meio+1, f);
        ii menores;
        menores.first = min(p1.first, p2.first);
        menores.second = min(max(p1.first, p2.first), min(p1.second, p2.second));
        return menores;
    }
}

int segundoMenor(int V[], int i, int f){
    ii m = segundoMenorDC(V, i, f);
    return m.second;
}

int main(){
    int V[] = {234, 122, 23245, 1221, 444, 235, 1000};
    cout << segundoMenor(V, 0, 6) << endl;
    
}
