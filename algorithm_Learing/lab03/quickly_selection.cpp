#include <bits/stdc++.h>

using namespace std;
const int N = 1000000;

int quickly_select(int l, int r, vector<int> &q, int k){
    if(l == r) return q[l];

    int mid = q[l + r >> 1], i = l - 1, j = r + 1;
    while(i < j){
        while(q[++i] < mid);
        while(q[--j] > mid);
        if(i < j) swap(q[i], q[j]);
    }

    int sl = j - l + 1;
    if(k <= sl)  return quickly_select(l, j, q, k);
    else return quickly_select(j + 1, r, q, k - sl);

}


int main(){
    vector<int> data;
	for (int i = 0; i < N; i++) data.push_back(rand());
    int k = rand() % N;

    clock_t start = clock();
    int res = quickly_select(0, N - 1, data, k);
    clock_t end = clock();

    cout << "要寻找第" << k << "小的数"<< endl;
    cout << "这个数为" << res << endl;
    cout << "寻找用时为:" << end - start << "ms" << endl;

    // for (int i = 0; i < N; i++){
	// 	cout << data[i] << " ";
	// }

    system("pause");
    return 0;
}