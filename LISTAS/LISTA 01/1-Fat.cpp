#include <bits/stdc++.h>

using namespace std;

int fat(int n){
    if(n==0) return 1;
    else{
        return n*fat(n-1);
    }
}

/* CORRETUDE FAT

BASE (n == 0):
    trivialmente, se n = 0, a funçao fat retorna 1, e  0! = 1. 


PASSO (Suponha fat(n-1)=(n-1)!, provemos fat(n)=n!):
    logo, se chamarmos fat(n), se n!=0, teremos como retorno n*fat(n-1)
    porem, fat(n-1)=(n-1)!, logo, fat(n) = n*(n-1)! = n!. CQD!



logo, a funçao fat funciona para todo n natural.
*/
