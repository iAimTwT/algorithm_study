#include <bits/stdc++.h>

using namespace std;

#define N 100000
int temp[N];

void merge_sort(vector <int> &a, int l ,int r){
    if(l >= r) return;
    int mid = l + r >> 1;


    merge_sort(a, l ,mid),merge_sort(a, mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j<= r)
    {
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while(i <= mid) temp[k++] = a[i++];
    while(j <= r) temp[k++] = a[j++];

    for(i = l,j = 0;i <= r;i++,j++) a[i] = temp[j];
}


int main(){
	vector<int> data;
	for (int i = 0; i < N; i++)
		data.push_back(rand());

    clock_t start = clock();

    merge_sort(data,0,N - 1);

	clock_t end = clock();

	cout << end - start << "ms" << endl;

    // for (int i = 0; i < N; i++){
	// 	cout << data[i] << " ";
	// }

	system("pause");
	return 0;
}