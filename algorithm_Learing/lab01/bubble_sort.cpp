#include <bits/stdc++.h>

using namespace std;
#define N 100000

void bubble_sort(vector <int> &a){     
        for (int i = 0; i < a.size() - 1; i++) {
            for (int j = 0; j < a.size() - 1 - i; j++) {
                if (a[j] > a[j + 1]) swap(a[j], a[j+1]);
            }
        }
}

int main(){
	vector<int> data;
	for (int i = 0; i < N; i++)
		data.push_back(rand());

    clock_t start = clock();

    bubble_sort(data);

	clock_t end = clock();

	cout << end - start << "ms" << endl;

    // for (int i = 0; i < N; i++){
	// 	cout << data[i] << " ";
	// }

	system("pause");
	return 0;
}