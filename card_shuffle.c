#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <string.h>
 
//define new datatype
typedef struct deck {
char type[10];
char used; 
int value;
}aDeck;

//function prototype
void shuffle(aDeck *);

int main(void) {
	int x, y;
	aDeck myDeck[52];
	srand(time(NULL));
    
	//initialize structure array
	for (x = 0; x < 4; x++) {
		for (y = 0; y < 13; y++) {
			switch (x) {
				case 0:
					strcpy(myDeck[y].type, "diamonds");
					myDeck[y].value = y;
					myDeck[y].used = 'n';
					break;
					
				case 1:
					strcpy(myDeck[y + 13].type, "clubs");
					myDeck[y + 13].value = y;
					myDeck[y + 13].used = 'n';
					break;
					
				case 2:
					strcpy(myDeck[y + 26].type, "hearts");
					myDeck[y + 26].value = y;
					myDeck[y + 26].used = 'n';
					break;
						
				case 3:
					strcpy(myDeck[y + 39].type, "spades");
					myDeck[y + 39].value = y;
					myDeck[y + 39].used = 'n';
					break;
			}
		}
	}
	//use for debugging
    /*for (x = 0; x < 52; x++) 
		printf("%d ", myDeck[x].value);	
		x += 1;*/
	shuffle(myDeck);
	return 0;
}

//function definition
void shuffle(aDeck thisDeck[]) {
    int x;
    int iRnd;
	int found = 0;
	
	system("cls");
	printf("\nYour five cards are:\n\n");
	
	while (found < 5) {
		iRnd = rand() % 51;

		if (thisDeck[iRnd].used == 'n') {
			switch (thisDeck[iRnd].value) {
				case 12:
					printf("Ace of %s\n", thisDeck[iRnd].type);
					break;
					
				case 11:
					printf("King of %s\n", thisDeck[iRnd].type);
					break;
				
				case 10:
					printf("Queen of %s\n", thisDeck[iRnd].type);
					break;
					
				case 9:
					printf("Jack of %s\n", thisDeck[iRnd].type);
					break;
				
				default:
					printf("%d of ", thisDeck[iRnd].value + 2);
					printf("%s\n", thisDeck[iRnd].type);
					break;
			}
			//use this for debugging
			/*for (x = 0; x < 52; x++) {
				printf("%d ", thisDeck[x].value);	
				x += 1;
			}*/
		}

		thisDeck[iRnd].used = 'y';
		found = found + 1;			//could also use: found += 1;	

	}
}