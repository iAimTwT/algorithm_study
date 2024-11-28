#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<string> str ={{"abc"},{"bac"},{"abb"},{"acc"},{"cba"}};
    unordered_map <string, vector<int>> m;
    vector<string> pre_strs;
    for(int i = 0; i < str.size(); i++){
        sort(str[i].begin(),str[i].end());
        m[str[i]].push_back(i);
    }
    vector<vector<string>> ans;
    ans.reserve(m.size());
       for (auto& entry : m) {
        vector<string> group;
        for (int idx : entry.second) {
            group.push_back(str[idx]);  // 根据索引找到原始字符串并加入分组
        }
        ans.push_back(group);  // 将分组加入结果
    }
    

    system("pause");
    return 0;
}