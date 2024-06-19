#ifndef THUATTOAN_H
#define THUATTOAN_H

#include "teacher.h"
#include "subject_table.h"
#include<stdio.h>
#include<string.h>
#define TEACHER_NUM 100
bool compareString(char s1[], char s2[]);
int compare(char s[]);
int convertCharToInt(char s);
bool checkFree(giaoVien a, SubjectTable b);
void advancedSort(giaoVien listTeacher[], int teacher_count, SubjectTable listSubject[], int subject_count);

#endif