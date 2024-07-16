#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct details {
    char uname[100];
    int age;
    char password[100];
    char email[100];
    char mobile[11];
    char address[100];
};

struct hotels {
    char hotel[100];
    char first_food[20];
    char second_food[20];
    char third_food[20];
    char fourth_food[25];
    int first, second, third, fourth;
};

struct hotels m[5];
struct details s[100];

// Function to get the input for new account.
void signup();
void account_check();

// Function to validate all the input fields.
int validate();
void login();
void cart();
void search_by_hotels();
void search_by_food();
void food_order(int food);

// Function to initialize the hotels and food
void hotel_initialize();
void hotels(int hotel_choice);

int flag = 1, i, j = 0, count = 0, caps = 0;
int small = 0, special = 0, numbers = 0;
int success = 0, x, choice;
char temp_name[100], temp_password1[100];
char temp_password2[100], temp_email[100];
char temp_mobile[11];
char temp_address[100];
int temp_age, total = 0, food_choice, n;
int hotel_choice, search_choice, confirm;
int ch, food, hotel_id;

int main() {
    while (1) {
        printf("\n\nWelcome to Food Ordering System\n\n1)SIGNUP\n");
        printf("2)LOGIN\n3)EXIT\n\n");
        printf("Enter your choice\t");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                signup();
                break;
            }
            case 2: {
                login();
                break;
            }
            case 3: {
                exit(0);
                return 0;
            }
            default: {
                printf("\nPlease Enter the valid choice\n");
                break;
            }
        }
    }
}

// Function to create a new user for the Food ordering system
void signup() {
    printf("Enter Your name\t");
    scanf("%s", temp_name);

    printf("Enter Your Age\t");
    scanf("%d", &temp_age);

    printf("Enter Your Email\t");
    scanf("%s", temp_email);

    printf("Enter Password\t");
    scanf("%s", temp_password1);

    printf("Confirm Password\t");
    scanf("%s", temp_password2);

    printf("Register Your Address:\t");
    getchar(); // to consume newline left by previous input
    fgets(temp_address, sizeof(temp_address), stdin);
    temp_address[strcspn(temp_address, "\n")] = 0; // Remove newline character

    printf("Enter Your Mobile Number\t");
    scanf("%s", temp_mobile);

    // Function Call to validate the user creation
    x = validate();
    if (x == 1)
        account_check();
}

// Function to validate the user for signup process
int validate() {
    // Validate the name
    for (i = 0; temp_name[i] != '\0'; i++) {
        if (!((temp_name[i] >= 'a' && temp_name[i] <= 'z') || (temp_name[i] >= 'A' && temp_name[i] <= 'Z'))) {
            printf("\nPlease Enter the valid Name\n");
            return 0;
        }
    }

    // Validate the Email ID
    count = 0;
    for (i = 0; temp_email[i] != '\0'; i++) {
        if (temp_email[i] == '@' || temp_email[i] == '.')
            count++;
    }
    if (!(count >= 2 && strlen(temp_email) >= 5)) {
        printf("\nPlease Enter Valid E-Mail\n\n");
        return 0;
    }

    // Check Password
    if (strcmp(temp_password1, temp_password2)) {
        printf("\nPassword Mismatch\n\n");
        return 0;
    }

    if (!(strlen(temp_password1) >= 8 && strlen(temp_password1) <= 12)) {
        printf("\nYour Password is very short\nLength must between 8 to 12\n\n");
        return 0;
    }

    caps = 0;
    small = 0;
    numbers = 0;
    special = 0;
    for (i = 0; temp_password1[i] != '\0'; i++) {
        if (temp_password1[i] >= 'A' && temp_password1[i] <= 'Z')
            caps++;
        else if (temp_password1[i] >= 'a' && temp_password1[i] <= 'z')
            small++;
        else if (temp_password1[i] >= '0' && temp_password1[i] <= '9')
            numbers++;
        else if (temp_password1[i] == '@' || temp_password1[i] == '&' || temp_password1[i] == '#' || temp_password1[i] == '*' || temp_password1[i] == '_')
            special++;
    }
    if (!(caps >= 1 && small >= 1 && numbers >= 1 && special >= 1)) {
        printf("\n\nPlease Enter the strong password, Your password must contain atleast one uppercase, Lowercase, Number and special character\n\n");
        return 0;
    }

    // Validate age
    if (!(temp_age > 0)) {
        printf("\n\nPlease Enter the valid age\n\n");
        return 0;
    }

    // Check mobile number
    if (strlen(temp_mobile) != 10) {
        printf("\n\nPlease Enter the 10 digit mobile number\n\n");
        return 0;
    }
    for (i = 0; i < 10; i++) {
        if (!(temp_mobile[i] >= '0' && temp_mobile[i] <= '9')) {
            printf("\n\nPlease Enter Valid Mobile Number\n\n");
            return 0;
        }
    }

    // Validate address
    for (i = 0; temp_address[i] != '\0'; i++) {
        if (!((temp_address[i] >= 'a' && temp_address[i] <= 'z') || (temp_address[i] >= 'A' && temp_address[i] <= 'Z') || (temp_address[i] >= '0' && temp_address[i] <= '9') || temp_address[i] == ' ' || temp_address[i] == ',' || temp_address[i] == '.')) {
            printf("Enter Valid Address....");
            return 0;
        }
    }

    return 1;
}

