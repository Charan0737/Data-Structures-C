#include<stdio.h>
#include<stdlib.h>

struct node {
    int coeff;
    int expo;
    struct node *next;
};

struct node *createNode(int coeff, int expo) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = NULL;
    return newNode;
}

struct node *insertTerm(struct node *poly, int coeff, int expo) {
    struct node *newNode = createNode(coeff, expo);
    if (poly == NULL) {
        return newNode;
    }

    struct node *temp = poly;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return poly;
}

void display(struct node *poly) {
    while (poly!= NULL) 
    {
        printf("%dx^%d", poly->coeff, poly->expo);
        poly = poly->next;
        if (poly != NULL)
        {
            printf(" + ");
		}
    }
    printf("\n");
}

struct node* addPolynomials(struct node* poly1, struct node* poly2) {
    struct node* result = NULL;
    struct node* temp;
    
    while (poly1 != NULL || poly2 != NULL) {
        int coeff = 0, expo;
        if (poly1 != NULL && (poly2 == NULL || poly1->expo > poly2->expo)) {
            coeff = poly1->coeff;
            expo = poly1->expo;
            poly1 = poly1->next;
        } else if (poly2 != NULL && (poly1 == NULL || poly2->expo > poly1->expo)) {
            coeff = poly2->coeff;
            expo = poly2->expo;
            poly2 = poly2->next;
        } else {
            coeff = poly1->coeff + poly2->coeff;
            expo = poly1->expo;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        
        if (coeff != 0) {
            if (result == NULL) {
                result = createNode(coeff, expo);
                temp = result;
            } else {
                temp->next = createNode(coeff, expo);
                temp = temp->next;
            }
        }
    }
    return result;
}

int main() {
    struct node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int n, coeff, expo;
    
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &expo);
        poly1 = insertTerm(poly1, coeff, expo);
    }
    
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &expo);
        poly2 = insertTerm(poly2, coeff, expo);
    }
    
    printf("Polynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);
    
    sum = addPolynomials(poly1, poly2);
    printf("Sum: ");
    display(sum);

    return 0;
}
