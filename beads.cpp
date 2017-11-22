
/*
ID: dswei191
LANG: C++
TASK: beads
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n;
string bead;

//获得下一个index
int next(int length, int index){
    return (index + 1 + length) % length;
}

//获得上一个index
int pre(int length, int index){
    return (index - 1 + length) % length;
}

bool checkMoveNext(int length, int & index, char & color, int & ret, vector<int> & vec){
    if(vec[index] != 0){
        return false;
    }
    if(color == '\0' || color == 'w'){
        color = bead[index];
        ret += 1;
        vec[index] = 1;
        index = next(length, index);
        return true;
    }else{
        if(bead[index] == 'w' || color == bead[index]){
            ret += 1;
            vec[index] = 1;
            index = next(length, index);
            return true;
        }else{
            return false;
        }
    }
}

bool checkMovePre(int length, int & index, char & color, int & ret, vector<int> & vec){
    if(vec[index] != 0){
        return false;
    }
    if(color == '\0' || color == 'w'){
        color = bead[index];
        ret += 1;
        vec[index] = 1;
        index = pre(length, index);
        return true;
    }else{
        if(bead[index] == 'w' || color == bead[index]){
            ret += 1;
            vec[index] = 1;
            index = pre(length, index);
            return true;
        }else{
            return false;
        }
    }
}




int checkMax(int index){
    int length = bead.length();
    vector<int> check(length, 0);
    if(length <= 0){
        return 0;
    }

    int nextIndex = index;
    int preIndex;
    char nextColor = '\0';
    char preColor = '\0';

    int count = 0;
    preIndex = pre(length, nextIndex);
    while(1){
        if(!checkMoveNext(length, nextIndex, nextColor, count, check)){
            break;
        }
    }
    while(1){
        if(!checkMovePre(length, preIndex, preColor, count, check)){
            break;
        }
    }
    return count;
}

int main(){
    ofstream fout("beads.out");
    ifstream fin("beads.in");

    fin >> n >> bead;
    int ret = 0;
    for(int i = 0; i < n; i++){
        int count = checkMax(i);
        ret = (ret < count) ? count : ret;
    }
    fout << ret <<endl;
    return 0;
}
