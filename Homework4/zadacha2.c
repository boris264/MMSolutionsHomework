#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

unsigned int getStudentNumber(void);

int main(void)
{
    uint32_t attendance = 0;
    int option;

    while (1)
    {
        printf("1. Set attendance\n");
        printf("2. Clear attendance\n");
        printf("3. Attendance info\n");
        printf("4. Change attendance\n");
        printf("5. Exit\n");
        scanf("%d", &option);

        if (option == 1)
        {
            int studentNumber = getStudentNumber();

            attendance |= (1 << studentNumber);
        }
        else if (option == 2)
        {
            int studentNumber = getStudentNumber();

            attendance &= ~(1 << studentNumber);
        }
        else if (option == 3)
        {
            for(uint32_t i = 0; i < sizeof(attendance) * 8; i++)
            {
                int mask = (1 << i);
                int studentInfo = (attendance & mask) >> i;

                if(studentInfo != 0)
                {
                    printf("Student with number %d is here.\n", i);
                }
                else
                {
                    printf("Student with number %d is not here.\n", i);
                }
            }
        }
        else if (option == 4)
        {
            int studentNumber = getStudentNumber();

            attendance ^= 1 << studentNumber;
        }
        else if (option == 5)
        {
            printf("Exiting...\n");
            return 0;
        }
        else
        {
            fprintf(stderr, "Invalid option!\n");
            return 1;
        }
    }

    return 0;
}

unsigned int getStudentNumber(void)
{
    uint32_t number;

    printf("Enter the student's number: ");
    scanf("%u", &number);

    if(number >= 32)
    {
        fprintf(stderr, "Invalid student number!\n");
        exit(1);
    }

    return number;
}