#include<stdio.h>
#include "card.h"


//1-CARD_OK
ST_cardData_t test1={
    "mohamad amgad elsayed","19 Septemper 2001","12/27"
};
ST_cardData_t test2={
    "yara amgad","17 October 2001","12/27"
};
//3-CARD_OK
ST_cardData_t test3={
    "Nada Ahmad elsayed mo","17 October 2001","12/27"
};
ST_cardData_t test4={
    "yara amgad elsayed ali daif","17 October 2001","12/27"
};
//5-CARD_OK
ST_cardData_t test5={
    "nora mohamad ahmad esa","17 October 2001","12/27"
};
//6-CARD_OK
ST_cardData_t test6={
    "ali ahmad amgad elsayed","17 October 2001","12/27"
};


EN_cardError_t  getCardHolderName(ST_cardData_t *cardData){
if(strlen(cardData->cardHolderName)<20||cardData->cardHolderName==NULL||strlen(cardData->cardHolderName)>24){
    return WRONG_NAME;
}else{
    return CARD_OK;
}
}

void printValueAsEnum(int d){
    switch (d)
    {
    case 0:
        printf("CARD_OK\n");
        break;
     case 1:
        printf("WRONG_NAME\n");
        break;
         case 2:
        printf("WRONG_EXP_DATE\n");
        break;
         case 3:
        printf("WRONG_PAN\n");
        break;
    default:
        printf("NON\n");
        break;
    }
}


void getCardHolderNameTest(){
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Tester Name: mohamad amgad\n");
    printf("Function Name: getCardHolderName\n");
    printf("Test Case 1: \n");
    printf("Input Data: %s\n",test1.cardHolderName);
    printf("Expected Result: CARD_OK\n");
    printValueAsEnum(getCardHolderName(&test1));
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Test Case 2: \n");
    printf("Input Data: %s\n",test2.cardHolderName);
    printf("Expected Result: WRONG_NAME\n");
    printValueAsEnum(getCardHolderName(&test2));
    printf("************************************ \n");
    printf("************************************ \n");
        printf("Test Case 3: \n");
    printf("Input Data: %s\n",test3.cardHolderName);
    printf("Expected Result: CARD_OK\n");
    printValueAsEnum(getCardHolderName(&test3));
    printf("************************************ \n");
    printf("************************************ \n");
        printf("Test Case 4: \n");
    printf("Input Data: %s\n",test4.cardHolderName);
    printf("Expected Result: WRONG_NAME\n");
    printValueAsEnum(getCardHolderName(&test4));
    printf("************************************ \n");
    printf("************************************ \n");
        printf("Test Case 5: \n");
    printf("Input Data: %s\n",test5.cardHolderName);
    printf("Expected Result: CARD_OK\n");
    printValueAsEnum(getCardHolderName(&test5));
    printf("************************************ \n");
    printf("************************************ \n");
        printf("Test Case 6: \n");
    printf("Input Data: %s\n",test6.cardHolderName);
    printf("Expected Result: CARD_OK\n");
    printValueAsEnum(getCardHolderName(&test6));
    printf("************************************ \n");
    printf("************************************ \n");
};

int main(){
getCardHolderNameTest();
return 0;
}