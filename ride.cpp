/*
ID: dswei191
LANG: C++
TASK: ride
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    string filename = "ride";
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    string str1, str2;
    int pro1, pro2;
    int i, j;
    while(fin>>str1>>str2){
        pro1 = 1;
        pro2 = 1;
        for(i = 0; i < str1.length(); i++){
            pro1 *= (str1[i] - 'A' + 1);
        }
        for(j = 0; j < str2. length(); j++){
            pro2 *= (str2[j] - 'A' + 1);
        }

        if((pro1 % 47) == (pro2 % 47)){
            fout << "GO" << endl;
        }else{
            fout << "STAY" << endl;
        }
    }
    return 0;
}
