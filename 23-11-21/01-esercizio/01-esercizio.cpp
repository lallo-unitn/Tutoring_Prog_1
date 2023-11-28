#include<iostream>
#include<cstring>

using namespace std;

#define MAX_STUDENTS 100

typedef struct {
    char name[20];
    char surname[20];
    unsigned int id;
} Student;

typedef struct {
    Student *studentsById;
    Student *studentsBySurname;
    unsigned int size;
} Archive;

typedef enum {
    ID,
    SURNAME
} SortBy;

bool addStudent(Student *student, Archive *archive);

bool insertSorted(Student *studentArray, Student *student, unsigned int size, SortBy sortBy);

void printArchive(Archive *ptr);

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

void printArchive(Archive *ptr) {
    cout << "Students by id" << endl;
    for (int i = 0; i < ptr->size && i < MAX_STUDENTS; i++) {
        cout << ptr->studentsById[i].id << " " << ptr->studentsById[i].name << " " << ptr->studentsById[i].surname
             << endl;
    }
    cout << "Students by surname" << endl;
    for (int i = 0; i < ptr->size && i < MAX_STUDENTS; i++) {
        cout << ptr->studentsBySurname[i].id << " " << ptr->studentsBySurname[i].name << " "
             << ptr->studentsBySurname[i].surname << endl;
    }

}

bool addStudent(Student *student, Archive *archive) {
    SortBy sortById = ID;
    SortBy sortBySurname = SURNAME;
    return (insertSorted(archive->studentsById, student, archive->size, sortById)
            && insertSorted(archive->studentsBySurname, student, archive->size, sortBySurname));
}

bool insertSorted(Student *studentArray, Student *student, unsigned int size, SortBy sortBy) {
    int i = 0;
    bool foundInsertionPoint = false;
    // find insertion point
    while (i < size && !foundInsertionPoint) {
        if ((sortBy == ID && (studentArray[i].id > student->id))
            || (sortBy == SURNAME && (strcmp(studentArray[i].surname, student->surname)) > 0)) {
            foundInsertionPoint = true;
        } else {
            i++;
        }
        if (i == MAX_STUDENTS - 1) {
            return false;
        }
    }
    cout << "i+1: " << i << " sortBy: " << sortBy << endl;
    // shift elements to the right to make space for the new element
    for (unsigned int j = size; j > i; j--) {
        studentArray[j] = studentArray[j - 1];
    }
    
    // insert element
    studentArray[i] = *student;
    return true;
}