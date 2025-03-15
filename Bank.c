#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

void transaction_details();
void account_details();
void transfer_money();
void withdraw_money();
void deposit_money();
void last_details();
void menu();
void divider();
char name[20],Benif[20];
int dip_amt , amount=10000 , acc_no,with_money,trans_Amount;

int main()
{
    int choice;
    printf("Enter your Name: ");
    gets(name);

    printf("Enter account Number: ");
    scanf("%d",&acc_no);
    while(1){
    menu();
    printf("Enter your choice\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: 
                deposit_money();
                break;

        case 2: 
                withdraw_money();
                break;

        case 3: 
                 transfer_money();
                break;

        case 4: 
                account_details();
                break;

        case 5: 
                transaction_details();
                break;

        case 6: 
                last_details();
                exit(0);
                break;
        default: printf("Invalid Choice\n");
                break;
    }
    }
    return 0;
}

void menu()
{
    printf("\nMAIN MENU\n");
    divider();
    printf("\n1.Deposit Money\n");
    printf("2.Withdraw Money\n");
    printf("3.Transfer Money\n");
    printf("4.Account Details\n");
    printf("5.Transcation Details\n");
    printf("6.Exit\n");
}

void deposit_money()
{
    time_t tm;
    time(&tm);
    FILE *ptr=fopen("Account.txt","a");
    printf("DEPOSITING MONEY\n");
    divider();
    printf("\nEnter the amount: \n");
    scanf("%d",&dip_amt);

    amount=amount+dip_amt;
    printf("Money Deposited Successfully!\n");
    printf("Current Balance: Rs%d\n",amount);
    fprintf(ptr,"Rs%d is deposited in your account %s\n",dip_amt,ctime(&tm));
}

void withdraw_money()
{
    time_t tm;
    time(&tm);
    FILE *ptr=fopen("Account.txt","a");

    printf("WITHDRAW MONEY\n");
    divider();
    printf("\nEnter Amount to withdraw\n");
    scanf("%d",&with_money);
    if(with_money>amount)
    {
        printf("No Enough Fund!\n");
        return;
    }
    amount=amount-with_money;
    printf("Money Withdraw Successfull!\n");
    printf("Current Balance: Rs%d\n",amount);
    fprintf(ptr,"Rs%d is withdrawed %s\n",with_money,ctime(&tm));
}

void transfer_money()
{
    time_t tm;
    time(&tm);
    FILE *ptr=fopen("Account.txt","a");
    int ac;
    printf("TRANSFER MONEY\n");
    divider();
    printf("\nEnter Benificiary Account number\n");
    scanf("%d",&ac);
    printf("Enter Amount to Transfer\n");
    scanf("%d",&trans_Amount);
    if(trans_Amount>amount)
    {
        printf("No Enough Fund!");
        return;
    }
    amount=amount-trans_Amount;
    printf("Amount Transfer Successful!\n");
    printf("Current Balance: Rs%d\n",amount);
    fprintf(ptr,"Rs%d is Transfered to A/c.%d %s\n",trans_Amount,ac,ctime(&tm));
    fclose(ptr);
    printf("Press any key to continue........\n");
    getch();
}

void account_details()
{
    printf("ACCOUNT DETAILS:\n");
    divider();
    printf("\n");
    printf("Name: %s\n",name);
    printf("A/c No.: %d\n",acc_no);
    printf("Closing Balance: %d\n",amount);
    printf("Press any key to continue........\n");
    getch();
}

void transaction_details()
{
    FILE *ptr=fopen("Account.txt","r");
    //check if file "Account.txt" is empty or not.
    char c= fgetc(ptr);
    printf("TRANSACTION DETAILS:\n");
    divider();
    printf("\n");
    if(c==EOF)
    {
        printf("No Transaction Made!\n");
    }
    else{
            while(c!=EOF)
            {
                printf("%c",c);
                c=fgetc(ptr);
            }
    }
    printf("Press any key to continue........\n");
    getch();
}

void last_details()
{
    printf("Name: %s\n",name);
    printf("A/c No.: %d\n",acc_no);
    printf("Closing Balance: %d\n",amount);
    printf("Press any key to continue........\n");
    getch();
}

void divider()
{
    for(int i=0;i<50;i++)
    {
        printf("-");
    }
}