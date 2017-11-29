
/*
ID: dswei191
LANG: C++
TASK: sprime
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
ofstream fout("sprime.out");
ifstream fin("sprime.in");

int N;
bool isPrime(int t){
    if(t % 2 == 0 && t != 2){
        return false;
    }
    int sq = (int)sqrt(t)+ 1;
    for(int i = 3; i <= sq; i+=2){
        if(t % i == 0){
            return false;
        }
    }
    return true;
}

int getLen(int t){
    int ret = 0;
    while(t != 0){
        t = t / 10;
        ret +=1;
    }
    return ret;
}

void solution(int number){

    int len = getLen(number);
    if(len == N){
        fout<< number <<endl;
        return;
    }
    for(int i = 1; i < 10; i+=2){
        int tmp = number * 10 + i;
        if(isPrime(tmp)){
            solution(tmp);
        }
    }

}
int main(){

    fin >> N;
    for(int i = 2; i < 10; i++){
        if(isPrime(i)) {
            solution(i);
        }
    }
    return 0;
}