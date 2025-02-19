#include <iostream>
#include <set>

using namespace std;

const int MAX_SIZE = 20;  // Максимальний розмір матриці

// ====================== Завдання 1: Matrix37 ======================
// Функція введення квадратної матриці для завдання 1
void getMatrix(int matrix[MAX_SIZE][MAX_SIZE], int &rows, int &cols) {
    // Користувач вводить розмірність матриці, перевіряємо, що вона квадратна
    do {
        cout << "Enter number of rows (2-20): ";
        cin >> rows;
        cout << "Enter number of columns (must equal rows, 2-20): ";
        cin >> cols;
        if (rows != cols) {
            cout << "Error: Matrix must be square. Try again." << endl;
        }
    } while (rows < 2 || rows > MAX_SIZE || cols < 2 || cols > MAX_SIZE || rows != cols);
    
    // Введення елементів матриці з перевіркою на допустимий діапазон (0-100)
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
    set<int> lastCol; // Множина для зберігання унікальних елементів останнього стовпця
    
    // Заповнюємо множину елементами останнього стовпця
    for (int i = 0; i < rows; i++) {
        lastCol.insert(matrix[i][cols - 1]);
    }
    
    int count = 0;
    // Перебираємо всі стовпці (крім останнього) та порівнюємо множини елементів
    for (int j = 0; j < cols - 1; j++) {
        set<int> currentCol;
        for (int i = 0; i < rows; i++) {
            currentCol.insert(matrix[i][j]); // Додаємо елементи стовпця в множину
        }
        if (currentCol == lastCol) { // Порівнюємо множини
            count++;
        }
    }
    return count;
}

// Функція для виведення матриці на екран
void showMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    cout << "\\nMatrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\\t";
        }
        cout << endl;
    }
}

// Функція завдання 1 (Matrix37) без параметрів
void task1() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;
    getMatrix(matrix, rows, cols); // Введення матриці
    showMatrix(matrix, rows, cols); // Виведення початкової матриці
    int similarCount = countSimilarColumns(matrix, rows, cols); // Підрахунок схожих стовпців
    cout << "\\nNumber of columns similar to the last column: " << similarCount << endl;
}

// ====================== Завдання 2: Matrix76 ======================
// Функція введення квадратної матриці для завдання 2
void getSquareMatrix(int matrix[MAX_SIZE][MAX_SIZE], int &size) {
    // Користувач вводить розмірність квадратної матриці
    do {
        cout << "Enter size of square matrix (2-20): ";
        cin >> size;
        if (size < 2 || size > MAX_SIZE) {
            cout << "Size must be between 2 and 20. Try again." << endl;
        }
    } while (size < 2 || size > MAX_SIZE);
    
    // Введення елементів матриці з перевіркою на діапазон значень
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
void zeroBelowDiagonal(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    // Проходимося по матриці, змінюючи значення елементів нижче головної діагоналі на 0
    for (int i = 1; i < size; i++) { // Починаємо з другого рядка
        for (int j = 0; j < i; j++) { // j < i - це всі елементи нижче головної діагоналі
            matrix[i][j] = 0;
        }
    }
}

// Функція завдання 2 (Matrix76) без параметрів
void task2() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int size;
    getSquareMatrix(matrix, size); // Введення матриці
    zeroBelowDiagonal(matrix, size); // Обнулення нижньої трикутної частини матриці
    cout << "\\nModified Matrix (elements below the main diagonal zeroed):" << endl;
    showMatrix(matrix, size, size); // Виведення зміненої матриці
}

// ====================== Головна функція ======================
int main() {
    int choice; // Змінна для збереження вибору користувача
    do {
        // Виведення меню
        cout << "\\nMenu:" << endl;
        cout << "1. Task1: Matrix37" << endl;
        cout << "2. Task2: Matrix76" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        // Обробка вибору користувача
        if (choice == 1) {
            task1(); // Виконати перше завдання
        } else if (choice == 2) {
            task2(); // Виконати друге завдання
        } else if (choice != 0) {
            cout << "Invalid choice. Please enter 1, 2, or 0." << endl;
        }
    } while (choice != 0); //
}

