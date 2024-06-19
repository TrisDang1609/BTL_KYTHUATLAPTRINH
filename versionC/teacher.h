#ifndef GIAOVIEN_H
#define GIAOVIEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define TEACHER_NUM 100

typedef struct{
    bool lession[13];
} DAY;
void setDefaultDay(DAY *day);
void setBusyLession(DAY *day, int start, int end);
bool checkBusy(DAY *day, int start, int end);


typedef struct{
    bool dayOfWeek[7];
    DAY dayWeekly[7];
} SCHEDULE;
void setDefaultSchedule(SCHEDULE *schedule);
void setBusyDay(SCHEDULE *schedule, int day, int start, int end);
bool checkBusyDay(SCHEDULE *schedule, int day, int start, int end);

typedef struct {
    char name[50];
    char telNum[15];
    char subject1[200];
    char subject2[200];
    int numOfSubject;
    int linkToSubject[100];
    SCHEDULE schedule;
} giaoVien;
void readTeacherData(giaoVien listTeacher[], int *teacherCount);
void showTeacher(giaoVien listTeacher[], int teacherCount);
giaoVien defineNewTeacher();
void addTeacher(giaoVien listTeacher[], int *teacherCount);
void delTeacher(giaoVien listTeacher[], int *teacherCount, int delTeacherPos);
void editTeacher(giaoVien listTeacher[], int teacherCount, int editTeacherPos);
void writeOutTeacher(giaoVien listTeacher[], int teacherPos);
#endif