void account_check() {
    for (i = 0; i < 100; i++) {
        // Check whether the email and password are already matched with existed account
        if (!strcmp(temp_email, s[i].email)) {
            printf("\n\nAccount Already Existed. Please Login !!\n\n");
            main();
            return;
        }
    }
    // if account does not already existed, it creates a new one with new inputs
    strcpy(s[j].uname, temp_name);
    s[j].age = temp_age;
    strcpy(s[j].password, temp_password1);
    strcpy(s[j].email, temp_email);
    strcpy(s[j].mobile, temp_mobile);
    strcpy(s[j].address, temp_address);
    j++;
    printf("\n\n\nAccount Successfully Created!!\n\n");
}

void login() {
    printf("\n\nLOGIN\n\n");
    printf("\nEnter Your Email\t");
    scanf("%s", temp_email);
    printf("Enter Your Password\t");
    scanf("%s", temp_password1);
    for (i = 0; i < 100; i++) {
        if (!strcmp(s[i].email, temp_email)) {
            if (!strcmp(s[i].password, temp_password1)) {
                printf("\n\nWelcome %s, ", s[i].uname);
                printf("Your are successfully logged in\n\nWe Provide two ways of search\n1) Search By Hotels\n2) Search by Food\n3) Exit\n\nPlease Enter your choice\t");
                scanf("%d", &search_choice);
                switch (search_choice) {
                    case 1: {
                        search_by_hotels();
                        break;
                    }
                    case 2: {
                        search_by_food();
                        break;
                    }
                    case 3: {
                        return;
                    }
                    default: {
                        printf("Please Enter the valid choice\n\n");
                        break;
                    }
                }
                return;
            } else {
                printf("\n\nInvalid Password! Please Enter the correct password\n\n");
                main();
                return;
            }
        }
    }
    printf("\n\nAccount doesn't exist, Please signup!!\n\n");
    main();
}

// Function to implement the Hotel initializer
void hotel_initialize() {
    strcpy(m[1].hotel, "ClassMate");
    strcpy(m[1].first_food, "Sandwich");
    strcpy(m[1].second_food, "Pizza");
    strcpy(m[1].third_food, "Fried_Rice");
    m[1].first = 70;
    m[1].second = 100;
    m[1].third = 95;
    strcpy(m[2].hotel, "Godavari_Hotel");
    strcpy(m[2].first_food, "Dosa");
    strcpy(m[2].second_food, "Idly");
    strcpy(m[2].third_food, "Paratha");
    m[2].first = 70;
    m[2].second = 20;
    m[2].third = 30;
    strcpy(m[3].hotel, "Food_Court");
    strcpy(m[3].first_food, "Noodles");
    strcpy(m[3].second_food, "Momos");
    strcpy(m[3].third_food, "Manchuria");
    m[3].first = 100;
    m[3].second = 70;
    m[3].third = 80;
    strcpy(m[4].hotel, "Campus_Hub");
    strcpy(m[4].first_food, "Tea");
    strcpy(m[4].second_food, "Puffs");
    strcpy(m[4].third_food, "Biscuits");
    m[4].first = 10;
    m[4].second = 20;
    m[4].third = 10;
}

