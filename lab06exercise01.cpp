#include <iostream>
#include <iomanip> // This is to help set the width of the columns so they are aligned.
#include <fstream> // This is to include the functionality for opening a file.

using namespace std;
static const int maximum = 100; // This specifies the maximum the matrix can be.
int matrix_A[maximum][maximum]; // Initializes the first N*N matrix with this maximum number in row and column.
int matrix_B[maximum][maximum]; // Initializes the second N*N matrix with this maximum number in row and column.
int real_size; // This will store the actual size of the Matrix that is read into.
void read_matrix(); // Functional prototype of read_matrix.
void print_matrix(int matrix_A[maximum][maximum]); // Functional prototype of print_matrix.
void matrix_sum(); // Functional prototype of matrix_sum.
void matrix_product(); // Functional prototype of matrix_product.

void matrix_difference(); // Functional prototype of matrix_difference.

int main() {
	read_matrix(); // Calls read_matrix to store the input file's values into the two matrices.
  cout << "Matrix A: " << endl;
	print_matrix(matrix_A); // Calls to the function that prints the contents of the stored two matrices.
  cout << "Matrix B: " << endl;
  print_matrix(matrix_B); // Calls to the function that prints the contents of the stored two matrices.
	matrix_sum(); // Calls to the function that prints the sum of two matrices.
	matrix_product(); // Calls to the function that prints the product of two matrices.
	matrix_difference(); // Calls to the function that prints the difference of two matrices.

}
void read_matrix() {
	int size; // This is to store what the actual size of the matrix that we are reading into.
	ifstream matrix_file; // Calls the read into functionality.
	matrix_file.open("matrix_input.txt"); // Opens the file and stores into matrix_file.
	matrix_file >> size; // Makes the first line which states the size of matrix be stored into size variable.
	real_size = size; // Makes the global variable of real_size become size specified in input file.
	for (int i = 0; i < size; i++) { // Iterates through the rows of first matrix with the specified size.
		for (int j=0; j < size; j++) { // Iterates through the cols of first matrix with the specified size.
			matrix_file >> matrix_A[i][j]; // Makes each entry that is read into the file be stored into matrix_A at the row and col.
		}
	}
	for (int i = 0; i <= size; i++) { // Iterates through the rows of second matrix with the specified size.
		for (int j=0; j < size; j++) { // Iterates through the cols of second matrix with the specified size.
			matrix_file >> matrix_B[i][j]; // Makes each entry that is read into the file be stored into matrix_B at the row and col.
		}

	}
	matrix_file.close(); // Closes the file.
}
void print_matrix(int matrix_A[maximum][maximum]) {
	for (int i = 0; i < real_size; i++) { // Goes through the rows of matrix_A and stops at the size given.
		for (int j = 0; j < real_size; j++) { // Goes through the cols of matrix_A and stops at the size given.
			cout << setw(3) << matrix_A[i][j] << setw(3) << " "; // Prints the value at that row and col. setw alligns columns.
		}
		cout << endl; // Space between rows.
	}
	cout << endl;

}
void matrix_sum() {
	cout << endl;
	cout << "Matrix Sum (A+B): " << endl;
	int matrix_sum[maximum][maximum]; // Initialiezs a matrix array that is of the max size given.
	for (int i = 0; i < real_size; i++) { // Goes through the rows of the matrix.
		for (int j = 0; j < real_size; j++) { // Goes through the cols of the matrix. (Both Matrix A and B have same size.)
			matrix_sum[i][j] = (matrix_A[i][j] + matrix_B[i][j]); // Adds the entries of A and B at that row and col and inputs it into the row and col of new matrix.
		}
	}
  // Prints matrix.
	print_matrix(matrix_sum);

}

void matrix_product() {
	cout << endl;
	cout << "Matrix Product (A*B): " << endl;
	int matrix_product[maximum][maximum]; // Initialiezs a matrix array that is of the max size given.
	for (int i = 0; i < real_size; i++) {
		for (int j = 0; j < real_size; j++) {
			int sum = 0; // Matrix Product is the the dot product for that specific row and col.
			for (int k = 0; k < real_size; k++) { // Must iterate a third time, to know which row and col needs to be dot producted.
				int one_product;
				one_product = (matrix_A[i][k] * matrix_B[k][j]); // Finds the product of the two numbers: matrix_A at its specific row and the value it is on (specified by k).
        // The second number is from matrix_B which is the value it is on (specified by k) and its col (specified by j).
				sum +=one_product; // Sums the product of all the numbers given for that row and col.
			}
		matrix_product[i][j] = sum; // The product is this sum for the specific row and col.
		}
	}
	print_matrix(matrix_product); // Print matrix.

}


void matrix_difference() {
	cout << endl;
	cout << "Matrix Difference (A-B): " << endl;
	int matrix_difference[maximum][maximum]; // Initializes a matrix array that is of the max size given.
	for (int i = 0; i < real_size; i++) { // Goes through rows until real size.
		for (int j = 0; j < real_size; j++) { // Goes through cols until real size.
			matrix_difference[i][j] = (matrix_A[i][j] - matrix_B[i][j]); // Finds the difference of the two entries of the two matrices at this row and col and stores into new matrix.
		}
	}
	print_matrix(matrix_difference); // Print matrix.



}
