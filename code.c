#include <stdio.h>
#include <string.h>

struct Car {
    int id;
    char name[50];
    int seats;
    int rentPerDay;
    int available;
} cars[50];

int count = 0;

void addCar() {
    printf("\nEnter Car ID: ");
    scanf("%d", &cars[count].id);
    printf("Enter Car Name: ");
    scanf("%s", cars[count].name);
    printf("Enter Number of Seats: ");
    scanf("%d", &cars[count].seats);
    printf("Enter Rent Per Day: ");
    scanf("%d", &cars[count].rentPerDay);

    cars[count].available = 1;
    count++;

    printf("\nCar Added Successfully!\n");
}

void viewCars() {
    printf("\n--- List of Cars ---\n");
    for(int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Seats: %d | Rent/day: %d | %s\n",
               cars[i].id, cars[i].name, cars[i].seats,
               cars[i].rentPerDay,
               cars[i].available ? "Available" : "Rented");
    }
}

void rentCar() {
    int id, days;
    printf("\nEnter Car ID to Rent: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(cars[i].id == id && cars[i].available == 1) {
            printf("Enter number of days: ");
            scanf("%d", &days);

            int total = days * cars[i].rentPerDay;
            printf("\nCar Rented Successfully!");
            printf("\nBill Amount: Rs %d\n", total);

            cars[i].available = 0;
            return;
        }
    }
    printf("\nCar Not Available OR Invalid ID\n");
}

void returnCar() {
    int id;
    printf("\nEnter Car ID to Return: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(cars[i].id == id && cars[i].available == 0) {
            cars[i].available = 1;
            printf("\nCar Returned Successfully!\n");
            return;
        }
    }
    printf("\nInvalid Car ID!\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n\n===== CAR RENTAL SYSTEM =====");
        printf("\n1. Add Car");
        printf("\n2. View Cars");
        printf("\n3. Rent a Car");
        printf("\n4. Return Car");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addCar(); break;
            case 2: viewCars(); break;
            case 3: rentCar(); break;
            case 4: returnCar(); break;
            case 5: printf("Thank you!"); return 0;
            default: printf("Invalid Choice!");
        }
    }
}
