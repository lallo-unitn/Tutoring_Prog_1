#include<iostream>
#include<cstring>

using namespace std;

#define MAX_STUDENTS 100

int main() {
    Student students[] = {
            {"Mario", "E", 4},
            {"Luigi", "B", 1},
            {"Luigi", "D", 2},
            {"Luigi", "C", 3}
    };
    Student studentsById[MAX_STUDENTS];
    Student studentsBySurname[MAX_STUDENTS];
    Archive archive = {studentsById, studentsBySurname, 0};

    for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++) {
        if (addStudent(&students[i], &archive)) {
            archive.size++;
            printf("Student added\n");
        } else {
            printf("Student not added\n");
        }
    }
    printArchive(&archive);
    return (0);
}