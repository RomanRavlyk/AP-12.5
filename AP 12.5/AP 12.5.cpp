#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void push(Elem*& top, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = top;
    top = tmp;
}

Info pop(Elem*& top)
{
    Elem* tmp = top->link;
    Info value = top->info;
    delete top;
    top = tmp;
    return value;
}

Info top(Elem* top)
{
    return top->info;
}

bool isEmpty(Elem* top)
{
    return top == nullptr;
}

bool isRightTriangle(int a, int b, int c) {
    return (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a);
}

double calculateIncircleRadius(int a, int b, int c) {
    double s = (a + b + c) / 2.0;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area / s;
}

void print(Elem* top)
{
    while (top != NULL)
    {
        cout << top->info << " ";
        top = top->link;
    }
}

string read(const string& filename) {
    ifstream fin(filename);
    string line;

    if (fin.is_open()) {
        string temp_line;
        while (fin >> temp_line) {
            line += temp_line + " ";
        }
        fin.close();
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }

    return line;
}

void processTriangles(Elem*& top) {
    while (top != nullptr && top->link != nullptr && top->link->link != nullptr) {
        int a = top->info;
        int b = top->link->info;
        int c = top->link->link->info;

        cout << "Triangle with sides: " << a << ", " << b << ", " << c << endl;

        if (isRightTriangle(a, b, c)) {
            cout << "Can form a right triangle." << endl;
            double radius = calculateIncircleRadius(a, b, c);
            cout << "Incircle radius: " << radius << endl;

            push(top, radius);
        }
        else {
            cout << "Cannot form a right triangle." << endl;
        }

        for (int i = 0; i < 3; ++i) {
            top = top->link;
            if (top == nullptr) break;
        }
    }
}

int main() {
    string filename = "numbers.txt";
    string line = read(filename);

    if (line.empty()) {
        return 1; // Вихід, якщо файл порожній або не вдається відкрити
    }

    Elem* top = nullptr;

    istringstream iss(line);
    int side;
    while (iss >> side) {
        push(top, side);
    }

    processTriangles(top);

    while (!isEmpty(top)) {
        pop(top);
    }

    return 0;
}