/*
ID: dswei191
LANG: C++
TASK: test
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ofstream fout("test.out");
    ifstream fin("test.in");
    if('\0' == 'a'){
        cout << 1 << endl;
    }else{
        cout << 2 <<endl;
    }
    return 0;
}
