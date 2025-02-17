#include <iostream>
#include <set>
using namespace std;

const int MAX_SIZE = 20;  // максимальний розмір матриці

// ====================== Завдання 1: Matrix37 ======================
// Функція введення квадратної матриці для завдання 1
void getMatrix(int matrix[MAX_SIZE][MAX_SIZE], int &rows, int &cols) {
    do {
        cout << "Enter number of rows (2-20): ";
        cin >> rows;
        cout << "Enter number of columns (must equal rows, 2-20): ";
        cin >> cols;
        if (rows != cols) {
            cout << "Error: Matrix must be square. Try again." << endl;
        }
    } while (rows < 2 || rows > MAX_SIZE || cols < 2 || cols > MAX_SIZE || rows != cols);
    
    cout << "Enter matrix elements (each from 0 to 100):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            do {
                cin >> matrix[i][j];
                if (matrix[i][j] < 0 || matrix[i][j] > 100) {
                    cout << "Element must be between 0 and 100. Try again: ";
                }
            } while (matrix[i][j] < 0 || matrix[i][j] > 100);
        }
    }
}

// Функція для підрахунку кількості стовпців, схожих на останній (порівнюємо множини елементів)
int countSimilarColumns(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    set<int> lastCol;
    for (int i = 0; i < rows; i++) {
        lastCol.insert(matrix[i][cols - 1]);
    }
    
    int count = 0;
    // Перебираємо всі стовпці, окрім останнього, і порівнюємо множини елементів
    for (int j = 0; j < cols - 1; j++) {
        set<int> currentCol;
        for (int i = 0; i < rows; i++) {
            currentCol.insert(matrix[i][j]);
        }
        if (currentCol == lastCol) {
            count++;
        }
    }
    return count;
}

// Функція для виведення матриці
void showMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    cout << "\nMatrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Функція завдання 1 (Matrix37) без параметрів
void task1() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;
    getMatrix(matrix, rows, cols);
    showMatrix(matrix, rows, cols);
    int similarCount = countSimilarColumns(matrix, rows, cols);
    cout << "\nNumber of columns similar to the last column: " << similarCount << endl;
}

// ====================== Завдання 2: Matrix76 ======================
// Функція введення квадратної матриці для завдання 2
void getSquareMatrix(int matrix[MAX_SIZE][MAX_SIZE], int &size) {
    do {
        cout << "Enter size of square matrix (2-20): ";
        cin >> size;
        if (size < 2 || size > MAX_SIZE) {
            cout << "Size must be between 2 and 20. Try again." << endl;
        }
    } while (size < 2 || size > MAX_SIZE);
    
    cout << "Enter matrix elements (each from 0 to 100):" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            do {
                cin >> matrix[i][j];
                if (matrix[i][j] < 0 || matrix[i][j] > 100) {
                    cout << "Element must be between 0 and 100. Try again: ";
                }
            } while (matrix[i][j] < 0 || matrix[i][j] > 100);
        }
    }
}

// Функція обнулення елементів, що знаходяться нижче головної діагоналі (i > j)
// Реалізовано без використання умовного оператора, шляхом коректного вибору діапазонів циклів.
void zeroBelowDiagonal(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) { // j < i гарантує, що оперуємо з елементами нижче головної діагоналі
            matrix[i][j] = 0;
        }
    }
}

// Функція завдання 2 (Matrix76) без параметрів
void task2() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int size;
    getSquareMatrix(matrix, size);
    zeroBelowDiagonal(matrix, size);
    cout << "\nModified Matrix (elements below the main diagonal zeroed):" << endl;
    showMatrix(matrix, size, size);
}

// ====================== Головна функція ======================
int main() {
    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Task1: Matrix37" << endl;
        cout << "2. Task2: Matrix76" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        // Перевірка введення вибору
        if (choice == 1) {
            task1();
        } else if (choice == 2) {
            task2();
        } else if (choice != 0) {
            cout << "Invalid choice. Please enter 1, 2, or 0." << endl;
        }
    } while (choice != 0);
    
    return 0;
}
