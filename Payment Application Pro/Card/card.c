#include "card.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MaxHolderName 24
#define MinHolderName 20
#define ExpiryDatLen 5
#define MaxCardPAN 19
#define MinCardPAN 16

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
    printf("Please enter the name on your card : ");
    uint8_t CardName[26] = { 0 };
    gets(CardName);


    if (strlen(CardName) > MaxHolderName || strlen(CardName) < MinHolderName || CardName == NULL)
        return WRONG_NAME;

    else
    {
        uint8_t letter = 0;
        for (letter = 0; letter < strlen(CardName); letter++) {
            if (!isalpha(CardName[letter]) && (CardName[letter] != ' ')) {
                printf("WRONG_NAME");
                return WRONG_NAME;
            }
            else {
                cardData->cardHolderName[letter] = CardName[letter];
            }
        }

                cardData->cardHolderName[letter] = '\0';
                printf("CARD__OK");
                return CARD_OK;
            
    }
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {
    printf("Please enter the Card Expiry Date IN the Format Of MM/YY : ");
    uint8_t Expiry_Date[12] = { 0 };
    gets(Expiry_Date);
    int number = 0;
    for (number = 0; number < 6; number++) {
        if ((Expiry_Date == NULL) || (strlen(Expiry_Date) != ExpiryDatLen
            )|| (Expiry_Date[0] > '1') ||
            (Expiry_Date[0] == '1') && (Expiry_Date[1] > '2')
            || (Expiry_Date[2] > '/')) {
            return WRONG_EXP_DATE;
        }
        else {
            printf("CARD__OK");
            return CARD_OK;
        }
    }
}




EN_cardError_t getCardPAN(ST_cardData_t* cardData) {
    
    printf("Please enter the Card PAN Number : ");
    uint8_t Pan[25] = { 0 };

    gets(Pan);
    if ((Pan == NULL) ||
        (strlen(Pan) > MaxCardPAN)
        || (strlen(Pan) > MinCardPAN)) {
        printf("WRONG_PAN");
        return WRONG_PAN;
    }
    else {
        printf("CARD_OK");
        return CARD_OK;
    }

}

void getCardHolderNameTest(void) {
    ST_cardData_t Data;
    printf("Tester Name: Fadia Magdy\n");
    printf("Function Name : getCardHolderName\n");
    printf("Test Case 1: NULL\nExpected Result : WRONG_NAME\nInput Data : ");
    getCardHolderName(&Data);
    printf("\n\nTest Case 2:Fadia magdy Hazkial Kozman\nExpected Result : WRONG_NAME\nInput Data :");
    getCardHolderName(&Data);
    printf("\n\nTest Case 3:Fadia magdy Hazkial m\nExpected Result : CARD_OK\nInput Data :");
    getCardHolderName(&Data);
}


void getCardExpiryDateTest(void) {
    ST_cardData_t Data;
    printf("Tester Name: Fadia Magdy");
    printf("Function Name : getCardExpiryDate");
    printf("Test Case 1: NULL\nExpected Result : WRONG_NAME\nInput Data : ");
    getCardExpiryDate(&Data);
    printf("\n\nTest Case 2:14/06/23\nExpected Result : WRONG_NAME\nInput Data :");
    getCardExpiryDate(&Data);
    printf("\n\nTest Case 3:07/24\nExpected Result : CARD_OK\nInput Data :");
    getCardExpiryDate(&Data);
}
void getCardPANeTest(void) {
    ST_cardData_t Data;
    printf("Tester Name: Fadia Magdy");
    printf("Function Name : getCardPAN");
    printf("Test Case 1: NULL\nExpected Result : WRONG_NAME\nInput Data : ");
    getCardExpiryDate(&Data);
    printf("\n\nTest Case 2:14/06/23\nExpected Result : WRONG_NAME\nInput Data :");
    getCardExpiryDate(&Data);
    printf("\n\nTest Case 3:07/24\nExpected Result : CARD_OK\nInput Data :");
    getCardExpiryDate(&Data);
}