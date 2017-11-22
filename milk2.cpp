/*
ID: dswei191
LANG: C++
TASK: milk2
*/

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int n;
class Duration{
public:
    int st,et;
    Duration(int st, int et){
        this->st = st;
        this->et = et;
    }

};
list<Duration> ldut;
vector<Duration> vdut;
int ret1 = 0;
int ret2 = 0;
bool compare(Duration a, Duration b){
    return a.st < b.st;
}
int main(){
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");

    fin >> n;
    int st, et;

    for(int i = 0; i < n; i++){
        fin >> st >> et;
        Duration d(st, et);
        vdut.push_back(d);
    }

    sort(vdut.begin(), vdut.end(), compare);

//    for(int i = 0; i < n; i++){
//        cout << vdut[i].st << ' ' << vdut[i].et <<endl;
//    }

    for(int i = 0; i < n; i++){
        ldut.push_back(vdut[i]);
    }
//
//    list<Duration>::iterator itStart;
    list<Duration>::iterator itStart = ldut.begin();
    list<Duration>::iterator it;
//    itStart = ldut.begin();
    for(it = ldut.begin(); it != ldut.end();){
        if(it == itStart){
            it++;
            continue;
        }
        if(it->st > itStart->et){
            itStart = it;
            it++;
        }else{
            itStart->et = max(itStart->et, it->et);
            it = ldut.erase(it);
        }
    }

//    for(it = ldut.begin(); it != ldut.end(); it++){
//        cout << it->st << ' ' << it->et <<endl;
//    }
    list<Duration>::iterator itNext;
    for(it = ldut.begin(); it != ldut.end(); it++){
        ret1 = max(ret1, it->et - it->st);
        itNext = it;
        itNext++;
        if(itNext != ldut.end()){
            ret2 = max(ret2, itNext->st - it->et);
        }
    }

    fout<< ret1 << ' ' << ret2 <<endl;
    return 0;
}
