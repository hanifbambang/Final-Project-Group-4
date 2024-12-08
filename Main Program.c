#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Role{DOCTOR, PATIENT, ADMIN}Role;

typedef struct Doctor
{
    char DocName[50];
    char DocID[12];
    struct Patient
    {
        char Name[50];
        char ID[12];
        char Symptoms[50];
        char Medicine[50];
    }Patient;
}Doctor;

typedef struct Admin
{
    struct Medicine
    {
        char Name[50];
        char ID[12];
    } Medicine;
    struct User
    {
        char Name[50];
        char ID[12];
        Role Role[12];
    }User;
    
}Admin;

int main ()
{
    return 0;
}