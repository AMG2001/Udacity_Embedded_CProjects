#include <stdio.h>
#include <stdbool.h>
#include "card.h"
#include "string.h"
/**
 * ******************************************************************
 * ******************************************************************
 * ###################### CardHolderName Check ######################
 * ******************************************************************
 * ******************************************************************
 */

/**
 * Test Cases of "CardHolderName" , "getCardExpiryDate" , "CARD PAN"
 * 
 * for CardHolderName :
 * for CardExpirtyDate :
 * for CardPan : 
 */
// 1-CARD_OK
ST_cardData_t test1_card = {
    "mohamad amgad elsayed", "12345aaC91234567", "1227"};


/**
 * Check the length of CardHolderName
 */
EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
    if (strlen(cardData->cardHolderName) < 20 || cardData->cardHolderName == NULL || strlen(cardData->cardHolderName) > 24)
    {
        return WRONG_NAME;
    }
    else
    {
        return CARD_OK;
    }
}

/**
 * this Function is Used to get value of enum and print it with it's name .
 */
void printValueAsEnum(int d)
{
    switch (d)
    {
    case 0:
        printf("Actual : CARD_OK\n");
        break;
    case 1:
        printf("Actual : WRONG_NAME\n");
        break;
    case 2:
        printf("Actual : WRONG_EXP_DATE\n");
        break;
    case 3:
        printf("Actual : WRONG_PAN\n");
        break;
    default:
        printf("Actual : NON\n");
        break;
    }
}

/**
 * Testing CardHolderName with number of tests.
 */
void getCardHolderNameTest()
{
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Tester Name: mohamad amgad\n");
    printf("Function Name: getCardHolderName\n");
    printf("Test Case 1: \n");
    printf("Input Data: %s\n", test1_card.cardHolderName);
    printf("Expected Result: CARD_OK\n");
    printValueAsEnum(getCardHolderName(&test1_card));
    printf("************************************ \n");
    printf("************************************ \n");
  
};

/**
 * ******************************************************************
 * ******************************************************************
 * ######################## Card Number Check #######################
 * ******************************************************************
 * ******************************************************************
 */

/**
 * Check validation of regex of card Number XX/XX .
 */

int validateCardNumber(ST_cardData_t *cardData)
{
    if (
        cardData->cardExpirationDate[0] >= 48 &&
         cardData->cardExpirationDate[0] <= 57 &&
          cardData->cardExpirationDate[1] >= 48 &&
           cardData->cardExpirationDate[1] <= 57 &&
            cardData->cardExpirationDate[2] == 47 &&
             cardData->cardExpirationDate[3] >= 48 &&
              cardData->cardExpirationDate[3] <= 57 &&
               cardData->cardExpirationDate[4] >= 48 &&
                cardData->cardExpirationDate[4] <= 57)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 *
 */

EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
    /**
     * Check validation of Card Number XX/XX  .
     */
    ;
    if (validateCardNumber(cardData) == 1)
    {
        /**
         * Chech the length of the card Number , must equal -> 5.
         */
        if (strlen(cardData->cardExpirationDate) !=5 )
        {
            return WRONG_EXP_DATE;
        }
        else
        {
            return CARD_OK;
        }
    }
    else
    {
        return WRONG_EXP_DATE;
    }
}

/**
 * To Check CardNumber and show expected and actual Enum .
 */

void getCardExpiryDateTest()
{
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Tester Name: mohamad amgad\n");
    printf("Function Name: getCardExpiryDate\n");
    printf("Test Case 1: \n");
    printf("Input Data: %s\n", test1_card.cardExpirationDate);
    printf("Expected Result: WRONG_EXP_DATE\n");
    printValueAsEnum(getCardExpiryDate(&test1_card));
    printf("************************************ \n");
    printf("************************************ \n");
    
}

/**
 * ******************************************************************
 * ******************************************************************
 * ###################### CardPan Check ######################
 * ******************************************************************
 * ******************************************************************
 */

EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{   
    /***
     * First check that the whole PAN is Numbers , there is no characters or symbols :
     * then check on the length of the PAN .
     */
    bool flag=true;

    for(int i =0;i<strlen(cardData->primaryAccountNumber);i++){
        if( cardData->primaryAccountNumber[i]>=48 && cardData->primaryAccountNumber[i]<=57){
            printf("value of it : %d \n",cardData->primaryAccountNumber[i]);
            flag=true;
        }
        else{
            printf("there is worng in pan loop \n");
             flag=false;
             break;
        }
    }
    if (strlen(cardData->primaryAccountNumber) < 16 || strlen(cardData->primaryAccountNumber) > 19 )
    {
        return WRONG_PAN;
    }else if(flag==false){
        return WRONG_PAN;
    }
    else
    {
        return CARD_OK;
    }
}

void getCardPANTest()
{
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Tester Name: mohamad amgad\n");
    printf("Function Name: getCardPAN\n");
    printf("Test Case 1: \n");
    printf("Input Data: %s\n", test1_card.primaryAccountNumber);
    printf("Expected Result: CARD_OK\n");
    printValueAsEnum(getCardPAN(&test1_card));
    printf("************************************ \n");
    printf("************************************ \n");

}

int main()
{
    // getCardHolderNameTest();
    // getCardExpiryDateTest();
    // getCardPANTest();
    
    return 0;
}