// перегрузка операторов: «Дробные числа».
#include <iostream>
using namespace std;

class ToPiNumber {
    private:
        double nmb;

    public:
        ToPiNumber(double num) {
            nmb = 3.1415926;
        }
};

class DoubleNumber {
    private:
        double number;

    public:
        DoubleNumber(double num) {
            number = num;
        }

        DoubleNumber& operator = (DoubleNumber nextNum) { // overdrive "=" operator (num is object of DoubleNumber class)
            number = nextNum.number;
            return *this;
        }

        void operator ++ (int) {    // overdrive increment operator
            number++; 
        } 

        DoubleNumber& operator - (DoubleNumber nextNum) {       // overdrive "-" operator 
            number = number - nextNum.number;
            return *this;
        }

        bool operator> (DoubleNumber& rightNum) {     // overdrive ">" operator 
            return number > rightNum.number;
        }

        void operator () (double num) {
            number = num;
        }

        friend void operator -- (DoubleNumber& num, int);
        friend DoubleNumber operator + (DoubleNumber leftNum, DoubleNumber rightNum);
        friend ostream& operator << (std::ostream& out, DoubleNumber num);
        friend int ToInt(DoubleNumber num);

        ToPiNumber ToPi() {
            return ToPiNumber(number);
        }
          
};

void operator -- (DoubleNumber& num, int) { 
    num.number--; 
}

DoubleNumber operator + (DoubleNumber leftNum, DoubleNumber rightNum) {       // overdrive "-" operator 
    return DoubleNumber(leftNum.number +rightNum.number);
}

ostream& operator << (std::ostream& out, DoubleNumber num) {
    return out << num.number;
}

int ToInt(DoubleNumber num) {
    return int(num.number);
}

string BoolToString(bool par) {
    return par ? "True" : "False";
}

int main()
{
    DoubleNumber one(19.12);
    DoubleNumber two(7.978);
    cout << "One = " << one << endl;
    cout << "Two = " << two << endl;

    cout << "Two to int = " << ToInt(two) << endl;

    one = one + two;
    cout << "One + Two = " << one << endl;

    two--;
    cout << "Two decrement = " << two << endl;

    bool isTrue = two > one;
    cout << "Is One bigger than Two? " << BoolToString(isTrue) << endl;

    ToPiNumber pi = one.ToPi();;
    printf("One to pi = %f", pi);

    return 0;
}