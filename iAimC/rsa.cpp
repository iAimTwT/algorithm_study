#include <bits/stdc++.h>

using namespace std;

int ras(int a, int b, int c){
	int r = 1;
	b = b + 1;
	while(b != 1){
		r = r * a;
		r = r % c;
		b--;
	} 
	return r;
}

int main(){
	cout << "输入两个奇素数p,q: ";
	int  p, q;
	cin >> p >> q;
	int n = p * q;
	int Fn = (p - 1) * (q - 1);
	cout << "输入整数e: ";
	int e;
	cin >> e;
	cout << "e,n的值为: " << e << " " << n <<endl; 
	
	int d = 1;
	while(((e * d) % Fn)!=1) d++;
	
	cout << "请输入明文个数: ";
	int num;
	cin >> num;
	cout << "请输入明文:";
	char origin[num];
	for(int i = 0; i < num; i++){
		cin >> origin[i];
	}
	int binnum[num];
	for(int i = 0; i < num; i++){
		binnum[i] = origin[i] + 0;
		binnum[i] = ras(binnum[i], e, n);
	}
	cout << "加密后的密文为：";
	for(int i = 0; i < num; i++){
		cout << binnum[i] <<" ";
	}
	cout <<endl;
	
	cout << "(解密)输入密文个数:";
	cin >> num;
	cout << "请输入密文:";
	int m[num];
	for(int i = 0; i < num; i++){
		cin >> m[i];
	}
	for(int i = 0; i < num; i++){
		m[i] = ras(m[i], d, n);
	}
	cout << "解密后的明文为：";
	for(int i = 0; i < num; i++){
		cout << char(m[i]);
	}
    
    system("pause");
	return 0;
}
