#include <bits/stdc++.h>

using namespace std;


void backPack(int n, int c, vector<int> &w, vector<int> &v, vector<vector<int>> &dp){
    vector<int> res(n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= c; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= w[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
                if(dp[i][j] == dp[i - 1][j - w[i]] + v[i]) res[i - 1] = 1;
            }
        }
    }
    cout << "dp[i][j]" <<endl;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= c; j++){
            cout << dp[i][j] <<" ";
        }
        cout << endl;
    }
    cout << "max_value = " << dp[n][c] <<endl;
    cout << "result: ";
    for(int i = 0; i < n; i++) cout << res[i] <<" ";
}



int main(){
    int n, c;
    cout << "请输入物品的个数和背包的容量: ";
    cin >> n >> c;
    vector<int> w(n + 1);
    vector<int> v(n + 1);   
    cout << "依次输入物品重量和价值: ";
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(c + 1));
    backPack(n, c, w, v, dp);


    system("pause");
    return 0;
}