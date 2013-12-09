/***************************************************************************
COSC 501
Lab 6
Elliott Plack
15 OCT 2013											   Due date: 21 OCT 2013
Problem: Calculate the combination function with c++
Algorithm: Input n and k, checking that they are valid, positive, and that
	k is less than n. Use the while loop with cin in the conditions to
	check. Pass the values of n, k, and (n-k) to the a factorial function
	and then pass each returned value to the combination function.
	Factorial function uses recursion (rather than an iteration loop) to
	determine the result.
	Combination function uses a simple division math function to determine
	the result.
	The entire operation will run in a for loop so that it can be tested 5
	times.

**************************************************************************/

#include <iostream>
using namespace std;

int factorial (int);
int combo (int, int, int);

int main ()
{
	unsigned int n(0),k(0); // used unsigned to since no negative values are possible
	unsigned int factorial_result_n(0), factorial_result_k(0), factorial_result_nk(0), combo_result(0);
	
	cout << "This program computes the combination function.\n"
		 << "It will determine the number of k objects in n objects.\n"
		 << "The program will run 5 times.\n";
	
	for (int i = 0; i < 5; i++)
	{
		cout << "Test # " << i+1 << endl; // display iteration number
		cout << "Enter n: ";
		while ((!(cin >> n)) || (n < 1)) // Get the input and validate it, check if outside of range
			{
				cin.clear();     // Clear the error flags
				cin.ignore(100, '\n');    // Remove unwanted characters from buffer
				cout << "\aEnter a positive integer: ";   // Re-issue the prompt
			}

		cout << "Enter k (hint: less than " << n << "): "; // get k, which must be less than n

		while ((!(cin >> k)) || (k < 1) || (k > n)) // Get the input and validate it, check if outside of range
			{
				cin.clear();     // Clear the error flags
				cin.ignore(100, '\n');    // Remove unwanted characters from buffer
				cout << "\aEnter a positive integer, less than "<< n << ": ";   // Re-issue the prompt
			}
		cout << "You entered n="<< n << " and k=" << k << "." << endl;
	
		// next get the factorial of each individual element
		factorial_result_n = factorial(n);
		factorial_result_k = factorial(k);
		factorial_result_nk = factorial(n - k);
		combo_result = combo(factorial_result_n,factorial_result_k,factorial_result_nk);
		cout << "\nThe result is: " << combo_result << endl;
	}
	
	return 0;
}

int factorial (int factorial_input) 
{
	unsigned int factorial_result(0);

	if (factorial_input <= 1) // factorial of 0 or 1 is 1
		return 1;
	factorial_result = factorial_input * factorial(factorial_input - 1); // recursion
	
	return factorial_result;
}

int combo(int factoial_result_n, int factorial_result_k, int factorial_result_nk)
{
	int combo(0);
	combo = (factoial_result_n / (factorial_result_k * factorial_result_nk));
	return combo;
}