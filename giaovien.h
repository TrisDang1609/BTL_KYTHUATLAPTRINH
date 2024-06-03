#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>

#ifndef GIAOVIEN_H
#define GIAOVIEN_H
using namespace std;
class Day{
    bool lessions[13];
public:
    void setDefaultLession(){
        for(int i = 1; i <= 12; i++){
            lessions[i] = true;
        }
    }
    void setBusyLession(int startBusy, int endBusy){
        for(int i = startBusy; i <= endBusy; i++){
            lessions[i] = false;
        }
    }
    bool checkBusy(int start, int end){
        for(int i = start; i <= end; i++){
            if(lessions[i] == false){
                return false;
            }
        }
        return true;
    }
};
class Schedule{
    bool dayOfWeek[7];
    Day day[7];
    public:
    void setDefaultDay(){
        for(int i = 0; i < 7; i++){
            dayOfWeek[i] = true;
        }
        for(int i = 1; i < 7; i++){
            day[i].setDefaultLession();
        }
    }
    bool checkBusy(int start, int end, int numOfDay){
        return day[numOfDay].checkBusy(start, end);
    }
    void setBusy(int start, int end, int numOfDay){
        day[numOfDay].setBusyLession(start, end);
    }
};
class Teacher{
    string name;
    string telNum;
    string subject1, subject2;
    Schedule schedule;
    vector<int> linkToSubject;

public:
    Teacher(){}
    Teacher(string _name, string _telNum, string _subject1, string _subject2) : name(_name), telNum(_telNum), subject1(_subject1), subject2(_subject2){}
    void addTeacher();
    void delTeacher();
    void editTeacher();
    void searchTeacher();
    void showTeacher();
    void readData();
    void writeData();
    void sortByName();
    void setName(string _name){
        name = _name;
    }
    void setTelNum(string _telNum){
        telNum = _telNum;
    }
    void setSubject1(string _subject){
        subject1 = _subject;
    }
    void setSubject2(string _subject){
        subject2 = _subject;
    }
    void setDefaultSchedule(){
        schedule.setDefaultDay();
    }
    string getSubject1(){
        return subject1;
    } 
    string getSubject2(){
        return subject2;
    }
    bool checkBusy(int start, int end, int numOfDay){
        return schedule.checkBusy(start, end, numOfDay);
    }
    void setBusy(int start, int end, int numOfDay){
        schedule.setBusy(start, end, numOfDay);
    }
    void setLink(int i){
        linkToSubject.push_back(i);
    }
};
vector<Teacher> listTeacher;
void Teacher::readData(){
    ifstream file("giaovienData.csv");
    if(!file.is_open()){
        cout << "File bi loi!" << endl;
        return;
    }
    string line;
    while(getline(file, line)){
        stringstream ss(line);
        string name, telNum, subject1, subject2;
        getline(ss, name, ',');
        getline(ss, telNum, ',');
        getline(ss, subject1, ',');
        getline(ss, subject2, ',');
        listTeacher.push_back(Teacher(name, telNum, subject1, subject2));
        listTeacher[listTeacher.size() - 1].setDefaultSchedule();
    }
    
    file.close();
}
void Teacher::showTeacher(){
    cout << "Danh sach giao vien: " << endl;
    for(int i = 0; i < listTeacher.size(); i++){
        cout << "Ten: " << listTeacher[i].name << endl;
        cout << "So dien thoai: " << listTeacher[i].telNum << endl;
        cout << "Mon day: " << listTeacher[i].subject1 << endl;
        cout << "Mon day: " << listTeacher[i].subject2 << endl;
    }
}
#endif