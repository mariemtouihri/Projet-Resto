#include <stdio.h>

int main()
{
    int ID;
    char Name[50];
    struct dob
{
     int day,month,year;
};
    struct dob patient;
    int MAXCHAR=1000;
    int choice;
    FILE *fptr;
    char str[MAXCHAR];
    char* filename = "C:\\Users\\Youss\\Desktop\\Assignment6\\PatientRecords.txt";

    printf("Welcome to the Clinic \n");

    while(1)
    {
     printf("Main Menu \n");
     printf("1- Display the patients of the clinic \n");
     printf("2- Search for a patient \n");
     printf("3- Add new Patient \n");
     printf("4- Remove Patient \n");
     printf("5- Exit \n");
     printf("Enter you option choice \n");
     scanf("%i",&choice);

     switch(choice)
    {
        case 1:
            fptr = fopen(filename, "r");
            if (fptr == NULL)
            {
            printf("Could not open file %s",filename);
            return 1;
            }
            while (fgets(str, MAXCHAR, fptr) != NULL)
            {
            printf("%s", str);
            }
            fclose(fptr);
            printf("\n");
            break;

         case 2:
            break;

         case 3:
            fptr = fopen(filename,"a");
            if(fptr == NULL)
            {
            printf("Error!");
            return 1;
            }
            printf("Enter Patient ID \n");
            scanf("%i",&ID);
            fprintf (fptr, "ID: %i",ID);
            printf("Enter Patient Name \n");
            scanf("%s",&Name);
            fprintf (fptr, "\nName: %s",Name);
            printf("Enter Patients Day/Month/Year \n");
            scanf("%i %i %i",&patient.day,&patient.month,&patient.year);
            fprintf (fptr, "\nDOB: %i-%i-%i",patient.day,patient.month,patient.year);
            fprintf(fptr,"\n------------------------------------------------------------------------");
            fclose(fptr);
            break;

         case 4:
            break;
         case 5:
             return 0;
            break;
         default:
            printf("Choice not available try choosing again");
     }
    }
}
