/*
ID: dswei191
LANG: C++
TASK: namenum
*/

#include <iostream>
#include <fstream>

using namespace std;

ofstream fout( "namenum.out");
ifstream fin("namenum.in");

string transform(string str){
    string ret = "";
    for(int i = 0; i < str.length(); i++){
        if(str[i] == 'A' || str[i] == 'B' || str[i] == 'C'){
            ret += "2";
        }else if(str[i] == 'D' || str[i] == 'E' || str[i] == 'F'){
            ret += "3";
        }else if(str[i] == 'G' || str[i] == 'H' || str[i] == 'I'){
            ret += "4";
        }else if(str[i] == 'J' || str[i] == 'K' || str[i] == 'L'){
            ret += "5";
        }else if(str[i] == 'M' || str[i] == 'N' || str[i] == 'O'){
            ret += "6";
        }else if(str[i] == 'P' || str[i] == 'R' || str[i] == 'S'){
            ret += "7";
        }else if(str[i] == 'T' || str[i] == 'U' || str[i] == 'V'){
            ret += "8";
        }else if(str[i] == 'W' || str[i] == 'X' || str[i] == 'Y'){
            ret += "9";
        }
    }
    return ret;
}

string dict[5000];
string tDict[5000];
int main(){
    ifstream fdict("dict.txt");
    int i = 0;
    while(fdict >> dict[i]){
        tDict[i] = transform(dict[i]);
        ++i;
    }

    string numStr;
    fin >> numStr;
    bool flag = false;
    for(int j = 0; j < i; j++){
        if(tDict[j] == numStr){
            flag = true;
            fout << dict[j] << endl;
        }
    }
    if(flag == false){
        fout << "NONE" <<endl;
    }
    return 0;

}