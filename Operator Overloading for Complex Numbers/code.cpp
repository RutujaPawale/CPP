#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;

    // 1. Default Constructor
    // Initializes the complex number to 0 + 0i
    Complex() : real(0), imag(0) {}

    // Optional: Parameterized Constructor for initialization flexibility
    Complex(int r, int i) : real(r), imag(i) {}

    // 2. Overloading operator+ for addition
    // Adds the real and imaginary parts of two complex numbers
    Complex operator+(const Complex& a) const {
        return Complex(real + a.real, imag + a.imag);
    }

    // 3. Overloading operator* for multiplication
    // Multiplies two complex numbers using the formula:
    // (a+bi) * (c+di) = (ac - bd) + (ad + bc)i
    Complex operator*(const Complex& a) const {
        return Complex(real * a.real - imag * a.imag, real * a.imag + imag * a.real);
    }

    // 4a. Overloading << for output
    // Outputs the complex number in the format "a+bi"
    friend ostream& operator<<(ostream& os, const Complex& z) {
        os << z.real << "+i" << z.imag;
        return os;
    }

    // 4b. Overloading >> for input
    // Reads the real and imaginary parts of the complex number
    friend istream& operator>>(istream& is, Complex& z) {
        cout << "Enter real part: ";
        is >> z.real;
        cout << "Enter imaginary part: ";
        is >> z.imag;
        return is;
    }
};

int main() {
    int option;
    char cont;
    Complex z1, z2;

    cout << "Welcome to Complex Calculator!";
    do {
        cout << "\n\nWhat do you want to perform?"
             << "\n1. Addition"
             << "\n2. Multiplication"
             << "\n\nEnter your choice: ";
        cin >> option;

        switch (option) {
            case 1: // Addition
                cout << "\nComplex Number 1:\n";
                cin >> z1; // Uses overloaded >> operator to read z1
                cout << "\nComplex Number 2:\n";
                cin >> z2; // Uses overloaded >> operator to read z2
                cout << "\nAddition Result: " << z1 + z2 << endl; // Uses overloaded + and << operators
                break;

            case 2: // Multiplication
                cout << "\nComplex Number 1:\n";
                cin >> z1; // Uses overloaded >> operator to read z1
                cout << "\nComplex Number 2:\n";
                cin >> z2; // Uses overloaded >> operator to read z2
                cout << "\nMultiplication Result: " << z1 * z2 << endl; // Uses overloaded * and << operators
                break;

            default:
                cout << "\nInvalid choice!" << endl;
                break;
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> cont;

    }
    while (cont == 'y' || cont == 'Y');

    cout << "\nThank you for using Complex Calculator." << endl;
    return 0;
}
