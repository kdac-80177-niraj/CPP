#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    void initDate() {
        day = 1;
        month = 1;
        year = 2000;
    }

    void printDateOnConsole() {
        std::cout << "Date: " << day << "/" << month << "/" << year << std::endl;
    }

    void acceptDateFromConsole() {
        std::cout << "Enter day: ";
        std::cin >> day;

        std::cout << "Enter month: ";
        std::cin >> month;

        std::cout << "Enter year: ";
        std::cin >> year;
    }

    bool isLeapYear() {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }
};

int main() {
    Date date;
    date.initDate();

    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Print date\n";
        std::cout << "2. Accept date\n";
        std::cout << "3. Check if leap year\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                date.printDateOnConsole();
                break;
            case 2:
                date.acceptDateFromConsole();
                break;
            case 3:
                if (date.isLeapYear())
                    std::cout << "The year is a leap year.\n";
                else
                    std::cout << "The year is not a leap year.\n";
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
