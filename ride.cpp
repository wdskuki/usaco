/*
ID: dswei191
LANG: C++
TASK: ride
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream fout("ride.out");
ifstream fin("ride.in");

int transform(string a){
    int ret = 1;
    for(int i = 0; i < a.length(); i++){
        ret *= (a[i] - 'A' + 1);
    }
    return ret % 47;
}
int main(){
    string str1, str2;
    fin >> str1 >> str2;
    if(transform(str1) == transform(str2)){
        fout << "GO" << endl;
    }else{
        fout << "STAY" << endl;
    }
    return 0;
}
