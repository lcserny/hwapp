#include <iostream>

void exercise_01() {
    std::cout << 3 + 4 << std::endl;
}

void exercise_02() {
    std::cout << "This (\") is a quote, and this (\\) is a backslash." << std::endl;
}

void exercise_03() {
    std::cout << "\tOne tab here." << std::endl;
    std::cout << "\t\tTwo tabs here." << std::endl;
    std::cout << "\t\t\tThree tabs here." << std::endl;
}

//int main() {
//    std::cout << "Hello, World!" << std::endl;
//
//    exercise_01();
//    exercise_02();
//    exercise_03();
//
//    return 0;
//}

// VALID
//int main() {{{{{{ std::cout << "Hello, world!" << std::endl; }}}}}}

// INVALID
//int main() {
//    /* This is a comment that extends over several lines
//       because it uses /* and */ as its starting and ending delimiters */
//     */
//    std::cout << "Does this work?" << std::endl;
//    return 0;
//}

// VALID
//int main;

int main() {
    std::cout
    <<
    "Hello, World!"
    <<
    std::endl;

    return 0;
}