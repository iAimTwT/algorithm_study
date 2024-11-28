#include <bits/stdc++.h>

using namespace std;

const int N = 7;
int a[N];
char b[N];
int sum = 0;

int main(){
  for(int i = 0; i < N; i++){
  scanf("%c",&b[N]);
  a[(N+4)%7] = (int)b[N];
}

for(int i = N; i >= 0; i--){
  sum +=  a[i] << (sizeof(a[i]) - 1);
}
  cout << sum <<endl;
  system("pause");
  return 0;
}