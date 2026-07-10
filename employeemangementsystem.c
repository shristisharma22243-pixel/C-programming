#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Employee
{
    int id;
    char name[50];
    char department[50];
    float salary;
};

struct Employee emp[MAX];
int total = 0;

// Add Employee
void addEmployee()
{
    if(total >= MAX)
    {
        printf("\nEmployee List Full!\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &emp[total].id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", emp[total].name);

    printf("Enter Department: ");
    scanf(" %[^\n]", emp[total].department);

    printf("Enter Salary: ");
    scanf("%f", &emp[total].salary);

    total++;

    printf("\nEmployee Added Successfully!\n");
}

// Display Employees
void displayEmployees()
{
    if(total == 0)
    {
        printf("\nNo Employee Records Found!\n");
        return;
    }

    printf("\n---------------------------------------------------------------");
    printf("\nID\tName\t\tDepartment\t\tSalary");
    printf("\n---------------------------------------------------------------");

    for(int i = 0; i < total; i++)
    {
        printf("\n%d\t%-15s %-20s %.2f",
               emp[i].id,
               emp[i].name,
               emp[i].department,
               emp[i].salary);
    }

    printf("\n---------------------------------------------------------------\n");
}

// Search Employee
void searchEmployee()
{
    int id;
    int found = 0;

    printf("\nEnter Employee ID: ");
    scanf("%d", &id);

    for(int i = 0; i < total; i++)
    {
        if(emp[i].id == id)
        {
            printf("\nEmployee Found");
            printf("\nID : %d", emp[i].id);
            printf("\nName : %s", emp[i].name);
            printf("\nDepartment : %s", emp[i].department);
            printf("\nSalary : %.2f\n", emp[i].salary);

            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nEmployee Not Found!\n");
}

// Update Salary
void updateSalary()
{
    int id;
    float salary;

    printf("\nEnter Employee ID: ");
    scanf("%d", &id);

    for(int i = 0; i < total; i++)
    {
        if(emp[i].id == id)
        {
            printf("Current Salary: %.2f\n", emp[i].salary);

            printf("Enter New Salary: ");
            scanf("%f", &salary);

            emp[i].salary = salary;

            printf("Salary Updated Successfully!\n");
            return;
        }
    }

    printf("Employee Not Found!\n");
}

// Delete Employee
void deleteEmployee()
{
    int id;
    int found = 0;

    printf("\nEnter Employee ID: ");
    scanf("%d", &id);

    for(int i = 0; i < total; i++)
    {
        if(emp[i].id == id)
        {
            for(int j = i; j < total - 1; j++)
            {
                emp[j] = emp[j + 1];
            }

            total--;
            found = 1;

            printf("Employee Deleted Successfully!\n");
            break;
        }
    }

    if(!found)
        printf("Employee Not Found!\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n=================================");
        printf("\n EMPLOYEE MANAGEMENT SYSTEM");
        printf("\n=================================");
        printf("\n1. Add Employee");
        printf("\n2. Display Employees");
        printf("\n3. Search Employee");
        printf("\n4. Update Salary");
        printf("\n5. Delete Employee");
        printf("\n6. Exit");
        printf("\nEnter Choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                updateSalary();
                break;

            case 5:
                deleteEmployee();
                break;

            case 6:
                printf("\nThank You!\n");
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}