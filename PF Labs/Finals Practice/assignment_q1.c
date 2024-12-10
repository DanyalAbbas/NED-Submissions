#include <stdio.h>

// Structure to represent a card
typedef struct {
    int number;
    int sum;
} Card;

// Function to get card data from user
void get_data(Card cards[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter card %d (100-999): ", i + 1);
        scanf("%d", &cards[i].number);

        // Calculate sum of digits
        cards[i].sum = 0;
        int num = cards[i].number;
        while (num != 0) {
            cards[i].sum += num % 10;
            num /= 10;
        }
    }
}

// Function to sort cards based on sum of digits
void sort(Card cards[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cards[i].sum > cards[j].sum) {
                // Swap cards
                Card temp = cards[i];
                cards[i] = cards[j];
                cards[j] = temp;
            }
        }
    }
}

// Function to display sorted cards
void display(Card cards[], int n) {
    printf("Sorted Cards (by sum of digits):\n");
    for (int i = 0; i < n; i++) {
        printf("%d (Sum: %d)\n", cards[i].number, cards[i].sum);
    }
}

int main() {
    int n;
    printf("Enter number of cards: ");
    scanf("%d", &n);

    Card cards[n];
    get_data(cards, n);
    sort(cards, n);
    display(cards, n);

    return 0;
}
