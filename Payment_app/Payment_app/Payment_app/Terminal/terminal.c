#include<conio.h>
#include<time.h>
#include <stdio.h>
#include "terminal.h"
//#include "../Card/card.h"

 ST_cardData_t test1_card = {
     "mohamad amgad elsayed", "19 Septemper 2001", "12/27"};

 ST_terminalData_t test1={
         1500.0, 3000.0, "20/12/2022"
 };




int charToInt(char x){
    return (int)x%48;
}
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
   /**
    * get expiration date "Month then year" from card Object .
    */
    expirationMonth= charToInt(cardData->cardExpirationDate[0])*10+charToInt(cardData->cardExpirationDate[1]);
    expirationYear=2000+charToInt(cardData->cardExpirationDate[3])*10+charToInt(cardData->cardExpirationDate[4]);
    /**
     * get Transaction month and year and compare it with expration date : 
     */
    transactionMonth=charToInt(termData->transactionDate[3])*10+charToInt(termData->transactionDate[4]);
    transactionYear=charToInt(termData->transactionDate[6])*1000+
    charToInt(termData->transactionDate[7])*100+
    charToInt(termData->transactionDate[8])*10+
    charToInt(termData->transactionDate[9]);


    printf("expiration month : %d \n",expirationMonth);
printf("expiration year %d \n",expirationYear);
printf("Transaction month = %d \n",transactionMonth);
printf("Transaction year = %d \n",transactionYear);
    /**
     * First Check on the year , then check months :
     */
    if(transactionYear<=expirationYear){
        if(transactionMonth<expirationMonth){
            return TERMINAL_OK;
        }else{
            return EXPIRED_CARD;
        }
    }else{
        return EXPIRED_CARD;
    }
 }

int main()
{
    printValueAsEnum(getTransactionDate(&test1));
    printValueAsEnum(isCardExpired( &test1_card,&test1));
    printf("Thied line printed \n");
}