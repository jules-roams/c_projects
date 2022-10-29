#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

//function prototypes
double addNumbers(double, double);
double subtractNumbers(double, double);
double multiplyNumbers(double, double);
double divideNumbers(double, double);
double modulusNumbers(int, int);
int testForPrime(int);
int factorial(int);


int main(void) {
	char  iSelection = '\0';
	double foperand1 = 0, foperand2 = 0;
	int ioperand1 = 0, ioperand2 = 0;
	char cClear = '\0';
	
	do {
		printf("\n\nTHE CALCULATOR\n");
		printf("\nCalculator menu:\n");
		printf("\n1\tAddition");
		printf("\n2\tSubtraction");
		printf("\n3\tMultiplication");
		printf("\n4\tDivision");
		printf("\n5\tModulus (Integers only)");
		printf("\n6\tTest if Prime (Integers only)");
		printf("\n7\tFactorial (Integers only)");
		printf("\n8\tPower");
		printf("\n9\tSquare Root");
		printf("\n0\tExit\n");
		printf("\nPlease enter your selection: ");
		scanf(" %c", &iSelection);	
		
		//here we check for if input was a digit
		if (isdigit(iSelection) == 0) {
		    printf("\nPlease enter a valid numerical value.\n");
		    continue;
		}

		switch(iSelection) {
			case '0':
				break;
				
			case '1':
				printf("\nEnter the two numbers to add seperated by a space: ");
				scanf("%lf %lf", &foperand1, &foperand2);
				printf("\n%.5lf + %.5lf = %.5lf\n", foperand1, foperand2, addNumbers(foperand1, foperand2));	
				break;
				
			case '2':
				printf("\nEnter the two numbers to subtract seperated by a space: ");
				scanf("%lf %lf", &foperand1, &foperand2);
				printf("\n%.5lf - %.5lf = %.5lf\n", foperand1, foperand2, subtractNumbers(foperand1, foperand2));	
				break;
				
			case '3':
				printf("\nEnter the two numbers to multiply seperated by a space: ");
				scanf("%lf %lf", &foperand1, &foperand2);
				printf("\n%.5lf * %.5lf = %.5lf\n", foperand1, foperand2, multiplyNumbers(foperand1, foperand2));
				break;
				
			case '4':
				printf("\nEnter the two numbers to divide seperated by a space: ");
				scanf("%lf %lf", &foperand1, &foperand2);
				printf("\n%.5lf / %.5lf = %.5lf\n", foperand1, foperand2, divideNumbers(foperand1, foperand2));		
				break;
				
			case '5':
				printf("\nEnter the two values to check the modulus of seperated by a space: ");
				scanf("%d %d", &ioperand1, &ioperand2);
				printf("\n%d %% %d = %lf\n", ioperand1, ioperand2, modulusNumbers(ioperand1, ioperand2));		
				break;
			
			case '6':
				printf("\nEnter the value to check if prime (positive integer): ");
				scanf("%d", &ioperand1);
				if (testForPrime(ioperand1) != 0)
					printf("\nThis number is prime.\n");
				else
					printf("\nThis number is not prime.\n");
				break;
				
			case '7':
				printf("\nEnter the value to do the factorial of: ");
				scanf("%d", &ioperand1);
				printf("\n%d! = %d\n", ioperand1, factorial(ioperand1));					
				break;
				
			case '8':
				printf("\nEnter the value for the base, then the power value seperated by a space: ");
				scanf("%lf %lf", &foperand1, &foperand2);
				printf("\n%lf^%lf = %lf\n", foperand1, foperand2, pow(foperand1, foperand2));					
				break;
				
			case '9':
				printf("\nEnter the value to do the square root of: ");
				scanf("%lf", &foperand1);
				printf("\nsqrt(%lf) = %lf\n", foperand1, sqrt(foperand1));					
				break;
	
			default:
				printf("\nPlease select a valid entry.\n");
			
		}
		//here we ask the user if we want to print the screen
		//fflush(stdin);						//standard input must be cleared
		if (iSelection != '0') {
			printf("\nDo you want to clear the screen? ('y' or 'n'): ");
			scanf(" %c", &cClear);
			//printf("%d", (int) cClear);	//these lines helped me to debug
			//scanf("%d", iSelection);
			//printf("%d", (int) system("cls"));
			if (cClear == 'y' || cClear == 'Y')
				system("cls");
		}

	} while (iSelection != '0');
	system("cls");
	printf("\nExiting Calculator.\n");
	return 0;
}

//addNumbers function definiton
double addNumbers(double operand1, double operand2) {
	return operand1 + operand2;
}

//subtractNumbers function definition
double subtractNumbers(double operand1, double operand2) {
	return operand1 - operand2;
}

//multiplyNumbers function definition
double multiplyNumbers(double operand1, double operand2) {
	return operand1 * operand2;
}

//divideNumbers function definition
double divideNumbers(double operand1, double operand2) {
	return operand1 / operand2;
}

//modulusNumbers function definition
double modulusNumbers(int operand1, int operand2) {
	return operand1 % operand2;
}

//factorial function definition
int factorial(int operand1) {
	int factorial = 1;
	for (int i = operand1; i > 0; i--)
	    factorial *= i;
	return factorial;
}
//another way to do factorial function below
	/*    
	do {
		factorial *= operand1--;
	} while(operand1 > 0);
	return factorial;
	*/

//testForPrime function definition
int testForPrime(int operand1) {
	int i = 0;
	if (operand1 < 2)
	    return 0;
	for (i = 2; i <= sqrt(operand1); i++) {
		if (operand1 % i == 0) 
			return 0;
	}
	return 1;
}