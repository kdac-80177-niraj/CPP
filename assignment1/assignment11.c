#include<stdio.h>

struct Date{
    int day,month,year;

};

void initDate(struct Date* d1){
    d1->day=10;
    d1->month = 11;
    d1->year = 12;
}

void printDate(struct Date* d1){
    printf("Todays date is: %d:%d:%d\n",d1->day,d1->month,d1->year);

}

void acceptFromConsole(struct Date* d1){
    printf("Enter Day: \n");
    scanf("%d",&d1->day);
    printf("Enter month: \n");
    scanf("%d",&d1->month);
    printf("Enter year: \n");
    scanf("%d",&d1->year);
}

int main(){

    struct Date d1;//object
    int choice;
    printf("Enter a choice : \n");
    printf("1)InitDate 2)AcceptDate 3)Exit\n");
    scanf("%d",&choice);
    printf("\n");

    if(choice!=3){
        do{
            switch(choice){
                case 1: printf("Init Date: \n");
                    initDate(&d1);
                    printDate(&d1);
                    break;

                case 2: printf("Accept Date: \n");
                    acceptFromConsole(&d1);
                    printDate(&d1);

                case 3: printf("Exit\n");
                        break;
                default: printf("Wrong choice!!!! Enter proper choice.\n");

            }
            printf("Enter choice again...\n");
            scanf("%d",&choice);
            if (choice == 3){
                printf("Exit\n");
            }
        }while(choice!=3);
}
else{
    printf("Exit\n");
}
}
