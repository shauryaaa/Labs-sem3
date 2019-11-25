#include<stdio.h>
#include<stdlib.h>

/*Data structure of each term in equation*/
struct node {
	int coeff, exp;
	struct node *next;
} *eqn1 = NULL, *eqn2 = NULL, *eqn3 = NULL;

/*Function to display coefficients and exponent values of all terms in equation*/
void dispPoly(struct node *start) {
	/*If equation is empty*/
	if(!start) {
		printf("0\n\n");
		return;
	}
	struct node *temp = start;
	int i;
	for(i = 1; temp; i++) {
		printf("Term %d:-\nCoeff: %d\nExp: %d\n", i, temp->coeff, temp->exp);
		temp = temp->next;
	}
}

/*Function to insert a term to the equation*/
struct node *insNode(struct node *start, int a, int b) {
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->coeff = a;
	head->exp = b;
	/*Check if start is not empty*/
	if(start) {
		struct node *temp = start;
		while(temp->next) {
			temp = temp->next;
		}
		temp->next = head;
	}
	/*If start is empty*/
	else {
		start = head;
	}
	return start;
}

/*Function to get an equation*/
struct node *getPoly(struct node *start) {
	int a, b, i, n;
	printf("Enter number of terms in equation: ");
	scanf("%d", &n);
	printf("Enter coefficient and exponent of each term in equation:-\n");
	for(i = 1; i <= n; i++) {
		printf("Term %d\nCoefficient: ", i);
		scanf("%d", &a);
		printf("Exponent: ");
		scanf("%d", &b);
		printf("\n");
		start = insNode(start, a, b);
	}
	printf("Entered polynomial:-\n");
	dispPoly(start);
	printf("\n");
	return start;
}

/*Function to multiply the two equations*/
void mulPoly() {
	/*
	If both equations are empty
	0 * 0 = 0
	If 1st equation is empty
	0 * (mx^n + ...) = 0
	If 2nd equation is empty
	(mx^n + ...) * 0 = 0
	*/
	if(!eqn1 || !eqn2) {
		printf("0\n");
	}
	/*
	If both equations are not empty.
	For documentation purpose let the equations be:
	Equation1: 1x^1 + 2x^2
	Equation2: 3x^1 + 3x^2
	*/
	else {
		struct node *temp = eqn1, *temp2, *prev;
		int flag;
		/*
		Loop to add multiply the two equations.
		Result: 3x^2 + 3x^3 + 6x^3 + 6x^4
		*/
		while(temp) {
			temp2 = eqn2;
			while(temp2) {
				eqn3 = insNode(eqn3, (temp->coeff * temp2->coeff), (temp->exp + temp2->exp));
				temp2 = temp2->next;
			}
			temp = temp->next;
		}
		/*
		Loop to simplify the result.
		Result: 3x^2 + 9x^3 + 6x^4
		*/
		temp = eqn3;
		while(temp) {
			temp2 = temp->next;
			prev = temp;
			while(temp2) {
				if(temp->exp == temp2->exp) {
					temp->coeff += temp2->coeff;
					prev->next = temp2->next;
				}
				temp2 = temp2->next;
				prev = prev->next;
			}
			temp = temp->next;
		}
		/*Display Equation1*/
		dispPoly(eqn3);
	}
}

void main() {
	int ch;
	printf("Enter polynomial equation 1:-\n");
	eqn1 = getPoly(eqn1);
	printf("Enter polynomial equation 2:-\n");
	eqn2 = getPoly(eqn2);
	printf("\n\nResult of polynomial multiplication:-\n==============================\n");
	mulPoly();
	printf("\n");
}
