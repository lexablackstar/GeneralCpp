#include <iostream>

using namespace std;

void lastDigitSquare();
void getInverseNo();
void getSumProdDivisors();
void divisorsMa();
void getBestUnit();

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
        cout << "4. Get the Ma of the divisors" << endl;
        cout << "5. Units profit" << endl;
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

        case 4:
            divisorsMa();
            break; 

        case 5:
            getBestUnit();
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
// Reads an int n and obtains its divisors
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
// ------------------------------------------
// Reads an int n and obtains its divisors
// Prints the Ma of the divisors between a and b
// If no divisor prints a messange
// ------------------------------------------
void divisorsMa() {
    unsigned int n, a, b, x;
    unsigned int ma = 0;
    x = 0;
    cout << "Input 3 numbers: ";
    cin >> n >> a >> b;

    for (unsigned int i = 2; i <= n/2; i++) {
        if (n % i == 0)
        {
           if (a < i && i < b)
           {
               ma += i;
               x++;
           }
           
        } 
        
    }
    if (x > 0)
        cout << ma / x << endl;
    else
    {
        cout << "The no doesn't have any divisors."<< endl;
    }
    

}
// ------------------------------------------
// A company has a no n of units (1 < n < 5)
// Each unit reported its profit for Q1, Q2, Q3, Q4
// Dysplays the best unit for quorter q
// ------------------------------------------
void getBestUnit() {
    unsigned int n, q;
    cout << "Input the no of units(1-5): ";
    cin >> n;

    int q1[5], q2[5], q3[5], q4[5];
    for (int i = 0; i < n; i++)
    {
        cout << i + 1<< " Input profit Q1: ";
        cin >> q1[i];
        cout << i + 1<< " Input profit Q2: ";
        cin >> q2[i];
        cout << i + 1<< " Input profit Q3: ";
        cin >> q3[i];
        cout << i + 1<< " Input profit Q4: ";
        cin >> q4[i];
    }
    cout << endl << "Input quarter(1-4): ";
    cin >> q;
    int max = 0;
    switch (q)
    {
    case 1:
        for (int i = 0; i < n; i++)
        {
            if(max < q1[i])
                max = q1[i];
        }
        
        break;
    
    case 2:
        for (int i = 0; i < n; i++)
        {
            if(max < q2[i])
                max = q2[i];
        }
        
        break;

    case 3:
        for (int i = 0; i < n; i++)
        {
            if(max < q3[i])
                max = q3[i];
        }
        
        break;

    case 4:
        for (int i = 0; i < n; i++)
        {
            if(max < q4[i])
                max = q4[i];
        }
        
        break;        

    default:
        break;
    }
    
    cout << "The most proditable on Q"<< q << " is " << max << endl;
}