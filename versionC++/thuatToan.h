/*
Trình bày cho ae nghe một chút về tư tưởng của thuật toán lần này:
Nó sort rất đơn giản theo đúng tiêu chỉ thoả mãn về năng lực và thời gian thì nhận, thế thôi 
bạn sẽ đi kiểm tra các yếu tố trong hàm checkFree, kết quả của hàm sẽ là nhận 
khi nhận rồi thì bạn sẽ làm một vài điểu sau để thể hiện là chốt cô này với môn này nhé:
1. setBusy cho giáo viên -- mục tiêu là tránh có môn khác trùng tên lại nhảy vào
2. getLink cho giáo viên và môn học -- mục tiêu là để biết được giáo viên nào dạy môn nào và môn nào được dạy bởi giáo viên nào
3. setStatus cho môn học -- mục tiêu là để biết được môn học này đã được chốt chưa _ cái này thì phục vụ cho việc xuất ra bên ngoài của khánh


Chứng minh tính đúng đắn của thuật toán:
thì thực ra hầu hết các nội dung đều khá là tuyến tính và không có nhiều điều kiện ràng buộc và quy chuẩn phải chính xác 100% nên là bạn sẽ nói về các 
trường hợp và cách mà thuật toán xư lý với nó
1. khi mà rảnh và có năng lực: nhận :)) 
2. khi mà các yếu tố có năng lực và rảnh không thoả mãn thì nó sẽ bỏ qua, do mình xử lý bài toán dưới dạng duyệt trâu (buffalo search) nên nó sẽ xét tất cả các cặp
giáo viên - môn học khác có thể xảy ra nên nó sẽ tự động tìm các ứng viên tiềm năng khác 
nên là yên tâm nó bao trọn 100% các trường hợp có năng lực và tốt theo đúng thứ tự 
3. kết quả có tốt hơn được không thì không thể vì thời gian là đã cố định sẵn, cho dù có dồn như nào thì vấn đề nhân lực là thực tế khó cách rời được
4. khi mà không thể nào thoả mãn được (ví dụ 1 thời điểml, 2 giáo viên, 3 môn học) thì có cố gắng tối ưu đến mấy cũng chịu thôi! :()
*/

/*
LƯU Ý: THUẬT TOÁN SẼ CẦN PHẢI CHẠY LẠI ĐỂ TỐI ƯU NẾU CÓ SỰ TINH CHỈNH VỀ CÁC DỮ LIỆU GIÁO VIÊN VÀ MÔN HỌC
*/

#include <iomanip>
#include<iostream>
#include"subject.h"
#include"giaovien.h"
#include<string>
#include<vector>
#include<sstream>
#include<fstream>

using namespace std;
int compare(string s){
     /*
     Giải thích cho ae một chút về việc quy đổi các giá trị giờ sang số này nhé:
     thứ nhất thì do bạn quy ước cái tiết của giáo viên là số và ở dưới dạng status là 0-1 cho nên không thể nào dùng string của định để giải quyết được 
     cho nên bạn phải convert cái giờ ấy sao cho tương đương với cái quy ước 12 tiết kia
     thứ hai là do cái giờ của bạn không đồng đều, vì có những khoảng nghỉ giữa giờ ấy. tuy nhiên thì giáo viên sẽ được phân công tiết này hay tiết kia thôi cho nên là 
     bạn sẽ kéo nó xuống
     */
     if(s == "0645") return 1;
     if(s == "0730") return 2;
     if(s == "0815" || s == "0825") return 3;
     if(s == "0910" || s == "0920") return 4;
     if(s == "1005" || s == "1015") return 5;
     if(s == "1100") return 6;
     if(s =="1145" || s == "1230") return 7;
     if(s == "1315") return 8;
     if(s == "1400" || s == "1410") return 9;
     if(s == "1455" || s == "1505") return 10;
     if(s == "1550" || s == "1600") return 11;
     if(s == "1645") return 12;
     if(s == "1730") return 13;
     return 0; // không bao giờ xảy ra nhưng mình không ghi vào thì nó lỗi cho nên cứ ghi bừa là 0 vào nhé :))
}
int convertStringToInt(string s){
     return (int)(s[0] - '0'); // cái này đơn giản '1' - '0' = (00000001)_quy ước ascii và chuyển sang int thì thành 1 
}
// các giá trị điểm đầu phù hợp, kết thúc và ngày trong tuần dùng khá nhiều mà nó lại tính toán mất thời gian nên bạn
// xây dựng biến cục bộ xử lý vấn để cho nó đơn giản
int _start, _end, _day; 
 // cái này đơn giản là kiểm chứng xem tại thời giểm của môn này thì cô giáo có năng lực chuyên môn của môn ấy có rảnh không
