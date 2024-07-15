#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STUDENTS 50

// Structure to represent a student record
struct Student {
    int id;
    char name[50];
    float marks;
};

// Global variables
struct Student students[MAX_STUDENTS];
int num_students = 0;

// Function prototypes
void addStudent();
void deleteStudent();
void searchStudent();
void displayStudents();

int main() {
    int choice;

    do {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Search Student\n");
        printf("4. Display All Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
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
                displayStudents();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (true);

    return 0;
}

void addStudent() {
    if (num_students >= MAX_STUDENTS) {
        printf("Cannot add more students. Student database is full.\n");
        return;
    }

    struct Student newStudent;
    printf("Enter Student ID (Only Digits) : ");
    scanf("%d", &newStudent.id);

    // Check if the ID already exists
    for (int i = 0; i < num_students; i++) {
        if (students[i].id == newStudent.id) {
            printf("Student with ID %d already exists. Cannot add duplicate IDs.\n", newStudent.id);
            return;
        }
    }

    printf("Enter Student Name: ");
    scanf(" %[^\n]s", newStudent.name);  // Read name with spaces
    printf("Enter Student Marks: ");
    scanf("%f", &newStudent.marks);

    students[num_students] = newStudent;
    num_students++;

    printf("Student added successfully.\n");
}

void deleteStudent() {
    int id, found_index = -1;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    // Shift elements to the left to fill the gap
    for (int i = found_index; i < num_students - 1; i++) {
        students[i] = students[i + 1];
    }

    num_students--;
    printf("Student with ID %d deleted successfully.\n", id);
}

void searchStudent() {
    int id;
    printf("Enter Student ID to search:");
    scanf("%d", &id);

    for (int i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            printf("Student ID: %d\n", students[i].id);
            printf("Student Name: %s\n", students[i].name);
            printf("Student Marks: %.2f\n", students[i].marks);
            return;
        }
    }

    printf("Student with ID %d not found.\n", id);
}

void displayStudents() {
    if (num_students == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nStudent Records:\n");
    printf("ID\tName\t\tMarks\n");
    for (int i = 0; i < num_students; i++) {
        printf("%d\t%s\t\t%.2f\n", students[i].id, students[i].name, students[i].marks);
    }
}
