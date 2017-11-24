/*
ID: dswei191
LANG: C++
TASK: milk
*/

#include <iostream>
#include <fstream>
#include<vector>
#include <sstream>
#include <algorithm>

using namespace std;

ofstream fout( "milk.out");
ifstream fin("milk.in");
int n, m;
int *p, *a;

class Farmer{
public:
    int p;
    int a;
    Farmer(int p, int a){
        this->p = p;
        this->a = a;
    }
};

bool comp(const Farmer &a, const Farmer &b){
    return a.p < b.p;
}
vector<Farmer> fvec;

int count(){
    int total = 0;

    for (int i = 0; i < m; i++) {
        if (n >= fvec[i].a) {
            total += fvec[i].a * fvec[i].p;
            n -= fvec[i].a;
        }else{
            total += n * fvec[i].p;
            n = 0;
        }
        if(n <= 0){
            break;
        }
    }
    return total;
}
int main(){

    fin >> n >> m;
    int tp, ta;
    for(int i = 0; i < m; i++){
        fin >> tp >> ta;
        Farmer f(tp, ta);
        fvec.push_back(f);
    }
    sort(fvec.begin(), fvec.end(), comp);

    fout << count() <<endl;
//    for(int i = 0; i < m; i++){
//        cout << fvec[i].p << ' ' << fvec[i].a <<endl;
//    }

    return 0;
}