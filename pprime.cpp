
/*
ID: dswei191
LANG: C++
TASK: pprime
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
ofstream fout("pprime.out");
ifstream fin("pprime.in");
int a, b;

vector<int> vec;


bool isPrime(int t){
    if(t < a || t > b){
        return false;
    }
    if(t % 2 == 0){
        return false;
    }
    int sq = (int)sqrt(t)+ 1;
    for(int i = 3; i <= sq; i+=2){
        if(t % i == 0){
            return false;
        }
    }
    vec.push_back(t);
    return true;
}
int main(){
    fin >> a >> b;
    for(int i1 = 1; i1 < 10; i1++){
        int t1 = i1;
        int t2 = i1 * 10 + i1;
        isPrime(t1);
        isPrime(t2);
        for(int i2 = 0; i2 < 10; i2++){
            int t1 = i1 * 100 + i2 * 10 + i1;
            int t2 = i1 * 1000 + i2 * 100 + i2 * 10 + i1;
            isPrime(t1);
            isPrime(t2);
            for(int i3 = 0; i3 < 10; i3++){
                int t1 = i1 * 10000 + i2 * 1000 + i3 * 100  + i2 * 10 + i1;
                int t2 = i1 * 100000 + i2 * 10000 + i3 * 1000 + i3 * 100 + i2 * 10 + i1;
                isPrime(t1);
                isPrime(t2);
                for(int i4 = 0; i4 < 10; i4++){
                    int t1 = i1 * 1000000 + i2 * 100000 + i3 * 10000  + i4 * 1000 + i3 * 100 + i2 * 10 + i1;
                    int t2 = i1 * 10000000 + i2 * 1000000 + i3 * 100000 + i4 * 10000 + i4 * 1000 + i3 * 100 + i2 * 10 + i1;
                    isPrime(t1);
                    isPrime(t2);
                }
            }
        }
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++){
        fout<<vec[i]<<endl;
    }
    return 0;
}
