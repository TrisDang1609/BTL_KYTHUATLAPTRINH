#include<iostream>
#include"subject.h" 
#include"giaovien.h"
#include"thuatToan.h"
#include<string>
#include<vector>
//#include"algorithm.h"
using namespace std;
int main(){
    SubjectTable sb;
    sb.readData();
    //sb.showSubject();
    Teacher gv;
    gv.readData();
    advancedSort(gv, sb);
    for (int i = 0; i < listSubject.size(); i++){
        //cout << convertStringToInt(listSubject[i].getDayOfWeek()) << " ";
        cout << listSubject[i].getLink() << " ";
    }
    cout << endl;
    cout << listSubject[9].getName();
}