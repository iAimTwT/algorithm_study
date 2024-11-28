#include <bits/stdc++.h>

using namespace std;

class point{
public:
    int x;
    int y;

    point(int _x, int _y){
        x = _x;
        y = _y;
    }
};



int main(){
    int n, c;
    cout << "请输入物品的个数和背包的容量: ";
    cin >> n >> c;
    vector<point> points;
    cout << "依次输入物品重量和价值: ";
    for(int i = 0; i < n; i++){
        int v,w;
        cin >> v >> w;
        points.push_back(point(v, w));
    }



    system("pause");
    return 0;
}