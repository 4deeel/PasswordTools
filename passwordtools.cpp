#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>

using namespace std;

//to generate random password
string generatePassword(int length, bool includeUppercase, bool includeDigits, bool includeSymbols) {
    const string lowercase = "abcdefghijklmnopqrstuvwxyz";
    const string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string digits = "0123456789";
    const string symbols = "!@#$%^&*()_+[]{}|;:,.<>?";

    string characters = lowercase;
    if (includeUppercase) characters += uppercase;
    if (includeDigits) characters += digits;
    if (includeSymbols) characters += symbols;

    if (characters.empty()) {
        return "";
    }

    string password = "";
    for (int i = 0; i < length; ++i) {
        password += characters[rand() % characters.size()];
    }

    return password;
}

//to check strength
void checkPasswordStrength(const string& password) {
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSymbol = false;
    for (char ch : password) {
        if (isupper(ch)) hasUpper = true;
        else if (islower(ch)) hasLower = true;
        else if (isdigit(ch)) hasDigit = true;
        else hasSymbol = true;
    }

    int length = password.length();
    cout << "Password strength: ";
    if (length >= 12 && hasUpper && hasLower && hasDigit && hasSymbol) {
        cout << "Strong" << endl;
    }
    else if (length >= 8 && ((hasUpper && hasLower && (hasDigit || hasSymbol)) || (hasLower && hasDigit && hasSymbol))) {
        cout << "Moderate" << endl;
    }
    else {
        cout << "Weak" << endl;
    }

    cout << "Recommendations: " << endl;
    if (length < 8) cout << "- Increase password length to at least 8 characters." << endl;
    if (!hasUpper) cout << "- Add uppercase letters." << endl;
    if (!hasLower) cout << "- Add lowercase letters." << endl;
    if (!hasDigit) cout << "- Include digits." << endl;
    if (!hasSymbol) cout << "- Include symbols." << endl;
}

//to estimate brute-force time
void estimateBruteForceTime(const string& password) {
    int length = password.length();
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSymbol = false;

    for (char ch : password) {
        if (isupper(ch)) hasUpper = true;
        else if (islower(ch)) hasLower = true;
        else if (isdigit(ch)) hasDigit = true;
        else hasSymbol = true;
    }

    int characterSetSize = 0;
    if (hasLower) characterSetSize += 26;
    if (hasUpper) characterSetSize += 26;
    if (hasDigit) characterSetSize += 10;
    if (hasSymbol) characterSetSize += 32; // Approximate number of common symbols

    // Total possible combinations
    unsigned long long totalCombinations = pow(characterSetSize, length);

    // Assuming a hypothetical cracking speed
    const unsigned long long attemptsPerSecond = 1000000; // 1 Million attempts per second

    // Time to crack in seconds
    unsigned long long seconds = totalCombinations / attemptsPerSecond;

    // Convert time to larger units
    unsigned long long minutes = seconds / 60;
    unsigned long long hours = minutes / 60;
    unsigned long long days = hours / 24;
    unsigned long long years = days / 365;

    cout << "Estimated brute-force cracking time: ";
    if (years > 0) {
        cout << years << " years" << endl;
    }
    else if (days > 0) {
        cout << days << " days" << endl;
    }
    else if (hours > 0) {
        cout << hours << " hours" << endl;
    }
    else if (minutes > 0) {
        cout << minutes << " minutes" << endl;
    }
    else {
        cout << seconds << " seconds" << endl;
    }
}

int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    char continueChoice;

    do {
        int choice;
        cout << "Choose an option:" << endl;
        cout << "1. Generate a new password" << endl;
        cout << "2. Check the strength of an existing password" << endl;
        cout << "3. Estimate brute-force cracking time for a password" << endl;
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> choice;

        if (choice == 1) {
            int length;
            bool includeUppercase, includeDigits, includeSymbols;

            // Input from the user
            cout << "Enter password length: ";
            cin >> length;

            cout << "Include uppercase letters? (1 for Yes, 0 for No): ";
            cin >> includeUppercase;

            cout << "Include digits? (1 for Yes, 0 for No): ";
            cin >> includeDigits;

            cout << "Include symbols? (1 for Yes, 0 for No): ";
            cin >> includeSymbols;

            // Generate and display the password
            string password = generatePassword(length, includeUppercase, includeDigits, includeSymbols);
            cout << "Generated Password: " << password << endl;

            // Check password strength
            checkPasswordStrength(password);

            // Estimate brute-force time
            estimateBruteForceTime(password);
        }
        else if (choice == 2) {
            string password;
            cout << "Enter the password to check: ";
            cin >> password;

            // Check password strength
            checkPasswordStrength(password);
        }
        else if (choice == 3) {
            string password;
            cout << "Enter the password to estimate brute-force time: ";
            cin >> password;

            // Estimate brute-force time
            estimateBruteForceTime(password);
        }
        else {
            cout << "Invalid choice. Please select 1, 2, or 3." << endl;
        }

        cout << "Do you want to perform another operation? (Y/N): ";
        cin >> continueChoice;

    } while (tolower(continueChoice) == 'y');

    cout << "Thank you for using the program. Goodbye!" << endl;

    return 0;
}
