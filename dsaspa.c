#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Struct to hold service details
typedef struct Service {
    char name[50];
    int price;
    struct Service* next;
} Service;
// Struct to hold user details
typedef struct User {
    char* name;
    char* email;
    char* city;
    long int phone;
    int day, month, year;
} User;
// Function declarations
void addService(Service** head, const char* name, int price);
void displayServices(Service* head);
void selectServices(Service* head, int sessionChoice, int** selectedPrices, int* count);
float applyDiscount(int sessionChoice, int* selectedPrices, int count);
void surprise(int day, int month, int year);
void freeServices(Service* head);
void freeUser(User* user);

int main() {
    User user;
    Service* services = NULL;
    int sessionChoice, count = 0;
    int* selectedPrices = NULL;
    float finalCost;
    // Initialize available services
    addService(&services, "Full Body Massage", 3999);
    addService(&services, "Hair Care", 7999);
    addService(&services, "Skin Care", 9999);
    addService(&services, "Pedicure", 4999);
    addService(&services, "Sauna Bath", 49999);
    addService(&services, "Herbal Bath", 9699);
    // Allocate memory for user details
    user.name = (char*)malloc(50 * sizeof(char));
    user.email = (char*)malloc(50 * sizeof(char));
    user.city = (char*)malloc(50 * sizeof(char));
    // Get user details
    printf("\nWelcome to M-CUBE Spa online platform\n\n");
    printf("Customer Details:\n");
    printf("Please enter your name:\n");
    scanf(" %[^\n]s", user.name);
    printf("Please enter your date of birth:\n");
    printf("Day: ");
    scanf("%d", &user.day);
    printf("Month: ");
    scanf("%d", &user.month);
    printf("Year: ");
    scanf("%d", &user.year);
    printf("Please enter your email address:\n");
    scanf("%s", user.email);
    printf("Please enter your city:\n");
    scanf("%s", user.city);
    printf("Please enter your phone number:\n");
    scanf("%ld", &user.phone);
    printf("\nHello, %s!\n", user.name);
    printf("Date of Birth: %02d/%02d/%04d\n", user.day, user.month, user.year);
    printf("Phone number: %ld\n", user.phone);
    printf("City: %s\n", user.city);
    // Display available sessions
    printf("\nTypes of sessions available at our spa:\n");
    printf("1. Full Day Session (9 A.M to 9 P.M, DISCOUNT-29%%)\n");
    printf("2. Half Day Session (9 A.M to 3 P.M, DISCOUNT-17%%)\n");
    printf("Enter your choice: ");
    scanf("%d", &sessionChoice);
    // Handle invalid session choice
    if (sessionChoice != 1 && sessionChoice != 2) {
        printf("Invalid choice. Please restart the registration.\n");
        freeUser(&user);
        freeServices(services);
        return 1;
    }
    // Display and select services
    printf("\nAvailable body care options:\n");
    displayServices(services);
    selectServices(services, sessionChoice, &selectedPrices, &count);
    // Apply discount
    finalCost = applyDiscount(sessionChoice, selectedPrices, count);
    // Check for surprises
    surprise(user.day, user.month, user.year);
    // Display final message
    printf("\nFinal Total Cost after discount: Rs %.2f\n", finalCost);
    printf("Thank you for registering at M-CUBE Spa!\nFor further queries, kindly contact us any time.\n");
    // Free allocated memory
    free(selectedPrices);
    freeUser(&user);
    freeServices(services);
    return 0;
}
// Function to add a service to the linked list
void addService(Service** head, const char* name, int price) {
    Service* newService = (Service*)malloc(sizeof(Service));
    strcpy(newService->name, name);
    newService->price = price;
    newService->next = *head;
    *head = newService;
}
// Function to display services
void displayServices(Service* head) {
    int i = 1;
    Service* temp = head;
    while (temp != NULL) {
        printf("%d. %s at Rs %d\n", i++, temp->name, temp->price);
        temp = temp->next;
    }
}
// Function to select services
void selectServices(Service* head, int sessionChoice, int** selectedPrices, int* count) {
    int choice, maxChoices = (sessionChoice == 1) ? 6 : 3;
    int capacity = 10;

    *selectedPrices = (int*)malloc(capacity * sizeof(int));
    *count = 0;

    printf("\nSelect up to %d body care options (Enter 0 to finish):\n", maxChoices);
    while (*count < maxChoices) {
        displayServices(head);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) break;

        Service* temp = head;
        for (int i = 1; i < choice && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Invalid choice. Please try again.\n");
        } else {
            printf("%s selected. Cost: Rs %d\n", temp->name, temp->price);
            if (*count >= capacity) {
                capacity *= 2;
                *selectedPrices = (int*)realloc(*selectedPrices, capacity * sizeof(int));
            }
            (*selectedPrices)[(*count)++] = temp->price;
        }
    }
}
// Function to apply discount
float applyDiscount(int sessionChoice, int* selectedPrices, int count) {
    float discountRate = (sessionChoice == 1) ? 0.29 : 0.17;
    float totalCost = 0;

    for (int i = 0; i < count; i++) {
        totalCost += selectedPrices[i];
    }

    float discountAmount = totalCost * discountRate;
    float finalCost = totalCost - discountAmount;

    printf("\nOriginal Total Cost: Rs %.2f\n", totalCost);
    printf("Discount: %.0f%%\n", discountRate * 100);
    printf("Discount Amount: Rs %.2f\n", discountAmount);

    return finalCost;
}
// Function to display surprise offers
void surprise(int day, int month, int year) {
    int hasSurprise = 0;
    printf("\nToday's lucky date is 12, lucky month is 10, and lucky year is 2004.\n");

    if (day == 12) {
        printf("Congratulations! You won a free unlimited service voucher valid for the next 3 weeks at our spa.\n");
        hasSurprise = 1;
    }
    if (month == 10) {
        printf("Congratulations! You won free unlimited movie passes of your choice, valid for the next 15 days.\n");
        hasSurprise = 1;
    }
    if (year == 2004) {
        printf("Congratulations! You won a free solo trip to Manali.\n");
        hasSurprise = 1;
    }
    if (!hasSurprise) {
        printf("No special offers for your birth date, but we appreciate your registration.\n");
    }
}
// Function to free the linked list of services
void freeServices(Service* head) {
    while (head != NULL) {
        Service* temp = head;
        head = head->next;
        free(temp);
    }
}
// Function to free user details
void freeUser(User* user) {
    free(user->name);
    free(user->email);
    free(user->city);
}

