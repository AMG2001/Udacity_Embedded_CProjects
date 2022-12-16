#include <stdbool.h>
#include<conio.h>
#include<time.h>
#include <stdio.h>
#include "terminal.h"



ST_cardData_t test1_card = {
    "mohamad amgad elsayed", "19 Septemper 2001", "12/27"};

 ST_terminalData_t test1={
         1500.0, 3000.0, "20/12/2022"
 };

void printValueAsEnum(int d)
{
    switch (d)
    {
    case 0:
        printf("TERMINAL_OK \n");
        break;
    case 1:
        printf("WRONG_DATE\n");
        break;
    case 2:
        printf("EXPIRED_CARD\n");
        break;
    case 3:
        printf("INVALID_CARD\n");
        break;
        case 4:
        printf("INVALID_AMOUNT\n");
        break;
        case 5:
        printf("EXCEED_MAX_AMOUNT\n");
        break;
        case 6:
        printf("INVALID_MAX_AMOUNT\n");
        break;
    default:
        printf("Actual : NON\n");
        break;
    }
}


/**
 * this function is used to check on the regex of Transaction Date "XX/XX/XXXX" .
 */
EN_terminalError_t getTransactionDate(ST_terminalData_t *termData){

    printf("current date from method : %s \n",termData->transactionDate);
    if(termData->transactionDate[0]>=48 &&
    termData->transactionDate[0]<=57&&
    termData->transactionDate[1]>=48 &&
    termData->transactionDate[1]<=57&&
    termData->transactionDate[2]==47 &&
    termData->transactionDate[3]>=48 &&
    termData->transactionDate[3]<=57&&
    termData->transactionDate[4]>=48 &&
    termData->transactionDate[4]<=57&&
    termData->transactionDate[5]==47 &&
    termData->transactionDate[6]>=48 &&
    termData->transactionDate[6]<=57&&
    termData->transactionDate[7]>=48 &&
    termData->transactionDate[7]<=57&&
    termData->transactionDate[8]>=48 &&
    termData->transactionDate[8]<=57&&
    termData->transactionDate[9]>=48 &&
    termData->transactionDate[9]<=57&&termData->transactionDate!=NULL){
        return TERMINAL_OK;
    }else return WRONG_DATE ;
};

/***
 * Get current date method in format "XX/XX/XXXX"
 */
void getCurrentDate(uint8_t *currentDate){
    
 time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    /**
     * Method used to Convert int to String .
     */
    sprintf(currentDate,"%d/%d/%d",tm.tm_mday,tm.tm_mon,tm.tm_year+1900);
}


/**
 * Compare transaction date and Expiration date .
 */
 EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData){
   int expirationMonth,expirationYear,transactionMonth,transactionYear;
//    uint8_t expirationDateInChar = (uint8_t) cardData->cardExpirationDate;
//    uint8_t transactionDateInChar = (uint8_t) termData->transactionDate;
//    printf("%s \n",expirationDateInChar);
return TERMINAL_OK;
 }

int main()
{
    // printValueAsEnum(getTransactionDate(&test1));
    isCardExpired( &test1_card,&test1);
    printf("Thied line printed \n");
}