#include <iostream>
#include <cstring>
using namespace std;
class Polynomial 
{
public:
    // default constructor
    Polynomial() : degree(0), coeff(nullptr) {}

    // parameterized constructor
    Polynomial(double* coefficients, int n) : degree(n-1), coeff(new double[n]) {
        std::memcpy(coeff, coefficients, n * sizeof(double));
    }

    // copy constructor
    Polynomial(const Polynomial& other) : degree(other.degree), coeff(new double[other.degree+1]) {
        std::memcpy(coeff, other.coeff, (other.degree+1) * sizeof(double));
    }

    // destructor
    ~Polynomial() {
        delete[] coeff;
    }

    // assignment operator
    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            delete[] coeff;
            degree = other.degree;
            coeff = new double[degree+1];
            std::memcpy(coeff, other.coeff, (degree+1) * sizeof(double));
        }
        return *this;
    }

    // indexed access (l-value)
    double& operator[](int n) 
	{
        return coeff[n];
    }

    // indexed access (r-value)
    const double& operator[](int n) const 
	{
        return coeff[n];
    }

    // addition operator
    friend Polynomial operator+(const Polynomial& p1, const Polynomial& p2) {
        int maxDegree = std::max(p1.degree, p2.degree);
        Polynomial result;
        result.degree = maxDegree;
        result.coeff = new double[maxDegree+1];
        for (int i = 0; i <= maxDegree; i++) {
            result.coeff[i] = p1[i] + p2[i];
        }
        return result;
    }

    // subtraction operator
    friend Polynomial operator-(const Polynomial& p1, const Polynomial& p2) {
        int maxDegree = std::max(p1.degree, p2.degree);
        Polynomial result;
        result.degree = maxDegree;
        result.coeff = new double[maxDegree+1];
        for (int i = 0; i <= maxDegree; i++) {
            result.coeff[i] = p1[i] - p2[i];
        }
        return result;
    }

    // multiplication operator
    friend Polynomial operator*(const Polynomial& p1, const Polynomial& p2) {
        int maxDegree = p1.degree + p2.degree;
        Polynomial result;
        result.degree = maxDegree;
        result.coeff = new double[maxDegree+1];
        for (int i = 0; i <= maxDegree; i++) {
            result.coeff[i] = 0;
        }
        for (int i = 0; i <= p1.degree; i++) {
            for (int j = 0; j <= p2.degree; j++) {
                result.coeff[i+j] += p1[i] * p2[j];
            }
        }
        return result;
    }

  double evaluate(const Polynomial& p, double x) 
  {
    double result = 0.0;
    for (int i = p.getDegree(); i >= 0; i--) {
        result *= x;
        result += p[i];
    }
    return result;
}

    // getter for degree
    int getDegree() const 
	{
        return degree;
    }
    int mySize() const 
	{
		return degree + 1;
	}

private:
int degree; // degree of polynomial
double* coeff; // array of coefficients
};

int main() 
{
    Polynomial empty;
    double one[] = {1};
    Polynomial One(one, 1);
    double quad[] = {3, 2, 1};
    double cubic[] = {1, 2, 0, 3};
    Polynomial q(quad, 3); // q is 3 + 2*x + x*x
    Polynomial c(cubic, 4); // c is 1 + 2*x + 0*x*x + 3*x*x*x
    Polynomial p = q; // test copy constructor
    Polynomial r;
    r = q; // test operator=
    r = c;
    cout << "Polynomial q " << endl;
    {
        for(int i = 0; i < 3; i++)
            cout << "term with degree " << i << " has coefficient " << q[i] << endl;
    }
    cout << "Polynomial c " << endl;
    {
        for(int i = 0; i < 4; i++)
            cout << "term with degree " << i << " has coefficient " << c[i] << endl;
    }
    cout << "value of q(2) is " << q.evaluate(q, 2) << endl;
    cout << "value of p(2) is " << p.evaluate(p, 2) << endl;
    cout << "value of r(2) is " << r.evaluate(r, 2) << endl;
    cout << "value of c(2) is " << c.evaluate(c, 2) << endl;
    r = q + c;
    cout << "value of (q + c)(2) is " << r.evaluate(r, 2) << endl;
    r = q - c;
    cout << "value of (q - c)(2) is " << r.evaluate(r, 2) << endl;
    r = q * c;
    cout << "size of q*c is " << r.mySize() << endl;
    cout << "Polynomial r (= q*c) " << endl;
    for(int i = 0; i < r.mySize(); i++)
        cout << "term with degree " << i << " has coefficient " << r[i] << endl;
    cout << "value of (q * c)(2) is " << r.evaluate(r, 2) << endl;
    return 0;
}
