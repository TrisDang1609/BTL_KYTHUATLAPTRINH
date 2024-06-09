#include<iostream>
#include"subject.h" 
#include"giaovien.h"
#include"thuatToan.h"
#include<string>
#include<vector>
//#include"algorithm.h"
using namespace std;

void ShowFullSchedule(Teacher gv, SubjectTable sb) //Xuat ra tat ca thoi khoa bieu
{
    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
	printf("| %-8s | %-12s | %-50s | %-8s | %-20s | %-18s |\n", "Ma lop", "Ten mon hoc", "Thu", "Thoi gian", "Dia diem hoc","Ten Giao vien");
	printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
	for(int i=0; i<listSubject.size(); i++){
		printf("| %-8s | %-12s | %-50s | %-8s | %-20s | %-18s |\n", listSubject[i].getID(), listSubject[i].getName(), listSubject[i].getDayOfWeek(), listSubject[i].getTime(), listSubject[i].getPlace(),listSubject[i].getTeacherName());
	}
	printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
}

void ShowWithTeacherName(Teacher gv, SubjectTable sb) //Xuat ra theo lua chon ten giao vien 
{
    int choice;
    cout<<"Chon ten giao vien: "<<endl;
    for (int i = 0; i < listTeacher.size(); i++){
        cout<<i<<"."<<listTeacher[i].getName()<<endl;
    }
    cin>>choice;


    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
    printf("| %-8s | %-12s | %-50s | %-8s | %-20s | %-18s |\n", "Ma lop", "Ten mon hoc", "Thu", "Thoi gian", "Dia diem hoc","Ten Giao vien");
    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
    for(int i=0; i<listSubject.size(); i++){
        if(listSubject[i].getTeacherName() == listTeacher[choice].getName()){
            printf("| %-8s | %-12s | %-50s | %-8s | %-20s |\n", listSubject[i].getID(), listSubject[i].getName(), listSubject[i].getDayOfWeek(), listSubject[i].getTime(), listSubject[i].getPlace());
        }
    }
    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
}

void ShowWithDayOfWeek(Teacher gv, SubjectTable sb) //Xuat ra theo lua chon thu{
    {cout<<"Nhap vao thu: "<<endl;
    string day;
    cin>>day;
    
    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
    printf("| %-8s | %-12s | %-50s | %-8s | %-20s | %-18s |\n", "Ma lop", "Ten mon hoc", "Thu", "Thoi gian", "Dia diem hoc","Ten Giao vien");
    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
    for(int i=0; i<listSubject.size(); i++){
        if(listSubject[i].getDayOfWeek() == day){
            printf("| %-8s | %-12s | %-50s | %-8s | %-20s | %-18s |\n", listSubject[i].getID(), listSubject[i].getName(), listSubject[i].getDayOfWeek(), listSubject[i].getTime(), listSubject[i].getPlace(),listSubject[i].getTeacherName());
        }
    }
    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
}

void ShowWithCourseID(Teacher gv, SubjectTable sb) //Xuat ra theo lua chon ma hoc phan
{
    cout<<"Nhap vao ma hoc phan: "<<endl;
    string courseID;
    cin>>courseID;
    
    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
    printf("| %-8s | %-12s | %-50s | %-8s | %-20s | %-18s |\n", "Ma lop", "Ten mon hoc", "Thu", "Thoi gian", "Dia diem hoc","Ten Giao vien");
    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
    for(int i=0; i<listSubject.size(); i++){
        if(listSubject[i].getID() == courseID){
            printf("| %-8s | %-12s | %-50s | %-8s | %-20s | %-18s |\n", listSubject[i].getID(), listSubject[i].getName(), listSubject[i].getDayOfWeek(), listSubject[i].getTime(), listSubject[i].getPlace(),listSubject[i].getTeacherName());
        }
    }
    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
}

//void



int main(){
    cout<<"checkpoint 1";
    SubjectTable sb;
    cout<<"checkpoint 2";
    
    sb.readData();
    cout<<"checkpoint 3";
    //sb.showSubject();
    Teacher gv;
    cout<<"checkpoint 4";
    gv.readData();
    cout<<"checkpoint 5";
    advancedSort(gv, sb);
    cout<<"checkpoint 6";

    ShowWithCourseID(gv, sb);
    cout<<"Test chuc nang";
    cout << endl;
}
