
/*
ID: dswei191
LANG: C++
TASK: combo
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
ofstream fout("main.out");
ifstream fin("main.in");

int n;
int ret = 0;
class Position{
public:
    int x, y;
    int pairIndex;
    bool visited;
    Position(int x, int y){
        this->x = x;
        this->y = y;
        this->pairIndex = -1;
        this->visited = false;
    }
    void clear(){
        this->pairIndex = -1;
        this->visited = false;
    }
};
vector<Position> vec;

void reset(){
    for(int i = 0; i < n; i++){
        vec[i].clear();
    }
}

int hasNext(int index){
    bool flag = false;
    for(int i = 0; i < n; i++){
        if(i != index && vec[i].y == vec[index].y && vec[i].x > vec[index].x){
            flag = true;
            if(vec[i].visited == true){
                return -1;
            }else{
                return i;
            }
        }
    }
    if(flag == false){
        return -2;
    }
}

bool checkLoop(int index){
    if(vec[index].visited = true){
        return true;
    }else{
        vec[index].visited = true;

        /**
         * 找到右边的节点
         * 如果右边没有节点，则返回失败
         * 如果右边有节点，且该节点没有被访问过，则继续checkLoop
         * 如果右边有节点，且该节点被访问过，则返回true
         */
        int rightIndex = hasNext(index);
        if(rightIndex == -2){
            return false; //右侧没有节点
        }else if(rightIndex == -1){
            return true;
        }else{
            return checkLoop(rightIndex);
        }
    }
}
void genPairs(int index){
    if(index == n - 1){
        for(int i = 0; i < n; i++){
            if(checkLoop(i)){
                ret +=1;
                reset();
                break;
            }
        }
        return;
    }
    if(vec[index].pairIndex != -1){
        genPairs(index + 1);
    }else{
        for(int i = index + 1; i < n; i++){
            if(vec[i].pairIndex == -1){
                vec[index].pairIndex = i;
                vec[i].pairIndex = index;
                genPairs(index+1);
                vec[index].pairIndex = -1;
                vec[i].pairIndex = -1;
            }
        }
    }
}

bool comp(Position a, Position b){
    return a.x < b.x;
}
int main(){
    ret = 0;
    fin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        fin >> x >> y;
        Position p(x, y);
        vec.push_back(p);
    }

    sort(vec.begin(), vec.end(), comp);

//    for(int i = 0; i < n; i++){
//        cout<<"("<<vec[i].x<<","<<vec[i].y<<")"<<endl;
//    }
    genPairs(0);
    cout<< ret <<endl;

//    cout<<"Hello world"<<endl;

    return 0;
}
