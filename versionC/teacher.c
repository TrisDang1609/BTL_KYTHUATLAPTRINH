#include "teacher.h"
// các xửt lý cho các struct con của struct teacher
// struct con DAY
void setDefaultDay(DAY *day){
    for(int i = 0; i < 13; i++){
        day->lession[i] = true;
    }
}
void setBusyLession(DAY *day, int start, int end){
    for(int i = start; i <= end; i++){
        day->lession[i] = false;
    }
}
bool checkBusy(DAY *day, int start, int end){
    for (int i = start; i <= end; i++){
        if(day->lession[i] == false){
            return false;
        }
    }
    return true;
}

// struct con SCHEDULE
void setDefaultSchedule(SCHEDULE *schedule){
    for (int i = 0; i < 7; i++){
        schedule->dayOfWeek[i] = true;
        setDefaultDay(&schedule->dayWeekly[i]);
    }
}
void setBusyDay(SCHEDULE *schedule, int day, int start, int end){
    setBusyLession(&(schedule->dayWeekly[day]), start, end);
}
bool checkBusyDay(SCHEDULE *schedule, int day, int start, int end){
    return checkBusy(&(schedule->dayWeekly[day]), start, end);
}
// các hàm xử lý trong main của struct teacher
void readTeacherData(giaoVien listTeacher[], int *teacher_count){
    FILE *file = fopen("giaoVienData.csv", "r");
    if (!file) {
        fprintf(stderr, "Không thể mở tệp CSV.\n");
        return;
    }
    int count = 0;
    char line[1024];
    while(fgets(line, sizeof(line), file)){
        if(count >= TEACHER_NUM){
            fprintf(stderr, "Quá giới hạn số lượng giáo viên.\n");
            break;
        }
        char *name = strtok(line, ",");
        char *telNum = strtok(NULL, ",");
        char *subject1 = strtok(NULL, ",");
        char *subject2 = strtok(NULL, ",");
        if(subject2 == NULL){
            subject2 = "";
        }
        if(name && telNum && subject1){
            strcpy(listTeacher[count].name, name);
            strcpy(listTeacher[count].telNum, telNum);
            strcpy(listTeacher[count].subject1, subject1);
            strcpy(listTeacher[count].subject2, subject2);
            listTeacher[count].numOfSubject = 0;
            setDefaultSchedule(&listTeacher[count].schedule);
            count++;
        } else {
            fprintf(stderr, "Loi dinh dang o vong: %s\n", line);
        }
    }
    fclose(file);
    *teacher_count = count;
}
void showTeacher(giaoVien listTeacher[], int teacher_count){
    printf("+------+-----------------+-----------------+-----------------+-----------------+\n");
    printf("| STT  |      Ten        |   So Dien Thoai |   Mon hoc 1     |   Mon hoc 2     |\n");
    printf("+------+-----------------+-----------------+-----------------+-----------------+\n");
    for(int i = 0; i < teacher_count; i++){
        printf("| %-4d | %-15s | %-15s | %-15s | %-15s |\n", i + 1, listTeacher[i].name, listTeacher[i].telNum, listTeacher[i].subject1, listTeacher[i].subject2);
    }
    printf("+------+-----------------+-----------------+-----------------+-----------------+\n");
}

giaoVien defineNewTeacher(){
    giaoVien a;
    char _name[50];
    char _telNum[15];
    char _subject1[200];
    char _subject2[200];
    printf("Nhap thong tin giao vien:\n");
    printf("Nhap ten giao vien: "); scanf("%s", &_name);
    printf("Nhap so dien thoai: "); scanf("%s", &_telNum);
    printf("Nhap mon hoc 1: "); scanf("%s", &_subject1);
    printf("Nhap mon hoc 2: "); scanf("%s", &_subject2);
    strcpy(a.name, _name);
    strcpy(a.telNum, _telNum);
    strcpy(a.subject1, _subject1);
    strcpy(a.subject2, _subject2);
    a.numOfSubject = 0;
    setDefaultSchedule(&a.schedule);
    return a;
}
void addTeacher(giaoVien listTeacher[], int *teacher_count){
    giaoVien tempTeacher  = defineNewTeacher();
    (*teacher_count)++; 
    listTeacher[*teacher_count] = tempTeacher;
}
void delTeacher(giaoVien listTeacher[], int *teacher_count, int delTeacherPos){
    for(int i = delTeacherPos; i < *teacher_count - 1; i++){
        listTeacher[i] = listTeacher[i + 1];
    }
    (*teacher_count)--;
}
void editTeacher(giaoVien listTeacher[], int teacher_count, int editTeacherPos){
    printf("Vui long nhap lai toan bo thong tin can thay doi cua giao vien:\n");
    giaoVien tempTeacher = defineNewTeacher();
    listTeacher[editTeacherPos] = tempTeacher;
}

