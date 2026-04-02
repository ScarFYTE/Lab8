#include <iostream>

using namespace std;

template <typename T>
class SparseMatrix {
    int rows;
    int cols;
    T* data;
    public:
    SparseMatrix(int r, int c) {
        rows = r;
        cols = c;
        data = new T[rows * cols]();
    }

    ~SparseMatrix() {
        delete[] data;
    }
    void input() {
        cout << "Enter the elements of the matrix (row-wise):" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i * cols + j];
            }
        }
    }

    SparseMatrix Add(SparseMatrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrices must have the same dimensions for addition.");
        }
        SparseMatrix result(rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    SparseMatrix Multiply(SparseMatrix& other) {
        if (cols != other.rows) {
            throw invalid_argument("Number of columns of the first matrix must equal the number of rows of the second matrix for multiplication.");
        }
        SparseMatrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                T sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum += data[i * cols + k] * other.data[k * other.cols + j];
                }
                result.data[i * other.cols + j] = sum;
            }
        }
        return result;
    }
    SparseMatrix subtract(SparseMatrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrices must have the same dimensions for subtraction.");
        }
        SparseMatrix result(rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i * cols + j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    SparseMatrix<int> mat1(3, 3);
    SparseMatrix<int> mat2(3, 3);
    mat1.input();
    mat2.input();

    SparseMatrix<int> mat3 = mat1.Add(mat2);
    SparseMatrix<int> mat4 = mat1.Multiply(mat2);
    SparseMatrix<int> mat5 = mat1.subtract(mat2);
    cout << "Matrix 1:" << endl;
    mat1.display();
    cout << "Matrix 2:" << endl;
    mat2.display();
    cout << "Matrix 1 + Matrix 2:" << endl;
    mat3.display();
    cout << "Matrix 1 * Matrix 2:" << endl;
    mat4.display();
    cout << "Matrix 1 - Matrix 2:" << endl;
    mat5.display();
    return 0;

}