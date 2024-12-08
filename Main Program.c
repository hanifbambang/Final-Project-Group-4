#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Role{DOCTOR, PATIENT, ADMIN}Role;

typedef struct Doctor
{
    char DocName[50];
    char DocID[13];
    struct Patient
    {
        char Name[50];
        char ID[13];
        char Symptoms[50];
        char Medicine[50];
    }Patient;
}Doctor;

typedef struct Admin
{
    struct Medicine
    {
        char Name[50];
        char ID[13];
    } Medicine;
    struct User
    {
        char Username[50];
        char Password[50];
        char Name[50];
        char ID[13];
        Role role;
    }User;
    
}Admin;

int main ()
{
    int chose;
    char Role[13];
    char username[50];
    char password[50];
    printf("Login as: ");
    scanf("%s", &Role);
    if (strcmp(Role, "ADMIN") == 0)
    {
        printf("Username: ");
        scanf("%s", &username);
        printf("Password: ");
        scanf("%s", &password);
        if ((strcmp(username, "admin") == 0) && (strcmp(password, "01234") == 0))
        {
            printf("Successfully logged in!\n");
            printf("1. Modify Storage\n");
            printf("2. Modify Account\n");
            printf("Chose (1-2): ");
            scanf("%d", &chose);
            switch (chose)
            {
            case 1:
                break;
            default:
                break;
            }
        }
        else
        {
            printf("Test %s", username);
        }
    }
    return 0;
}