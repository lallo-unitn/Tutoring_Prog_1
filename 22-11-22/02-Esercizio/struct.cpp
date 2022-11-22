#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

/*structure declaration*/
struct student {
  std::string name;
  int roll;
  float perc;
};

int main() {
  student *pstd;

  std::cout << "Enter number of student: ";
  int num_student;
  std::cin >> num_student;
  pstd = new student[num_student];

  if (pstd == NULL) {
    std::cout << "Insufficient Memory, Exiting... \n";
    return 0;
  }

  std::string name;
  for (int i = 0; i < num_student; i++) {
    /*read and print details*/
    std::cout << "Enter name: ";
    std::cin >> name;
    pstd[i].name = name;

    std::cout << "Enter roll number: ";
    std::cin >> pstd[i].roll;

    std::cout << "Enter percentage: ";
    std::cin >> pstd[i].perc;

    std::cout << "\nEntered details are:\n";
    std::cout << "Name: " << pstd[i].name << std::endl
              << "Roll Number: " << pstd[i].roll << std::endl
              << "Percentage: " << pstd[i].perc << std::endl;
  }
  for (int i = 0; i < num_student; i++) {
    std::cout << "\nEntered details are:\n";
    std::cout << "Name: " << pstd[i].name << std::endl
              << "Roll Number: " << pstd[i].roll << std::endl
              << "Percentage: " << pstd[i].perc << std::endl;
  }

  return 0;
}
