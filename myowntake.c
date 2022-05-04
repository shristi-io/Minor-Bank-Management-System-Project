#include <stdio.h>
#include <string.h>

int menu(void);
void create(void);
void check(char *str);
void deposit(char *str);
void withdraw(char *str);

int main()
{
    printf("\n\tWelcome to the BANK\n\n");
    int choice = menu();
    char name[20];

    if (choice==1) create();
    else
    {
        printf("Please enter your name\n:");
        scanf("%s", name);

        if (choice==2) check(name);
        else if (choice==3) deposit(name);
        else if (choice==4) withdraw(name);
        else if (choice==5)
        {
            char remover;
            while(remover!='n' || remover!='N'){

                printf("Are you sure? Y/N?\n");
                scanf("%c", &remover);
                if (remover=='y' || remover=='Y')
                {
                    remove(name);
                    printf("Your account has been removed successfully\n");
                    break;
                }
                else if(remover=='n' || remover=='N') break;
            }
        }
    }



    return 0;
}

int menu(void)
{
    int i;
    printf("1. Create an account\n");
    printf("2. Check balance\n");
    printf("3. Deposit amount\n");
    printf("4. Withdraw\n");
    printf("5. Remove account\n");
    scanf("%d", &i);

    return i;
}

void create(void)
{
    char name[20];
    int amount;

    FILE* ptr;
    printf("Enter your name: \n");
    scanf("%s", name);
    ptr = fopen(name, "w");

    printf("Deposit initial amount: \n");
    scanf("%d", &amount);
    fprintf(ptr, "%d", amount);
    fclose(ptr);
}

void check(char *name)
{

    FILE* ptr;
    ptr = fopen(name, "r");
    if (ptr==NULL) printf("Sorry account doesn't exist\n");
    else
    {
        float num;
        fscanf(ptr, "%f", &num);

        printf("Tour current account balance: %.2f\n",num);
    }
    fclose(ptr);
}

void deposit(char *name)
{
    FILE* ptr;
    float amount;
    int addition;
    ptr = fopen(name, "r");
    if (ptr==NULL) printf("Sorry account doesn't exist\n");
    else
    {
        fscanf(ptr, "%f", &amount);
        printf("Account balance: %.2f\n", amount);
        fclose(ptr);
        ptr = fopen(name, "w");
        printf("Enter the amount you want to deposit: \n");
        scanf("%d", &addition);
        amount = amount + addition;
        fprintf(ptr, "%f", amount);
        printf("Amount deposited\n");
    }
    fclose(ptr);
}

void withdraw(char *name)
{
    FILE* ptr;
    float amount;
    int withdrawal;
    ptr = fopen(name, "r");
    if (ptr==NULL) printf("Account doesn't exist\n");
    else
    {
        fscanf(ptr, "%f", &amount);
        fclose(ptr);
        ptr = fopen(name, "w");
        printf("Enter the amount you want to withdraw: \n");
        scanf("%d", &withdrawal);
        if (withdrawal>amount)
        {
            printf("Not sufficient funds\n");
            fprintf(ptr, "%f", amount);
            fclose(ptr);
        }
        else
        {
            amount = amount - withdrawal;
            fprintf(ptr, "%f", amount);
            printf("Account balance: %.2f", amount);
            fclose(ptr);
        }
    }

}
