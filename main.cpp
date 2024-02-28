#include <iostream>
#include <string>
#include <cmath>

class HeartRates {
private:
    std::string firstName;
    std::string lastName;
    int birthMonth;
    int birthDay;
    int birthYear;

public:
    HeartRates(const std::string& first, const std::string& last, int month, int day, int year)
        : firstName(first), lastName(last), birthMonth(month), birthDay(day), birthYear(year) {}

    // Setters
    void setFirstName(const std::string& first) {
        firstName = first;
    }

    void setLastName(const std::string& last) {
        lastName = last;
    }

    void setBirthMonth(int month) {
        birthMonth = month;
    }

    void setBirthDay(int day) {
        birthDay = day;
    }

    void setBirthYear(int year) {
        birthYear = year;
    }

    // Getters
    std::string getFirstName() const {
        return firstName;
    }

    std::string getLastName() const {
        return lastName;
    }

    int getBirthMonth() const {
        return birthMonth;
    }

    int getBirthDay() const {
        return birthDay;
    }

    int getBirthYear() const {
        return birthYear;
    }

    // Function to calculate age
    int getAge(int currentMonth, int currentDay, int currentYear) const {
        int age = currentYear - birthYear;
        if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
            age--;
        }
        return age;
    }

    // Function to calculate maximum heart rate
    int getMaximumHeartRate(int currentMonth, int currentDay, int currentYear) const {
        int age = getAge(currentMonth, currentDay, currentYear);
        return 220 - age;
    }

    // Function to calculate target heart rate range
    std::pair<int, int> getTargetHeartRate(int currentMonth, int currentDay, int currentYear) const {
        int maxHeartRate = getMaximumHeartRate(currentMonth, currentDay, currentYear);
        int lowerRange = std::round(0.5 * maxHeartRate); // 50% of max heart rate
        int upperRange = std::round(0.85 * maxHeartRate); // 85% of max heart rate
        return std::make_pair(lowerRange, upperRange);
    }
};

int main() {
    std::string firstName, lastName;
    int birthMonth, birthDay, birthYear;
    int currentMonth, currentDay, currentYear;

    // Prompt for person's information
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cout << "Enter birth month, day, and year (separated by spaces): ";
    std::cin >> birthMonth >> birthDay >> birthYear;
    std::cout << "Enter current month, day, and year (separated by spaces): ";
    std::cin >> currentMonth >> currentDay >> currentYear;

    // Create HeartRates object
    HeartRates person(firstName, lastName, birthMonth, birthDay, birthYear);

    // Print person's information
    std::cout << "\nPerson's Information:\n";
    std::cout << "First Name: " << person.getFirstName() << std::endl;
    std::cout << "Last Name: " << person.getLastName() << std::endl;
    std::cout << "Date of Birth: " << person.getBirthMonth() << "/" << person.getBirthDay() << "/" << person.getBirthYear() << std::endl;

    // Calculate and print age
    int age = person.getAge(currentMonth, currentDay, currentYear);
    std::cout << "\nAge: " << age << " years" << std::endl;

    // Calculate and print maximum heart rate
    int maxHeartRate = person.getMaximumHeartRate(currentMonth, currentDay, currentYear);
    std::cout << "Maximum Heart Rate: " << maxHeartRate << " bpm" << std::endl;

    // Calculate and print target heart rate range
    std::pair<int, int> targetHeartRate = person.getTargetHeartRate(currentMonth, currentDay, currentYear);
    std::cout << "Target Heart Rate Range: " << targetHeartRate.first << " - " << targetHeartRate.second << " bpm" << std::endl;

    return 0;
}
