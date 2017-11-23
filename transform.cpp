/*
ID: dswei191
LANG: C++
TASK: transform
*/

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX_NUM 10

ofstream fout( "transform.out");
ifstream fin("transform.in");

int n;

bool type1(char before[MAX_NUM][MAX_NUM], char after[MAX_NUM][MAX_NUM]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(after[i][j] != before[n-j-1][i]){
                return false;
            }
        }
    }
    return true;
}

bool type2(char before[MAX_NUM][MAX_NUM], char after[MAX_NUM][MAX_NUM]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(after[i][j] != before[n-i-1][n-j-1]){
                return false;
            }
        }
    }
    return true;
}

bool type3(char before[MAX_NUM][MAX_NUM], char after[MAX_NUM][MAX_NUM]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(after[i][j] != before[j][n-i-1]){
                return false;
            }
        }
    }
    return true;
}

bool type4(char before[MAX_NUM][MAX_NUM], char after[MAX_NUM][MAX_NUM]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(after[i][j] != before[i][n-j-1]){
                return false;
            }
        }
    }
    return true;
}

bool type5(char before[MAX_NUM][MAX_NUM], char after[MAX_NUM][MAX_NUM]){
    char tmp[10][10];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            tmp[i][n-j-1] = before[i][j];
        }
    }

    if(type1(tmp, after) || type2(tmp, after) || type3(tmp, after)){
        return true;
    }else{
        return false;
    }
}


bool type6(char before[MAX_NUM][MAX_NUM], char after[MAX_NUM][MAX_NUM]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(after[i][j] != before[i][j]){
                return false;
            }
        }
    }
    return true;
}

int checkType(char before[MAX_NUM][MAX_NUM], char after[MAX_NUM][MAX_NUM]){
    if(type1(before, after)){
        return 1;
    }else if(type2(before, after)){
        return 2;
    }else if(type3(before, after)){
        return 3;
    }else if(type4(before, after)){
        return 4;
    }else if(type5(before, after)){
        return 5;
    }else if(type6(before, after)){
        return 6;
    }else {
        return 7;
    }
}

int main(){
    fin >> n;
    char before[MAX_NUM][MAX_NUM];
    char after[MAX_NUM][MAX_NUM];
    for(int i = 0; i < n; i++){
        fin >> before[i];
    }

    for(int i = 0; i < n; i++){
        fin >> after[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<< before[i][j] << ' ';
        }
        cout<<endl;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<< after[i][j] << ' ';
        }
        cout<<endl;
    }


    int ret = checkType(before, after);
//    cout << ret <<endl;
    fout << ret <<endl;
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n; j++){
//            cout<< before[i][j] << ' ';
//        }
//        cout<<endl;
//    }
    return 0;
}
