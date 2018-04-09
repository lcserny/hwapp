#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::sort;
using std::domain_error;
using std::istream;
using std::streamsize;
using std::setprecision;

double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double median(vector<double> vec) {
    typedef vector<double>::size_type vec_size;

    vec_size size = vec.size();
    if (size == 0) {
        throw domain_error("median of an empty vector");
    }

    sort(vec.begin(), vec.end());

    vec_size mid = size / 2;

    return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double grade(double midterm, double final, const vector<double>& hw) {
    if (hw.empty()) {
        throw domain_error("student has done no homework");
    }
    return grade(midterm, final, median(hw));
}

// read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        // get rid of previous contents
        hw.clear();

        // read homework grades
        double x;
        while (in >> x) {
            hw.push_back(x);
        }

        // clea the stream so that input will work for next student
        in.clear();
    }

    return in;
}

int main() {
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "hello, " << name << "!" << endl;

    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    cout << "Enter all your homework grades, "
            "followed by end-of-file";

    vector<double> homework;
    read_hw(cin, homework);

    try {
        double final_grade = grade(midterm, final, homework);
        streamsize prevPrecision = cout.precision();
        cout << "Your final grade is: " << setprecision(3)
             << final_grade << setprecision((int) prevPrecision) << endl;
    } catch (domain_error) {
        cout << endl << "You must enter your grades. "
                        "Please try again." << endl;
        return 1;
    }

    return 0;
}