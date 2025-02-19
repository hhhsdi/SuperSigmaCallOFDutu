#include "Customer.h"
#include <iostream>

Customer::Customer(std::string n, double b) : name(n), balance(b) {}

bool Customer::purchase(Shop& shop, std::string productName, int quantity) {
    for (auto& product : shop.products) {
        if (product.name == productName && product.quantity >= quantity) {
            double totalCost = product.price * quantity;
            if (balance >= totalCost) {
                balance -= totalCost;
                product.quantity -= quantity;
                std::cout << name << " ����� " << quantity << " " << productName << " � " << shop.name << "\n";
                return true;
            }
            else {
                std::cout << "������������ ������� � " << name << "\n";
                return false;
            }
        }
    }
    std::cout << "����� �� ������ ��� ������������ � ������� � " << shop.name << "\n";
    return false;
}

void Customer::displayBalance() {
    std::cout << "������ " << name << ": " << balance << "\n";
}