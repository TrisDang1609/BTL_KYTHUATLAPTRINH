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
        void sortByID();
        void writeData();
        void changeGiaoVien(int &subjectPos, int &newTeacher);
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
        void setNewTeacher(int subjectPos, int newTeacher);
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
void SubjectTable::addSubject(){
    cout << "Nhap thong tin cua mon hoc moi theo form duoi day:" << endl;
    string _IDClass, _CourseID, _Name, _DayOfWeek, _Time, _Place, _TeacherName;
    cout << "Nhap ma lop: ";
    cin.ignore();
    getline(cin, _IDClass);
    cout << "Nhap ma hoc phan: ";
    getline(cin, _CourseID);
    cout << "Nhap ten mon hoc: ";
    getline(cin, _Name);
    cout << "Nhap thu: ";
    getline(cin, _DayOfWeek);
    cout << "Nhap thoi gian: ";
    getline(cin, _Time);
    cout << "Nhap dia diem hoc: ";
    getline(cin, _Place);
    cout << "Nhap ten giao vien: ";
    getline(cin, _TeacherName);
    listSubject.push_back(SubjectTable(_IDClass, _CourseID, _Name, _DayOfWeek, _Time, _Place,_TeacherName));
    cout << "Them mon hoc thanh cong!" << endl;
}
void SubjectTable::delSubject(){
    int delSubjectPos;
    cout << "Nhap vi tri mon hoc can xoa: ";
    for (int i = 0; i < listSubject.size(); i++){
        cout << i << " "<< listSubject[i].Name << endl;
    }
    cin >> delSubjectPos;
    listSubject.erase(listSubject.begin() + delSubjectPos);
    cout << "Xoa mon hoc thanh cong!" << endl;
}
void SubjectTable::editSubject(){
    cout << "Nhap vi tri mon hoc can sua: ";
    for (int i = 0; i < listSubject.size(); i++){
        cout << i << " "<< listSubject[i].Name << endl;
    }
    
    int editSubjectPos;
    cin >> editSubjectPos;
    cout << "Nhap thong tin moi cua mon hoc theo form duoi day:" << endl;
    string _IDClass, _CourseID, _Name, _DayOfWeek, _Time, _Place, _TeacherName;
    cout << "Nhap ma lop: ";
    cin.ignore();
    getline(cin, _IDClass);
    cout << "Nhap ma hoc phan: ";
    getline(cin, _CourseID);
    cout << "Nhap ten mon hoc: ";
    getline(cin, _Name);
    cout << "Nhap thu: ";
    getline(cin, _DayOfWeek);
    cout << "Nhap thoi gian: ";
    getline(cin, _Time);
    cout << "Nhap dia diem hoc: ";
    getline(cin, _Place);
    cout << "Nhap ten giao vien: ";
    getline(cin, _TeacherName);
    listSubject[editSubjectPos].IDClass = _IDClass;
    listSubject[editSubjectPos].CourseID = _CourseID;
    listSubject[editSubjectPos].Name = _Name;
    listSubject[editSubjectPos].DayOfWeek = _DayOfWeek;
    listSubject[editSubjectPos].Time = _Time;
    listSubject[editSubjectPos].Place = _Place;
    listSubject[editSubjectPos].TeacherName = _TeacherName;
    cout << "Sua mon hoc thanh cong!" << endl;
}
void SubjectTable::searchSubject(){
    cout << "Nhap ten mon hoc can tim: ";
    string searchName;
    cin.ignore();
    getline(cin, searchName);
    cout << "Ket qua tim kiem: " << endl;
    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
    printf("| %-8s | %-12s | %-50s | %-8s | %-20s | %-18s |\n", "Ma lop", "Ma hoc phan", "Ten mon hoc", "Thu", "Thoi gian", "Dia diem hoc");
    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
    for(int i=0; i<listSubject.size(); i++){
        if(listSubject[i].Name.find(searchName) != string::npos){
            printf("| %-8s | %-12s | %-50s | %-8s | %-20s | %-18s | %-18s |\n", listSubject[i].IDClass.c_str(), listSubject[i].CourseID.c_str(), listSubject[i].Name.c_str(), listSubject[i].DayOfWeek.c_str(), listSubject[i].Time.c_str(), listSubject[i].Place.c_str(),listSubject[i].TeacherName.c_str());
        }
    }
    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
}
void SubjectTable::sortByID(){
    sort(listSubject.begin(), listSubject.end(), [](const SubjectTable &a, const SubjectTable &b) { // hàm lambda 
        return a.IDClass < b.IDClass;
    });
    cout << "Sap xep thanh cong!" << endl;
}
void SubjectTable::sortByName(){
    sort(listSubject.begin(), listSubject.end(), [](const SubjectTable &a, const SubjectTable &b) { // hàm lambda 
        return a.Name < b.Name;
    });
    cout << "Sap xep thanh cong!" << endl;
}

