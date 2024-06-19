#ifndef SUBJECT_TABLE_H
#define SUBJECT_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SUBJECTS 1000
#define MAX_STRING_LEN 100

typedef struct {
    char IDClass[MAX_STRING_LEN];
    char CourseID[MAX_STRING_LEN];
    char Name[MAX_STRING_LEN];
    char DayOfWeek[MAX_STRING_LEN];
    char Time[MAX_STRING_LEN];
    char Place[MAX_STRING_LEN];
    bool status;
    int linkToTeacher;
} SubjectTable;

void addSubject(SubjectTable subjects[], int *subject_count);
void delSubject(SubjectTable subjects[], int *subject_count, int delSubject_pos);
void editSubject(SubjectTable subjects[], int subject_count, int editSubject_pos);
void searchSubject(SubjectTable subjects[], int subject_count, const char *course_id);
void showSubject(SubjectTable subjects[], int subject_count);
void readData(SubjectTable subjects[], int *subject_count);
void writeData(SubjectTable subjects[], int subject_count);
void sortByID(SubjectTable subjects[], int subject_count);
void sortByName(SubjectTable subjects[], int subject_count);
void printOutLink(SubjectTable subjects[], int subject_count);
SubjectTable defineNewSubject();
#endif // SUBJECT_TABLE_H
