#include "thuattoan.h"
bool compareString(char s1[], char s2[]){
    for (int i = 0; i < 4; i++){
        if(s1[i] != s2[i]) return false;
    }
    return true;
}
char s1[10] = "0645";
char s2[10] = "0730";
char s3[10] = "0815";
char s4[10] = "0910";
char s5[10] = "1005";
char s6[10] = "1100";
char s7[10] = "1145";
char s8[10] = "1315";
char s9[10] = "1400";
char s10[10] = "1455";
char s11[10] = "1550";
char s12[10] = "1645";
char s13[10] = "1730";
char s14[10] = "0825";
char s15[10] = "0920";
char s16[10] = "1015";
char s17[10] = "1230";
char s18[10] = "1410";
char s19[10] = "1505";
char s20[10] = "1600";
int compare(char s[]){
     if(compareString(s, s1)) return 1;
     if(compareString(s, s2)) return 2;
     if(compareString(s, s3) || compareString(s, s14)) return 3;
     if(compareString(s, s4) || compareString(s, s15)) return 4;
     if(compareString(s, s5) || compareString(s, s16)) return 5;
     if(compareString(s, s6)) return 6;
     if(compareString(s, s7) || compareString(s, s17)) return 7;
     if(compareString(s, s8)) return 8;
     if(compareString(s, s9) || compareString(s, s18)) return 9;
     if(compareString(s, s10) || compareString(s, s19)) return 10;
     if(compareString(s, s11) || compareString(s, s20)) return 11;
     if(compareString(s, s12)) return 12;
     if(compareString(s, s13)) return 13;
     return 0; // không bao giờ xảy ra nhưng mình không ghi vào thì nó lỗi cho nên cứ ghi bừa là 0 vào nhé :))
}
int convertCharToInt(char s){
    return (int)(s - '0');
}
int _start, _end, _day;
bool checkFree(giaoVien a, SubjectTable b){
    if(compareString(a.subject1, b.Name) || compareString(a.subject2, b.Name)){
        char cut1[10];
        char cut2[10];
        for (int i = 0; i < 4; i++){
            cut1[i] = b.Time[i];
        }
        int temp = 0;
        for (int i = 5; i < 9; i++){
            cut2[temp] = b.Time[i];
            temp++;
        }
       // printf("%s\n", cut2);
        _start = compare(cut1);
        _end = compare(cut2) - 1;
        _day = convertCharToInt(b.DayOfWeek[0]);
      //  printf("%d %d %d\n", _start, _end, _day);
        if(checkBusyDay(&(a.schedule), _day, _start, _end)){
            setBusyDay(&(a.schedule), _day, _start, _end);
            return true;
        }
    }
    return false;
}
void advancedSort(giaoVien listTeacher[], int teacher_count, SubjectTable listSubject[], int subject_count){
    for (int i = 0; i < subject_count; i++) listSubject[i].status = false;
    for (int i = 0; i < subject_count; i++){
        for (int j = 0; j < teacher_count; j++){
            if(checkFree(listTeacher[j], listSubject[i])){
                listSubject[i].status = true;
                listSubject[i].linkToTeacher = j;
                listTeacher[j].linkToSubject[listTeacher[j].numOfSubject] = i;
                listTeacher[j].numOfSubject++;
                break;
            }
        }
    }
}