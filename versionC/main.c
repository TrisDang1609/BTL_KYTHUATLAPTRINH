#include "subject_table.h"
#include "teacher.h"
#include "thuattoan.h"
#include <stdio.h>
#define TEACHER_NUM 100
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
    //showTeacher(listTeacher, teacher_count);
    advancedSort(listTeacher, teacher_count, subjects, subject_count);
    printOutLink(subjects, subject_count);
    return 0;
}
