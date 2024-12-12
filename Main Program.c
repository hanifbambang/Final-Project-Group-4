#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Role{DOCTOR, PATIENT, ADMIN}Role;

typedef struct DOCTORS
{
    char DocName[50];
    char DocID[13];
    char PatientID[50];
}DOCTORS;

typedef struct PATIENTS
{
    char DocID[13];
    char Name[50];
    char ID[13];
    char Symptoms[50];
    char Medicine[50];
}PATIENTS;

typedef struct MEDICINES
{
    char Name[50];
    char ID[13];
    int stock;
} MEDICINES;

typedef struct USERS
    {
    char Username[50];
    char Password[50];
    char Name[50];
    char ID[13];
    enum Role role;
}USERS;

int end(USERS *user, MEDICINES *medicine, PATIENTS *patient, DOCTORS *doctor);

int main ()
{
    int chose, UserKe = 0, DoctorKe = 0, PatientKe = 0, MedicineKe = 0;
    char type[13];
    char Role[13];
    char username[50];
    char password[50];
    USERS* user = (USERS*)malloc(1 * sizeof(USERS));
    MEDICINES* medicine = (MEDICINES*)malloc(1 * sizeof(MEDICINES));
    PATIENTS* patient = (PATIENTS*)malloc(1 * sizeof(PATIENTS));
    DOCTORS* doctor = (DOCTORS*)malloc(1 * sizeof(DOCTORS));
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
                        (strcmp(type, "DOCTOR") == 0) ? user[UserKe].role = DOCTOR : 0;
                        (strcmp(type, "PATIENT") == 0) ? user[UserKe].role = PATIENT : 0;
                        printf("New %s Account:\n", type);
                        printf("Username: ");
                        scanf("%s", &user[UserKe].Username);
                        printf("Password: ");
                        scanf("%s", &user[UserKe].Password);
                        UserKe++;
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
    return end(user, medicine, patient, doctor);
}

int end(USERS *user, MEDICINES *medicine, PATIENTS *patient, DOCTORS *doctor)
{
    free(user);
    free(patient);
    free(doctor);
    free(medicine);
    return 0;
}