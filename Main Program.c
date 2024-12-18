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
    float price;
}MEDICINES;

typedef struct USERS
    {
    char Username[50];
    char Password[50];
    char Name[50];
    char ID[13];
    enum Role role;
}USERS;

int end(USERS **user, MEDICINES **medicine, PATIENTS **patient, DOCTORS **doctor);

int ModifyAccount(int *UserKe, USERS **user, DOCTORS **doctor, PATIENTS **patient);

void CreateAccount(int *UserKe, int *DoctorKe, int *PatientKe, USERS **user, DOCTORS **doctor, PATIENTS **patient);

void AddMedicine(int *UserKe, int *MedicineKe, USERS **user, DOCTORS **doctor, PATIENTS **patient, MEDICINES **medicine);

int ModifyMedicine(int *MedicineKe, MEDICINES **medicine);

int main ()
{
    int chose, UserKe = 0, DoctorKe = 0, PatientKe = 0, MedicineKe = 0, lanjut = 0;
    char type[13];
    char Role[13];
    char username[50];
    char password[50];
    char string[50];
    int Roles; 
    USERS* user = (USERS*)malloc(1 * sizeof(USERS));
    MEDICINES* medicine = (MEDICINES*)malloc(1 * sizeof(MEDICINES));
    PATIENTS* patient = (PATIENTS*)malloc(1 * sizeof(PATIENTS));
    DOCTORS* doctor = (DOCTORS*)malloc(1 * sizeof(DOCTORS));
    do
    {
        printf("\nLogin as: ");
        scanf("%s", &Role);
        (strcmp(Role, "ADMIN") == 0) ? Roles = 0 : -1;
        (strcmp(Role, "DOCTOR") == 0) ? Roles = 1 : -1;
        (strcmp(Role, "PATIENT") == 0) ? Roles = 2 : -1;
        switch (Roles)
        {
            case 0:
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
                                AddMedicine(&UserKe, &MedicineKe, &user, &doctor, &patient, &medicine);
                                break;
                            case 2:
                                lanjut = ModifyMedicine(&MedicineKe, &medicine);
                        }
                        break;
                    case 2:
                        printf("1. Add\n");
                        printf("2. Modify\n");
                        printf("Chose (1-2): ");
                        scanf("%d", &chose);
                        switch (chose)
                        {
                            case 1:
                                CreateAccount(&UserKe, &DoctorKe, &PatientKe, &user, &doctor, &patient);
                                break;
                            case 2:
                                lanjut = ModifyAccount(&UserKe, &user, &doctor, &patient);
                        }
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 1:
                printf("Doctor");
                break;
            case 2:
                printf("Patient");
                lanjut = 1;
                break;
            default:
                return 0;
                break;
        }
    } while (lanjut == 1);
    return end(&user, &medicine, &patient, &doctor);
    
}

int ModifyMedicine(int *MedicineKe, MEDICINES **medicine)
{
    char string[50];
    int chose;
    if (MedicineKe > 1)
    {
        printf("Name: ");
        scanf("%s", &string);
        for (int i = 0; i < MedicineKe; i++)
        {
            if (strcmp(string, (*medicine)[i].Name) == 0)
            {
                printf("Change:\n");
                printf("1. Stock\n");
                printf("2. Price\n");
                printf("Chose (1-2): \n");
                scanf("%d", &chose);
                switch (chose)
                {
                    case 1:
                        printf("New Stock: ");
                        scanf("%d", medicine[i]->stock);
                        break;
                    case 2:
                        printf("New Price: ");
                        scanf("%d", medicine[i]->price);
                        break;
                    default:
                        break;
                }
            }
        }
        printf("Medicine not Found!");
        return 0;
    }
    else
    {
        printf("Currently not available!");
        return 1;
    }
}

void AddMedicine(int *UserKe, int *MedicineKe, USERS **user, DOCTORS **doctor, PATIENTS **patient, MEDICINES **medicine)
{
    char string[50];
    printf("New Medicine:\n");
    printf("Name: ");
    scanf("%s", &string);
    strcpy((*medicine)[*UserKe].Name, string);
    printf("ID: ");
    scanf("%s", &string);
    strcpy((*medicine)[*UserKe].ID, string);
    printf("Stock: ");
    scanf("%d", medicine[*MedicineKe]->stock);
    printf("Price: ");
    scanf("%d", medicine[*MedicineKe]->price);
    *MedicineKe++;
    (*medicine) = (MEDICINES *) realloc((*medicine), (*MedicineKe * sizeof(MEDICINES)));
    printf("New Medicine Added!");
}

int ModifyAccount(int *UserKe, USERS **user, DOCTORS **doctor, PATIENTS **patient)
{
    char username[50];
    int chose;
    if (UserKe > 1)
    {
        printf("Username: ");
        scanf("%s", &username);
        for (int i = 0; i < UserKe; i++)
        {
            if (strcmp(username, (*user)[i].Username) == 0)
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
                        scanf("%s", &(*user)[i].Username);
                        break;
                    case 2:
                        printf("New Password: ");
                        scanf("%s", &(*user)[i].Password);
                        break;
                    case 3:
                        printf("New Name: ");
                        scanf("%s", &(*user)[i].Name);
                        break;
                    case 4:
                        printf("New ID: ");
                        scanf("%s", &(*user)[i].ID);
                        break;
                    default:
                        break;
                }
            }
        }
        printf("Username not Found!");
        return 0;
    }
    else
    {
        printf("Currently not available!");
        return 1;
    }
}

void CreateAccount(int *UserKe, int *DoctorKe, int *PatientKe, USERS **user, DOCTORS **doctor, PATIENTS **patient)
{
    char type[13];
    char string[50];
    printf("Account Type: ");
    scanf("%s", &type);
    (strcmp(type, "DOCTOR") == 0) ? (*user)[*UserKe].role = DOCTOR : 0;
    (strcmp(type, "PATIENT") == 0) ? (*user)[*UserKe].role = PATIENT : 0;
    printf("New %s Account:\n", type);
    printf("Username: ");
    scanf("%s", &string);
    strcpy((*user)[*UserKe].Username, string);
    printf("Password: ");
    scanf("%s", &string);
    strcpy((*user)[*UserKe].Password, string);
    printf("Name: ");
    scanf("%s", &string);
    strcpy((*user)[*UserKe].Name, string);
    printf("ID: ");
    scanf("%s", &string);
    strcpy((*user)[*UserKe].ID, string);
    UserKe++;
    (*user) = (USERS *) realloc((*user), (*UserKe * sizeof(USERS)));
    switch ((*user)[*UserKe-1].role)
    {
    case 1:
        strcpy((*doctor)[*UserKe-1].DocName, (*user)[*UserKe-1].Name);
        strcpy((*doctor)[*UserKe-1].DocID, (*user)[*UserKe-1].ID);
        *DoctorKe++;
        (*doctor) = (DOCTORS *) realloc((*doctor), (*DoctorKe * sizeof(DOCTOR)));
        break;
    case 2:
        strcpy((*patient)[*UserKe-1].Name, (*user)[*UserKe-1].Name);
        strcpy((*patient)[*UserKe-1].ID, (*user)[*UserKe-1].ID);
        *PatientKe++;
        (*patient) = (PATIENTS *) realloc((*patient), (*PatientKe * sizeof(PATIENTS)));
        break;
    default:
        break;
    }
    printf("New %s Account Created!", type);
}

int end(USERS **user, MEDICINES **medicine, PATIENTS **patient, DOCTORS **doctor)
{
    free(*user);
    free(*patient);
    free(*doctor);
    free(*medicine);
    return 0;
}