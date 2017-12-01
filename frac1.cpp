
/*
ID: dswei191
LANG: C++
TASK: frac1
*/



/**
 * w,n,e,s，对应0, 1, 2, 3, 左、上、右、下
 */
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
ofstream fout("frac1.out");
ifstream fin("frac1.in");

#define MAX_N 160
int N;
int f[MAX_N+1][MAX_N+1];

vector<pair<int, int> > vec;

//最大公约数
int maxCommDivider(int a, int b){
    if(a == 1 || b == 1){
        return 1;
    }else if(a == 0 || b == 0){
        return 0;
    }
    if(a < b){
        int t = a;
        a = b;
        b = t;
    }
    while(a % b != 0){
        int t = a - b;
        if(t > b){
            a = t;
        }else{
            a = b;
            b = t;
        }
    }
    return b;
}

//最小公倍数
int minCommMultiple(int a, int b){
    if(a== 0 || b == 0){
        return 0;
    }
    int t = maxCommDivider(a, b);
    return (b / t) * a;
}



//比较两个分数a1/a2和b1/b2的大小
bool comp(pair<int, int > & a, pair<int, int > & b){
    int t = minCommMultiple(a.second, b.second);
    return a.first * (t / a.second) < b.first * (t / b.second);
}


int main(){
    fin >> N;

    f[0][1] = 1;
    vec.push_back(make_pair(0, 1));
    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j++){
            int t = maxCommDivider(i, j);
            int i1 = i/t;
            int j1 = j/t;
            if(f[i1][j1] == 0){
                f[i1][j1] = 1;
                vec.push_back(make_pair(i1, j1));
            }
        }
    }

    sort(vec.begin(), vec.end(), comp);

    for(int i = 0; i < vec.size(); i++){
        fout<< vec[i].first << "/" <<vec[i].second <<endl;
    }
    return 0;
}