//Program name: LIS.cpp
//Author: Dan Kercher
//Date last updated: 11/28/2020
//Purpose: To find the longest increasing subsequence from an input file using dynamic programming principles
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


// Function to find LIS from a list of IS (increeasing subsequences) ending with each input element. 
// Subsequent IS are constructed from previously as we go up the input to make it a dynamic programming problem
void DynamicProgrammingLIS(vector<int> vect, int inputLength)
{
	// Vector of vectors for subsequences of length of input
	vector<vector<int> > vectors(inputLength);

	// Special case: IS ending in first element is simply first element
	vectors[0].push_back(vect[0]);

	// Nested loop starting with the second element of our input (since the first element was a special case)
	for (int i = 1; i < inputLength; i++)
	{
		// Check IS ending with current i element
		for (int j = 0; j < i; j++)
		{
			// Is this an IS?
			if (vect[i] > vect[j])
			{
				// Is this an optimal IS for this stage? (based on previous)
				if (vectors[i].size() < vectors[j].size() + 1)
				{
					vectors[i] = vectors[j];
				}
			}
		}
		// Add the longest at this point to the list
		vectors[i].push_back(vect[i]);
	}

	// Find the largest size IS and this is the LIS
	vector<int> LIS = vectors[0];
	for (vector<int> largest : vectors)
	{
		if (largest.size() > LIS.size())
		{
			LIS = largest;
		}
	}

	// Print length of LIS 
	cout << "*****LIS Length****\n";
	cout << LIS.size() << "\n";

	// Print values of LIS 
	cout << "*****LIS Values****\n";
	for (int x : LIS)
		cout << x << " ";
	cout << "\n";
}

int main()
{
	// A vector to hold input
	vector<int> numbers;

	// Input file stream from peak.txt resource file
	ifstream in("incseq.txt", ios::in);

	// Push input file stream to populate vector
	int number;
	while (in >> number)
	{
		numbers.push_back(number);
	}

	// Close the file stream
	in.close();

	// Vector length, used several times below
	int length = numbers.size();

	// Print input vector
	cout << "*****Input Vector****\n";
	for (int i = 0; i < length; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << "\n";

	// Find and print length and values of LIS
	DynamicProgrammingLIS(numbers, length);

	return 0;
}
