#include <cmath>
#include <iostream>
#include <vector>
#include<iomanip>

const double EPS = 1e-6;
const int PRECISION = 20;

typedef std::vector<double> Column;
typedef std::vector<double> Row;
typedef std::vector<Row> Matrix;

using namespace std;

struct Equation
{
    Equation(const Matrix &a, const Column &b) : a(a),
                                                 b(b)
    {
    }

    Matrix a;
    Column b;
};

struct Position
{
    Position(int column, int row) : column(column),
                                    row(row)
    {
    }

    int column;
    int row;
};


Equation ReadEquation()
{
    int size;
    std::cin >> size;
    Matrix a(size, std::vector<double>(size, 0.0));
    Column b(size, 0.0);
    for (int row = 0; row < size; ++row)
    {
        for (int column = 0; column < size; ++column)
            std::cin >> a[row][column];
        std::cin >> b[row];
    }
    return Equation(a, b);
}

Position SelectPivotElement(
    const Matrix &a,
    std::vector<bool> &used_rows,
    std::vector<bool> &used_columns)
{
    // This algorithm selects the first free element.
    // You'll need to improve it to pass the problem.
    Position pivot_element(0, 0);
    while (used_rows[pivot_element.row])
        ++pivot_element.row;
    while (used_columns[pivot_element.column])
        ++pivot_element.column;

    double max = 0;
    for(int from = pivot_element.row, size = a.size(); from < size; from ++){
        if(fabs(a[from][pivot_element.column]) > fabs(max)){
            max = fabs(a[from][pivot_element.column]);
            pivot_element.row = from;
        }
    }
    return pivot_element;
}

void SwapLines(Matrix &a, Column &b, std::vector<bool> &used_rows, Position &pivot_element)
{
    std::swap(a[pivot_element.column], a[pivot_element.row]);
    std::swap(b[pivot_element.column], b[pivot_element.row]);
    std::swap(used_rows[pivot_element.column], used_rows[pivot_element.row]);
    pivot_element.row = pivot_element.column;
}

void scale_pivot(Matrix &a, Column &b, const Position &pivot_element){
    const double div = a[pivot_element.row][pivot_element.column];
    const int size = a.size();

    for(int j = pivot_element.column; j < size; j ++){
        a[pivot_element.row][j] /= div;
    }

    b[pivot_element.row] /= div;
}

void ProcessPivotElement(Matrix &a, Column &b, const Position &pivot_element)
{
    const int size = a.size();
    double multiple{0.0};

    scale_pivot(a, b, pivot_element);

    for(int i = pivot_element.row + 1; i < size; i ++){
        multiple = a[i][pivot_element.column];
        for(int j = pivot_element.column; j < size; j ++){
            a[i][j] -= (a[pivot_element.row][j] * multiple);
        }
        b[i] -= b[pivot_element.row] * multiple;
    }
}

void MarkPivotElementUsed(const Position &pivot_element, std::vector<bool> &used_rows, std::vector<bool> &used_columns)
{
    used_rows[pivot_element.row] = true;
    used_columns[pivot_element.column] = true;
}

Column SolveEquation(Equation equation)
{
    Matrix &a = equation.a;
    Column &b = equation.b;
    int size = a.size();

    std::vector<bool> used_columns(size, false);
    std::vector<bool> used_rows(size, false);
    for (int step = 0; step < size; ++step)
    {
        Position pivot_element = SelectPivotElement(a, used_rows, used_columns);
        SwapLines(a, b, used_rows, pivot_element);
        ProcessPivotElement(a, b, pivot_element);
        MarkPivotElementUsed(pivot_element, used_rows, used_columns);
    }

    for(int i = size - 1; i >= 0; i --){
        double v = b[i];
        for(int j = 0; j != i; j ++){
            b[j] -= a[j][i] * v;
            a[j][i] = 0;
        }
    }

    return b;
}

void PrintColumn(const Column &column)
{
    int size = column.size();
    std::cout.precision(PRECISION);
    for (int row = 0; row < size; ++row)
        std::cout << std::fixed << std::setprecision(6) << column[row] << std::endl;
}

int main()
{
    Equation equation = ReadEquation();

    if(equation.a.size()){
        Column solution = SolveEquation(equation);
        PrintColumn(solution);
    }

    return 0;
}
