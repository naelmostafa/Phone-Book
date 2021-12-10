#ifndef TELE_H_INCLUDED
#define TELE_H_INCLUDED

typedef struct
{
    int day;
    int month;
    int year;
} date;
typedef struct
{
    char last[30];
    char name[30];
    char address[50];
    char Email[100];
    int mobile;
    date dob;
} person;
person read_new()
{
    int phone;
    person New;
    printf("Enter Last_Name==>");
    scanf("%s",New.last);
    printf("Enter First_Name==>");
    scanf("%s",New.name);
    do
    {
        printf("Enter Date Of Birth (dd/mm/yy)==>");
        scanf("%d%d%d",&New.dob.day,&New.dob.month,&New.dob.year);
    }
    while(New.dob.day > 31 || New.dob.day < 1 || New.dob.month > 12 || New.dob.month < 1 || New.dob.year < 1900 || New.dob.year < 1 || New.dob.year > 2019);
    fflush(stdin);
    printf("Enter Address==>");
    gets(New.address);
    printf("Enter Email (Example@Domin.com)==>");
    scanf("%s",New.Email);
    printf("Enter Phone Number (03-XXX XXXX)==>");
    scanf("%d",&New.mobile);
    return New;
}
void sort_Lname(int x,person y[])
{
    int i,j;
    person temp;
    for(i=0; i<x; i++)
    {
        for(j=i+1; j<x; j++)
        {
            if(strcasecmp(y[i].last,y[j].last)>0)
            {
                temp=y[i];
                y[i]=y[j];
                y[j]=temp;
            }
        }
    }

}
void sort_DOB(int x,person y[])
{
    int i,j;
    person temp;

    for(i=0; i<x; i++)
    {
        for(j=i+1; j<x; j++)
        {
            if(y[i].dob.year<y[j].dob.year)
            {
                temp=y[i];
                y[i]=y[j];
                y[j]=temp;
            }
            else if(y[i].dob.year == y[j].dob.year)
            {
                if(y[i].dob.month<y[j].dob.month)
                {
                    temp=y[i];
                    y[i]=y[j];
                    y[j]=temp;
                }
                else if(y[i].dob.month == y[j].dob.month)
                {
                    if(y[i].dob.day<y[j].dob.day)
                    {
                        temp=y[i];
                        y[i]=y[j];
                        y[j]=temp;
                    }
                }

            }
        }
    }
}
void print(int x , person y[])
{
    printf("\n");
    int i=0;
    for(i=0; i<x; i++)
    {
        printf("\n%d)Last Name:%s | First Name:%s | Date of birth:%d/%d/%d | Address:%s | Email:%s | Mobile:%d",i+1,y[i].last,y[i].name,y[i].dob.day,y[i].dob.month,y[i].dob.year,y[i].address,y[i].Email,y[i].mobile);
    }
    printf("\n\n");
}
void Delete(int x,person y[])
{
    int mod[20];
    int i,target,z;
    search(1);
    printf("Chose contact to Delete:");
    scanf("%d",&z);
    target = mod[z];
    for(i=target; i<x-1; i++)
    {
        y[i] = y[i+1];
    }
    x--;
    fflush(stdin);
    printf("Contact deleted Successfully");
    menu();
}

#endif // TELE_H_INCLUDED
