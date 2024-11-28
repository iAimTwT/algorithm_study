#include <bits/stdc++.h>

using namespace std;


int longestCommonSubsequence(string text1, string text2, vector<vector<int>> &dp) {
    int n = text1.size();
    int m = text2.size();
    dp.assign(n + 1, vector<int>(m + 1, 0)); 


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m]; 
}


string backtrackLCS(const string &text1, const string &text2, const vector<vector<int>> &dp) {
    string lcs;
    int i = text1.size();
    int j = text2.size();

    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            lcs += text1[i - 1]; 
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--; 
        } else {
            j--; 
        }
    }

    reverse(lcs.begin(), lcs.end()); 
    return lcs;
}

int main() {
    string text1, text2;
    cout << "输入序列1: ";
    cin >> text1;
    cout << "输入序列2: ";
    cin >> text2;


    if (text1.size() < 10 || text2.size() < 10) {
        cout << "序列长度不足 10,请重新输入!" << endl;
        return 1;
    }

    vector<vector<int>> dp; 
    int lcsLength = longestCommonSubsequence(text1, text2, dp);

    cout << "\nc[i][j] 动态规划表:" << endl;
    for (int i = 0; i <= text1.size(); i++) {
        for (int j = 0; j <= text2.size(); j++) {
            cout << setw(3) << dp[i][j] << " ";
        }
        cout << endl;
    }

    string lcs = backtrackLCS(text1, text2, dp);
    cout << "\n最长公共子序列长度: " << lcsLength << endl;
    cout << "最长公共子序列: " << lcs << endl;

    system("pause");
    return 0;
}
