#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

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