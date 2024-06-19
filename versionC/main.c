#include "subject_table.h"
#include "teacher.h"
#include "thuattoan.h"
#include <stdio.h>
#define TEACHER_NUM 100

void show(){
    printf("1. Show full schedule\n");
    printf("2. Show with teacher name\n");
    printf("3. Show with day of week\n");
    printf("4. Show with course ID\n");
    printf("5. Edit subject information\n");
    printf("6. Edit teacher information\n");
    printf("7. Exit\n");
}
void showFullSchedule(giaoVien listTeacher[], int teacher_count, SubjectTable listSubject[], int subject_count){
    for (int i = 0; i < teacher_count; i++){
        printf("%s\n", listTeacher[i].name);
        for (int j = 0; j < listTeacher[i].numOfSubject; j++){
            printf("%s\n", listSubject[listTeacher[i].linkToSubject[j]].Name);
        }
    }
}

void showWithTeacherName(giaoVien listTeacher[], int teacher_count, SubjectTable listSubject[], int subject_count){
    char teacher_name[100];
    scanf("%s", teacher_name);
    for (int i = 0; i < teacher_count; i++){
        if(compareString(teacher_name, listTeacher[i].name)){
            for (int j = 0; j < listTeacher[i].numOfSubject; j++){
                printf("%s\n", listSubject[listTeacher[i].linkToSubject[j]].Name);
            }
        }
    }
}
void showWithDayOfWeek(giaoVien listTeacher[], int teacher_count, SubjectTable listSubject[], int subject_count){
    char day[100];
    scanf("%s", day);
    for (int i = 0; i < subject_count; i++){
        if(compareString(day, listSubject[i].DayOfWeek)){
            printf("%s\n", listSubject[i].Name);
        }
    }
}
 void showWithCourseID(giaoVien listTeacher[], int teacher_count, SubjectTable listSubject[], int subject_count){
    char courseID[100];
    scanf("%s", courseID);
    for (int i = 0; i < subject_count; i++){
        if(compareString(courseID, listSubject[i].CourseID)){
            printf("%s\n", listSubject[i].Name);
        }
    }
}

void showSubjectChoice(){
    printf("1. Edit subject name\n");
    printf("2. Edit teacher name\n");
    printf("3. Edit day of week\n");
    printf("4. Edit course ID\n");
    printf("5. Exit\n");
}

void showTeacherChoice(){
    printf("1. Edit teacher name\n");
    printf("2. Edit subject name\n");
    printf("3. Exit\n");
}

void suaDoiThongTinMonHoc(int choice, SubjectTable listSubject[], int subject_count){
    if(choice == 1){
        char subject_name[100];
        char new_name[100];
        scanf("%s", subject_name);
        scanf("%s", new_name);
        for (int i = 0; i < subject_count; i++){
            if(compareString(subject_name, listSubject[i].Name)){
                copyString(new_name, listSubject[i].Name);
            }
        }
    }
    else if(choice == 2){
        char subject_name[100];
        char new_name[100];
        scanf("%s", subject_name);
        scanf("%s", new_name);
        for (int i = 0; i < subject_count; i++){
            if(compareString(subject_name, listSubject[i].Name)){
                copyString(new_name, listSubject[i].TeacherName);
            }
        }
    }
    else if(choice == 3){
        char subject_name[100];
        char new_name[100];
        scanf("%s", subject_name);
        scanf("%s", new_name);
        for (int i = 0; i < subject_count; i++){
            if(compareString(subject_name, listSubject[i].Name)){
                copyString(new_name, listSubject[i].DayOfWeek);
            }
        }
    }
    else if(choice == 4){
        char subject_name[100];
        char new_name[100];
        scanf("%s", subject_name);
        scanf("%s", new_name);
        for (int i = 0; i < subject_count; i++){
            if(compareString(subject_name, listSubject[i].Name)){
                copyString(new_name, listSubject[i].CourseID);
            }
        }
    }
}

void suaDoiThongTinGiaoVien(int choice, giaoVien listTeacher[], int teacher_count){
    if(choice == 1){
        char teacher_name[100];
        char new_name[100];
        scanf("%s", teacher_name);
        scanf("%s", new_name);
        for (int i = 0; i < teacher_count; i++){
            if(compareString(teacher_name, listTeacher[i].name)){
                copyString(new_name, listTeacher[i].name);
            }
        }
    }
    else if(choice == 2){
        char teacher_name[100];
        char new_name[100];
        scanf("%s", teacher_name);
        scanf("%s", new_name);
        for (int i = 0; i < teacher_count; i++){
            if(compareString(teacher_name, listTeacher[i].name)){
                copyString(new_name, listTeacher[i].subject1);
            }
        }
    }
}



int main() {
    SubjectTable subjects[MAX_SUBJECTS];
    int subject_count = 0;
    
    readData(subjects, &subject_count);
    printf("%d\n", subject_count);
    showSubject(subjects, subject_count);
    printOutLink(subjects, subject_count);
    printf("\n");
    giaoVien listTeacher[TEACHER_NUM];
    int teacher_count = 0;
    readTeacherData(listTeacher, &teacher_count);
    advancedSort(listTeacher, teacher_count, subjects, subject_count);
    //printOutLink(subjects, subject_count);
    while(1){
        show();
        int choice;
        scanf("%d", &choice);
        if(choice == 1){
            showFullSchedule(listTeacher, teacher_count, subjects, subject_count);
        }
        else if(choice == 2){
            showWithTeacherName(listTeacher, teacher_count, subjects, subject_count);
        }
        else if(choice == 3){
            showWithDayOfWeek(listTeacher, teacher_count, subjects, subject_count);
        }
        else if(choice == 4){
            showWithCourseID(listTeacher, teacher_count, subjects, subject_count);
        }
        else if(choice == 7){
            break;
        }
        else if(choice == 5){
            printf("Tien hanh sua duoi thong tin mon hoc\n");
            while(1){
                showSubjectChoice();
                int choice1;
                scanf("%d", &choice1);
                if(choice1 == 5) break;
                suaDoiThongTinMonHoc(choice1, subjects, subject_count);
            }
        }
        else if(choice == 6){
            printf("Tien hanh sua duoi thong tin giao vien\n");
            while(1){
                showTeacherChoice();
                int choice1;
                scanf("%d", &choice1);
                if(choice1 == 3) break;
                suaDoiThongTinGiaoVien(choice1, listTeacher, teacher_count);
            }
        }
        else{
            printf("LOI!!\n");
            printf("Xin moi nhap lai lua chon\n");
        }
    }
    



    return 0;
    
}
