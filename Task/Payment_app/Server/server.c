#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "server.h"
#include "../Card/card.h"
#include "../Terminal/terminal.h"
/**
 * Accounts DB
 */


ST_cardData_t card_test = {
     "mohamad amgad elsayed", "379354508162306", "12/27"};

 ST_terminalData_t terminal_test ={
         1500.0, 3000.0, "20/12/2022"
 };


struct ST_accountsDB_t accountsDB[255]={
        {10000.0,BLOCKED,"179354508162306"}, {10000.0,BLOCKED,"279354508162306"},{10000.0,BLOCKED,"379354508162306"}
};

/***
 * Transactions DB ;
 */
int transactionsIndex=0; // this index will track number of transactions that done .
struct ST_transaction_t transactionsDB[255];

ST_accountsDB_t current_account;



EN_transState_t updateBalance(float transAmount,ST_accountsDB_t *accountsDatabase)
{

    current_account.balance -= transAmount;

    for(int i =0;i<(sizeof(accountsDatabase)/sizeof(accountsDatabase[0]));i++){
        /**
         * to store changes in DB .
         */
        if(accountsDatabase->primaryAccountNumber==current_account.primaryAccountNumber){
            accountsDatabase->balance-=transAmount;
        }
    }

    return APPROVED;
}
/**
 * Check Transaction Data
 */
EN_transState_t recieveTransactionData(struct ST_transaction_t *transData){

  /***
   * First check if the Card Exist or not .
   */



if (isValidAccount(&transData->cardHolderData) != SERVER_OK)
	  {
        transData->transState = DECLINED_STOLEN_CARD;
        saveTransaction(transData);
        return DECLINED_STOLEN_CARD;
    }


      if (isBlockedAccount( &current_account))
	  {
        transData->transState = DECLINED_STOLEN_CARD;
        saveTransaction(transData);
        return DECLINED_STOLEN_CARD;
    }

    
    if (isAmountAvailable(&transData->terminalData,&current_account) != SERVER_OK) 
	{
        transData->transState = DECLINED_INSUFFECIENT_FUND;
        saveTransaction(transData);
        return DECLINED_INSUFFECIENT_FUND;
    }

     updateBalance(transData->terminalData.transAmount,&accountsDB);

    transData->transState = APPROVED;

    transData->transactionSequenceNumber = transactionsIndex++;

    if (saveTransaction(transData) != SERVER_OK)
	{
        return INTERNAL_SERVER_ERROR;
    }

    return APPROVED;

}

/**
 * Check if the account is exist in DB or not .
 */
EN_serverError_t isValidAccount(ST_cardData_t *cardData){
   
  for(int i =0;i<4;i++){
    // printf("cards numbers from DB : %s \n",accountsDB[i].primaryAccountNumber);
    // printf("inserted card data : %s \n",cardData->primaryAccountNumber);
    if(cardData->primaryAccountNumber == accountsDB[i].primaryAccountNumber){
      printf("card okay \n");
      current_account=accountsDB[i];
      break;
      return SERVER_OK ;
    }
  }
  return ACCOUNT_NOT_FOUND ;
}

EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence){
  if(accountRefrence->state==BLOCKED){
    return BLOCKED;
  }else{
    return SERVER_OK;
  }
}

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountRefrence){
  if(termData->transAmount<=accountRefrence->balance){
    return SERVER_OK;
  }else{
    return LOW_BALANCE;
  }
}

EN_serverError_t saveTransaction(struct ST_transaction_t *transData){
  transactionsDB[transactionsIndex].cardHolderData=transData->cardHolderData;
  transactionsDB[transactionsIndex].terminalData=transData->terminalData;
  transactionsDB[transactionsIndex].transactionSequenceNumber=transData->transactionSequenceNumber;
  transactionsDB[transactionsIndex].transState=transData->transState;
  transactionsIndex++;
  return SERVER_OK;
}

void listSavedTransactions(void){
  int i =0;
  while(&transactionsDB[i].cardHolderData.cardHolderName!=NULL){
    printf("Transaction sequence = %s \n",transactionsDB[i].transactionSequenceNumber);
  printf("Transaction Date = %s \n",transactionsDB[i].terminalData.transactionDate);
   printf("Transaction Amount = %f \n",transactionsDB[i].terminalData.transAmount);
   printf("Transaction state = %s \n",transactionsDB[i].transState);
  printf("Terminal Max Amount = %s \n",transactionsDB[i].terminalData.maxTransAmount);
  printf("Cardholder Name: %s \n",transactionsDB[i].cardHolderData.cardHolderName);
  printf("PAN : %s \n",transactionsDB[i].cardHolderData.primaryAccountNumber);
  printf("Card Expiration Date: %s \n",transactionsDB[i].cardHolderData.cardExpirationDate);
  i++;
  }
}



int main(){
    printf("\n\n server start \n\n");
EN_serverError_t  message = isValidAccount(&card_test);
if(message == SERVER_OK) printf("card exist \n");
else printf("Card not exist !! \n");

}
