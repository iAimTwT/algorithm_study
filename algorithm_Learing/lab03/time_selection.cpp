#include <bits/stdc++.h>

using namespace std;
int const N = 1000010;

int quick_sort(vector <int> &a, int l, int r,int x){
    
    if(l >= r) return l;

    int i = l - 1,j = r + 1;
    x = a[x - 1];
    while(i < j){
    do i++; while (a[i] < x);
    do j--; while (a[j] > x);
    if(i < j ) swap(a[i],a[j]);
    }
    return quick_sort(a,l,j,x);
    return quick_sort(a,j + 1,r,x);
    
}

int time_select(vector<int> &q, int l, int r, int k){
    if(r - l) return q[l + r - 1];

    for(int i = 0; i <= (r - l - 4)/5; i++){
        int x = time_select(q, l, l+(r - l - 4)/5, (r - l - 4/10));
        int temp = quick_sort(q, l, r, x), j = i - l + 1;
        if(k <= j) return time_select(q, l, i, k);
        else return time_select(q, i+1, r, k+1);
    }
}


int main(){
    vector<int> data;
	for (int i = 0; i < N; i++) data.push_back(rand());
    int k = rand() % N;

    clock_t start = clock();
    int res = time_select(data, 0, N - 1, k);
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