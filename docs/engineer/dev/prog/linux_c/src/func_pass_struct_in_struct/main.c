// https://www.geeksforgeeks.org/structure-pointer/

// C program to illustrate the
// structure pointer

#include <stdio.h>

// Structure declaration for
// vertices
struct point {
	int x;
	int y;
};

// Strcuture declaration for
// rectangle
struct rect {

	// An object left is declared
	// with 'point'
	struct point left;

	// An object right is declared
	// with 'point'
	struct point right;
};

// Function to calculate area of
// the given rectangle
void areaOfRectangle(struct rect r)
{
	// Find the area of the rectangle
	// using variables of point
	// structure where variables of
	// point structure is accessed
	// by left and right objects
	int area
		= (r.right.x - r.left.x)
		* (r.right.y - r.left.y);

	// Print the area
	printf("%d", area);
}

// Driver Code
int main()
{
	// Initialize variable 'r'
	// with vertices of rectangle
	struct rect r = { { 2, 3 }, { 5, 2 } };

	// Function Call
	areaOfRectangle(r);

	return 0;
}
