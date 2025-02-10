#include <stdio.h>
// #include "login.h"
// #include "student.h"

int main()
{
    // if (!login()) {
    //     return 0;
    // }

    int option;
    while (1)
    {
        printf("\n--- Student Management System Menu ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            // addStudent();
            break;
        case 2:
            // viewStudents();
            break;
        case 3:
            // updateStudent();
            break;
        case 4:
            // deleteStudent();
            break;
        case 5:
            printf("Exiting system. Goodbye!\n");
            return 0;
        default:
            printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}
