#include <iostream>
#include <fstream>

using namespace std;
static const int maximum = 100;
int matrix_A[maximum][maximum];
int matrix_B[maximum][maximum];
int real_size;
void read_matrix();
void print_matrix();
void matrix_sum();
void matrix_product();

void matrix_difference();

int main() {
	read_matrix();
	print_matrix();
	matrix_sum();
	matrix_product();
	matrix_difference();

}
void read_matrix() {
	int size;
	ifstream matrix_file;
	matrix_file.open("matrix_input.txt");
	matrix_file >> size;
	real_size = size;
	for (int i = 0; i < size; i++) {
		for (int j=0; j < size; j++) {
			matrix_file >> matrix_A[i][j];
		}
	}
	for (int i = 0; i <= size; i++) {
		for (int j=0; j < size; j++) {
			matrix_file >> matrix_B[i][j];
		}

	}
	matrix_file.close();
}
void print_matrix() {
	cout << "Matrix A: " << endl;
	for (int i = 0; i < real_size; i++) {
		for (int j = 0; j < real_size; j++) {
			cout << matrix_A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Matrix B: " << endl;
	for (int i = 0; i < real_size; i++) {
		for (int j = 0; j < real_size; j++) {
			cout << matrix_B[i][j] << " ";
		}
		cout << endl;
	}

}
void matrix_sum() {
	cout << endl;
	cout << "Matrix Sum (A+B): " << endl;
	int matrix_sum[real_size][real_size];
	for (int i = 0; i < real_size; i++) {
		for (int j = 0; j < real_size; j++) {
			matrix_sum[i][j] = (matrix_A[i][j] + matrix_B[i][j]);
		}
	}
	for (int i = 0; i < real_size; i++) {
		for (int j = 0; j < real_size; j++) {
			cout << matrix_sum[i][j] << " ";
		}
		cout << endl;
	}

}

void matrix_product() {
	cout << endl;
	cout << "Matrix Product (A*B): " << endl;
	int matrix_product[real_size][real_size];
	for (int i = 0; i < real_size; i++) {
		for (int j = 0; j < real_size; j++) {
			int sum = 0;
			for (int k = 0; k < real_size; k++) {
				int one_product;
				one_product = (matrix_A[i][k] * matrix_B[k][j]);
				sum +=one_product;
			}
		matrix_product[i][j] = sum;
		}
	}
	for (int i = 0; i < real_size; i++) {
		for (int j = 0; j < real_size; j++) {
			cout << matrix_product[i][j] << " ";
		}
		cout << endl;
	}

}


void matrix_difference() {
	cout << endl;
	cout << "Matrix Difference (A-B): " << endl;
	int matrix_difference[real_size][real_size];
	for (int i = 0; i < real_size; i++) {
		for (int j = 0; j < real_size; j++) {
			matrix_difference[i][j] = (matrix_A[i][j] - matrix_B[i][j]);
		}
	}
	for (int i = 0; i < real_size; i++) {
		for (int j = 0; j < real_size; j++) {
			cout << matrix_difference[i][j] << " ";
		}
		cout << endl;
	}



}
