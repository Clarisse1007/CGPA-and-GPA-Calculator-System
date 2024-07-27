#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

#define MAX_STUDENTS 30
#define MAX_COURSES 2
#define MAX_SEMESTERS 3
//definition of gradepoints
#define GRADEA 4.00
#define GRADEAm 3.75
#define GRADEBp 3.50
#define GRADEB 3.00
#define GRADEBm 2.75
#define GRADECp 2.50
#define GRADEC 2.00

// Function submenus
void staffMenu();
void studentMenu();
int isEmpty();
int studentLogin();
int courseDetails();
int stuCGPA();

int names[MAX_STUDENTS][30];
int IDs[MAX_STUDENTS];

int choice;
int staffChoice;
int stuChoice;

//student details variables
char studentName[30];
int ID;
char courseCode[10];
float creditHour = 0, totalCHcgpa = 0;
char grade[20][3][5] = {};
int semSession;
int sem = 0;
int n = 0;
int m = 0;

int num_students = 0;
int stu = 0;
int studentFound = 0; // To check if the student with the given ID is found

//calculate GPA and CGPA variables
float qualityPoint = 0;
float gpa[MAX_STUDENTS][MAX_SEMESTERS] = {};
float cgpa[MAX_STUDENTS] = {};
float gradeP;
float totalQPcgpa = 0;

int main() {
    system("cls");

    printf("============================================================================================================================================================================================\n");
    printf("\n\n");
    printf("\tKKK      KKK   OOOOOOOOOOOO    LLL               EEEEEEEEEEEEEE    JJJJJJJJJJJJJJJJJ          PPPPPPPPPPPPPP    AAAAAAAAAAAAA    SSSSSSSSSSSSS    AAAAAAAAAAAAA    RRRRRRRRRRRRR \n");
    printf("\tKKK     KKK    OOOOOOOOOOOO    LLL               EEEEEEEEEEEEEE    JJJJJJJJJJJJJJJJJ          PPPPPPPPPPPPPP    AAAAAAAAAAAAA    SSSSSSSSSSSSS    AAAAAAAAAAAAA    RRRRRRRRRRRRR \n");
    printf("\tKKK    KKK     OOO      OOO    LLL               EEE                      JJJJJ               PPP        PPP    AAA       AAA    SSS              AAA       AAA    RRR       RRR \n");
    printf("\tKKK   KKK      OOO      OOO    LLL               EEE                      JJJJJ               PPP        PPP    AAA       AAA    SSS              AAA       AAA    RRR       RRR \n");
    printf("\tKKK  KKK       OOO      OOO    LLL               EEE                      JJJJJ               PPP        PPP    AAA       AAA    SSS              AAA       AAA    RRR       RRR \n");
    printf("\tKKK KKK        OOO      OOO    LLL               EEEEEEEEEEEEE            JJJJJ               PPP        PPP    AAA       AAA    SSS              AAA       AAA    RRR       RRR \n");
    printf("\tKKK KKK        OOO      OOO    LLL               EEEEEEEEEEEEE            JJJJJ               PPPPPPPPPPPPPP    AAAAAAAAAAAAA    SSSSSSSSSSSSS    AAAAAAAAAAAAA    RRRRRRRRRRRRR \n");
    printf("\tKKK  KKK       OOO      OOO    LLL               EEE                      JJJJJ               PPPPPPPPPPPPPP    AAAAAAAAAAAAA    SSSSSSSSSSSSS    AAAAAAAAAAAAA    RRRRRRRRRRRRR \n");
    printf("\tKKK   KKK      OOO      OOO    LLL               EEE                      JJJJJ               PPP               AAA       AAA              SSS    AAA       AAA    RRRRRRRRR    \n");
    printf("\tKKK    KKK     OOO      OOO    LLL               EEE               JJJJJ  JJJJJ               PPP               AAA       AAA              SSS    AAA       AAA    RRR    RRR   \n");
    printf("\tKKK     KKK    OOO      OOO    LLL               EEE               JJJJJ  JJJJJ               PPP               AAA       AAA              SSS    AAA       AAA    RRR     RRR  \n");
    printf("\tKKK      KKK   OOOOOOOOOOOO    LLLLLLLLLLLLLL    EEEEEEEEEEEEEE     JJJJJJJJJJ                PPP               AAA       AAA     SSSSSSSSSSSS    AAA       AAA    RRR      RRR \n");
    printf("\tKKK       KKK  OOOOOOOOOOOO    LLLLLLLLLLLLLL    EEEEEEEEEEEEEE      JJJJJJJJ                 PPP               AAA       AAA     SSSSSSSSSSSS    AAA       AAA    RRR       RRR \n");
    printf("\n\n");
    printf("============================================================================================================================================================================================\n");
    printf("\n\n");

    int choice;
    int validChoice = 0;

    while (!validChoice) {
        //prompt user for input

        printf("\nWELCOME TO KOLEJ PASAR!\n\n");
        printf("1. Staff\n");
        printf("2. Student\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            validChoice = 1;
            system("cls");
            staffMenu();
            break;
        }
        else if (choice == 2) {
            validChoice = 1;
            system("cls");
            if (studentLogin())
                studentMenu();
            break;
        }
        else if (choice == 3) {
            //exit
            return 0;
        }
        else {
            printf("Invalid option. Try again.\n\n");
            system("pause");
            system("cls");
            validChoice = 0;
        }
    }
    return 0;
}

