
/*
ID: dswei191
LANG: C++
TASK: combo
*/

#include <iostream>
#include <fstream>

using namespace std;
ofstream fout("combo.out");
ifstream fin("combo.in");

int n;
int a[3];
int b[3];

int getDistance(int x, int y){
    int ret;
    if(x > y){
        ret = x - y;
    }else{
        ret = y - x;
    }
    if( ret > n / 2){
        ret = n - ret;
    }
    return ret;
}
int main(){
    fin >> n;
    fin >> a[0] >> a[1] >> a[2];
    fin >> b[0] >> b[1] >> b[2];

    int ret;
    if(n < 5){
        ret = n * n * n;
    }else{
        ret = 5 * 5 * 5 * 2;
        int t[3];
        for(int i = 0; i < 3; i++){
            t[i] = getDistance(a[i], b[i]);
//            cout<<t[i]<<endl;
            if(5 - t[i] < 0){
                t[i] = 0;
            }else{
                t[i] = 5 - t[i];
            }
        }
        int m = t[0] * t[1] * t[2];
        ret -= m;
    }

    fout << ret <<endl;
    return 0;
}