// Function to search for hotels
void search_by_hotels() {
    hotel_initialize();
    printf("\n\nPlease Enter the Hotel ID\n\n1)ClassMate\n2)Godavari_Hotel\n3)Food_Court\n4)Campus_Hub\n\n");
    printf("Enter Your choice\t");
    scanf("%d", &hotel_choice);
    hotels(hotel_choice);
}

// Function to print the hotel details based on the hotel ID
void hotels(int hotel_choice) {
    printf("\n\nThe Menu is:\n\n");
    printf("Food ID\tFood_Name\tPrice\n\n");
    printf("1\t%s\t%d\n", m[hotel_choice].first_food, m[hotel_choice].first);
    printf("2\t%s\t%d\n", m[hotel_choice].second_food, m[hotel_choice].second);
    printf("3\t%s\t%d\n", m[hotel_choice].third_food, m[hotel_choice].third);
    printf("\n\nPlease Enter the food ID to order\n");
    scanf("%d", &food);
    food_order(food);
}

// Function to order food based on the food ID
void food_order(int food) {
    switch (food) {
        case 1:
            total = total + m[hotel_choice].first;
            break;
        case 2:
            total = total + m[hotel_choice].second;
            break;
        case 3:
            total = total + m[hotel_choice].third;
            break;
        default:
            printf("Invalid Food choice!!\n\n");
            return;
    }
    printf("\n\nFood added to Cart Successfully\n");
    printf("\n\nPlease Enter your Choice\n\n1)Order More\n2)Cart\n\n");
    scanf("%d", &confirm);
    switch (confirm) {
        case 1:
            search_by_hotels();
            break;
        case 2:
            cart();
            break;
        default:
            printf("Invalid Choice\n\n");
            break;
    }
}

// Function to search for food
void search_by_food() {
    hotel_initialize();
    printf("\n\nPlease Enter the Food ID\n\n1)Sandwich\n2)Pizza\n3)Fried_Rice\n4)Dosa\n5)Idly\n6)Paratha\n7)Noodles\n8)Momos\n9)Manchuria\n10)Tea\n11)Puffs\n12)Biscuits\n\n");
    printf("Enter Your choice\t");
    scanf("%d", &food_choice);
    switch (food_choice) {
        case 1:
            total = total + m[1].first;
            break;
        case 2:
            total = total + m[1].second;
            break;
        case 3:
            total = total + m[1].third;
            break;
        case 4:
            total = total + m[2].first;
            break;
        case 5:
            total = total + m[2].second;
            break;
        case 6:
            total = total + m[2].third;
            break;
        case 7:
            total = total + m[3].first;
            break;
        case 8:
            total = total + m[3].second;
            break;
        case 9:
            total = total + m[3].third;
            break;
        case 10:
            total = total + m[4].first;
            break;
        case 11:
            total = total + m[4].second;
            break;
        case 12:
            total = total + m[4].third;
            break;
        default:
            printf("Invalid Food choice!!\n\n");
            return;
    }
    printf("\n\nFood added to Cart Successfully\n");
    printf("\n\nPlease Enter your Choice\n\n1)Order More\n2)Cart\n\n");
    scanf("%d", &confirm);
    switch (confirm) {
        case 1:
            search_by_food();
            break;
        case 2:
            cart();
            break;
        default:
            printf("Invalid Choice\n\n");
            break;
    }
}

// Function to display the cart and total amount
void cart() {
    int payment_choice;
    
    // Display total amount to the user
    printf("\n\nTotal Amount: %d\n\n", total);

    // Prompt user to select a payment method
    printf("Select Payment Method:\n");
    printf("1) Credit Card\n2) Debit Card\n3) UPI\n4) Cash on Delivery\n\n");
    printf("Enter your choice: ");
    scanf("%d", &payment_choice);

    // Process the payment based on user's choice
    switch (payment_choice) {
        case 1:
            printf("Processing payment via Credit Card... Payment Successful!\n");
            break;
        case 2:
            printf("Processing payment via Debit Card... Payment Successful!\n");
            break;
        case 3:
            printf("Processing payment via UPI... Payment Successful!\n");
            break;
        case 4:
            printf("Cash on Delivery selected! Payment Successful!\n");
            break;
        default:
            printf("Invalid Payment Method. Please select a valid option.\n");
            return; // Exit function if payment method is invalid
    }

    // Reset total for next order
    total = 0;

    // Confirm delivery to registered address
    printf("\n\nYour order will be delivered to your registered address.\n");
}

