#include "subject_table.h"
SubjectTable defineNewSubject(){
    SubjectTable a;
    char _IDCLass[50];
    char _CourseID[50];
    char _Name[50];
    char _DayOfWeek[50];
    char _Time[50];
    char _Place[50];
    printf("Nhap thong tin mon hoc:\n");
    printf("Nhap ma lop: "); scanf("%s", &_IDCLass);
    printf("Nhap ma hoc phan: "); scanf("%s", &_CourseID);
    printf("Nhap ten mon hoc: "); scanf("%s", &_Name);
    printf("Nhap thu: "); scanf("%s", &_DayOfWeek);
    printf("Nhap thoi gian: "); scanf("%s", &_Time);
    printf("Nhap dia diem hoc: "); scanf("%s", &_Place);
    strcpy(a.IDClass, _IDCLass);
    strcpy(a.CourseID, _CourseID);
    strcpy(a.Name, _Name);
    strcpy(a.DayOfWeek, _DayOfWeek);
    strcpy(a.Time, _Time);
    strcpy(a.Place, _Place);
    a.status = false;
    a.linkToTeacher = -1;
    return a;
}
void addSubject(SubjectTable subjects[], int *subject_count) {
    SubjectTable tempsubject = defineNewSubject();
    if (*subject_count >= MAX_SUBJECTS) {
        fprintf(stderr, "Quá giới hạn số lượng môn học.\n");
        return;
    }
    (*subject_count) += 1;
    subjects[*subject_count] = tempsubject;
}

void delSubject(SubjectTable subjects[], int *subject_count, int delSubject_pos) {
    for(int i = delSubject_pos; i < *subject_count - 1; i++){
        subjects[i] = subjects[i + 1];
    }
    (*subject_count) -= 1;
}

void editSubject(SubjectTable subjects[], int subject_count, int editSubject_pos) {
    printf("Nhap toan bo thong tin cua mon can thay doi:\n");
    SubjectTable tempsubject = defineNewSubject();
    subjects[editSubject_pos] = tempsubject;
}

void searchSubject(SubjectTable subjects[], int subject_count, const char *course_id) {
    //updating
}

void showSubject(SubjectTable subjects[], int subject_count) {
    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
    printf("| %-8s | %-12s | %-50s | %-8s | %-20s | %-18s |\n", "Ma lop", "Ma hoc phan", "Ten mon hoc", "Thu", "Thoi gian", "Dia diem hoc");
    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
    for (int i = 0; i < subject_count; ++i) {
        printf("| %-8s | %-12s | %-50s | %-8s | %-20s | %-18s |\n",
               subjects[i].IDClass, subjects[i].CourseID, subjects[i].Name,
               subjects[i].DayOfWeek, subjects[i].Time, subjects[i].Place);
    }
    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
}

void readData(SubjectTable subjects[], int *subject_count) {
    FILE *file = fopen("TKB.csv", "r");
    if (!file) {
        fprintf(stderr, "Không thể mở tệp CSV.\n");
        return;
    }

    char line[1024];
    int count = 0;

    // Đọc dòng tiêu đề
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        if (count >= MAX_SUBJECTS) {
            fprintf(stderr, "Quá giới hạn số lượng môn học.\n");
            break;
        }

        char *_IDClass = strtok(line, ",");
        char *_CourseID = strtok(NULL, ",");
        char *_Name = strtok(NULL, ",");
        char *_DayOfWeek = strtok(NULL, ",");
        char *_Time = strtok(NULL, ",");
        char *_Place = strtok(NULL, ",");

        if (_IDClass && _CourseID && _Name && _DayOfWeek && _Time && _Place) {
            strcpy(subjects[count].IDClass, _IDClass);
            strcpy(subjects[count].CourseID, _CourseID);
            strcpy(subjects[count].Name, _Name);
            strcpy(subjects[count].DayOfWeek, _DayOfWeek);
            strcpy(subjects[count].Time, _Time);
            strcpy(subjects[count].Place, _Place);
            subjects[count].status = false;
            subjects[count].linkToTeacher = -1;
            ++count;
        } else {
            fprintf(stderr, "Loi dinh dang o vong: %s\n", line);
        }
    }

    fclose(file);
    *subject_count = count;
}

// Implement the rest of the functions

void writeData(SubjectTable subjects[], int subject_count) {
    printf("Thong tin cua mon hoc ban quan tam la:\n");
    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
    printf("| %-8s | %-12s | %-50s | %-8s | %-20s | %-18s |\n", "Ma lop", "Ma hoc phan", "Ten mon hoc", "Thu", "Thoi gian", "Dia diem hoc");
    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
    for (int i = 0; i < subject_count; ++i) {
        printf("| %-8s | %-12s | %-50s | %-8s | %-20s | %-18s |\n",
               subjects[i].IDClass, subjects[i].CourseID, subjects[i].Name,
               subjects[i].DayOfWeek, subjects[i].Time, subjects[i].Place);
    }
    printf("+----------+--------------+----------------------------------------------------+----------+----------------------+--------------------+\n");
}

void sortByID(SubjectTable subjects[], int subject_count) {
    for(int i = 0; i < subject_count - 1; i++){
        for(int j = i + 1; j < subject_count; j++){
            if(strcmp(subjects[i].IDClass, subjects[j].IDClass) > 0){
                SubjectTable temp = subjects[i];
                subjects[i] = subjects[j];
                subjects[j] = temp;
            }
        }
    }
}

void sortByName(SubjectTable subjects[], int subject_count) {
    for (int i = 0; i < subject_count; i++){
        for (int j = i + 1; j < subject_count; j++){
            if (strcmp(subjects[i].Name, subjects[j].Name) > 0){
                SubjectTable temp = subjects[i];
                subjects[i] = subjects[j];
                subjects[j] = temp;
            }
        }
    }
}

void printOutLink(SubjectTable subjects[], int subject_count) {
    for (int i = 0; i < subject_count; ++i) {
        printf("%d   ", subjects[i].linkToTeacher);
    }
}

