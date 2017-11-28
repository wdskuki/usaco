
/*
ID: dswei191
LANG: C++
TASK: ariprog
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ofstream fout("ariprog.out");
ifstream fin("ariprog.in");

int N, M;
int h[125001];
vector<pair<int,int > > vec;


bool valid(int a, int b){
    for(int n = 0; n < N; n++){
        if(h[a + n * b] != 1){
            return false;
        }
    }
    return true;
}
int main(){
    fin >> N >> M;
    for(int i = 0; i <= M; i++){
        for(int j = 0; j <=M; j++){
            int t = i * i + j * j;
            h[t] = 1;
        }
    }
    int M2 = M*M*2;
    int maxB = M2 / (N-1);
    bool flag = false;
    for (int b = 1; b <= maxB; b++){
        for(int a = 0; a <= M2; a++){
            if(a + b * (N-1) > M2){
                break;
            }
            if(valid(a, b)){
                flag = true;
                fout<< a << " "<<b <<endl;
            }
        }
    }

    if(flag == false){
        fout << "NONE"<<endl;
    }




    return 0;
}
