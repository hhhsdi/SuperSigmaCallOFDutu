#include <iostream>
#include <vector>
#include "Shop.h"
#include "Customer.h"

void displayMenu() {
    std::cout << "\n����:\n";
    std::cout << "1. �������� �������\n";
    std::cout << "2. �������� ����� � �������\n";
    std::cout << "3. ������� ������\n";
    std::cout << "4. ������� ������ ����������\n";
    std::cout << "5. ����� ������� � ����� ������ �����\n";
    std::cout << "6. ������� ������ � ���������\n";
    std::cout << "0. �����\n";
}

int main() {
    std::setlocale(LC_ALL,"rus");
    std::vector<Shop> shops;
    Customer customer("����", 100.0);

    int choice;
    do {
        displayMenu();
        std::cout << "�������� �����: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string shopName;
            std::cout << "������� �������� ��������: ";
            std::cin >> shopName;
            shops.emplace_back(shopName);
        }
        else if (choice == 2) {
            std::string shopName, productName;
            double price;
            int quantity;
            std::cout << "������� �������� ��������: ";
            std::cin >> shopName;
            std::cout << "������� �������� ������: ";
            std::cin >> productName;
            std::cout << "������� ����: ";
            std::cin >> price;
            std::cout << "������� ����������: ";
            std::cin >> quantity;
            for (auto& shop : shops) {
                if (shop.name == shopName) {
                    shop.addProduct(productName, price, quantity);
                    break;
                }
            }
        }
        else if (choice == 3) {
            std::string shopName, productName;
            int quantity;
            std::cout << "������� �������: ";
            std::cin >> shopName;
            std::cout << "������� �����: ";
            std::cin >> productName;
            std::cout << "������� ����������: ";
            std::cin >> quantity;
            for (auto& shop : shops) {
                if (shop.name == shopName) {
                    customer.purchase(shop, productName, quantity);
                    break;
                }
            }
        }
        else if (choice == 4) {
            customer.displayBalance();
        }
        else if (choice == 6) {
            for (auto& shop : shops) {
                shop.displayProducts();
            }
        }
    } while (choice != 0);
    return 0;
}
