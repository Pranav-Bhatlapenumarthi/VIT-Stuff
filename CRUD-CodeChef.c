                                                  /**************************************
                                                  **                                   **
                                                  **    BLOG MANANGEMENT SYSTEM        **
                                                  **    PROGRAMMED IN C                **
                                                  **    BY PRANAV BHATLAPENUMARTHI     **
                                                  **                                   **
                                                  ***************************************/

// IMPORTING ALL NECCESSARY HEADER FILES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DECLARING ALL NECCESSARY FUNCTIONS
void create_blog(void);
void open_blog(void);
void delete_blog(void);
void display(char*);
void login(void);
void login1(void);
void acc(void);
void acc_created(void);
void logout(void);

// CREATING A STRUCTURE OT STORE THE DATA OF THE USER
struct user_data{
    int date, month, year; // for D.O.B
    char mobilenumber[15];
    char firstname[25];
    char lastname[25];
    char address[100];
    char mail_id[40];
    char username[50];
    char password[35];
};

// DRIVER CODE
int main(void)
{
    int choice;

    printf("\n\n\t\t\t\t===== BLOG MANAGEMENT SYSTEM ======\n\n\n\n");
    printf("\t1...CREATE NEW BLOGGING ACCOUNT\n\n\t2...LOGIN INTO EXISTING ACCOUNT\n\n\t3...EXIT PORTAL");
    printf("\n\n\t----------------------------------------------------------------------------");
    printf("\n\n\tENTER YOUR CHOICE:  "); scanf("%d", &choice); //Receiving input from the user

    // Initialising switch case w.r.t choice

    switch(choice){
    case 1:
        system("cls");
        printf("\n\n\tENTER USER NAME (MAX. 50 CHARACTERS)");
        printf("\n\tENTER PASSWORD(MAX. 20 CHARACTERS)");
        acc();
        break;

    case 2:
        login();
        break;

    case 3:
        exit(0);
        break;

    default:
        break;
    }
}

// DEFINING THE FUNCTION BODY USED TO CREATE NEW ACCOUNTS
void acc(void)
{
    char password[20], ch;
    int passwdlen, i, seek = 0;
    FILE *fp, *fu;
    struct user_data u1;

    // Opening file to write the data of the user
    fp = fopen("user_data.txt", "wb");

    //Receiving the inputs from the user
    system("cls");
    printf("\n\n\t*****CREATING A NEW ACCOUNT*****\n\n");
    printf("\n\tFIRST NAME:   "); scanf("%s", &u1.firstname);
    printf("\n\tLAST NAME:   "); scanf("%s", &u1.lastname);

    // Taking input for DOB and checking respective conditions
    printf("\n\tDATE OF BIRTH:"); printf("\n\t\tDATE:   "); scanf("%d", &u1.date);
    if((u1.date > 31) | (u1.date < 0))
    {
        printf("\n\t\tINVALID INPUT !\n");
        printf("\n\t\tDATE:   "); scanf("%d", &u1.date);
    }
    printf("\n\t\tMONTH(1-12):   "); scanf("%d", &u1.month);
    if((u1.month < 0) | (u1.month > 12))
    {
        printf("\n\t\tINVALID INPUT !\n");
        printf("\n\t\tMONTH:   "); scanf("%d", &u1.month);
    }
    printf("\n\t\tYEAR:   "); scanf("%d", &u1.year);
    if(u1.year > 2024)
    {
        printf("\n\t\tINVALID INPUT !\n");
        printf("\n\t\tYEAR:   "); scanf("%d", &u1.year);
    }
    // Proceeding with other information inputs

    printf("\n\tMOBILE NUMBER(NO SPACE BETWEEN COUNTRY CODE AND MOBILE NUMBER):   "); scanf("%s.", &u1.mobilenumber);
    if (strlen(u1.mobilenumber) > 15)
    {
        printf("\n\tINVALID INPUT !\n");
        printf("\n\tMOBILE NUMBER(NO SPACE BETWEEN COUNTRY CODE AND MOBILE NUMBER):   "); scanf("%s.", &u1.mobilenumber);
    }
    for(i = 0; i<strlen(u1.mobilenumber); i++){
        if(i >=48 & i<= 57)
            continue;
        else
            break;
    }

    printf("\n\tCITY OF RESIDENCE:   "); scanf("%s.", &u1.address);
    printf("\n\tMAIL ID:   "); scanf("%s.", &u1.mail_id);

    printf("\n\tUSERNAME(NO SPACE):   ");scanf("%s.", &u1.username);
    printf("\n\tPASSWORD:   "); scanf("%s.", &u1.password);

    fwrite(&u1, sizeof(u1), 1, fp);

    fclose(fp);

    acc_created(); // Calling another function after the account is created successfully

}

