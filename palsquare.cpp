/*
ID: dswei191
LANG: C++
TASK: palsquare
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

ofstream fout( "palsquare.out");
ifstream fin("palsquare.in");

string decimalTran(int val, int n){
    string ret = "";
    while(val > 0){
        stringstream ss;
        int t = val % n;
        if(t >= 10){
            char strT = 'A' + (t - 10);
            ret += strT;
        }else{
            ret += (t + '0');
        }

        val = val / n;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

bool checkPal(string str){
    int length = str.length();
    for(int i = 0; i < length / 2; i++){
        if(str[i] != str[length - i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    fin >> n;
    for(int i = 1; i <= 300; i++){
        int ret = i * i;
        string val = decimalTran(ret, n);
        if(checkPal(val)){
            fout << decimalTran(i, n) << ' ' << val <<endl;
        }
    }
}