void SubjectTable::changeGiaoVien(int &subjectPos, int &newTeacher){
    listSubject[subjectPos].setLink(newTeacher);
}
void showSubjectChoice(){
    cout << "1. Tien hanh them mon hoc" << endl;
    cout << "2. Tien hanh xoa mon hoc" << endl;
    cout << "3. Tien hanh sua mon hoc" << endl;
    cout << "4. Tien hanh tim kiem mon hoc" << endl;
    cout << "5. Tien hanh sap xep mon hoc theo ID" << endl;
    cout << "6. Tien hanh sap xep mon hoc theo ten" << endl;
    cout << "7. Tien hanh thay doi giao vien day mon hoc" << endl;
    cout << "8. Them giao vien cho mon chua duoc xep" << endl;
    cout << "9. Thoat tien trinh sua mon hoc" << endl;
}
bool suadoithongtinmonhoc(int choice, SubjectTable &sb){
    if(choice == 1){
        cout << "Tien hanh them mon hoc:" << endl;
        sb.addSubject();
        return true;
    } else if(choice == 2){
        cout << "Tien hanh xoa mon hoc:" << endl;
        sb.delSubject();
        return true;
    } else if(choice == 3){
        cout << "Tien hanh sua mon hoc:" << endl;
        sb.editSubject();
        return true;
    } else if(choice == 4){
        cout << "Tien hanh tim kiem mon hoc:" << endl;
        sb.searchSubject();
        return true;
    } else if(choice ==5){
        cout << "Tien hanh sap xep mon hoc theo ID:" << endl;
        sb.sortByID();
        return true;
    } else if(choice == 6){
        cout << "Tien hanh sap xep mon hoc theo ten:" << endl;
        sb.sortByName();
        return true;
    } else if(choice == 7){
        cout << "Tien hanh thay doi giao vien day mon hoc:" << endl;
        int newTeacher, subjectPos;
        cout << "Nhap vi tri mon hoc can thay doi giao vien: ";
        cin >> subjectPos;
        cout << "Nhap vi tri giao vien moi: ";
        cin >> newTeacher;
        sb.changeGiaoVien(subjectPos, newTeacher);
        return true;
    } else if(choice == 9){
        cout << "Thoat tien trinh sua mon hoc";
        return false;
    } else if(choice == 8){
         for (int i = 0; i < listSubject.size(); i++){
               if(listSubject[i].getLink() == -1){
                    cout << "Nhap chi so cua giao vien can them vao ";
                    int newTeacher;
                    cin >> newTeacher;
                    listSubject[i].setLink(newTeacher);
               }
         }
         return true;
    } else {
        cout << "LOI!!" << endl;
        cout<<"Xin moi nhap lai lua chon"<<endl;
        return true;
    }
}
void SubjectTable :: writeData(){
    ofstream file("TKB_NEW.csv");
    if (!file.is_open()) {
        cerr << "Không thể mở tệp CSV." << endl;
        return;
    }
    file << "Ma lop, Ma hoc phan, Ten mon hoc, Thu, Thoi gian, Dia diem hoc, Ten giao vien" << endl;
    for (int i = 0; i < listSubject.size(); i++) {
        file << listSubject[i].IDClass << "," << listSubject[i].CourseID << "," << listSubject[i].Name << "," << listSubject[i].DayOfWeek << "," << listSubject[i].Time << "," << listSubject[i].Place << "," << listSubject[i].TeacherName << endl;
    }
    file.close();
}
#endif