// DEFINING FUNCTION BODY FOR THE NEXT STEP AFTER ACCOUNT CREATION
void acc_created(void)
{
    int i; char ch;
    printf("\n\n\t\tPLEASE WAIT WHILE WE PROCESS YOUR DATA...");

    for(i = 0; i < 20000000; i++)
    {
        i++;i--;
    }
    printf("\n\n\t\tACCOUNT CREATED SUCCESSFULLY !");

    login();
}

// FUNCTION DEFINITION FOR LOGIN PROCESS
void login(void)
{
    char username[50], password[50];
    int i; char ch;
    FILE *fp;
    struct user_data u1;

    fp = fopen("user_data.txt", "rb");
    if (fp == NULL)
    {
        printf("\n\n\tERROR IN OPENING FILE");
    }

    printf("\n\n\t\t ==== LOGIN ====");

    printf("\n\n\tUSERNAME... "); scanf("%s", &username);
    printf("\n\tPASSWORD... "); scanf("%s", &password);



    // verifying username and password of the user with the data in the file
    while(fread(&u1, sizeof(u1),1, fp))
    {
        if((strcmp(username, u1.username) == 0) & (strcmp(password, u1.password) == 0))
            {
                login1();
                display(username);
                break;
            }
        else
        {
            while((strcmp(username, u1.username) != 0) | (strcmp(password, u1.password) != 0))
            {
                printf("\n\tINVALID USER ID OR PASSWORD. PLEASE TRY AGAIN.");
                printf("\n\n\tUSERNAME... "); scanf("%s", &username);
                printf("\n\tPASSWORD... "); scanf("%s", &password);

                if((strcmp(username, u1.username) == 0) & (strcmp(password, u1.password) == 0))
                {
                    login1();
                    display(username);
                    break;
                }
            }
        }
    }

    fclose(fp);
}

// REDIRECTING AFTER SUCCESSFUL LOGIN
void login1(void)
{
    int i; char ch;

    system("cls");
    printf("\nVERIFYING LOGIN CREDENTIALS....");

    for(i = 0; i < 200000; i++)
    {
        i++; i--;
    }

    printf("\n\nLOGIN SUCCESSFUL !\nPRESS ENTER TO CONTINUE..");

    ch = getchar();
}

// DISPLAYING ACCOUNT DETAILS OF USER
void display(char username1[])
{
    system("cls");
    FILE *fp;
    int choice, i;
    fp = fopen("user_data.txt", "rb");
    struct user_data u1;

    if( fp == NULL )
    {
        printf("\n\tERROR ENCOUNTERED WHILE ACCESSING FILE.");
    }

    while(fread(&u1, sizeof(u1) , 1, fp))
    {
        if(strcmp(username1, u1.username) == 0)
        {
            printf("\n\n\tWELCOME %s %s", u1.firstname, u1.lastname);
            printf("\n\t--------------------------------------");
        }
    }

    fclose(fp);

    // Menu options to perform different actions after logging in

    printf("\n\n\t\t ===== HOME =====");
    printf("\n\n\t1...CREATE NEW BLOG");
    printf("\n\n\t2...OPEN EXISTING BLOG");
    printf("\n\n\t2...DELETE EXISTING BLOG");
    printf("\n\n\t3...LOG OUT");
    printf("\n\n\t4...EXIT");

    printf("\n\n\t\tENTER YOUR PREFERENCE:  "); scanf("%d", &choice);\

    // Initialising switch case according to user choice

    switch(choice){
    case 1:
        //create_blog();
        break;

    case 2:
        //open_blog();
        break;

    case 3:
        //delete_blog();
        break;

    case 4:
        //logout();
        break;

    case 5:
        exit(0);
        break;

    default:
        break;
    }

}

