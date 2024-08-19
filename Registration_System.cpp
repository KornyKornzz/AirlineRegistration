#include <iostream>
#include <vector>
#include <string>

class Customer {
public:
    std::string name;
    int age;

    Customer(const std::string& n, int a) : name(n), age(a) {}
};

class AirlineRegistration {
private:
    std::vector<Customer> allCustomers;

public:
    void addCustomer() {
        std::string name;
        int age;

        std::cout << "Enter customer name: ";
        std::cin >> name;
        std::cout << "Enter customer age: ";
        std::cin >> age;

        allCustomers.emplace_back(name, age);
        std::cout << "Customer added successfully!\n";
    }

    void removeCustomer() {
        std::string name;
        std::cout << "Enter customer name to remove: ";
        std::cin >> name;

        for (auto it = allCustomers.begin(); it != allCustomers.end(); ++it) {
            if (it->name == name) {
                allCustomers.erase(it);
                std::cout << "Customer removed successfully!\n";
                return;
            }
        }

        std::cout << "Customer not found.\n";
    }

    void displayCustomers() {
        if (allCustomers.empty()) {
            std::cout << "No customers registered yet.\n";
            return;
        }

        std::cout << "Registered Customers:\n";
        for (const auto& customer : allCustomers) {
            std::cout << "Name: " << customer.name << ", Age: " << customer.age << "\n";
        }
    }
};

void displayMenu() {
    std::cout << "Airline Registration System\n";
    std::cout << "1. Add Customer\n";
    std::cout << "2. Remove Customer\n";
    std::cout << "3. Display Customers\n";
    std::cout << "4. Exit\n";
}

int main() {
    AirlineRegistration airlineRegistration;

    while (true) {
        displayMenu();
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                airlineRegistration.addCustomer();
                break;
            case 2:
                airlineRegistration.removeCustomer();
                break;
            case 3:
                airlineRegistration.displayCustomers();
                break;
            case 4:
                std::cout << "Exiting the program. Thank you!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}