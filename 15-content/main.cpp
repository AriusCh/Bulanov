#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <string>

const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

const std::vector<std::string> movies = {
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "11",
    "12",
    "13",
    "14",
    "15",
    "16",
    "17",
    "18",
    "19",
    "20",
    "21",
    "22",
    "23",
    "24",
    "25",
    "26",
    "27",
    "28"
};

const std::vector<std::string> vips = {
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "11",
    "12",
    "13",
    "14",
    "15",
    "16",
    "17",
    "18",
    "19",
    "20",
    "21",
    "22",
    "23",
    "24",
    "25",
    "26",
    "27",
    "28"
};

const std::vector<std::string> music = {
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9"
};

std::string strToLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });
    return s;
}

int get_year() {
    int output;
    bool success = false;

    while (!success) {
        std::string input;

        std::cout << "Enter your birth year: ";
        std::cin >> input;

        double dnum;

        try {
            dnum = std::stod(input);
        } catch (std::invalid_argument e) {
            std::cout << "Not a number. Try again." << std::endl;
            continue;
        }

        if (dnum != std::floor(dnum)) {
            std::cout << "Not a whole number. Try again." << std::endl;
            continue;
        }

        if (dnum <= 0.0) {
            std::cout << "You are too old. Try again." << std::endl;
            continue;
        }

        output = dnum;
        success = true;
    }
    return output;
}

std::string get_string(const std::string& what_to_get) {
    std::string output;
    bool success = false;

    while (!success) {
        std::string input;
        std::cout << what_to_get << ": ";
        std::cin >> input;
        input = strToLower(input);

        output = input;
        success = true;
    }

    return output;
}

int year_conversion(int input) {
    int output = 0;
    while (input > 0) {
        output += input % 10;
        input /= 10;
    }
    if (output > 9) {
        output = year_conversion(output);
    }
    return output;
}

int main() {
    std::string name;
    std::string surname;
    int birth_year;

    std::cout << "Hello there! I have some fine HIGH QUALITY content for you!" << std::endl;
    std::cout << "All you have to do is:" << std::endl;
    std::cout << "Give me your name, surname and birth year! Easy, right?" << std::endl;
    std::cout << "Also, 3-digit number from the back of your credit card would be very helpful!" << std::endl;
    std::cout << "Alright, let's begin!" << std::endl << std::endl;

    name = get_string("Name");
    surname = get_string("Surname");
    birth_year = get_year();

    std::cout << std::endl << "Well, I'm done! Here are the results!" << std::endl;
    std::cout << "Your film is " << movies[alphabet.find(name[0])] << std::endl;
    std::cout << "Your VIP is " << vips[alphabet.find(surname[0])] << std::endl;
    std::cout << "Your music track is " << music[year_conversion(birth_year) - 1] << std::endl;

    return 0;

}
