
/*
ID: dswei191
LANG: C++
TASK: numtri
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define MAX_R 1000
using namespace std;
ofstream fout("numtri.out");
ifstream fin("numtri.in");

int R;
int value[MAX_R + 1][MAX_R + 1];

int main(){
    fin >> R;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= i; j++){
            fin >> value[i][j];
            int t = value[i][j];
            if(i-1 > 0 && j -1 > 0){
                t = max(value[i][j] + value[i-1][j-1], value[i][j] + value[i-1][j]);
            }else if(i - 1 > 0){
                t =  value[i][j] + value[i-1][j];
            }
            value[i][j] = t;
        }
    }

    int maxValue = -1;
    for(int i = 1; i <= R; i++){
        maxValue = (value[R][i] > maxValue) ? value[R][i] : maxValue;
    }

    fout<<maxValue<<endl;

    return 0;
}