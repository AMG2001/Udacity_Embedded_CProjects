#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "server.h"


  ST_accountsDB_t account1={10000.0, BLOCKED, "8989374615436851"};
ST_accountsDB_t account2={10000.0,BLOCKED,"8989374615436851"};
ST_accountsDB_t account3={10000.0,BLOCKED,"8989374615436851"};
ST_accountsDB_t account4={10000.0,BLOCKED,"8989374615436851"};

struct ST_accountsDB_t accountsDB[255]={
        {10000.0,BLOCKED,"8989374615436851"}
};



struct ST_transaction_t transactionsDB[255];

int main(){
    printf("\n\n server start \n\n");
}
