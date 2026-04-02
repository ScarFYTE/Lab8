#include <iostream>
#include <vector>


using namespace std;
template <typename T , typename BinaryOperation>

vector<vector<T>> Matrix_Operation (const vector<vector<T>>& A,const vector<vector<T>>& B, size_t rows , size_t cols, BinaryOperation op) {
    vector<vector<T>> result(rows, vector<T>(cols));
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result[i][j] = op(A[i][j], B[i][j]);
        }
    }
    return result;
}

void displayMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};
    cout<<"Matrix A:" << endl;
    displayMatrix(A);
    cout<<"Matrix B:" << endl;
    displayMatrix(B);


    auto add_op = [](int a, int b) { return a + b; };
    auto sub_op = [](int a, int b) { return a - b; };
    auto mul_op = [](int a, int b) { return a * b; };

    vector<vector<int>> sum = Matrix_Operation(A, B, 2, 2, add_op);
    vector<vector<int>> diff = Matrix_Operation(A, B, 2, 2, sub_op);
    vector<vector<int>> prod = Matrix_Operation(A, B, 2, 2, mul_op);

    cout << "Sum of A and B:" << endl;
    displayMatrix(sum);
    cout << "Difference of A and B:" << endl;
    displayMatrix(diff);
    cout << "Product of A and B:" << endl;
    displayMatrix(prod);
    //Note that the product here is element-wise multiplication, not matrix multiplication.

    return 0;
}