#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class LeastSquare {
    public:
        LeastSquare(const vector<double> &x, const vector<double> &y) : a(0), b(0) {
            double t1 = 0, t2 = 0, t3 = 0, t4 = 0;
            for (int i = 0; i < x.size(); ++i) {
                t1 += x[i] * y[i];
                t2 += x[i];
                t3 += y[i];
                t4 += x[i] * x[i];
            }
            int sz = x.size();
            a = (sz * t1 - t2 * t3) / (sz * t4 - t2 * t2);
            b = (t4 * t3 - t2 * t1) / (sz * t4 - t2 * t2);
        }

        double getY(const double x) const {
            return a * x + b;
        }

        void print() const {
            cout << "y = " << a << " * x + " << b << endl; 
        }
    private:
        double a, b;
};

int main(int argc, const char *argv[])
{
    vector<double> x, y;
    ifstream in(argv[1]);
    int a;
    for (int i = 0; i < 10; ++i) {
        cin >> a;
        x.push_back(a);
        y.push_back(a * 125 + 3);
    }
    int sz = x.size();

    LeastSquare ls(x, y);
    ls.print();

    double x0;
    cout << "Input x: ";
    while (cin >> x0) {
        cout << "y = " << ls.getY(x0) << endl;
        cout << "Input x: ";
    }

    return 0;
}
