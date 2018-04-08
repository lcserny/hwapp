#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void improvedFramingName() {
    cout << "Please enter your first name: ";

    string name;
    cin >> name;

    // build the message that we intend to write
    const string greeting = "Hello, " + name + "!";

    // the number of blanks surrounding the greeting
    const int pad = 1;

    // totla number of wors to write
    const int rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * 2 + 2;

    // separate the output from the input
    cout << endl;

    // invariant: we have written r rows so far
    // setting r to 0 makes the invariant true
    for (int r = 0; r != rows; ++r) {
        string::size_type c = 0;

        // invariant: we have written c characters to the output so far
        while (c != cols) {
            if (r == pad + 1 && c == pad + 1) {
                cout << greeting;
                c += greeting.size();
            } else {
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                    cout << "*";
                } else {
                    cout << " ";
                }
                ++c;
            }
        }

        cout << endl;
    }
}

int main() {
    improvedFramingName();
    return 0;
}