bool checkFree(Teacher a, SubjectTable b){
     // kiểm tra xem cô có phải là giáo viên của môn này không
     if((a.getSubject1() == b.getName()) || (a.getSubject2() == b.getName())){ 
          // hai cái này để lấy cái đoạn giờ phút mã hoá là 0645, 0730, 0815, 0825, 0910, 0920, 1005, 
          //1015, 1100, 1145, 1230, 1315, 1400, 1410, 1455, 1505, 1550, 1600, 1645, 1730
          string cut1 = "", cut2 = "";
          string c = b.getTime();
          for (int i = 0; i <= 3; i++) cut1 = cut1 + c[i];
          for (int i = 5; i <= 8; i++) cut2 = cut2 + c[i];
          //cout << cut1 << " " << cut2 << endl;
          _start = compare(cut1);
          _end = compare(cut2) - 1;
          _day = convertStringToInt(b.getDayOfWeek());
          if(a.checkBusy(_start, _end, _day)){
               a.setBusy(_start, _end, _day);
               return true;
          }
     };
     return false;  // false thì nó sẽ bỏ qua cô này tìm cô khác nhé 
}

void advancedSort(Teacher gv, SubjectTable sb){
     for (int i = 0; i < listSubject.size(); i++) listSubject[i].setStatus(false); // reset trạng thái môn học mỗi khi chạy sort_ đọc lưu ý bên trên là hiểu
     for (int i = 0; i < listSubject.size(); i++)
     {
          for (int j = 0; j < listTeacher.size(); j++)
          {
               if (checkFree(listTeacher[j], listSubject[i]))
               {
                    listSubject[i].setLink(j);
                    listTeacher[j].setLink(i);
                    listSubject[i].setStatus(true);
                    listSubject[i].setTeacherName(listTeacher[j].getName());
                    
                    break;
               }
          }
     }
}
void ShowFullSchedule(Teacher gv, SubjectTable sb) //Xuat ra tat ca thoi khoa bieu
{
    cout<<"+----------+--------------+----------------------------------------------+----------+----------------------+---------------------+-----------------------+\n";
    cout<<"|"<<" Ma lop   "<<"|"<<setw(6)<<" Ma mon hoc"<<setw(4)<<"|"<<"Ten mon hoc"<<setw(47)<<"|   Thu    |"<<"      Thoi gian       "<<"|"<<" Dia diem hoc        "<<"|"<<"     Ten giao vien     "<<"|"<<endl;
    for(int i=0; i<listSubject.size(); i++){
        cout<<"|"<<listSubject[i].getID()<<setw(6)<<"| "<<listSubject[i].getCourseID()<<setw(14-listSubject[i].getCourseID().size())<<"|"<<listSubject[i].getName()<<setw(47-listSubject[i].getName().size())<<"|"<<setw(5)<<listSubject[i].getDayOfWeek()<<setw(6)<<"|"<<setw(15)<<listSubject[i].getTime()<<setw(8)<<"|"<<setw(7)<<listSubject[i].getPlace()<<setw(15)<<"|"<<listSubject[i].getTeacherName()<<setw(24-listSubject[i].getTeacherName().size())<<"|"<<endl;
    }
	cout<<"+----------+--------------+----------------------------------------------+----------+----------------------+---------------------+-----------------------+\n";
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

void show(){
     cout<<"PHAN CONG GIAO VIEN"<<endl;
    cout<<"1. Xem toan bo thoi khoa bieu"<<endl;
    cout<<"2. Xem theo ten giao vien"<<endl;
    cout<<"3. Xem theo ngay trong tuan"<<endl;
    cout<<"4. Xem theo ma hoc phan"<<endl;
    cout << "5. Tien hanh sua doi thong tin mon hoc" << endl;
    cout << "6. Thoat khoi chuong trinh" << endl;
    cout<<"Chon lua chon: ";
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
bool suadoithongtinmonhoc(int choice, SubjectTable sb){
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
        listSubject[subjectPos].setLink(newTeacher);
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
