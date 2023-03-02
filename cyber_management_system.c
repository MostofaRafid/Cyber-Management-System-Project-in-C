/***
Mostofa Rafid
213902097
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void heading();
void main_heading();
void menu();
void user_menu();
void insert();
void display();
void search();
void delete();
void main()
{
    char name[30];
    int id;
    int ch;
    char username[20];
    char password[20];

    system("CLS");
    heading();
    printf("\n\n\t\t\t\t\t1) Login as Admin");
    printf("\n\t\t\t\t\t2) Login as user");
    printf("\n\n\t\t\t\t\tEnter your choice (1/2) : ");
    scanf("%d",&ch);
    system("CLS");

    switch(ch)
    {
    case 1:
        system("CLS");
        heading();
        printf("\n\n\t\t\t\t\t\t||    ADMIN LOGIN    ||\t\t\t\t");
        printf("\n\n\n\t\t\t\t\tUsername :");
        scanf("%s",&username);
        printf("\t\t\t\t\tPassword :");
        scanf("%s",&password);

        if(strcmp(username, "admin")==0)
        {
            if(strcmp(password,"admin123")==0)
            {
                system("CLS");
                main_heading();
                printf("\n\n\t\t\t\t\t\tLOGIN SUCCESSFULL!!!");
                menu();
            }
            else
            {
                printf("\t\t\t\t\tIncorrect Password !!! Failed to Login");
            }
        }
        else
        {
            printf("\t\t\t\t\tUsername is invalid !!! Failed to Login");
        }

        break;
    case 2:
        system("CLS");
        main_heading();
        user_menu();

    default:
    {
        printf("\n\n\t\t\t\t\tInvalid Choice!!!");
    }
    break;
    }
}
void heading()
{
    printf("\n\t\t\t\t****************************************************\t\t\t\t");
    printf("\n\t\t\t\t||       WELCOME TO CYBER MANAGEMENT SYSTEM       ||\t\t");
    printf("\n\t\t\t\t****************************************************\t\t\t\t\n");
}

void main_heading()
{
    printf("\n\t\t\t\t*****************************************************\t\t\t\t");
    printf("\n\t\t\t\t||              CYBER MANAGEMENT SYSTEM            ||\t\t");
    printf("\n\t\t\t\t*****************************************************\t\t\t\t");
}

void menu()
{
    int choice;
    printf("\n\n\n\t\t\t\t\t\t  |<----MENU---->|");
    printf("\n\n\t\t\t\t\t\t1.Insert Record");
    printf("\n\t\t\t\t\t\t2.Display Record");
    printf("\n\t\t\t\t\t\t3.Search Record");
    printf("\n\t\t\t\t\t\t4.Delete Record");
    printf("\n\t\t\t\t\t\t5.Exit");
    printf("\n\n\t\t\t\t\t\tEnter your choice :");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        system("CLS");
        insert();
        break;

    case 2:
        system("CLS");
        main_heading();
        display();
        printf("\n\n\t\t\t\t\tPress any key to continue ");
        fflush(stdin);
        getchar();
        menu();

    case 3:
        system("CLS");
        search();
        printf("\n\n\t\t\t\t\tPress any key to continue ");
        fflush(stdin);
        getchar();
        menu();
        break;

    case 4:
        system("CLS");
        delete();
        break;

    case 5:
        system("CLS");
        exit(0);
        break;

    default:
        printf("INVALID CHOICE !!!");
    }
}

void user_menu()
{
    int choice;
    printf("\n\n\n\t\t\t\t\t\t|<----MENU---->|");
    printf("\n\n\t\t\t\t\t\t1.View Your Record");
    printf("\n\t\t\t\t\t\t2.Exit");
    printf("\n\n\t\t\t\t\t\tEnter your choice :");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        system("CLS");
        search();
        break;

    case 2:
        system("CLS");
        exit(0);
        break;
    }
}

void insert()
{
    time_t mytime;
    struct tm* current_time;
    mytime = time(NULL);
    current_time = localtime(&mytime);

    FILE *fp;
    char name[30];
    int id;
    char choice='y';
    system("CLS");
    fp = fopen("cyber.txt","ab+");

    if(fp==NULL)
    {
        printf("\n\t\t\t\t\tERROR OPENING FILE !!!");
        return;
    }
    fflush(stdin);
    while(choice=='y')
    {
        main_heading();
        printf("\n\n\t\t\t\t\t\tENTER NEW USER DATA :");
        printf("\n\n\t\t\t\t\tEnter ID : ");
        scanf("%d",&id);
        fflush(stdin);
        printf("\n\n\t\t\t\t\tEnter Name : ");
        scanf("%s",&name);
        fflush(stdin);
        fprintf(fp,"%d %s\t",id,name);
        fprintf(fp,"%02d/%02d/%d %02d:%02d",current_time->tm_mday,current_time->tm_mon+1,current_time->tm_year+1900,current_time->tm_hour,current_time->tm_min);
        fprintf(fp,"\n");
        printf("\n\n\t\t\t\t     USER RECORD INSERTED SUCCESSFULLY !!!");
        printf("\n\n\t\t\t\t     Want to add another record ? (y/n) : ");
        scanf("%c",&choice);
        fflush(stdin);
        system("CLS");
        fflush(stdin);
    }
    fclose(fp);
    printf("\n\n\t\t\t\t\t     Press any key to continue ");
    getchar();
    menu();
}

void display()
{
    time_t mytime;
    struct tm* current_time;
    mytime = time(NULL);
    current_time = localtime(&mytime);
    FILE *fp;
    fp = fopen("cyber.txt","rb");

    if(fp==NULL)
    {
        printf("\n\t\t\t\t\tERROR OPENING FILE !!!");
        return;
    }
    char name[30];
    int id;
    int mday,mmon,myear,mmin,mhour;
    printf("\n\n\t\t\t\t\t\t<|----USER DETAILS----|>");
    printf("\n\t\t\t   ____________________________________________________________________");
    printf("\n\n\t\t\t   User_ID\t\tName of User\t\tDate\t\tTime");
    printf("\n\t\t\t   ____________________________________________________________________");

    while(fscanf(fp,"%d %s %02d/%02d/%d %02d:%02d",&id,&name,&mday,&mmon,&myear,&mhour,&mmin)!=EOF)
    {
        printf("\n\n\t\t\t    %d \t\t\t%s \t\t\t%02d/%02d/%d \t%02d:%02d",id,name,mday,mmon,myear,mhour,mmin);
    }
    fclose(fp);
}
void search()
{
    system("CLS");
    main_heading();
    int my_id,flag=0;
    time_t mytime;
    struct tm* current_time;
    mytime = time(NULL);
    current_time = localtime(&mytime);
    FILE *fp;
    char name[30];
    int id;
    int mday,mmon,myear,mmin,mhour;
    fp = fopen("cyber.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\t\t\t\tERROR OPENING FILE !!!");
        return;
    }
    printf("\n\n\t\t\t\t\tEnter ID to fetch information :");
    scanf("%d",&my_id);
    while(fscanf(fp,"%d %s %02d/%02d/%d %02d:%02d",&id,&name,&mday,&mmon,&myear,&mhour,&mmin)!=EOF)
    {
        if(my_id == id)
        {
            flag=1;
            printf("\n\t\t\t\t\tRECORD FOUND SUCCESSFULLY !!!");
            printf("\n\n\t\t\t\t\tUser ID : %d",id);
            printf("\n\t\t\t\t\tName : %s",name);
            printf("\n\t\t\t\t\tLogin Date And Time : %02d/%02d/%d   %02d:%02d",mday,mmon,myear,mhour,mmin);
        }
    }
    fclose(fp);
    if(flag==0)
    {
        printf("\n\t\t\t\t\tRECORD NOT FOUND !!!");
    }
}

void delete()
{
    system("CLS");
    main_heading();
    FILE *fp,*ft;
    time_t mytime;
    struct tm* current_time;
    mytime = time(NULL);
    current_time = localtime(&mytime);
    int my_id;
    char name[30];
    int id;
    int mday,mmon,myear,mmin,mhour;
    unsigned flag=0;
    fp = fopen("cyber.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\t\t\t\tERROR OPENING FILE !!!");
        return;
    }
    printf("\n\t\t\t\t\t<|-------- PREVIOUS ENTERED DATA --------|>");
    display();
    printf("\n\n\n\t\t\t\tEnter ID to delete : ");
    scanf("%d",&my_id);

    ft = fopen("cyber1.txt","wb");
    if(ft==NULL)
    {
        printf("\n\t\t\t\tERROR OPENING NEW FILE !!!");
    }
    while(fscanf(fp,"%d %s %02d/%02d/%d %02d:%02d",&id,&name,&mday,&mmon,&myear,&mhour,&mmin)!=EOF)
    {
        if(my_id!=id)
        {
            flag=1;
            fprintf(ft,"%d %s\t",id,name);
            fprintf(ft,"%02d/%02d/%d %02d:%02d",mday,mmon,myear,mhour,mmin);
            fprintf(ft,"\n");
        }
    }
    if(flag==0)
    {
        printf("\n\t\t\t\tNo Such Record Found!!!");
    }
    fclose(fp);
    fclose(ft);
    remove("cyber.txt");
    rename("cyber1.txt","cyber.txt");
    printf("\n\n\t\t\t\tRecord Deleted Successfully!!!");
    printf("\n\n\t\t\t\t\t    <|----- Updated Records -----|> ");
    display();
    printf("\n\n\t\t\t\t\tPress any key to Continue");
    fflush(stdin);
    getchar();
    system("CLS");
    main_heading();
    menu();
}
