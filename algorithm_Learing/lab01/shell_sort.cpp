#include <bits/stdc++.h>

using namespace std;
#define N 100000

void shell_sort(vector <int> &a){      
    int gap = 1;
    while (gap < a.size() / 3) {
        gap = 3 * gap + 1;
    }
    while (gap >= 1) {
        for (int i = gap; i < a.size(); i++) {
            for (int j = i; j >= gap && a[j] < a[j - gap]; j -= gap) {
                swap(a[j], a[j - gap]);
            }
        }
        gap = gap / 3;
    }
}

int main(){
	vector<int> data;
	for (int i = 0; i < N; i++)
		data.push_back(rand());

    clock_t start = clock();

    shell_sort(data);

	clock_t end = clock();

	cout << end - start << "ms" << endl;

    // for (int i = 0; i < N; i++){
	// 	cout << data[i] << " ";
	// }

	system("pause");
	return 0;
}