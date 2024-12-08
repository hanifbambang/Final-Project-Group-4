#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Role{DOCTOR, PATIENT, ADMIN}Role;

typedef struct DOCTOR
{
    char DocName[50];
    char DocID[13];
    struct PATIENT
    {
        char Name[50];
        char ID[13];
        char Symptoms[50];
        char Medicine[50];
    }PATIENT;
}DOCTOR;

typedef struct ADMIN
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
    
}ADMIN;

int main ()
{
    ADMIN Admin;
    int chose;
    char type[50];
    char Role[13];
    char username[50];
    char password[50];
    ADMIN* admins = (ADMIN*)malloc(1 * sizeof(ADMIN));
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
            printf("1. Storage\n");
            printf("2. Account\n");
            printf("Chose (1-2): ");
            scanf("%d", &chose);
            switch (chose)
            {
            case 1:
                printf("1. Add\n");
                printf("2. Modify\n");
                printf("Chose (1-2): ");
                scanf("%d", &chose);
                switch (chose)
                {
                    case 1:
                        printf("Account Type: ");
                        scanf("%s", &type);
                        break;
                }
                break;
            case 2:
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