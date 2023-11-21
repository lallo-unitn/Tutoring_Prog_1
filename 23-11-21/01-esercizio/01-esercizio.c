#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[20];
    char surname[20];
    unsigned int id;
} Student;

typedef struct {
    Student studentsById[MAX_STUDENTS];
    Student studentsBySurname[MAX_STUDENTS];
    unsigned int size;
} Archive;

typedef enum {
    ID,
    SURNAME
} SortBy;

int addStudent(Student *student, Archive *archive);

int insertSorted(Student *studentArray, Student *student, unsigned int size, SortBy sortBy);

void printArchive(Archive *ptr);

int main() {
    Archive archive = {{0}, {0}, 0};
    Student students[] = {
            {"Mario", "E", 4},
            {"Luigi", "B", 1},
            {"Luigi", "D", 2},
            {"Luigi", "C", 3}
    };
    int i;
    for (i = 0; i < sizeof(students) / sizeof(students[0]); i++) {
        if (addStudent(&students[i], &archive)) {
            archive.size++;
            printf("Student added\n");
        } else {
            printf("Student not added\n");
        }
    }

    printArchive(&archive);
    return 0;
}

void printArchive(Archive *ptr) {
    printf("Students by id\n");
    int i;
    for (i = 0; i < ptr->size && i < MAX_STUDENTS; i++) {
        printf("%u %s %s\n", ptr->studentsById[i].id, ptr->studentsById[i].name, ptr->studentsById[i].surname);
    }

    printf("Students by surname\n");
    for (i = 0; i < ptr->size && i < MAX_STUDENTS; i++) {
        printf("%u %s %s\n", ptr->studentsBySurname[i].id, ptr->studentsBySurname[i].name,
               ptr->studentsBySurname[i].surname);
    }
}

int addStudent(Student *student, Archive *archive) {
    SortBy sortById = ID;
    SortBy sortBySurname = SURNAME;

    return (insertSorted(archive->studentsById, student, archive->size, sortById) &&
            insertSorted(archive->studentsBySurname, student, archive->size, sortBySurname));
}

int insertSorted(Student *studentArray, Student *student, unsigned int size, SortBy sortBy) {
    int i = 0;
    int foundInsertionPoint = 0;

    /*find insertion point*/
    while (i < size && !foundInsertionPoint) {
        if ((sortBy == ID && (studentArray[i].id > student->id)) ||
            (sortBy == SURNAME && (strcmp(studentArray[i].surname, student->surname) > 0))) {
            foundInsertionPoint = 1;
        } else {
            i++;
        }

        if (i == MAX_STUDENTS - 1) {
            return 0;
        }
    }

    printf("i+1: %d sortBy: %d\n", i, sortBy);
    unsigned int j;
    /* shift elements to the right to make space for the new element */
    for (j = size; j > i; j--) {
        studentArray[j] = studentArray[j - 1];
    }

    /* insert element */
    studentArray[i] = *student;
    return 1;
}
