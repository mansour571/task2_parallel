#include <stdio.h>

// Define the structure for user information
struct UserInfo {
    char username[50];
    char password[50];
    int isActive; // 1 for True, 0 for Error
};

// Define a union for flash drive price estimation
union FlashDrivePrice {
    float price;
    int estimate[4]; // Prices for four countries
};

int main() {
    // Initialize a user
    struct UserInfo user;

    // Get user information during registration
    printf("Enter username: ");
    scanf("%s", user.username);

    printf("Enter password: ");
    scanf("%s", user.password);

    printf("Set user status (1 for True, 0 for Error): ");
    scanf("%d", &user.isActive);

    // Check user status before allowing login
    if (user.isActive == 1) {
        // Allow login
        printf("Login successful!\n");

        // Example: Use the union to estimate flash drive price
        union FlashDrivePrice flashDrive;
        printf("Enter flash drive price for four countries:\n");
        for (int i = 0; i < 4; ++i) {
            printf("Country %d: $", i + 1);
            scanf("%d", &flashDrive.estimate[i]);
        }

        // Example: Print estimated flash drive prices
        printf("Estimated flash drive prices:\n");
        for (int i = 0; i < 4; ++i) {
            printf("Country %d: $%.2f\n", i + 1, flashDrive.price);
        }
    } else {
        // Deny login
        printf("Login unsuccessful. User is not active.\n");
    }

    return 0;
}
