#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>    // For std::this_thread::sleep_for
#include <chrono>    // For std::chrono::seconds

// Coffee types
enum CoffeeType {
    ESPRESSO,
    LATTE,
    CAPPUCCINO
};

const std::vector<std::string> coffeeNames = {
    "Espresso",
    "Latte",
    "Cappuccino"
};

const std::vector<int> coffeePrices = {
    5, // Espresso
    6, // Latte
    7  // Cappuccino
};

// Customer class
class Customer {
public:
    Customer(CoffeeType coffeeType) : coffeeType(coffeeType) {}

    CoffeeType getOrder() const {
        return coffeeType;
    }

private:
    CoffeeType coffeeType;
};

// Game class
class CoffeeShopGame {
public:
    CoffeeShopGame() : money(0) {
        std::srand(std::time(0)); // Seed random number generator
    }

    void start() {
        std::cout << "Welcome to the Coffee Shop Game!\n";

        while (true) {
            showMenu();
            int choice = getChoice();

            if (choice == 1) {
                takeOrder();
            } else if (choice == 2) {
                std::cout << "Exiting game. Thanks for playing!\n";
                break;
            } else {
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
    }

private:
    int money;

    void showMenu() const {
        std::cout << "\nMenu:\n";
        std::cout << "1. Take an order\n";
        std::cout << "2. Exit\n";
        std::cout << "Choose an option: ";
    }

    int getChoice() const {
        int choice;
        std::cin >> choice;
        return choice;
    }

    void takeOrder() {
        // Simulate a customer order
        CoffeeType coffeeType = static_cast<CoffeeType>(std::rand() % coffeeNames.size());
        Customer customer(coffeeType);

        std::cout << "\nNew order:\n";
        std::cout << "Customer wants a " << coffeeNames[coffeeType] << ".\n";
        std::cout << "Preparing the coffee...\n";

        // Prepare coffee
        serveCoffee(customer);

        std::cout << "Coffee served! You earned $" << coffeePrices[coffeeType] << ".\n";
        money += coffeePrices[coffeeType];
        std::cout << "Total money earned: $" << money << "\n";
    }

    void serveCoffee(const Customer& customer) const {
        // Simulate coffee preparation time
        std::cout << "Preparing your coffee...\n";
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Wait for 2 seconds
    }
};

int main() {
    CoffeeShopGame game;
    game.start();
    return 0;
}
