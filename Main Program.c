#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Roles{DOCTOR, PATIENT, ADMIN}Roles;

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
}MEDICINES;

typedef struct USERS
    {
    char Username[50];
    char Password[50];
    char Name[50];
    char ID[13];
    enum Roles role;
}USERS;

int end(USERS *user, MEDICINES *medicine, PATIENTS *patient, DOCTORS *doctor);

int main ()
{
    int chose, UserKe = 0, DoctorKe = 0, PatientKe = 0, MedicineKe = 0, patientChose;
    char type[13];
    char Role[13];
    char username[50];
    char password[50];
    char string[50];
    Roles Roless; 
    USERS* user = (USERS*)malloc(1 * sizeof(USERS));
    MEDICINES* medicine = (MEDICINES*)malloc(1 * sizeof(MEDICINES));
    PATIENTS* patient = (PATIENTS*)malloc(1 * sizeof(PATIENTS));
    DOCTORS* doctor = (DOCTORS*)malloc(1 * sizeof(DOCTORS));
    do
    {
        printf("\nLogin as: ");
        scanf("%s", &Role);
        (strcmp(Role, "ADMIN") == 0) ? Roless = ADMIN : 0;
        (strcmp(Role, "DOCTOR") == 0) ? Roless = DOCTOR : 0;
        (strcmp(Role, "PATIENT") == 0) ? Roless = PATIENT : 0;
        switch (Roless)
        {
            case ADMIN:
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
                    case 2:
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
                                scanf("%s", &string);
                                strcpy(user[UserKe].Username, string);
                                printf("Password: ");
                                scanf("%s", &string);
                                strcpy(user[UserKe].Password, string);
                                printf("Name: ");
                                scanf("%s", &string);
                                strcpy(user[UserKe].Name, string);
                                printf("ID: ");
                                scanf("%s", &string);
                                strcpy(user[UserKe].ID, string);
                                UserKe++;
                                user = (USERS *) realloc(user, (UserKe * sizeof(USERS)));
                                switch (user[UserKe-1].role)
                                {
                                case 1:
                                    strcpy(doctor[UserKe-1].DocName, user[UserKe-1].Name);
                                    strcpy(doctor[UserKe-1].DocID, user[UserKe-1].ID);
                                    doctor = (DOCTORS *) realloc(doctor, (UserKe * sizeof(DOCTOR)));
                                    break;
                                case 2:
                                    patient = (PATIENTS *) realloc(patient, (UserKe * sizeof(PATIENTS)));
                                    strcpy(patient[UserKe-1].Name, user[UserKe-1].Name);
                                    strcpy(patient[UserKe-1].ID, user[UserKe-1].ID);
                                    break;
                                default:
                                    break;
                                }
                                printf("New %s Account Created!", type);
                                break;
                            case 2:
                                if (UserKe > 1)
                                {
                                    printf("Username: ");
                                    scanf("%s", &username);
                                    for (int i = 0; i < UserKe; i++)
                                    {
                                        if (strcmp(username, user[i].Username) == 0)
                                        {
                                            printf("Change:\n");
                                            printf("1. Username\n");
                                            printf("2. Password\n");
                                            printf("3. Name\n");
                                            printf("4. ID\n");
                                            printf("Chose (1-4): \n");
                                            scanf("%d", &chose);
                                            switch (chose)
                                            {
                                                case 1:
                                                    printf("New Username: ");
                                                    scanf("%s", &user[i].Username);
                                                    break;
                                                case 2:
                                                    printf("New Password: ");
                                                    scanf("%s", &user[i].Password);
                                                    break;
                                                case 3:
                                                    printf("New Name: ");
                                                    scanf("%s", &user[i].Name);
                                                    break;
                                                case 4:
                                                    printf("New ID: ");
                                                    scanf("%s", &user[i].ID);
                                                    break;
                                                default:
                                                    break;
                                            }
                                        }
                                    }
                                    printf("Username not Found!");
                                }
                                else 
                                {
                                    printf("Currently not available!");
                                }
                        }
                        break;
                    case 1:
                        break;
                    default:
                        break;
                    }
                }
                break;
            case DOCTOR:
                printf("Doctor");
                break;
            case PATIENT:
                printf("Username: ");
                scanf("%s", &username);
                printf("Password: ");
                scanf("%s", &password);
                if ((strcmp(username, "admin") == 0) && (strcmp(password, "01234") == 0))
                {
                    printf("Successfully logged in!\nWelcome Patient %s",username);

                    printf("pleace choose options:\n");
                    printf("1. Checkout in this Hospital\n");
                    printf("2. Deliver medicine home\n");
                    printf("3. Checkout in Other Pharmacies\n");
                    printf("please type down which number : ");
                    scanf("%d", &patientChose);
                    switch (patientChose)
                    {
                    case 1: 
                        
                        break;
                    
                    case 2:
                        
                        break;
                    case 3:

                        break;
                    default:
                        printf("Sorry this is not an Option! try again");
                        break;
                    }
                }
                break;
            default:
                break;
        }
    } while (1);
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