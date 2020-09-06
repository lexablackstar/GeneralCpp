#include <iostream>

using namespace std;

void lastDigitSquare();
void getInverseNo();
void getSumProdDivisors();

// ------------------------------------------
// main(): Everything starts here
// ------------------------------------------
int main (int argc, char* argv[]) {

    int op;

    while (true) {
        cout << endl << endl;
        cout << "=================================" << endl;
        cout << "Basic cpp functions "<< endl;
        cout << "=================================" << endl;
        cout << "1. Get square of last digit " << endl;
        cout << "2. Get inverse no for digits avg < 5" << endl;
        cout << "3. Get sum and prod for divisors of a no" << endl;
        cout << "0. Exit" << endl;
        cout << "=================================" << endl;
        cout << " Choose: ";
        cin >> op;

        switch (op)
        {
        case 1:
            lastDigitSquare();
            break;

        case 2:
            getInverseNo();
            break;   

        case 3:
            getSumProdDivisors();
            break; 


        case 0:
            return 0;

        default:
            break;
        }
    }

    return 0;
}
// ------------------------------------------
// Reads an int n and displays all no from 0 - 1000 that have last digit == n
// ------------------------------------------
void lastDigitSquare() {
    unsigned int n;
    cout << "Input n(0 - 9): ";
    cin >> n;

    if (n >= 10) {
        cout << "Error: n must be a digit" << endl;
        return;
    }

    bool found = false;
    for (int i = 0; i <= 1000; i++) {
        if ((i * i) % 10 == n){
            cout << i << " ";
            found = true;
        }
    }
    if (found == false)
        cout << "There is no number with last digit == " << n;

    cout << endl;    
}
// ------------------------------------------
// Reads positive int (stops when 0)
// For each no gets all digits and calculates avg
// If avg < 5 prints the inverse of the no(eg. if no is 103, print 301)
// ------------------------------------------
void getInverseNo(){
    unsigned int number = 1;
    unsigned int sumdigits = 0;
    unsigned int inverse = 0;

    while (number > 0) {
        cout << "Input n: ";
        cin >> number;

        inverse = 0;
        sumdigits = 0;
        unsigned int x = 0;
        unsigned temp = number;
        while (temp > 0) {
            int digit = temp % 10;
            inverse = inverse * 10 + digit;
            sumdigits += digit;
            temp /= 10;
            x++;
        }
        if (x > 0) {
            if ((sumdigits / x ) < 5)
                cout << "Inverse no is " << inverse << endl;
            else
            {
                cout << "The avg of its digits is >= 5" << endl;
            }
                
        }
    }
}
// ------------------------------------------
// Reads an int n and optains its divisors
// Prints the sum and prod of its divisors
// If no divisor prints a messange
// ------------------------------------------
void getSumProdDivisors() {
    unsigned int n;
    cout << "Input n: ";
    cin >> n;

    unsigned int sum = 0;
    unsigned int prod = 1;

    for (unsigned int i = 2; i <= n/2; i++) {
        if (n % i == 0)
        {
            sum += i;
            prod *= i;
        }
        
    }
    if (sum == 0)
        cout << "There is no divisor for " << n << endl;
    else
    {
        cout << "Sum of its divisors is " << sum << endl;
        cout << "Prod of its divisors is " << prod << endl;
    }
        
    
}