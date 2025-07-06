import random
import string
import math

def generate_password(length, include_uppercase, include_digits, include_symbols):
    lowercase = string.ascii_lowercase
    uppercase = string.ascii_uppercase
    digits = string.digits
    symbols = string.punctuation

    characters = lowercase
    if include_uppercase:
        characters += uppercase
    if include_digits:
        characters += digits
    if include_symbols:
        characters += symbols

    if not characters:
        return ""

    return ''.join(random.choice(characters) for _ in range(length))

def check_password_strength(password):
    has_upper = any(c.isupper() for c in password)
    has_lower = any(c.islower() for c in password)
    has_digit = any(c.isdigit() for c in password)
    has_symbol = any(c in string.punctuation for c in password)
    length = len(password)

    print("Password strength: ", end="")
    if length >= 12 and has_upper and has_lower and has_digit and has_symbol:
        print("Strong")
    elif length >= 8 and ((has_upper and has_lower and (has_digit or has_symbol)) or (has_lower and has_digit and has_symbol)):
        print("Moderate")
    else:
        print("Weak")

    print("Recommendations:")
    if length < 8:
        print("- Increase password length to at least 8 characters.")
    if not has_upper:
        print("- Add uppercase letters.")
    if not has_lower:
        print("- Add lowercase letters.")
    if not has_digit:
        print("- Include digits.")
    if not has_symbol:
        print("- Include symbols.")

def estimate_bruteforce_time(password):
    length = len(password)
    has_upper = any(c.isupper() for c in password)
    has_lower = any(c.islower() for c in password)
    has_digit = any(c.isdigit() for c in password)
    has_symbol = any(c in string.punctuation for c in password)

    charset_size = 0
    if has_lower:
        charset_size += 26
    if has_upper:
        charset_size += 26
    if has_digit:
        charset_size += 10
    if has_symbol:
        charset_size += 32

    total_combinations = math.pow(charset_size, length)
    attempts_per_second = 1_000_000_000  # 1 billion attempts per second
    seconds = total_combinations / attempts_per_second

    years = seconds / (60 * 60 * 24 * 365)
    if years > 1:
        print(f"Estimated brute-force cracking time: {years:.2f} years")
    elif seconds > 86400:
        print(f"Estimated brute-force cracking time: {seconds / 86400:.2f} days")
    elif seconds > 3600:
        print(f"Estimated brute-force cracking time: {seconds / 3600:.2f} hours")
    elif seconds > 60:
        print(f"Estimated brute-force cracking time: {seconds / 60:.2f} minutes")
    else:
        print(f"Estimated brute-force cracking time: {seconds:.2f} seconds")


def main():
    while True:
        print("Choose an option:")
        print("1. Generate a new password")
        print("2. Check the strength of an existing password")
        print("3. Estimate brute-force cracking time for a password")
        print("4. Exit")

        choice = input("Enter your choice (1, 2, 3, or 4): ")

        if choice == '1':
            length = int(input("Enter password length: "))
            include_uppercase = input("Include uppercase letters? (y/n): ").lower() == 'y'
            include_digits = input("Include digits? (y/n): ").lower() == 'y'
            include_symbols = input("Include symbols? (y/n): ").lower() == 'y'
            password = generate_password(length, include_uppercase, include_digits, include_symbols)
            print(f"Generated Password: {password}")
            check_password_strength(password)
            estimate_bruteforce_time(password)

        elif choice == '2':
            password = input("Enter the password to check: ")
            check_password_strength(password)

        elif choice == '3':
            password = input("Enter the password to estimate brute-force time: ")
            estimate_bruteforce_time(password)

        elif choice == '4':
            print("Thank you for using the program. Goodbye!")
            break

        else:
            print("Invalid choice. Please select 1, 2, 3, or 4.")

if __name__ == "__main__":
    main()
