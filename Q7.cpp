#include<iostream>
#include<vector>
using namespace std;

class Matrix {
    public:
        int rows;
        int cols;
        vector<int> data;
        Matrix(int r, int c) : rows(r), cols(c), data(r * c) {}
        ~Matrix() = default;

        void input() {
            cout << "Enter the elements of the matrix:" << endl;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    cin >> data[i * cols + j];
                }
            }
        }

        void display() {
            cout << "Matrix:" << endl;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    cout << data[i * cols + j] << " ";
                }
                cout << endl;
            }
        }




        struct RowProxy {
            int* rowPtr;
            int maxcols;
            int& operator[](int col) {
                if(col < 0 || col >= maxcols) {
                    throw out_of_range("Column index out of range");
                }
                return rowPtr[col];
            }
        };

        struct constProxy {
            const int* rowPtr;
            int maxcols;
            const int& operator[](int col) const {
                if(col < 0 || col >= maxcols) {
                    throw out_of_range("Column index out of range");
                }
                return rowPtr[col];
            }
        };

        RowProxy operator[](int row) {
            if(row < 0 || row >= rows) {
                throw out_of_range("Row index out of range");
            }

            return RowProxy{ &data[row * cols],cols };
        }

        constProxy operator[](int row) const {
            if(row < 0 || row >= rows) {
                throw out_of_range("Row index out of range");
            }

            return constProxy{ &data[row * cols],cols };
        }
    };

    int main() {
    try {
        Matrix m(3, 3);
        m.input();

        // 1. Mutable access (Writing)
        m[1][1] = 100; 

        // 2. Const access (Reading)
        const Matrix& ref = m;
        cout << "Value at [1][1]: " << ref[1][1] << endl;

        cout << m[5][0]; // This will throw out_of_range
    } 
    catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}