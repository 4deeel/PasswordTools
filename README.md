# Password Management Tool

---

## Introduction

The Password Management Tool is a cross-language utility developed in both C++ and Python. It helps users create secure passwords, check password strength, and estimate the time required to crack passwords using brute-force methods. This project serves as a foundational exercise in programming logic, user input handling, and security-focused development.

---

## Objectives

- Generate strong, customizable passwords.
- Analyze and rate the strength of a given password.
- Estimate brute-force cracking time based on password complexity.
- Provide helpful recommendations to improve weak passwords.

---

## Features

### 1. Password Generator

- User-defined password length.
- Options to include:
  - Uppercase letters
  - Digits
  - Symbols
- Random password generation based on selected criteria.

### 2. Password Strength Checker

- Analyzes password content (uppercase, lowercase, digits, symbols).
- Categorizes strength as:
  - Weak
  - Moderate
  - Strong
- Suggests improvements for weak passwords.

### 3. Brute-force Time Estimator

- Calculates estimated time to crack a password based on:
  - Length
  - Character diversity
- Displays time in seconds, minutes, hours, days, or years.

### 4. Interactive Menu

- Allows users to:
  - Generate passwords
  - Check strength
  - Estimate cracking time
- Continues running until the user chooses to exit.

---

## Implementation

### C++ Version

- Uses standard libraries for input/output and string manipulation.
- Secure password generation using seeded random functions.
- Interactive logic managed using do-while loops.

### Python Version

- Utilizes `string` and `random` libraries for password generation.
- Modular function design:
  - `generate_password()`
  - `check_strength()`
  - `estimate_crack_time()`
- Interactive menu managed using a while loop.

---

## Use Cases

1. Generating New Passwords  
   Useful for creating secure credentials during account setup.

2. Checking Existing Passwords  
   Helps users assess and improve current password security.

3. Estimating Password Vulnerability  
   Educates users on how long a brute-force attack might take on a password.

---

## Limitations and Future Enhancements

### Limitations

- Assumes a fixed rate of password attempts (does not simulate modern attack techniques).
- Does not detect dictionary words or reused passwords.

### Future Enhancements

- Add database integration for storing/retrieving passwords.
- Apply hashing algorithms for secure password storage.
- Develop a graphical user interface (GUI) for better usability.

---

## Conclusion

This Password Management Tool demonstrates the application of programming concepts in both C++ and Python. It offers a practical and educational experience in password security, with planned enhancements to increase functionality, user experience, and security awareness.

---

## Author

**Muhammad Adeel Haider - 241541**
BS Cybersecurity – Air University  
