/*
ID: dswei191
LANG: C++
TASK: sort3
*/


#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
ofstream fout("sort3.out");
ifstream fin("sort3.in");
#define MAX_N 1000
string retStr;
int N;
int ret = 0;
int main(){
    fin >> N;
    string str = "";
    int t;
    for(int i = 0; i < N; i++) {
        fin >> t;
        str += (t + '0');
    }

    retStr = str;
    sort(retStr.begin(), retStr.end());

    for(int i = 0; i < str.length(); i++){
        if(str[i] != retStr[i]){
            for(int j = i+1; j < str.length(); j++){
                if(str[j] != retStr[j] && str[j] == retStr[i] && str[i] == retStr[j]){
                    char t = str[i];
                    str[i] = str[j];
                    str[j] = t;
                    ret++;
                    break;
                }
            }
        }
    }
    if(str != retStr){
        for(int i = 0; i < str.length(); i++){
            if(str[i] != retStr[i]){
                for(int j = i+1; j < str.length(); j++){
                    if(str[j] != retStr[j] && str[j] == retStr[i]){
                        char t = str[i];
                        str[i] = str[j];
                        str[j] = t;
                        ret++;
                        break;
                    }
                }
            }
        }
    }

    fout<<ret<<endl;
    return 0;
}