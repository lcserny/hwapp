#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::sort;

void averageProcess() {
    // ask for and read the student's name
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // ask for and read the midterm and final grades
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    // ask for the homework grades
    cout << "Enter all your homework grades, " // this works!, it concatenates automagically
            "followed by end-of-file: ";

    // the number and sum of grades read so far
    int count = 0;
    double sum = 0;

    // a variable into which to read
    double x;

    /* invariant:
     * we have read count grades so far, and
     * sum is the sum of the first count grades
     */
    while (cin >> x) {
        ++count;
        sum += x;
    }

    // write the result
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
         << setprecision(prec) << endl;
}

int medianProcess() {
    // ask for and read the student's name
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // ask for and read the midterm and final grades
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    // ask for the homework grades
    cout << "Enter all your homework grades, " // this works!, it concatenates automagically
            "followed by end-of-file: ";

    // revised version
    double x;
    vector<double> homework;

    /* invariant:
     * homework contains all the homework grades read so far
     */
    while (cin >> x) {
        homework.push_back(x);
    }

    typedef vector<double>::size_type vec_size;
    vec_size size = homework.size();

    if (size == 0) {
        cout << endl << "You must enter your grades. "
                        "Please try again." << endl;
        return 1;
    }

    sort(homework.begin(), homework.end());

    vec_size mid = size / 2;

    double median = size % 2 == 0
                    ? (homework[mid] + homework[mid - 1]) / 2
                    : homework[mid];

    // write the result
    streamsize prevPrecision = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * median
         << setprecision(prevPrecision) << endl;

    return 0;
}

int main() {
    // averageProcess();
    // return 0;
    return medianProcess();
}