#include <bits/stdc++.h>

using namespace std;
#define N 100000

void select_sort(vector <int> &a){      
        for (int i = 0; i < a.size() - 1; i++) {
            int min = i;
            for (int j = i; j < a.size(); j++) {
                if (a[min] > a[j]) min = j;
            }
            if(min != i){
                swap(a[i], a[min]);
            }
        }
}

int main(){
	vector<int> data;
	for (int i = 0; i < N; i++)
		data.push_back(rand());

    clock_t start = clock();

    select_sort(data);

	clock_t end = clock();

	cout << end - start << "ms" << endl;

    // for (int i = 0; i < N; i++){
	// 	cout << data[i] << " ";
	// }

	system("pause");
	return 0;
}