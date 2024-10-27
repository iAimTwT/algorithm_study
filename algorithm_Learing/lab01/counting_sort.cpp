#include <bits/stdc++.h>

using namespace std;
#define N 1000000

void counting_sort(vector <int> &a){      
    int max = *max_element(a.begin(), a.end());
    
    vector<int> count(max + 1, 0);
    for (int num : a) {
        count[num]++;
    }
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            a[index++] = i;
            count[i]--;
        }
    }
}

int main(){
	vector<int> data;
	for (int i = 0; i < N; i++)
		data.push_back(rand());

    clock_t start = clock();

    counting_sort(data);

	clock_t end = clock();

	cout << end - start << "ms" << endl;

    for (int i = 0; i < N; i++){
		cout << data[i] << " ";
	}

	system("pause");
	return 0;
}