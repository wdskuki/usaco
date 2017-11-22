/*
ID: dswei191
LANG: C++
TASK: friday
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int week[7] = {0,0,0,0,0,0,0};
int leapMonthDays[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int noLeapMonthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
ofstream fout("friday.out");
ifstream fin("friday.in");

bool isLeap(int year){
    if(year % 100 == 0){
        if(year % 400 == 0){
            return true;
        }else{
            return false;
        }
    }else{
        if(year % 4 == 0){
            return true;
        }else{
            return false;
        }
    }
}

int loopMonth(int year, int month, int startWeekDay){
    int* monthDays;
    if(month == 1 && isLeap(year)){
        monthDays = leapMonthDays;
    }else{
        monthDays = noLeapMonthDays;
    }
    int idx = (startWeekDay + (13 % 7)) % 7;
    week[idx] += 1;
    int nxtIdx = (startWeekDay + (monthDays[month] % 7)) % 7;
    // cout << nxtIdx <<endl;
    return nxtIdx;
}

int loopYear(int year, int startWeekDay){
    for(int i = 0; i < 12; i++){
        startWeekDay = loopMonth(year, i, startWeekDay);
    }
    return startWeekDay;
}

int main(){
    int n;
    fin >> n;
    int year, startWeekDay = 1;
    for(int i = 0; i < n; i++){
        year = 1900 + i;
        startWeekDay = loopYear(year, startWeekDay);
    }
    for(int i = 0; i < 7; i++){
        fout<< week[i];
        if(i != 6){
            fout << ' ';
        }
    }
    fout << endl;
    return 0;
}
