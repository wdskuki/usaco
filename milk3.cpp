
/*
ID: dswei191
LANG: C++
TASK: milk3
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX_N 20
using namespace std;
ofstream fout("milk3.out");
ifstream fin("milk3.in");


int Capacity[3];
int retHash[MAX_N + 1];
int visit[MAX_N+1][MAX_N+1][MAX_N+1];
class Volume{
public:
    int v[3];
    Volume(int a, int b, int c){
        v[0] = a;
        v[1] = b;
        v[2] = c;
    }
};


bool isVisited(Volume v){
    if(visit[v.v[0]][v.v[1]][v.v[2]] == 1){
        return true;
    }else{
        return false;
    }
}
void dump(queue<Volume> &qvol){
    Volume vol = qvol.front();
    qvol.pop();
    if(vol.v[0] == 0){
        retHash[vol.v[2]] = 1;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i != j && vol.v[i] != 0 && vol.v[j] < Capacity[j]){
                Volume tmp(vol.v[0], vol.v[1], vol.v[2]);
                int rest = Capacity[j] - tmp.v[j];
                if(tmp.v[i] > rest){
                    tmp.v[i] = tmp.v[i] - rest;
                    tmp.v[j] = Capacity[j];
                    if(!isVisited(tmp)){
                        visit[tmp.v[0]][tmp.v[1]][tmp.v[2]] = 1;
                        qvol.push(tmp);
                    }
                }else{
                    tmp.v[j] = tmp.v[j] + tmp.v[i];
                    tmp.v[i] = 0;
                    if(!isVisited(tmp)){
                        visit[tmp.v[0]][tmp.v[1]][tmp.v[2]] = 1;
                        qvol.push(tmp);
                    }
                }
            }
        }
    }
}

void dump(Volume vol){
    if(vol.v[0] == 0){
        retHash[vol.v[2]] = 1;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i != j && vol.v[i] != 0 && vol.v[j] < Capacity[j]){
                Volume tmp(vol.v[0], vol.v[1], vol.v[2]);
                int rest = Capacity[j] - tmp.v[j];
                if(tmp.v[i] > rest){
                    tmp.v[i] = tmp.v[i] - rest;
                    tmp.v[j] = Capacity[j];
                    if(!isVisited(tmp)){
                        visit[tmp.v[0]][tmp.v[1]][tmp.v[2]] = 1;
                        dump(tmp);
                        visit[tmp.v[0]][tmp.v[1]][tmp.v[2]] = 0;
                    }
                }else{
                    tmp.v[j] = tmp.v[j] + tmp.v[i];
                    tmp.v[i] = 0;
                    if(!isVisited(tmp)){
                        visit[tmp.v[0]][tmp.v[1]][tmp.v[2]] = 1;
                        dump(tmp);
                        visit[tmp.v[0]][tmp.v[1]][tmp.v[2]] = 0;
                    }
                }
            }
        }
    }
}

//深搜
void dfs(){
    Volume vol(0, 0, Capacity[2]);
    visit[vol.v[0]][vol.v[1]][vol.v[2]] = 1;
    dump(vol);
}

//广搜
void bfs(){
    queue<Volume> qvol;
    Volume vol(0, 0, Capacity[2]);
    visit[vol.v[0]][vol.v[1]][vol.v[2]] = 1;
    qvol.push(vol);
    while(!qvol.empty()){
        dump(qvol);
    }
}






int main(){
    for(int i = 0; i < 3; i++){
        fin >> Capacity[i];
    }

//    bfs();
    dfs();
    bool flag = false;
    for(int i = 0; i < MAX_N + 1; i++){
        if(retHash[i] != 0){
            if(flag == false){
                flag = true;
                fout<<i;
            }else{
                fout << " "<<i;
            }
        }
    }
    fout<<endl;
    return 0;
}