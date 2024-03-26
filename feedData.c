#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct banking
{
  char name[20],acc[7];
  int balance;	
};
int main()
{   time_t currentTime;
    time(&currentTime);
    struct tm *myTime = localtime(&currentTime);	
    struct banking std[50];
	FILE *f1 = fopen("Account Database.txt","w");
	int i=0,k=1,ct=0,option;
	char count[5];
	if(f1==NULL)
	{
		printf("Error\n");
		exit(1);
	}
	printf("\t\t\t\t\t  ***WELCOME TO SSB BANK***\n\n");
	fseek(f1,-52,SEEK_END);
	fscanf(f1,"%1s",count);
	fclose(f1);
	ct=atoi(count);
	ct++;
	FILE *f2 = fopen("Account Database.txt","a");
	//fprintf(f2,"Sr. \t\t NAME \t\t ACCOUNT NO. \t\t BALANCE\n");
	printf("\n\t\t\t\t\t   \4Feed Costumer's Data\n\n");
	 printf("\n\t\t\t\t\tDate:%i/%i/%i\t   Time: %i:%i\n\n",myTime->tm_mday,myTime->tm_mon+1,myTime->tm_year+1900,myTime->tm_hour,myTime->tm_min);
	while(k==1)
	{
	printf("\n\nEnter the name of the costumer: ");
	fflush(stdin);
	gets(std[i].name);
	printf("\n\nEnter the Account No. to be provided: ");
	fflush(stdin);
	gets(std[i].acc);
	printf("\n\nEnter the initial deposited amount: ");
	fflush(stdin);
	scanf("%d",&std[i].balance);
	fprintf(f2,"%s \t\t  %s \t\t %d",std[i].name,std[i].acc,std[i].balance);
	fprintf(f2,"\n");
	printf("\n\n***Data is stored in file 'Account Database.txt' successfully***");
	printf("\n\nWant to enter another data?\n1.YES\t\t2.NO\n");
	scanf("%d",&k);
	i++;
	ct++;	
    }
	fclose(f2);
	printf("\n\t\t\t\t\t     -----------------------");
    printf("\n\t\t\t\t\t\tS.S.B BANK LIMITED\n");
    printf("\t\t\t\t\t     -----------------------\n\n");
	//printf("\n\t\t\t\t\t\4 Total Costumers Strength is %d",ct-1);
	return 0; 
}
