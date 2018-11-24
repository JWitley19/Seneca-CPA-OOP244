/**********************************************************
 * Name: Jordan Witley
 * Student ID: 142433176
 * Seneca email: jwitley@myseneca.ca
 * Date of Completion: 20/11/2018
 **********************************************************/

#include <iostream>
#include <cstring>

namespace sict
{
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;
	const int COLUMN_WIDTH = 15;

	int min(const int* data, int n);

	// max returns the largest item in data
	// initializes to the first element in the array
	// loops through each element of the array
	// if the current element of the array is bigger than 'max'
	// move the current element to the beginning of the array
	// returns
	//

	template<typename T>
	T max(const T* data, int n)
	{
		// initializes a max element
		T max = data[0];

		for (int i = 1; i < n; i++)
		{
			if (max < data[i])
			{
				max = data[i];
			}
		}
		return max;
	}

	// min returns the smallest item in data
	// initializes the template element to the first element of the array
	// loops through the array
	// if the template element is bigger than the current element
	// 'min' will get the value of the smaller valued element
	// returns the template element
	//

	template <typename T>
	T min(const T* data, int n)
	{
		//initializes a min element
		T min = data[0];

		for (int i = 1; i < n; i++)
		{
			if (min > data[i])
			{
				min = data[i];
			}
		}
		return min;
	}

	// sum returns the sum of n items in data
	// initializes the sum template variable
	// loop through the elements
	// keeps adding each array elements
	// 

	template<typename T>
	T sum(const T* data, int n)
	{
		T sum = 0;

		for (int i = 0; i < n; ++i)
		{
			sum += data[i];
		}
		return sum;
	}

	// average returns the average of n items in data
	// sum of data / n
	//

	template<typename T>
	double average(const T* data, int n)
	{
		return sum(data, n) / n;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//

	template<typename T>
	bool read(std::istream& input, T* data, int n)
	{
		for (int i = 0; i < n; ++i)
		{
			// ignores 1 character by default
			input.ignore();
			// takes the input into the current element of the array
			input >> data[i];
			// if the input process fails, false is returned 
			if (input.fail())
			{
				return false;
			}
		}
		return true;
	}

	// display inserts n items of data into std::cout
	// displays name right-justified in a field of 20 
	// and each dataa element in a field of 15
	//

	template<typename T>
	void display(const char* name, const T* data, int n)
	{
		//sets the width and justify to the right
		std::cout.width(20);
		std::cout << std::right << name;

		for (int i = 0; i < n; i++)
		{
			std::cout.width(15);
			std::cout << data[i];
		}
		std::cout << "\n";
	}

	template<typename T>
	T readRow(std::istream& input, const char* name, T* data, int n)
	{
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok)
		{
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0)
			{
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)

			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;


	}


	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}


