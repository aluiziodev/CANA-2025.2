#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> Matriz;
typedef pair<int,int> pii;


int getCaminho(Matriz memo, int valor, int i){
    if(valor == memo[i][1]) return 1;
    if(valor == memo[i][2]) return 2;
    if(valor == memo[i][3]) return 3;
    return -1;
}

bool titulo(Matriz tempo, int n, Matriz  &caminho){
    Matriz memo(n+1, vi(4));
    for(int i = 1; i<4; i++) memo[1][i] = tempo[1][i];
    for(int i = 2; i<=n; i++){
        for(int j = 1; j<4; j++){
            if(j == 1){
                memo[i][j] = tempo[i][j] + min({memo[i-1][j], memo[i-1][j+1] + 5,  
                memo[i-1][j+2] + 12});
            }
            if(j == 2){
                memo[i][j] = tempo[i][j] + min({memo[i-1][j-1] + 5, memo[i-1][j],
                memo[i-1][j+1] + 5});
            }
            if(j == 3){
                memo[i][j] = tempo[i][j] + min({memo[i-1][j], memo[i-1][j-1] + 5, 
                memo[i-1][j-2] + 12});
            }

            caminho[i][j] = getCaminho(memo, memo[i][j] - tempo[i][j], i-1);
        }
    }
    int finalPath = min({memo[n][1], memo[n][2], memo[n][3]});
    
    // Reconstruir o caminho
    int lastColumn;
    if(finalPath == memo[n][1]) lastColumn = 1;
    else if(finalPath == memo[n][2]) lastColumn = 2;
    else lastColumn = 3;

    vector<int> path;
    for(int i = n; i >= 1; i--) {
        path.push_back(lastColumn);
        lastColumn = caminho[i][lastColumn];
    }
    reverse(path.begin(), path.end());

    cout << "Caminho escolhido: ";
    for(int col : path) {
        cout << col << " ";
    }
    cout << endl;


    return (finalPath<=240);
}

int main(){
    int n; cin >> n;
    Matriz tempo(n+1, vi(4));
    Matriz caminho(n+1, vi(4, -1));
    for(int i =1;i<=n;i++){
        for(int j =1;j<4;j++){
            cin >> tempo[i][j];
        }
    }
    bool res = titulo(tempo, n, caminho);
    if(res) cout << "SIM" << endl;
    else cout << "NAO" << endl;
    return 0;
}