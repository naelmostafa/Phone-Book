#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"tele.h"

person contact[100];
char ch;
int numb;

void menu();
void load();
void save();
void search(int x);
void add();
void print_menu();
void modify();

int main()
{
    load();
    menu();
    return 0;
}

void menu()
{

    printf("\n\t\t********TELEPHONE BOOK********\n");
    printf("\n\nMENU:\n======\n");
    printf("1.load\t\t 2.Search\t\t 3.Add \n4.Delete\t 5.Modify\t\t 6.Print(Sort) \n7.Save \t\t 0.Quite\n==>");
    ch = getchar();
    fflush(stdin);
    switch(ch)
    {
    case'1':
        system("cls");
        load();
        break;

    case '2':
        system("cls");
        search(0);
        break;

    case '3':
        system("cls");
        add();
        break;

    case '4':
        system("cls");
        Delete(numb,contact);
        break;

    case '5':
        system("cls");
        modify();
        break;

    case '6':
        system("cls");
        print_menu();
        break;

    case '7':
        system("cls");
        save();
        break;

    case '0':
        system("cls");
        printf("Are you sure you want to Quit Without saving data (Y/N) :");
        ch = getchar();
        fflush(stdin);
        if(ch == 'y' || ch == 'Y')
            exit(0);
        else
            menu();
        break;

    default:
        system("cls");
        printf("<<<INVALID CHOICE>>> \nSELECT FROM 1 TO 8\n");
        menu();
    }
}
void print_menu()
{
    printf("\nPRINT(SORT)\n============");
    printf("\n1.Sort by LAST NAME\t\t 2.Sort by DOB\t\t 3.NO SORTING\n0.MENU\n==>");
    ch = getchar();
    fflush(stdin);
    switch(ch)
    {
    case '0':
        system("cls");
        menu();
        break;
    case '1':
        sort_Lname(numb,contact);
        printf("TASK COMPLETED SUCCESFULLY\n");
        print(numb,contact);
        print_menu();
        break;
    case '2':
        sort_DOB(numb,contact);
        printf("TASK COMPLETED SUCCESFULLY\n");
        print(numb,contact);
        print_menu();
        break;
    case '3':
        print(numb ,contact);
        print_menu();
        break;
    default:
        system("cls");
        printf("<<<INVALID CHOICE>>>\n");
        print_menu();
    }
}

void load()
{
    numb = 0;
    FILE *f;
    f = fopen("Phone_book.txt","r+");
    if(f == NULL)
    {
        printf("\n\t\t\t Error: Cannot Open File");
        menu();
    }
    else
    {
        while(!feof(f))
        {
            fscanf(f,"%[^,],",contact[numb].last);
            fscanf(f,"%[^,],",contact[numb].name);
            fscanf(f,"%d-",&contact[numb].dob.day);
            fscanf(f,"%d-",&contact[numb].dob.month);
            fscanf(f,"%d,",&contact[numb].dob.year);
            fscanf(f,"%[^,],",contact[numb].address);
            fscanf(f,"%[^,],",contact[numb].Email);
            fscanf(f,"%d\n",&contact[numb].mobile);
            numb++;
        }
    }
    fflush(stdin);
    fclose(f);
    printf("<<<File Loaded Successfully>>>\n");
    menu();
}
void save()
{
    printf("Are you sure you want to save (Y/N) : ");
    ch = getchar();
    fflush(stdin);
    if(ch == 'n' || ch == 'N')
    {
        menu();
        system("cls");
    }
    int i;
    FILE *f;
    f = fopen("Telephone_book.txt","w+");
    if(f == NULL)
    {
        printf("\n\t\t\t Error: Cannot Open File");
        menu();
    }
    for(i=0; i<numb; i++)
    {
        fprintf(f,"%s,",contact[i].last);
        fprintf(f,"%s,",contact[i].name);
        fprintf(f,"%d-",contact[i].dob.day);
        fprintf(f,"%d-",contact[i].dob.month);
        fprintf(f,"%d,",contact[i].dob.year);
        fprintf(f,"%s,",contact[i].address);
        fprintf(f,"%s,",contact[i].Email);
        fprintf(f,"%d\n",contact[i].mobile);
    }
    fclose(f);
    printf("Contact saved Successfully\n");
    menu();
}

void search(int x)
{
    int mod[20];
    int i;
    char last[35];
    int flag=0;
    person flagp[50];
    do
    {
        printf("<<<<TYPE N/A TO GO BACK TO MENU>>>>\n\n");
        printf("Enter Last Name :");
        scanf("%s",last);
        fflush(stdin);
        if(strcasecmp(last,"n/a") == 0 )
        {
            menu();
        }
        for(i=0; i<numb; i++)
        {
            if(strcasecmp(last,contact[i].last) == 0)
            {
                flagp[flag] = contact[i];
                flag++;
                mod[flag] = i;
            }
        }
        printf("%d Contacts Found\n",flag);
    }
    while(flag == 0);
    printf("\n");
    for(i=0; i<flag; i++)
        printf("%d)Last Name:%s | First Name:%s |Date of birth (dd/mm/yy):%d/%d/%d | Address:%s | Email:%s Mobile:%d \n",i+1,flagp[i].last,flagp[i].name,flagp[i].dob.day,flagp[i].dob.month,flagp[i].dob.year,flagp[i].address,flagp[i].Email,flagp[i].mobile);
    printf("\n");
    if(x == 0)
        menu();
}
void add()
{
    person con;
    int N,i=0;
    printf("How many contact you want to add:");
    scanf("%d",&N);
    for(i=0; i<N; i++)
    {
        con = read_new();
        contact[numb] = con;
        numb++;
        printf("\t=================================\n");
    }

    fflush(stdin);
    system("cls");
    printf("<<CONTACTS ADDED SUCCESFULLY>>\n");
    menu();
}

void modify()
{
    int mod[20];
    int req;
    search(1);
    printf("Enter the Number:");
    scanf("%d",&req);
    contact[mod[req]] = read_new();
    fflush(stdin);
    printf("Contact modified Successfully\n");
    menu();
}


