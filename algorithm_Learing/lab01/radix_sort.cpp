#include <bits/stdc++.h>

using namespace std;
#define N 100000

int getDigit(int number, int digit) {
    return (number / (int)pow(10, digit)) % 10;
}

void radix_sort(vector <int> &a){      
    if (a.empty()) return;

    int max = *max_element(a.begin(), a.end());
    int maxDigits = 0;

    while (max > 0) {
        max /= 10;
        maxDigits++;
    }


    for (int digit = 0; digit < maxDigits; digit++) {
        vector<vector<int>> buckets(10);

        for (int num : a) {
            int bucketIndex = getDigit(num, digit);
            buckets[bucketIndex].push_back(num);
        }

        a.clear();
        for (const auto& bucket : buckets) {
            a.insert(a.end(), bucket.begin(), bucket.end());
        }
    }
}

int main(){
	vector<int> data;
	for (int i = 0; i < N; i++)
		data.push_back(rand());

    clock_t start = clock();

    radix_sort(data);

	clock_t end = clock();

	cout << end - start << "ms" << endl;

    // for (int i = 0; i < N; i++){
	// 	cout << data[i] << " ";
	// }

	system("pause");
	return 0;
}