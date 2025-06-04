/*
Consider the following statements to represent the registration of students in a subject and implement a function that prints the registration number, name, class and average of all students approved in the subject.
Assume that the strategy for approval is given by the average of the three tests (p1, p2 and p3).
The function receives as parameters the number of students and a vector of pointers to the student data.
Implement a function that has as its return value the final average obtained by students in a given class.
Each student's final grade is given by the average of the three tests.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE_NAME 81
#define SIZE_ID 8

struct student {
	char name[81];
	char id[8];
	char class;
	float e1;
	float e2;
	float e3;
};

typedef struct student Student;

void print_approved(int n, Student **class) {
    for (int i = 0; i < n; i++) {
        float average = (class[i]->e1 + class[i]->e2 + class[i]->e3) / 3;
        if (average < 7) {
            continue;
        }
        printf("\nStudent approved!\n");
        printf("Registration number: %s\n", class[i]->id);
        printf("Name: %s\n", class[i]->name);
        printf("Class: %c\n", class[i]->class);
        printf("Average: %.2f\n", average);
    }
}

float average_class(int n, Student **classes, char class) {
    float sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (classes[i]->class == class) {
            sum += (classes[i]->e1 + classes[i]->e2 + classes[i]->e3) / 3;
            count++;
        }
    }

    return sum / count;
}

int main() {
	int qnt;
	printf("Enter the number of students: ");
	scanf("%d", &qnt);

    Student *students[qnt]; // create an array of pointers to students

    for (int i = 0; i < qnt; i++) {
        students[i] = (Student *)malloc(sizeof(Student)); // allocate memory for each student

        // read student data
        printf("\nEnter the student's name: ");
        scanf(" %[^\n]", students[i]->name);
        printf("Enter the student's id: ");
        scanf(" %[^\n]", students[i]->id);
        printf("Enter the student's class: ");
        scanf(" %c", &students[i]->class);
        printf("Enter the student's grade in the first test: ");
        scanf("%f", &students[i]->e1);
        printf("Enter the student's grade in the second test: ");
        scanf("%f", &students[i]->e2);
        printf("Enter the student's grade in the third test: ");
        scanf("%f", &students[i]->e3);
    }

    // print approved students
    print_approved(qnt, students);

    // calculate and print the average for each class
    char classes[qnt];
    int class_count = 0;

    for (int i = 0; i < qnt; i++) {
        int found = 0;
        for (int j = 0; j < class_count; j++) {
            if (classes[j] == students[i]->class) {
                found = 1;
                break;
            }
        }
        if (!found) {
            classes[class_count++] = students[i]->class;
        }
    }

    printf("\n");
    for (int i = 0; i < class_count; i++) {
        float avg = average_class(qnt, students, classes[i]);
        printf("The average for class %c is: %.2f\n", classes[i], avg);
    }

    // free allocated memory
    for (int i = 0; i < qnt; i++) {
        free(students[i]);
    }

	return 0;
}
