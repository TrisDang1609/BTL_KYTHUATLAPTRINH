#include<iostream>
#include"subject.h" 
#include"giaovien.h"
#include"thuatToan.h"
#include<string>
#include<vector>
#include <iomanip>
//#include"algorithm.h"
using namespace std;

int main(){
    
    SubjectTable sb;
    sb.readData();
    Teacher gv;
    gv.readData();
    advancedSort(gv, sb);
    
    while(true){
        show();
        int choice;
        cin >> choice;
        if(choice == 1){
            ShowFullSchedule(gv, sb);
        }
        else if(choice == 2){
            ShowWithTeacherName(gv, sb);
        }
        else if(choice == 3){
            ShowWithDayOfWeek(gv, sb);
        }
        else if(choice == 4){
            ShowWithCourseID(gv, sb);
        }
        else if(choice == 6){
            break;
        }
        else if(choice == 5){
            cout << "Tien hanh sua duoi thong tin mon hoc" << endl;
            while(true){
                showSubjectChoice();
                int choice1;
                cin >> choice1;
                if(!suadoithongtinmonhoc(choice1, sb)) break;;
            }
        }
        else{
            cout << "LOI!!" << endl;
            cout<<"Xin moi nhap lai lua chon"<<endl;
        }
    }
}

