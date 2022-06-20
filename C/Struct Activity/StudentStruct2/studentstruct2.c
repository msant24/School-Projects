
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DOB(int month, int day, int year);

int main(int argc, char *argv[])
{
    typedef struct
    {
        char *Firstname, *Lastname;
        char *ID;
        int day, month, year, class;
        float gpa;
    } students;
    int size;
    int i;
    if( argc == 2 ) {
      size = atoi(argv[1]);
   }
   else if( argc > 2 ) {
      size = atoi(argv[1]);
   }
   else {
      size = 5;
   }
    
    if (size <= 0 || size > 5)
    {
        printf("Expected a size from 1 to 5");
        exit(0);
    }
    students *student = malloc(size * sizeof *student);
    for (i = 0; i < size; i++)
    {
        printf("Enter the First name for student %d\n", i + 1);
        student[i].Firstname = (char *)malloc(sizeof(char *));
        scanf("%s", student[i].Firstname);
        printf("Enter the Last name for student %d\n", i + 1);
        student[i].Lastname = (char *)malloc(sizeof(char *));
        scanf("%s", student[i].Lastname);
        printf("Enter the 7 digit ID for student %d\n", i + 1);
        student[i].ID = (char *)malloc(sizeof(char *));
        scanf("%s", student[i].ID);
        if (strlen(student[i].ID) != 7)
        {
            printf("Invalid ID\n");
            exit(1);
        }
            printf("Enter the date of birth's month number for student %d\n", i + 1);
            scanf("%d", &student[i].month);
            printf("Enter the date of birth's day number for student %d\n", i + 1);
            scanf("%d", &student[i].day);
            printf("Enter the date of birth's year number for student %d\n", i + 1);
            scanf("%d", &student[i].year);
            printf("Enter the class number for student %d\n", i + 1);
            scanf("%d", &student[i].class);
            printf("Enter the gpa for student %d\n", i + 1);
            scanf("%f", &student[i].gpa);
        }
        for (i = 0; i < size; i++)
        {
            printf("Structure for student %d\n", i + 1);
            printf("--------------------------------------------------\n");
            printf("Name: %s %s\n", student[i].Firstname, student[i].Lastname);
            printf("Student ID: %s\n", student[i].ID);
            DOB(student[i].month, student[i].day, student[i].year);
            switch (student[i].class)
            {
            case 1:
                printf("Standing: Freshman\n");
                break;
            case 2:
                printf("Standing: Sophomore\n");
                break;
            case 3:
                printf("Standing: Junior\n");
                break;
            case 4:
                printf("Standing Senior\n");
                break;
            default:
                printf("Invalid class\n");
            }
            printf("GPA: %.2f\n", student[i].gpa);
            printf("--------------------------------------------------\n\n");
        }
    }
    void DOB(int month, int day, int year)
    {
        if (year <= 999 || year >= 9999)
        {
            printf("Wrong year input\n");
            exit(1);
        }
        if (day <= 0 || day >= 32)
        {
            printf("Wrong day input\n");
            exit(1);
        }
        switch (month)
        {
        case 1:
            printf("Jan/%d/%d\n", day, year);
            break;
        case 2:
            printf("Feb/%d/%d\n", day, year);
            break;
        case 3:
            printf("Mar/%d/%d\n", day, year);
            break;
        case 4:
            printf("Apr/%d/%d\n", day, year);
            break;
        case 5:
            printf("May/%d/%d\n", day, year);
            break;
        case 6:
            printf("Jun/%d/%d\n", day, year);
            break;
        case 7:
            printf("Jul/%d/%d\n", day, year);
            break;
        case 8:
            printf("Aug/%d/%d\n", day, year);
            break;
        case 9:
            printf("Sep/%d/%d\n", day, year);
            break;
        case 10:
            printf("Oct/%d/%d\n", day, year);
            break;
        case 11:
            printf("Nov/%d/%d\n", day, year);
            break;
        case 12:
            printf("Dec/%d/%d\n", day, year);
            break;
        default:
            printf("Wrong month input\n");
            exit(1);
        }
    }
