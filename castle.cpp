
/*
ID: dswei191
LANG: C++
TASK: main
*/



/**
 * w,n,e,s，对应0, 1, 2, 3, 左、上、右、下
 */
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

#define MAX_VALUE 50
using namespace std;
ofstream fout("main.out");
ifstream fin("main.in");

int N, M;
string wall[MAX_VALUE+1][MAX_VALUE+1];
int visit[MAX_VALUE+1][MAX_VALUE+1];

int numRoom = 0;
int maxRoomSize = 0;
int maxCreatedRoomSize = 0;
int idxA = -1;
int idxB = MAX_VALUE+1;
int idxK;


string transform(int a){
    string ret = "";
    for(int i = 0; i < 4; i++){
        if(a == 0){
            ret += "0";
        }else{
            if(a % 2 == 1){
                ret += "1";
            }else{
                ret += "0";
            }
            a = a / 2;
        }
    }
    return ret;
}

int dfs(int a, int b){
    if(a <1 || a > N || b < 1 || b > M || visit[a][b] == 1){
        return 0;
    }
    int ret = 1;
    visit[a][b] = 1;
    for(int i = 0; i < 4; i++){ //0, 1, 2, 3 => 左、上、右、下
        if(wall[a][b][i] == '0'){
            //没墙
            switch(i){
                case 0:
                    ret += dfs(a, b-1);
                    break;
                case 1:
                    ret += dfs(a-1, b);
                    break;
                case 2:
                    ret += dfs(a, b+1);
                    break;
                case 3:
                    ret += dfs(a+1, b);
                    break;
            }
        }
    }
    return ret;
}


void floodFill(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(visit[i][j] == 0){
                ++numRoom;
                int t = dfs(i, j);
                maxRoomSize = (t > maxRoomSize) ? t : maxRoomSize;
            }
        }
    }
}


void removeWall(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            memset(visit, 0, sizeof(visit));
            for(int k = 0; k < 4; k++){
                if(i == 4 && j == 1){
                    cout<<"hel"<<endl;
                }
                if (wall[i][j][k] == '1') {
                    wall[i][j][k] = '0';
                    if (visit[i][j] == 0) {
                        int t = dfs(i, j);
                        if (t > maxCreatedRoomSize) {
                            maxCreatedRoomSize = t;
                        } else if (t == maxCreatedRoomSize) {
                            cout << "hello: " << i << " " << j << " " << k << endl;
                            if (idxB > j) {
                                maxCreatedRoomSize = t;
                                idxA = i;
                                idxB = j;
                                idxK = k;
                            } else if (idxB == j) {
                                if (idxA < i) {
                                    maxCreatedRoomSize = t;
                                    idxA = i;
                                    idxB = j;
                                    idxK = k;
                                }
                            }
                        }
                    }
                    wall[i][j][k] = '1';
                }
            }
        }
    }
}
int main(){
    fin >> M >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            int t;
            fin >> t;
            wall[i][j] = transform(t);
        }
    }
    memset(visit, 0, sizeof(visit));
    floodFill();
    removeWall();

    cout<< numRoom<<endl;
    cout<< maxRoomSize<<endl;
    cout<< maxCreatedRoomSize<<endl;
    cout << idxA << " "<<idxB << " "<<idxK<<endl;
    return 0;
}