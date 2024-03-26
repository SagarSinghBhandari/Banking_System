#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct banking
{
char name[20],acc[10];
int balance;	
};
int main()
{
time_t currentTime;
time(&currentTime);
struct tm *myTime = localtime(&currentTime);	
int draw=0,dep=0,transfer=0,k=0,l=0,k2=0;
char name[24],c[10],c2[10];
char account1[7],account2[7],account3[7];
int i=0,type,ecc=1,flag=0,flag2=0,back=0;
int transaction=1,balance,balance2,sum1=0,sum2=0,sum3=0;
// Welcome Display:-
printf("\t\t\t\t\t\4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4\n");
printf("\t\t\t\t\t\4\t\t\t\t\t\t\4\n");
printf("\t\t\t\t\t\4\t\t\t\t\t\t\4\n");
printf("\t\t\t\t\t\4\tWELCOME TO OUR S.S.B BANKING SYSTEM\t\4\t\t\n");
printf("\t\t\t\t\t\4\t\t\t\t\t\t\4\n");
printf("\t\t\t\t\t\4\t\t\t\t\t\t\4\n");
printf("\t\t\t\t\t\4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4\n");
// Credential Entry:-
entry:
struct banking std[50];
FILE *f1 = fopen("Account Database.txt","r+");
char acct[7],str[10];
printf("\nEnter your six digit Account number: ");
gets(acct);
if(f1==NULL){
printf("Error\n");
exit(1);
}
while(fscanf(f1,"%s\n,%s\n",&std[i].acc,&std[i].balance)!=EOF && flag==0){
if(strcmp(std[i].acc,acct)==0){
flag=1;
k=ftell(f1);
printf("\n\n\t\t\t\t\t\t******Account found******\n");
fscanf(f1, "%[^\n]s",c);
}
}
if(flag==0){
if(ecc!=3){	
printf("\n\n\t\t\t\t\t Account Entered Is Not Correct!!\n\nPlease try again(%d)\n",ecc);
}
while(ecc!=3){
ecc++;
goto entry;
}
if(ecc=3){
printf("\n\nMaximum limit reached\n\n\4\4\4\t Acess Denied!! \t\4\4\4\n");
exit(1);	
}

// Action to be performed:-

}
int option;
printf("\nchoose what you want to do\n");
printf("1 - Balance Enquiry\n");
cc:
printf("2 - Deposit\n");	
printf("3 - Withdraw\n");	
printf("4 - transfer\n");
printf("5 - exit\n");
balance=atoi(c);
scanf("%d",&option);
fflush(stdin);
while(option!=5){
switch(option)
{
case 1:
printf("\t\t\t*BALANCE ENQUIRY*\n\n");
printf("your current balance is: %d.00Rs\n",balance);
break;
case 2:
{	
printf("\n\t\t\t*DEPOSIT AMMOUNT*\n\n");
printf("how much money do you want to deposit:");
scanf("%d",&dep);
if(dep > 0 && dep<=20000)
{	
printf("\%d.00Rs deposited in your account.\n\n",dep);
sum1=sum1+dep;
}
else if(dep>20000)
{
printf("\nyou can't deposit that much ammount in one time.\n\n");
}
else
{
printf("\ninvalid deposit amount\n");
}
}
break;
case 3:
{
printf("\n\t\t*WITHDRAW AMMOUNT*\n\n");
printf("how much money do you want to withdraw:");
scanf("%d",&draw);
if(draw<=balance && draw<=20000)
{
printf("\nyou just withdraw %dRs\n\n",draw);
sum2=sum2+draw;
}
else if(draw>20000)
{
printf("\nyou can't withdraw that much amount in one time.\n\n");
}
else
{
printf("\nyou dont have enough money\n\n");
}
}
break;
case 4:
{	
printf("\t\t\tTRANSFER AMMOUNT \n\n");
printf("\n\t\tAccount You Want To Transfer: ");
scanf("%s",&account2);
fseek(f1,0,SEEK_SET);
flag2=0;
while(fscanf(f1,"%s\n,%s\n",&std[i].acc,&std[i].balance)!=EOF && flag2==0){
if(strcmp(std[i].acc,account2)==0)
{
flag2=1;
k2=ftell(f1);
fscanf(f1, "%[^\n]s",c2);
printf("\nhow much ammount?: ");
fflush(stdin);
scanf("%d",&transfer);
if(balance>=transfer)
{
balance2=atoi(c2);
printf("\n%d.00Rs successfully transfered\n\n",transfer);
sum3=sum3+transfer;
balance2+=transfer;
}
else
{
printf("\nyou do not have sufficient balance\n\n");
}
}
}
if(flag2==0){	
printf("\n\n\t\t\t\t\t***No such Account Is Found!!***\n\n");
}
break;
}
default:
printf("invalid transaction\n");
}

// Bank data to be updated:-

balance+=sum1;
balance-=sum2;
balance-=sum3;
fseek(f1,k,SEEK_SET);
fprintf(f1,"%d",balance);
fseek(f1,k2,SEEK_SET);
fprintf(f1,"%d",balance2);

// Doing transaction again:-

if(option!=1){
printf("do you want to do another transaction?\n");
printf("1. yes 2. no\n");
scanf("%d",&transaction);
if (transaction==1){
goto cc;	
}
else if(transaction!=1 && transaction!=2)
{
printf("invalid no.\nchoose between 1 and 2 only\n");
}
else
{
goto dd;	
}
}
fflush(stdin);

// Transaction information:-

dd:
printf("\n\t\t\t\t\t   -----------------------");
printf("\n\t\t\t\t\t\tS.S.B BANK LIMITED\n");
printf("\t\t\t\t\t   -----------------------\n\n");
printf("\t\t\t\t\tDate:%i/%i/%i\t   Time: %i:%i\n",myTime->tm_mday,myTime->tm_mon+1,myTime->tm_year+1900,myTime->tm_hour,myTime->tm_min);
printf("\n\t\t\t\t\t\4 Your name: %s\n\n",name);
printf("\t\t\t\t\t\4 Your account no: %s\n\n",acct);
if(dep >= 0 && dep < 20000)
{
printf("\t\t\t\t\t\4 You've deposited %d.00Rs\n",sum1);
}
else
{printf("\t\t\t\t\t\4 You've deposited 0Rs\n");}
if(draw>0 && draw<=20000 && draw<=balance)
{
printf("\n\t\t\t\t\t\4 You've withdraw %d.00Rs\n",sum2);
}
else
{printf("\n\t\t\t\t\t\4 You've withdraw 0Rs\n");
}
if(transfer>0 && transfer<=20000 && transfer<=balance)
{
printf("\n\t\t\t\t\t\4 You've Transfered %d.00Rs\n",sum3);
}
else
{
printf("\n\t\t\t\t\t\4 You've Transfered 0Rs\n ");
}

// Closing Window:-	
	
printf("\n\n\t\t\t\t\t     Thank you! \n");
printf("\t\t\t\t   Welcome back again SSB Banking System\n");
printf("\t\t\t\t      www.SSBBANKINGSYSTEM.com\n");
fclose(f1);
return(0);
getchar();
}
}

