#include <bits/stdc++.h>

using namespace std;

void matrixChain(vector<int> &p, int n, vector<vector<int>> &m, vector<vector<int>> &s){
    for(int r = 2; r <= n; r++){
        for(int i = 1; i <= n - r + 1; i++){
            int j = i + r - 1;
            m[i][j] = m[i+1][j] + p[i - 1] * p[i] * p[j];
            s[i][j] = i;
            for(int k = i + 1; k < j; k++){
                if(m[i][j] != min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j])) s[i][j] = k;
                m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
            }
        }
    }   
}

void printOptimalParens(const vector<vector<int>> &s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        cout << "x";
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main(){
    int n;
    cout << "输入矩阵的个数n: ";
    cin >> n;
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));
    vector<int> p; 
    cout << "输入P0 ~ Pn: ";
    for(int i = 0; i <= n; i++){
        int tmp;
        cin >> tmp;
        p.push_back(tmp);
    }
    matrixChain(p, n, m, s);
    for(int i = 0; i <= n; i++){
        cout << endl;
        for(int j = 0; j <= n; j++) printf("%8d",m[i][j]);
    }
    cout << endl;
    printOptimalParens(s, 1, n);
    cout << endl;

    system("pause");
    return 0;

}