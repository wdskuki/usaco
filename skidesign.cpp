
/*
ID: dswei191
LANG: C++
TASK: skidesign
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
ofstream fout("skidesign.out");
ifstream fin("skidesign.in");

int n;
vector<int> vec;

int check(int base){
    int ret = 0;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] < base){
            ret += (base - vec[i]) * (base - vec[i]);
        }else if(vec[i] > base + 17){
            ret += (vec[i] - base - 17) * (vec[i] - base - 17);
        }
    }
    return ret;
}

int main(){
    int ret = -1;
    fin >> n;
    for (int i = 0; i < n; i++){
        int t;
        fin >> t;
        vec.push_back(t);
    }


    for(int i = 0; i <= 83; i++){
        int t  = check(i);
        if(ret < 0){
            ret = t;
        }else{
            ret = (t < ret) ? t: ret;
        }
    }
    ret = (ret < 0) ? 0 : ret;
    fout << ret <<endl;
    return 0;
}
