/*Ben Cradick
 * CS2750 PA4
 * 11-22-17
 */
#include <stdio.h>

void deposit();
void withdraw();
void create_account();
void remove_account();
void balance_inquiry();
void view_account();


int main(){
    int leave = 0;
    while(leave != 1) {
        char action;
        printf("\n0.\tExit\n1.\tDeposit\n2.\tWithdrawal\n3.\tAdd account\n4.\tRemove account\n5.\tBalance inquiry\n6.\tView accounts"
                       "\n");
        scanf("%s", &action);

        /*main controller of the application serves to route each input to appropriate interface*/
        switch(action){
            case '0':
                printf("Exiting program\n");
                leave++;
                break;

            case '1':
                deposit();
                break;

            case '2':
                withdraw();
                break;
            case '3':
                create_account();
                break;
            case '4':
                remove_account();
                break;
            case '5':
                balance_inquiry();
                break;
            case '6':
                view_account();
                break;
            default:
                printf("Please enter a valid input\n");



        }
    }
}

/*TODO: write deposit script*/
void deposit(){

}
/*TODO: write withdraw script*/
void withdraw(){

}
/*TODO: write create account script*/
void create_account(){

}
/*TODO: write remove account script*/
void remove_account(){

}
/*TODO: write balance_inquiry script*/
void balance_inquiry(){

}
/*TODO: write view account script*/
void view_account(){

}
