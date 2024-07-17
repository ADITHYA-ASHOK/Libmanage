#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


struct book{
    int book_id;
    char title[50];
    char author[50];
   int available;
    
};

struct stud{
    int stud_id;
    int roll_num;
    char name[50];
    
};

struct issuebook{
    int book_id;
    int stud_id;
    char issue_date[50];
    char return_date[50];
};
struct returnbook{
    int book_id;
    int stud_id;
    char issue_date[50];
    char return_date[50];
    int days;
    int fine;

};

struct fine{
    int book_id;
    int stud_id;
    char return_date[50];
    char due_date[20];
    float fineamnt;
    int fine;
    int days;
};
void add_book();
void add_student();
void issue_book();
void return_book();
void show_fine();

int main()
{
    int choice;

    printf("LIBRARY MANGEMENT");
    printf("1.Add book\n");
    printf("2.Add student\n");
    printf("3.Issue book\n");
    printf("4.return book\n");
    printf("5.show fines\n");
    printf("6.exit\n");

    while(1){
        printf("Enter your choice:");
        scanf("%d",&choice);
    
    switch(choice){
        case 1:
        add_book();
        break;
        case 2:
        add_student();
        break;
        case 3:
        issue_book();
        break;
        case 4:
        return_book();
        break;
        case 5:
        show_fine();
        break;
        case 6:
        exit(0);
        break;
        default:
        printf("Invalid choice!\n");
        }
}
        return 0;
}

void add_book(){
    struct book Book;
    printf("enter the book id:");
    scanf("%d",&Book.book_id);
    printf("enter the book title:");
    scanf("%s",Book.title);
    printf("enter the book author:");
    scanf("%s",Book.author);
    Book.available=1;

    FILE *fp=fopen("books.txt","a");
    if(fp==NULL){
        printf("Error opening file\n");
        return;
    }
    fprintf(fp,"%d %s %s\n",Book.book_id,Book.title,Book.author);
    fclose(fp);
    printf("book added successfully.\n");
}

void add_student(){
    struct stud Stud;
    printf("enter the student id:");
     scanf("%d",&Stud.stud_id);
     printf("enter the roll number:");
     scanf("%d",&Stud.roll_num);
     printf("enter the student name:");
     scanf("%s",Stud.name);

     FILE*fp=fopen("students.txt","a");
     if(fp==NULL){
        printf("Error opening file\n");
        return;
}
fprintf(fp,"%d %d %s\n",Stud.stud_id,Stud.roll_num,Stud.name);
fclose(fp);
printf("student have added successfully!");
}

void issue_book(){
    struct issuebook Issuebook;
    printf("enter the book id:");
    scanf("%d",&Issuebook.book_id);
    printf("enter the student id:");
    scanf("%d",&Issuebook.stud_id);
    printf("enter the issue date:");
    scanf("%s",Issuebook.issue_date);


FILE*fp=fopen("issues.txt","a");
     if(fp==NULL){
        printf("Error opening file\n");
        return;
}
fprintf(fp,"%d %d %s\n",Issuebook.book_id,Issuebook.stud_id,Issuebook.issue_date);
fclose(fp);
printf("student have issued successfully!");

}


void return_book(){
    int days;
    int fine;
struct returnbook Return;
printf("enter the book id:");
scanf("%d",&Return.book_id);
printf("enter the student id:");
scanf("%d",&Return.stud_id);
printf("enter the issue_date:");
scanf("%s",Return.issue_date);
printf("enter the return date:");
scanf("%s",Return.return_date);
printf("enter the number of due dates:");
scanf("%d",&days);

FILE*fp=fopen("returned.txt","a");
     if(fp==NULL){
        printf("Error opening file\n");
        return;
}
fprintf(fp,"%d %d %s %s %d\n",Return.book_id,Return.stud_id,Return.issue_date,Return.return_date,days);
fclose(fp);
printf("book returned successfully!");

if(days>0){
    float fine=days*10.0;
    printf("fineamount=%f\n;",fine);
    FILE*fineFile=fopen("fines.txt","a");
if(fineFile==NULL){
    printf("error in opening the file!\n");
    return;
}
fprintf(fineFile,"%d %d %f %s\n",Return.stud_id,Return.book_id,Return.fine,Return.return_date);
fclose(fineFile);
printf("Fine recorded successfully.\n");

}else{
    printf("no fine\n");
}
}


void show_fine(){
   char line[100];
FILE *fineFile=fopen("fines.txt","r");
if(fineFile==NULL){
    printf("error in opening file");
    return;
}
printf("fines:\n");
while(fgets(line,sizeof(line),fineFile)){
    printf("%s",line);
}
    fclose(fineFile);
}















    








