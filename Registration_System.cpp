#include <iostream>
#include <vector>
#include <string>

class Customer {
public:
    std::string name;
    int age;

    Customer(const std::string& n, int a) : name(n), age(a) {}
};

void displayMenu() {
    std::cout << "Airline Registration System\n";
    std::cout << "1. Add Customer\n";
    std::cout << "2. Exit\n";
}

void addCustomer(std::vector<Customer>& customers) {
    std::string name;
    int age;

    std::cout << "Enter customer name: ";
    std::cin >> name;
    std::cout << "Enter customer age: ";
    std::cin >> age;

    customers.emplace_back(name, age);
    std::cout << "Customer added successfully!\n";
}

int main() {
    std::vector<Customer> allCustomers;

    while (true) {
        displayMenu();
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addCustomer(allCustomers);
                break;
            case 2:
                std::cout << "Exiting the program. Thank you!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}