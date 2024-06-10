#include<iostream>
#include"subject.h" 
#include"giaovien.h"
#include"thuatToan.h"
#include<string>
#include<vector>
#include <iomanip>
//#include"algorithm.h"
using namespace std;

void ShowFullSchedule(Teacher gv, SubjectTable sb) //Xuat ra tat ca thoi khoa bieu
{
    cout<<"+----------+--------------+----------------------------------------------+----------+----------------------+---------------------+-----------------------+\n";
    cout<<"|"<<" Ma lop   "<<"|"<<setw(6)<<" Ma mon hoc"<<setw(4)<<"|"<<"Ten mon hoc"<<setw(47)<<"|   Thu    |"<<"      Thoi gian       "<<"|"<<" Dia diem hoc        "<<"|"<<"     Ten giao vien     "<<"|"<<endl;
    for(int i=0; i<listSubject.size(); i++){
        cout<<"|"<<listSubject[i].getID()<<setw(6)<<"| "<<listSubject[i].getCourseID()<<setw(14-listSubject[i].getCourseID().size())<<"|"<<listSubject[i].getName()<<setw(47-listSubject[i].getName().size())<<"|"<<setw(5)<<listSubject[i].getDayOfWeek()<<setw(6)<<"|"<<setw(15)<<listSubject[i].getTime()<<setw(8)<<"|"<<setw(7)<<listSubject[i].getPlace()<<setw(15)<<"|"<<listSubject[i].getTeacherName()<<setw(24-listSubject[i].getTeacherName().size())<<"|"<<endl;
    }
	cout<<"+----------+--------------+---------------------------------------------+----------+----------------------+---------------------+-----------------------+\n";
}

void ShowWithTeacherName(Teacher gv, SubjectTable sb) //Xuat ra theo lua chon ten giao vien 
{
    int choice;
    cout<<"Danh sach giao vien: "<<endl;
    for (int i = 0; i < listTeacher.size(); i++){
        cout<<i<<"."<<listTeacher[i].getName()<<endl;
    }
    cout<<"Chon giao vien: "<<endl;
    
    cin>>choice;
    cout<<"+----------+--------------+----------------------------------------------+----------+----------------------+---------------------+-----------------------+\n";
    cout<<"|"<<" Ma lop   "<<"|"<<setw(6)<<" Ma mon hoc"<<setw(4)<<"|"<<"Ten mon hoc"<<setw(47)<<"|   Thu    |"<<"      Thoi gian       "<<"|"<<" Dia diem hoc        "<<"|"<<"     Ten giao vien     "<<"|"<<endl;
    cout<<"+----------+--------------+----------------------------------------------+----------+----------------------+---------------------+-----------------------+\n";
    for(int i=0; i<listSubject.size(); i++){
        if(listSubject[i].getTeacherName() == listTeacher[choice].getName()){
    
        cout<<"|"<<listSubject[i].getID()<<setw(6)<<"| "<<listSubject[i].getCourseID()<<setw(14-listSubject[i].getCourseID().size())<<"|"<<listSubject[i].getName()<<setw(47-listSubject[i].getName().size())<<"|"<<setw(5)<<listSubject[i].getDayOfWeek()<<setw(6)<<"|"<<setw(15)<<listSubject[i].getTime()<<setw(8)<<"|"<<setw(7)<<listSubject[i].getPlace()<<setw(15)<<"|"<<listSubject[i].getTeacherName()<<setw(24-listSubject[i].getTeacherName().size())<<"|"<<endl;
	
        }
    
        }    
        cout<<"+----------+--------------+----------------------------------------------+----------+----------------------+---------------------+-----------------------+\n";
    }



void ShowWithDayOfWeek(Teacher gv, SubjectTable sb) //Xuat ra theo lua chon thu{
    {
    string choice;
    cout<<"Chon ngay trong tuan: "<<endl;
    cin>>choice;
    cout<<"+----------+--------------+----------------------------------------------+----------+----------------------+---------------------+-----------------------+\n";
    cout<<"|"<<" Ma lop   "<<"|"<<setw(6)<<" Ma mon hoc"<<setw(4)<<"|"<<"Ten mon hoc"<<setw(47)<<"|   Thu    |"<<"      Thoi gian       "<<"|"<<" Dia diem hoc        "<<"|"<<"     Ten giao vien     "<<"|"<<endl;
    cout<<"+----------+--------------+----------------------------------------------+----------+----------------------+---------------------+-----------------------+\n";
    for(int i=0; i<listSubject.size(); i++){
        if(listSubject[i].getDayOfWeek() == choice){
    
        cout<<"|"<<listSubject[i].getID()<<setw(6)<<"| "<<listSubject[i].getCourseID()<<setw(14-listSubject[i].getCourseID().size())<<"|"<<listSubject[i].getName()<<setw(47-listSubject[i].getName().size())<<"|"<<setw(5)<<listSubject[i].getDayOfWeek()<<setw(6)<<"|"<<setw(15)<<listSubject[i].getTime()<<setw(8)<<"|"<<setw(7)<<listSubject[i].getPlace()<<setw(15)<<"|"<<listSubject[i].getTeacherName()<<setw(24-listSubject[i].getTeacherName().size())<<"|"<<endl;
	
        }
    
        }    
        cout<<"+----------+--------------+---------------------------------------------+----------+----------------------+---------------------+-----------------------+\n";
    }


void ShowWithCourseID(Teacher gv, SubjectTable sb) //Xuat ra theo lua chon ma hoc phan
{
    cout<<"Nhap vao ma hoc phan: "<<endl;
    string courseID;
    cin>>courseID;
    
    cout<<"+----------+--------------+----------------------------------------------+----------+----------------------+---------------------+-----------------------+\n";
    cout<<"|"<<" Ma lop   "<<"|"<<setw(6)<<" Ma mon hoc"<<setw(4)<<"|"<<"Ten mon hoc"<<setw(47)<<"|   Thu    |"<<"      Thoi gian       "<<"|"<<" Dia diem hoc        "<<"|"<<"     Ten giao vien     "<<"|"<<endl;
    cout<<"+----------+--------------+----------------------------------------------+----------+----------------------+---------------------+-----------------------+\n";
    for(int i=0; i<listSubject.size(); i++){
        if(listSubject[i].getID() == courseID){
            cout<<"|"<<listSubject[i].getID()<<setw(6)<<"| "<<listSubject[i].getCourseID()<<setw(14-listSubject[i].getCourseID().size())<<"|"<<listSubject[i].getName()<<setw(46-listSubject[i].getName().size())<<"|"<<setw(5)<<listSubject[i].getDayOfWeek()<<setw(6)<<"|"<<setw(15)<<listSubject[i].getTime()<<setw(8)<<"|"<<setw(7)<<listSubject[i].getPlace()<<setw(15)<<"|"<<listSubject[i].getTeacherName()<<setw(24-listSubject[i].getTeacherName().size())<<"|"<<endl;
        }
    }
    cout<<"+----------+--------------+----------------------------------------------+----------+----------------------+---------------------+-----------------------+\n";
  
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
    cout<<"checkpoint 6"<<endl;

    
    ShowFullSchedule(gv, sb);


    cout<<"Test chuc nang";
    cout << endl;
}

