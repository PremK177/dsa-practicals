//
// Created by PREM on 08-11-2025.
//

/*
Using an array of structures, implement a student database with attributes:
roll no, name, department, subject, subject marks. Write functions for:
adding a student, deleting a student, searching for a student.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct Student {
    int rollNo;
    char name[MAX];
    char department[MAX];
    char subjects[3][MAX];
    int subjectMarks[3];
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    if (count >= MAX) {
        printf("Maximum number of students reached\n");
        return;
    }
    struct Student s;
    printf("Enter roll no: ");
    scanf("%d", &s.rollNo);
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter department: ");
    scanf("%s", s.department);
    for (int i = 0; i < 3; i++) {
        printf("Enter subject %d name: ", i + 1);
        scanf("%s", s.subjects[i]);
        printf("Enter marks for %s: ", s.subjects[i]);
        scanf("%d", &s.subjectMarks[i]);
    }
    students[count] = s;
    count++;
}

void deleteStudent() {
    int rollNo;
    printf("Enter roll no to delete: ");
    scanf("%d", &rollNo);
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            return;
        }
    }
    printf("Roll no not found\n");
}

void searchStudent() {
    int rollNo;
    printf("Enter roll no to search: ");
    scanf("%d", &rollNo);
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo) {
            printf("Roll no: %d\nName: %s\nDepartment: %s\n", students[i].rollNo, students[i].name, students[i].department);
            for (int j = 0; j < 3; j++) {
                printf("Subject %d: %s\nMarks: %d\n", j + 1, students[i].subjects[j], students[i].subjectMarks[j]);
            }
            return;
        }
    }
    printf("Roll no not found\n");
}

int main() {
    while (1) {
        printf("1. Add student\n2. Delete student\n3. Search student\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}