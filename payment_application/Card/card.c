#include <stdio.h>
#include <stdbool.h>
#include "card.h"

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
ST_cardData_t test1 = {
    "mohamad amgad elsayed", "19 Septemper 2001", "1227"};
ST_cardData_t test2 = {
    "yara amgad", "17 - October 2001", "12/27"};
// 3-CARD_OK
ST_cardData_t test3 = {
    "Nada Ahmad elsayed mo", "October 2001", "08/25"};
ST_cardData_t test4 = {
    "yara amgad elsayed ali daif", "17 October ", "12//887"};
// 5-CARD_OK
ST_cardData_t test5 = {
    "nora mohamad ahmad esa", "17  2001", "//27"};
// 6-CARD_OK
ST_cardData_t test6 = {
    "ali ahmad amgad elsayed", " October 2001", "1272/"};

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
    printf("Input Data: %s\n", test1.cardHolderName);
    printf("Expected Result: CARD_OK\n");
    printValueAsEnum(getCardHolderName(&test1));
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Test Case 2: \n");
    printf("Input Data: %s\n", test2.cardHolderName);
    printf("Expected Result: WRONG_NAME\n");
    printValueAsEnum(getCardHolderName(&test2));
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Test Case 3: \n");
    printf("Input Data: %s\n", test3.cardHolderName);
    printf("Expected Result: CARD_OK\n");
    printValueAsEnum(getCardHolderName(&test3));
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Test Case 4: \n");
    printf("Input Data: %s\n", test4.cardHolderName);
    printf("Expected Result: WRONG_NAME\n");
    printValueAsEnum(getCardHolderName(&test4));
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Test Case 5: \n");
    printf("Input Data: %s\n", test5.cardHolderName);
    printf("Expected Result: CARD_OK\n");
    printValueAsEnum(getCardHolderName(&test5));
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Test Case 6: \n");
    printf("Input Data: %s\n", test6.cardHolderName);
    printf("Expected Result: CARD_OK\n");
    printValueAsEnum(getCardHolderName(&test6));
    printf("************************************ \n");
    printf("************************************ \n\n\n");
};

/**
 * ******************************************************************
 * ******************************************************************
 * ######################## Card Number Check #######################
 * ******************************************************************
 * ******************************************************************
 */

/**
 * Check validation of regex of card Number .
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
     * Check validation of Card Number XX/XX .
     */
    ;
    if (validateCardNumber(cardData) == 1)
    {
        /**
         * Chech the length of the card Number .
         */
        if (strlen(cardData->cardExpirationDate) > 5 || strlen(cardData->cardExpirationDate) < 5)
        {
            return WRONG_EXP_DATE;
        }
        else if (cardData->cardExpirationDate[2] != '/')
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
    printf("Input Data: %s\n", test1.cardExpirationDate);
    printf("Expected Result: WRONG_EXP_DATE\n");
    printValueAsEnum(getCardExpiryDate(&test1));
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Test Case 2: \n");
    printf("Input Data: %s\n", test2.cardExpirationDate);
    printf("Expected Result: CARD_OK\n");
    printValueAsEnum(getCardExpiryDate(&test2));
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Test Case 3: \n");
    printf("Input Data: %s\n", test3.cardExpirationDate);
    printf("Expected Result: CARD_OK\n");
    printValueAsEnum(getCardExpiryDate(&test3));
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Test Case 4: \n");
    printf("Input Data: %s\n", test4.cardExpirationDate);
    printf("Expected Result: WRONG_EXP_DATE\n");
    printValueAsEnum(getCardExpiryDate(&test4));
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Test Case 5: \n");
    printf("Input Data: %s\n", test5.cardExpirationDate);
    printf("Expected Result: WRONG_EXP_DATE\n");
    printValueAsEnum(getCardExpiryDate(&test5));
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Test Case 6: \n");
    printf("Input Data: %s\n", test6.cardExpirationDate);
    printf("Expected Result: WRONG_EXP_DATE\n");
    printValueAsEnum(getCardExpiryDate(&test6));
    printf("************************************ \n");
    printf("************************************ \n\n\n");
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
    if (strlen(cardData->primaryAccountNumber) < 16 || strlen(cardData->primaryAccountNumber) > 19)
    {
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
    printf("Input Data: %s\n", test1.primaryAccountNumber);
    printf("Expected Result: CARD_OK\n");
    printValueAsEnum(getCardPAN(&test1));
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Test Case 2: \n");
    printf("Input Data: %s\n", test2.primaryAccountNumber);
    printf("Expected Result: CARD_OK\n");
    printValueAsEnum(getCardPAN(&test2));
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Test Case 3: \n");
    printf("Input Data: %s\n", test3.primaryAccountNumber);
    printf("Expected Result: WRONG_PAN\n");
    printValueAsEnum(getCardPAN(&test3));
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Test Case 4: \n");
    printf("Input Data: %s\n", test4.primaryAccountNumber);
    printf("Expected Result: WRONG_PAN\n");
    printValueAsEnum(getCardPAN(&test4));
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Test Case 5: \n");
    printf("Input Data: %s\n", test5.primaryAccountNumber);
    printf("Expected Result: WRONG_PAN\n");
    printValueAsEnum(getCardPAN(&test5));
    printf("************************************ \n");
    printf("************************************ \n");
    printf("Test Case 6: \n");
    printf("Input Data: %s\n", test6.primaryAccountNumber);
    printf("Expected Result: WRONG_PAN\n");
    printValueAsEnum(getCardPAN(&test6));
    printf("************************************ \n");
    printf("************************************ \n\n\n");
}

int main()
{
    getCardHolderNameTest();
    getCardExpiryDateTest();
    getCardPANTest();
    return 0;
}