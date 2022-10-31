#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void encrypt(char [], int);
void decrypt(char [], int);

int main(void) {
    char myString[21] = {'\0'};
    int iSelection = 0;
    int iRand;

    srand(time(NULL));

    iRand = (rand() % 4) + 1;   //ramdom # 1-4

    while (iSelection != 4) {
        printf("\n\n1\tEncrypt Clear Text\n");
        printf("2\tDecrypt Cipher Text\n");
        printf("3\tGenerate New Key\n");
        printf("4\tQuit\n");
        printf("\nSelect a Cryptography Option: ");
        scanf("%d", &iSelection);

        switch (iSelection) {
            case 1:
                printf("Enter one word as clear text to encrypt: ");
                scanf("%s", myString);
                encrypt(myString, iRand);
                break;

            case 2:
                printf("\nEnter cipher text to decrypt: ");
                scanf("%s", myString);
                decrypt(myString, iRand);
                break;
            
            case 3:
                iRand = (rand() % 4) + 1;   //random # 1-4
                printf("\nNew Key Generated\n");
                break;
        }
    }
}

//function encrypt definition
void encrypt(char sMessage[], int random) {
    int x = 0;
    //encrypt the message by shifting each characters ASCII value
    while (sMessage[x]) {
        sMessage[x] += random;
        x++;
    }
    x = 0;
    printf("\nEncrypted message is: ");

    //print the encrypted message
    while (sMessage[x]) {
        printf("%c", sMessage[x]);
        x++;
    }
}

//function decrypt definition
void decrypt(char sMessage[], int random) {
    int x = 0;
    //decrypt the message by shifting each characters ASCII value 
    while (sMessage[x]) {
        sMessage[x] = sMessage[x] - random;
        x++;
    }
    x = 0;
    printf("\nDecrypted Message is: ");

    //print the decrypted message
    while (sMessage[x]) {
        printf("%c", sMessage[x]);
        x++;
    }
}