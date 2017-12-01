
/*
ID: dswei191
LANG: C++
TASK: castle
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <string.h>

#define MAX_VALUE 50
using namespace std;
ofstream fout("castle.out");
ifstream fin("castle.in");

int N, M;
string wall[MAX_VALUE+1][MAX_VALUE+1];
int visit[MAX_VALUE+1][MAX_VALUE+1];

int numRoom = 0;
int maxRoomSize = 0;
int maxCreatedRoomSize = 0;
int idxA = -1;
int idxB = MAX_VALUE+1;
int idxK;

// (W, N, E, S) <=> (0, 1, 2, 3) <=> (左、上、右、下)
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

//洪水算法遍历连通图
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

// 将数字转化为方向字母
char direction(int i){
    char ret;
    switch(i){
        case 0:
            ret = 'W';
            break;
        case 1:
            ret = 'N';
            break;
        case 2:
            ret = 'E';
            break;
        case 3:
            ret = 'S';
            break;
    }
    return ret;
}

//遍历每个房间的每一堵墙移去之后的连通图
void removeWall(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            for(int k = 0; k < 4; k++){
                memset(visit, 0, sizeof(visit));
                if (wall[i][j][k] == '1') {
                    wall[i][j][k] = '0';
                    if (visit[i][j] == 0) {
                        int t = dfs(i, j);
                        if (t > maxCreatedRoomSize) {
                            maxCreatedRoomSize = t;
                            idxA = i;
                            idxB = j;
                            idxK = k;
                        } else if (t == maxCreatedRoomSize) {
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

    floodFill();
    removeWall();

    fout<< numRoom<<endl;
    fout<< maxRoomSize<<endl;
    fout<< maxCreatedRoomSize<<endl;
    fout << idxA << " "<<idxB << " "<<direction(idxK)<<endl;
    return 0;
}