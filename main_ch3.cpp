#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::sort;
using std::reverse;
using std::stringstream;
using std::map;

typedef vector<double>::size_type vec_size;

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

void exercise_31() {
    vector<double> values = {1, 2, 3, 4, 5};
    vec_size size = values.size();
    vec_size mid = size / 2;

    // don't know this one...

    double median = size % 2 == 0
                    ? values[mid] + values[mid - 1] - 2
                    : values[mid];

    cout << median << endl;
}

void exercise_32() {
    vector<int> values = {3, 9, 57, 7, 23, 5, 13};
    vector<double> quarters;
    for (int value : values) {
        double quarter = (double) value / 4;
        quarters.push_back(quarter);
    }
    sort(quarters.begin(), quarters.end());
    reverse(quarters.begin(), quarters.end());
    for (double quarter : quarters) {
        cout << quarter << endl;
    }
}

void exercise_33() {
    string input = "hello there this is a hello input";
    string buffer;
    stringstream ss(input);

    map<string, int> wordsMap;
    while (ss >> buffer) {
        if (wordsMap.find(buffer) == wordsMap.end()) {
            wordsMap[buffer] = 1;
        } else {
            wordsMap[buffer]++;
        }
    }

    for (auto word : wordsMap) {
        cout << word.first << " -> " << word.second << endl;
    }
}

void exercise_34() {
    string input = "hello there this is a Leonardo hello input";
    string buffer;
    stringstream ss(input);
    string::size_type smallest = 0, longest = 0;

    while (ss >> buffer) {
        string::size_type length = buffer.size();
        if (smallest == 0 || length < smallest) {
            smallest = length;
        }

        if (longest == 0 || length > longest) {
            longest = length;
        }
    }

    cout << "Smallest: " << smallest << endl;
    cout << "Longest: " << longest << endl;
}

void exercise_35() {

}

int main() {
//    exercise_31();
//    exercise_32();
//    exercise_33();
//    exercise_34();
    exercise_35();

//    return medianProcess();
    // averageProcess();
     return 0;
}