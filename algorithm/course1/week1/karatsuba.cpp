/*
Question 1
In this programming assignment you will implement one or more of the integer multiplication algorithms described in lecture.

To get the most out of this assignment, your program should restrict itself to multiplying only pairs of single-digit numbers.  You can implement the grade-school algorithm if you want, but to get the most out of the assignment you'll want to implement recursive integer multiplication and/or Karatsuba's algorithm.

So: what's the product of the following two 64-digit numbers?

3141592653589793238462643383279502884197169399375105820974944592

2718281828459045235360287471352662497757247093699959574966967627

[TIP: before submitting, first test the correctness of your program on some small test cases of your own devising. Then post your best test cases to the discussion forums to help your fellow students!]

[Food for thought: the number of digits in each input number is a power of 2.  Does this make your life easier?  Does it depend on which algorithm you're implementing?]

The numeric answer should be typed in the space below.  So if your answer is 1198233847, then just type 1198233847 in the space provided without any space / commas / any other punctuation marks. 

(We do not require you to submit your code, so feel free to use any programming language you want --- just type the final numeric answer in the following space.)
*/

#include<iostream>
#include<stdio.h>
#include<cmath>

using namespace std;

int countDigit(int a);
unsigned long long Karatsuba(unsigned long long a, unsigned long long b);

int main() {
    // unsigned long long x, y;

    // Input the integers to be multiplied
    // cout << "Enter the first integer: ";
    // cin >> x;
    // cout << "Enter the second integer: ";
    // cin >> y;

    unsigned long long x = 314159532;
    unsigned long long y = 2718285387;

    // Perform the multiplication using Karatsuba algorithm
    unsigned long long result = Karatsuba(x, y);

    // Output the result
    cout<<"Classical Algorithm : " <<endl;
    const clock_t classical_time = clock();
    cout << "Result of multiplication: " << x*y << endl;
    cout << float( clock () - classical_time ) /  CLOCKS_PER_SEC<<endl<<endl;

    cout<<endl<<"Karatsuba Algorithm : "<<endl;
    const clock_t karatsuba_time = clock();
    cout << "Result of multiplication: " << result << endl;
    cout << float( clock () - karatsuba_time ) /  CLOCKS_PER_SEC<<endl<<endl;

    return 0;
}

int countDigit(unsigned long long num) {
    if (num == 0) return 1;

    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

unsigned long long Karatsuba(unsigned long long num1, unsigned long long num2) {
    int numDigit = max(countDigit(num1), countDigit(num2)) / 2;

    if (num1 < 10 || num2 < 10) {
        return num1*num2;
    } else {
        unsigned long long scale = pow(10, numDigit);
        unsigned long long a = num1 / scale;
        unsigned long long b = num1 % scale;
        unsigned long long c = num2 / scale;
        unsigned long long d = num2 % scale; 

        unsigned long long ac = Karatsuba(a, c);
        unsigned long long bd = Karatsuba(b, d);
        unsigned long long pq = Karatsuba(a + b, c + d);

        return pow(10, numDigit*2)*ac + scale*(pq - ac - bd) + bd;
    }
}
