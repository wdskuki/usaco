/*
ID: dswei191
LANG: C++
TASK: barn1
*/

#include <iostream>
#include <fstream>
#include<vector>
#include <sstream>
#include <algorithm>

using namespace std;

ofstream fout( "barn1.out");
ifstream fin("barn1.in");
int M,S,C;

vector<int> vec;

int main(){
    fin >> M >> S >> C;
    int t;
    for(int i = 0; i < C; i++){
        fin >> t;
        vec.push_back(t);
    }
    sort(vec.begin(), vec.end());
    int total = vec[vec.size()-1] - vec[0] + 1;
    vector<int> tvec;
    int base = vec[0];
    for(int i = 1; i < vec.size(); i++){
        if(base + 1 == vec[i]){
            base = vec[i];
        }else{
            tvec.push_back(vec[i] - base - 1);
            base = vec[i];
        }
    }
    sort(tvec.begin(), tvec.end());

    for(int i = tvec.size() - 1; i >= 0 &&  M> 1; i--, M--){
        total -= tvec[i];
    }


    fout << total <<endl;
    return 0;
}