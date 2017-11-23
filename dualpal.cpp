/*
ID: dswei191
LANG: C++
TASK: dualpal
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

ofstream fout( "dualpal.out");
ifstream fin("dualpal.in");

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

bool checkDualPal(int val){
    int cnt = 0;
    for(int i = 2; i <= 10; i++){
        string str = decimalTran(val, i);
        if(checkPal(str)){
            ++cnt;
        }
        if(cnt >= 2){
            return true;
        }
    }
    return false;
}

int main(){
    int n, s;
    fin >> n >> s;
    int t = s+1;

    while(n--){
        while(true){
            if(checkDualPal(t)){
                fout << t <<endl;
                ++t;
                break;
            }
            ++t;
        }
    }

}