// Function to check if the student array is empty
int isEmpty() {
    if (IDs[0] == 0) { // If the first element in the array is empty
        printf("Student with ID %d not found.\n", ID);
        printf("\n\n");
        system("pause");
        system("cls");
        return 1;
        studentMenu();
    }
    return 0;
}

// Function to handle student login
int studentLogin() {
    int foundStudent = 0;

    printf("\n---Student Login Page---\n");
    printf("\nPlease enter your student ID: KPKL");
    scanf("%d", &ID);

    if (isEmpty()) {
        printf("No students are registered. Please contact the staff to register.\n\n");
        system("pause");
        main();
        return 0;
    }

    for (int n = 0; n < num_students; n++) {
        if (ID == IDs[n]) {
            foundStudent = 1;
            printf("\nSuccessful login!\n");
            return 1;
        }
    }
    printf("\nStudent with ID %d not found.\n", ID);
    system("pause");

    return 0;
}

// Function to display the staff menu
void staffMenu() {
    int staffChoice;
    int validSC = 0;

    while (!validSC) {
        printf("\n\n---Administrator Mode---\n\n");

        printf("\n\n1. Student details\n");
        printf("2. Student's GPA\n");
        printf("3. Student's CGPA\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &staffChoice);

        if (staffChoice == 1) {
            validSC = 1;

            printf("\n\nEnter student name  : ");
            scanf("%s", names[stu]);

            printf("Enter student ID    : KPKL");
            scanf("%d", &IDs[stu]);

            courseDetails();
            printf("\n\n");
            printf("Details of student %d successfully recorded!\n\n", num_students);
            system("pause");
            system("cls");
            staffMenu();
            break;
        }
        else if (staffChoice == 2) {
            validSC = 1;

            printf("\n\nEnter student ID: KPKL");
            scanf("%d", &ID);

            if (IDs[0] == 0) { // If the array is empty
                printf("Student with ID %d not found.\n", ID);
                studentFound = 0;

                printf("\n\n");
                system("pause");
                system("cls");
                staffMenu();
            }
            for (int n = 0; n < num_students; n++) {
                if (ID == IDs[n]) {
                    studentFound = 1;

                    for (int i = 0; i < m; i++) {
                        printf("\nSemester %d\n", i + 1);
                        printf("GPA: %.2f\n\n", gpa[i][i]);
                    }
                }
                else {
                    printf("Student with ID %d not found.\n", ID);
                    studentFound = 0;
                }
            }
            printf("\n\n");
            system("pause");
            system("cls");
        }
        else if (staffChoice == 3) {
            validSC = 1;

            printf("\n\nEnter student ID: KPKL");
            scanf("%d", &ID);

            if (IDs[0] == 0) { // If the array is empty
                printf("Student with ID %d not found.\n", ID);
                studentFound = 0;

                printf("\n\n");
                system("pause");
                system("cls");
                staffMenu();
            }

            for (int n = 0; n < num_students; n++) {
                if (ID == IDs[n]) {
                    studentFound = 1;

                    for (int i = 0; i < num_students; i++) {
                        cgpa[i] = totalQPcgpa / totalCHcgpa;
                        printf("\nCGPA: %.2f\n", cgpa[i]);
                    }
                }
                else {
                    printf("Student with ID %d not found.\n", ID);
                    studentFound = 0;
                }
            }
            printf("\n\n");
            system("pause");
            system("cls");
        }
        else if (staffChoice == 4) {
            validSC = 1;
            break;
        }
        else {
            printf("Invalid option. Try again.\n\n");

            system("pause");
            system("cls");
            validSC = 0;
            staffMenu();
            break;
        }
    }
    main();
}

// Function to display the student menu
void studentMenu() {
    int stuChoice;
    int validStuC = 0;

    while (!validStuC) {
        printf("\n\n---Student Mode---\n\n");
        printf("\n\n1. Student Name and ID\n");
        printf("2. View GPA\n");
        printf("3. View CGPA\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &stuChoice);

        if (stuChoice == 1) {
            validStuC = 1;

            for (int n = 0; n < num_students; n++) {
                if (ID == IDs[n]) {
                    studentFound = 1;

                    printf("\n\nStudent name: %s\n", names[n]);
                    printf("Student ID: %d\n", IDs[n]);
                    printf("\n\n");
                }
                else {
                    printf("Student with ID %d not found.\n", ID);
                    studentFound = 0;
                }
            }
            system("pause");
            system("cls");
            studentMenu();
        }
        else if (stuChoice == 2) {
            validStuC = 1;

            for (int n = 0; n < num_students; n++) {
                if (ID == IDs[n]) {
                    studentFound = 1;

                    printf("\n\n---View GPA---\n\n");

                    for (int i = 0; i < m; i++) {
                        printf("\nSemester %d\n", i + 1);
                        printf("GPA: %.2f\n\n", gpa[i][i]);
                    }
                }
                else {
                    printf("Student with ID %d not found.\n", ID);
                    studentFound = 0;
                }
            }
            system("pause");
            system("cls");
            studentMenu();
        }
        else if (stuChoice == 3) {
            validStuC = 1;

            for (int n = 0; n < num_students; n++) {
                if (ID == IDs[n]) {
                    studentFound = 1;
                    stuCGPA();

                }
                else {
                    printf("Student with ID %d not found.\n", ID);
                    studentFound = 0;
                }
                system("pause");
                system("cls");
                studentMenu();
            }
        }
        else if (stuChoice == 4) {
            validStuC = 1;
            break;
        }
        else {
            printf("Student with ID %d not found.\n", ID);
            studentFound = 0;
            validStuC = 0;
        }
        printf("\n\n");
    }
    main();
}

// Function to input course details
int courseDetails() {
    do {
        for (semSession = 0; semSession < MAX_SEMESTERS; semSession++) { // 3 semesters
            float totalQP = 0;
            float totalCHgpa = 0;

            if (sem < MAX_SEMESTERS)
                sem++;
            else
                sem = 1;

            printf("\n\nSemester %d", sem);

            printf("\n\n-----------------Course details-----------------\n\n");

            int courseNum = 0;

            do {
                for (int j = 0; j < MAX_COURSES; j++) { // 2 courses
                    printf("\nEnter course code               : ");
                    scanf("%s", courseCode);

                    printf("\nEnter credit hours              : ");
                    scanf("%f", &creditHour);

                    printf("Enter grade obtained            : ");
                    scanf("%s", grade[n][j]);

                    if (strcmp(grade[n][j], "A") == 0)
                        gradeP = GRADEA;
                    else if (strcmp(grade[n][j], "A-") == 0)
                        gradeP = GRADEAm;
                    else if (strcmp(grade[n][j], "B+") == 0)
                        gradeP = GRADEBp;
                    else if (strcmp(grade[n][j], "B") == 0)
                        gradeP = GRADEB;
                    else if (strcmp(grade[n][j], "B-") == 0)
                        gradeP = GRADEBm;
                    else if (strcmp(grade[n][j], "C+") == 0)
                        gradeP = GRADECp;
                    else if (strcmp(grade[n][j], "C") == 0)
                        gradeP = GRADEC;
                    else if (strcmp(grade[n][j], "F") == 0)
                        gradeP = 0.00;
                    else
                        printf("\nInvalid grade!\n");

                    printf("Enter current semester session  : ");
                    scanf("%d", &semSession);

                    if (totalCHcgpa < 22) {
                        totalCHcgpa += creditHour;
                    }

                    totalCHgpa += creditHour;

                    qualityPoint = gradeP * creditHour;

                    totalQP += qualityPoint;

                    gpa[m][sem - 1] = totalQP / totalCHgpa;

                    n++;

                    if (courseNum < MAX_COURSES)
                        courseNum++;
                    else
                        courseNum = 0;
                }
            } while (courseNum < MAX_COURSES);
            m++;
            totalQPcgpa += totalQP;
        }
    } while (totalCHcgpa < 21);
    num_students++;  // Increase the number of student records
    stu++;
    return 0;
}

//Function to input CGPA
int stuCGPA() {
    printf("\n\n---View CGPA---\n\n");

    cgpa[n] = totalQPcgpa / totalCHcgpa;
    printf("CGPA: %.2f\n\n", cgpa[n]);

    if (cgpa[n] == 4.00) {
        printf("Congratulations! You will receive a full scholarship for the following semester.\n\n");
    }
    else if (cgpa[n] >= 3.85) {
        printf("Congratulations! You will receive an 85%% scholarship.\n\n");
    }
    else if (cgpa[n] >= 3.75) {
        printf("Congratulations! You will receive a 65%% scholarship.\n\n");
    }
    else if (cgpa[n] >= 3.65) {
        printf("Congratulations! You will receive a 50%% scholarship.\n\n");
    }
    else if (cgpa[n] >= 3.55) {
        printf("Congratulations! You will receive a 35%% scholarship.\n\n");
    }
    else if (cgpa[n] >= 3.45) {
        printf("Congratulations! You will receive a 15%% scholarship.\n\n");
    }
    else {
        printf("Your CGPA hasn't reached the target to receive a scholarship discount.\n");
        printf("Try again next time.\n\n");
    }
    return 0;
}