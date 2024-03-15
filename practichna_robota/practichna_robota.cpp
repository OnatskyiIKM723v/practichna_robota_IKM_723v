#include <iostream>
#include <vector>
#include <algorithm>

// Функція для знаходження суми всіх елементів у масиві
int findSum(const std::vector<int>& arr) {

    setlocale(LC_CTYPE, "ukr"); // дозволити використання української мови

    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

// Функція для знаходження середнього значення елементів у масиві
double findAverage(const std::vector<int>& arr) {
    if (arr.empty()) {
        return 0.0;
    }
    int sum = findSum(arr);
    return static_cast<double>(sum) / arr.size();
}

// Функція для сортування елементів у масиві
void sortArray(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
}

// Функція для знаходження повторюваних елементів у масиві
std::vector<int> findDuplicates(const std::vector<int>& arr) {
    std::vector<int> duplicates;
    std::vector<int> temp = arr;
    std::sort(temp.begin(), temp.end());
    for (size_t i = 0; i < temp.size() - 1; ++i) {
        if (temp[i] == temp[i + 1]) {
            duplicates.push_back(temp[i]);
        }
    }
    return duplicates;
}

int main() {
    std::vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 }; // Заданий масив

    // Знаходимо суму всіх елементів у масиві
    int sum = findSum(arr);
    std::cout << "Сума всіх елементів у масиві: " << sum << std::endl;

    // Знаходимо середнє значення елементів у масиві
    double average = findAverage(arr);
    std::cout << "Середнє значення елементів у масиві: " << average << std::endl;

    // Сортуємо елементи у масиві
    sortArray(arr);
    std::cout << "Відсортований масив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Знаходимо всі повторювані елементи у масиві
    std::vector<int> duplicates = findDuplicates(arr);
    if (!duplicates.empty()) {
        std::cout << "Повторювані елементи у масиві: ";
        for (int num : duplicates) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "У масиві немає повторюваних елементів." << std::endl;
    }

    return 0;
}
