#include <bits/stdc++.h>

using namespace std;


void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
            continue;
        }

        used[i] = true;
        current.push_back(nums[i]);
        backtrack(nums, used, current, result);
        current.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);


    sort(nums.begin(), nums.end());
    backtrack(nums, used, current, result);
    return result;
}

int main() {
    int n;
    cout << "请输入数组的大小: ";
    cin >> n;
    vector<int> nums(n);
    cout << "请输入数组元素（用空格分隔）: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    vector<vector<int>> permutations = permuteUnique(nums);

    cout << "全排列结果：" << endl;
    for (int i = 0; i < permutations.size(); ++i) {
    cout << "{ ";
    for (int j = 0; j < permutations[i].size(); ++j) {
        cout << permutations[i][j] << " ";
    }
    cout << "}" << endl;
    }
    system("pause");
    return 0;
}