
/*
ID: dswei191
LANG: C++
TASK: crypt1
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ofstream fout("crypt1.out");
ifstream fin("crypt1.in");


int ret;
vector<int> vec;

int N;

int input[10];
bool valid(int num, int length){
    int len = 0;
    while(num != 0){
        int t = num % 10;
        if(input[t] != 1){
            return false;
        }
        num = num / 10;
        ++len;
    }
    if(len != length){
        return false;
    }else{
        return true;
    }
}

void solve(){
    for(int i = 0; i < vec.size(); i++){
        for (int j = 0; j < vec.size(); j++){
            for(int k = 0; k < vec.size(); k++){
                int val1 = vec[i] * 100 + vec[j] * 10 + vec[k];
                for(int z = 0; z < vec.size(); z++){
                    if(!valid(val1 * vec[z], 3)){
                        continue;
                    }
                    for(int t = 0; t < vec.size(); t++){
                        if(!valid(val1 * vec[t], 3)){
                            continue;
                        }

                        int val2 = vec[z] * 10 + vec[t];
                        int val = val1 * val2;
                        if(val < 10000 && valid(val1 * val2, 4)){
                            ret +=1;
                        }
                    }
                }
            }
        }
    }
}



int main(){

    fin>> N;
    for(int i = 0; i < N; i++){
        int t;
        fin >> t;
        input[t] = 1;
        vec.push_back(t);
    }

    solve();

    fout<<ret<<endl;
    return 0;
}
