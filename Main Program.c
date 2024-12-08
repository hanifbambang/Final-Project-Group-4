#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char DocName[50];
    char PatientName[50];
    enum {DOCTOR, PATIENT, ADMIN}Role;
} user;

int main ()
{
    return 0;
}