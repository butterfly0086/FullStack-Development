// 7 Segment Display in C++ - Nishant Giri

#include<iostream>
using namespace std;
// lookupSegments[digit][segment] == 1 if the digit has the segment switched ON
int const lookupSegments[10][7] = 
{
	{1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 1},
	{1, 1, 1, 1, 0, 0, 1},
	{0, 1, 1, 0, 0, 1, 1},
	{1, 0, 1, 1, 0, 1, 1},
	{1, 0, 1, 1, 1, 1, 1},
	{1, 1, 1, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 0, 1, 1},
};
int main() 
{
	int segmentSize;
	cout<<"Enter Size of Each Segment: ";
	cin>>segmentSize;
	if(segmentSize < 1) 
	{
		cout<<"\nError: Segment Size Must Be >= 1\n";
		return -1;
	}
	int numberToPrint;
	cout<<"Enter Number to Print: ";
	cin>>numberToPrint;
	cout<<"\n";
	int numberOfDigits = 0;
	for(int i = numberToPrint; i > 0; i /= 10) 
	{
		numberOfDigits++;
	}
	int const numberOfRows = 2 * segmentSize + 3;
	int const numberOfColumns = numberOfDigits * (segmentSize + 3);
	// Contains the number representation as a 2D character array
	char buffer[numberOfRows][numberOfColumns];
	// Initialize buffer to all spaces
	for(int i = 0; i < numberOfRows; i++) 
	{
		for(int j = 0; j < numberOfColumns; j++) 
		{
			buffer[i][j] = ' ';		
		}
	}
	for(int i = 0; i < numberOfDigits; i++) 
	{
		int currentDigit = numberToPrint % 10;
		numberToPrint /= 10;
		int offset = (numberOfDigits - i - 1) * (segmentSize + 3);
		// Horizontal Segments
		// Segment A
		if(lookupSegments[currentDigit][0]) 
		{
			for(int j = 0; j < segmentSize; j++) 
			{
				buffer[0][offset + 1 + j] = '-';
			}
		}
		// Segment D
		if(lookupSegments[currentDigit][3]) 
		{
			for(int j = 0; j < segmentSize; j++) 
			{
				buffer[numberOfRows - 1][offset + 1 + j] = '-';
			}
		}
		// Segment G	
		if(lookupSegments[currentDigit][6]) 
		{
			for(int j = 0; j < segmentSize; j++) 
			{
				buffer[segmentSize + 1][offset + 1 + j] = '-';
			}
		}
		// Vertical Segments
		// Segment B
		if(lookupSegments[currentDigit][1]) 
		{
			for(int j = 0; j < segmentSize; j++) 
			{
				buffer[j + 1][offset + 1 + segmentSize] = '|';
			}
		}
		// Segment C
		if(lookupSegments[currentDigit][2]) 
		{
			for(int j = 0; j < segmentSize; j++) 
			{
				buffer[j + segmentSize + 2][offset + 1 + segmentSize] = '|';
			}
		}
		// Segment E
		if(lookupSegments[currentDigit][4]) 
		{
			for(int j = 0; j < segmentSize; j++) 
			{
				buffer[j + segmentSize + 2][offset] = '|';
			}
		}
		// Segment F
		if(lookupSegments[currentDigit][5]) 
		{
			for(int j = 0; j < segmentSize; j++) 
			{
				buffer[j + 1][offset] = '|';
			}
		}
	}
	// Display the buffer
	for(int i = 0; i < numberOfRows; i++) 
	{
		for(int j = 0; j < numberOfColumns; j++) 
		{
			cout<<buffer[i][j];
		}
		printf("\n");
	}
	return 0;
}