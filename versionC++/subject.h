#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

#ifndef SUBJECT_H
#define SUBJECT_H
class SubjectTable{
    private:
        string IDClass;
        string CourseID;
        string Name;
        string DayOfWeek;
        string Time;
        string Place;
        string TeacherName;
        bool status = false;
        int linkToTeacher = -1;

    public:
        SubjectTable(){}
        SubjectTable(string _IDClass, string _CourseID, string _Name, string _DayOfWeek, string _Time, string _Place,string _TeacherName) : IDClass(_IDClass), CourseID(_CourseID), Name(_Name), DayOfWeek(_DayOfWeek), Time(_Time), Place(_Place),TeacherName(_TeacherName){}
        void addSubject();
        void delSubject();
        void editSubject();
        void searchSubject();
        void showSubject();
        void readData();
        void writeData();
        void sortByID();
        void sortByName();
        void setName(string _Name){
            Name = _Name;
        }
        void setCourseID(string _CourseID){
            CourseID = _CourseID;
        }
        void setDayOfWeek(string _DayOfWeek){
            DayOfWeek = _DayOfWeek;
        }
        void setTime(string _Time){
            Time = _Time;
        }
        void setPlace(string _Place){
            Place = _Place;
        }
        void setTeacherName(string _TeacherName){
            TeacherName = _TeacherName;
        }
        
        string getID(){
            return IDClass;
        }
        string getName(){
            return Name;
        }
        string getTime(){
            return Time;
        }
        string getDayOfWeek(){
            return DayOfWeek;
        }
        string getPlace(){
            return Place;
        }
        string getTeacherName(){
            return TeacherName;
        }
        string getCourseID(){
            return CourseID;
        }
        

        void setLink(int i){
            linkToTeacher = i;
        }
        int getLink(){
            return linkToTeacher;
        }
        void setStatus(bool _status){
            status = _status;
        }
        bool getStatus(){
            return status;
        }
        
};

vector<SubjectTable> listSubject;

void SubjectTable::readData() {
    ifstream file("TKB.csv");
    if (!file.is_open()) {
        cerr << "Không thể mở tệp CSV." << endl;
        return;
    }

    string header, line;
    string _IDClass, _CourseID, _Name, _DayOfWeek, _Time, _Place, _TeacherName;
    getline(file, header); // Đọc dòng tiêu đề

    while (getline(file, line)) {
        stringstream str(line);
        if (getline(str, _IDClass, ',') && getline(str, _CourseID, ',') && getline(str, _Name, ',') && 
            getline(str, _DayOfWeek, ',') && getline(str, _Time, ',') && getline(str, _Place, ',') && getline(str, _TeacherName, ',')) {
            listSubject.push_back(SubjectTable(_IDClass, _CourseID, _Name, _DayOfWeek, _Time, _Place,_TeacherName));
        } else {
            cerr << "Loi dinh dang o vong: " << line << endl;
        }
    }
    file.close();
}

void SubjectTable::showSubject(){
    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
	printf("| %-8s | %-12s | %-50s | %-8s | %-20s | %-18s |\n", "Ma lop", "Ma hoc phan", "Ten mon hoc", "Thu", "Thoi gian", "Dia diem hoc");
	printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
	for(int i=0; i<listSubject.size(); i++){
		printf("| %-8s | %-12s | %-50s | %-8s | %-20s | %-18s | %-18s |\n", listSubject[i].IDClass.c_str(), listSubject[i].CourseID.c_str(), listSubject[i].Name.c_str(), listSubject[i].DayOfWeek.c_str(), listSubject[i].Time.c_str(), listSubject[i].Place.c_str(),listSubject[i].TeacherName.c_str());
	}
	printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
}
#endif
