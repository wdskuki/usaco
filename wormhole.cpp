
/*
ID: dswei191
LANG: C++
TASK: wormhole
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
ofstream fout("wormhole.out");
ifstream fin("wormhole.in");

#define MAX_N 12

int N;
int ret = 0;
vector<int> pairs(MAX_N+1, -1); //pairs[i] = j,表示i和j是一对
vector<int> nxt(MAX_N+1, -1); //next[i] = j, 表示i的右边第一个为j
vector<pair<int, int> > wormholes(MAX_N+1); //表示wormhole的坐标
vector<bool> visit(MAX_N+1, false); //visit[i],表示i是否被访问过
void print(vector<int> vec){
    for(int i = 1; i <=N; i++){
        cout<< vec[i] <<endl;
    }
}
//检测是否有环路

bool checkLoop(int i) {
    /**
     * 从一个点出来，一直找到他右侧的第一个点
     *
     * 1. 如果没有找到，则失败
     * 2. 如果找到了 i，且已经被访问过，则成功
     * 3. 如果找到了 i，且没有被访问过，则进入到改点的配对点 j，继续checkLoop
     */

//    if(nxt[i] == -1){
//        return false;
//    }
//
//    //存在右侧节点
//    if(visit[nxt[i]] == true){
//        return true;
//    }
//    //右侧节点没有被访问过
//    visit[nxt[i]] = true;
//
//    return checkLoop(pairs[nxt[i]]);


    if(visit[i] == true){
        return true;
    }

    visit[i] = true;

    if(nxt[pairs[i]] == -1){
        return false;
    }else{
        return checkLoop(nxt[pairs[i]]);
    }

}

bool checkLoop(){
    for(int i = 1; i <= N; i++){
        bool noLoop = false;
        int start = i;
        for(int j = 0; j < N; j++){
            int pairIndex = pairs[start];
            if(nxt[pairIndex] == -1){
                noLoop = true;
                break;
            }else{
                start = nxt[pairIndex];
            }
        }
        if(noLoop == false){
            return true;
        }
    }
    return false;
}

void makePairs(){
    int i;
    for(i = 1; i <= N; i++){
        if(pairs[i] == -1)
            break;
    }
    if( i > N){
        //所有虫洞都配对好了
//        if(checkLoop()){
//            ret += 1;
//        }
        for(int k = 1; k <= N; k++){
            for(int t = 1; t <= N; t++){
                visit[t] = false;
            }
            if(checkLoop(k)){
                ret +=1;
                break;
            }
        }
    }
    for(int j = i+1; j <= N; j++){
        if(pairs[j] == -1){
            pairs[i] = j;
            pairs[j] = i;
            makePairs();
            pairs[i] = -1;
            pairs[j] = -1;
        }
    }
}

void makePairs(int index){
    if(index > N){
        //所有的虫洞都配对好了
        for(int k = 1; k <= N; k++){
            for(int t = 1; t <= N; t++){
                visit[t] = false;
            }
            if(checkLoop(k)){
                ret +=1;
                break;
            }
        }
        return;
    }
    if(pairs[index] != -1){
        makePairs(index + 1);
        return;
    }else{
        for(int i = index + 1; i <= N; i++){
            if(pairs[i] == -1){
                pairs[index] = i;
                pairs[i] = index;
                makePairs(index + 1);
                pairs[i] = pairs[index] = -1;
            }
        }
    }
}

int main(){
    fin>>N;
    for(int i = 1; i <=N; i++){
        int x, y;
        fin>>x>>y;
        wormholes[i] = make_pair(x, y);
    }

    for(int i = 1; i <= N; i++){
        int nextIndex = -1;
        for(int j = 1; j <= N; j++){
            if(wormholes[i].second == wormholes[j].second && wormholes[i].first < wormholes[j].first){
                if(nextIndex < 0 || wormholes[nextIndex].first > wormholes[j].first){
                    nextIndex = j;
                }
            }
        }
        nxt[i] = nextIndex;
    }

    makePairs();
    fout<<ret<<endl;

    return 0;
}
