#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

/*
   Giải phương trình bậc 4 dạng: a*x^4 + b*x^2 + c = 0
   (dạng thu gọn thường gặp trong môn học kiểm thử phần mềm)
*/
int solveQuartic(double a, double b, double c, double x[]) {
    if (a == 0 && b == 0 && c == 0) {
        return -1; // vô số nghiệm
    }
    if (a == 0 && b == 0) {
        return 0; // vô nghiệm
    }
    if (a == 0) { // b*x^2 + c = 0
        double y = -c / b;
        if (y < 0) return 0;
        x[0] = sqrt(y);
        x[1] = -sqrt(y);
        return 2;
    }

    double delta = b*b - 4*a*c;
    if (delta < 0) return 0;

    double y1 = (-b + sqrt(delta)) / (2*a);
    double y2 = (-b - sqrt(delta)) / (2*a);

    int count = 0;
    if (y1 >= 0) {
        x[count++] = sqrt(y1);
        x[count++] = -sqrt(y1);
    }
    if (y2 >= 0 && y2 != y1) {
        x[count++] = sqrt(y2);
        x[count++] = -sqrt(y2);
    }
    return count;
}

// ================== TEST CASES ==================
void test_cases() {
    double x[4];
    int n;

    // Test 1: Vô số nghiệm
    n = solveQuartic(0,0,0,x);
    assert(n == -1);

    // Test 2: Vô nghiệm
    n = solveQuartic(0,0,5,x);
    assert(n == 0);

    // Test 3: bậc 2 rút gọn: x^2 = 4 => nghiệm ±2
    n = solveQuartic(0,1,-4,x);
    assert(n == 2);

    // Test 4: bậc 4 có nghiệm: x^4 - 5x^2 + 4 = 0
    n = solveQuartic(1,-5,4,x);
    assert(n == 4);

    // Test 5: vô nghiệm do delta < 0
    n = solveQuartic(1,0,1,x);
    assert(n == 0);

    cout << "✅ All test cases passed!" << endl;
}

int main() {
    test_cases();
    return 0;
}
