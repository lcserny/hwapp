#include <iostream>
#include <string>

void framingName() {
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >> name;

    // build the message that we intend to write
    const std::string greeting = "Hello, " + name + "!";

    // build the second and fourth lines of output
    const std::string spaces(greeting.size(), ' ');
    const std::string second = "* " + spaces + " *";

    // build the first and fifth lines of output
    const std::string first(second.size(), '*');

    // write it all
    std::cout << std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;
}

void promptName() {
    // ask for the person's name
    std::cout << "Please enter your first name: ";

    // read the name
    std::string name;
    std::cin >> name;

    // write a greeting
    std::cout << "Hello, " << name << "!" << std::endl;
}

void exercise_11() {
    const std::string hello = "Hello";
    const std::string message = hello + ", world" + "!";
}

void exercise_12() {
    const std::string exclam = "!";
    // can't build because concatenation is left-associative
//    const std::string message = "Hello" + ", world" + exclam;
}

void exercise_13() {
    {
        const std::string s = "a string";
        std::cout << s << std::endl;
    }

    {
        const std::string s = "another string";
        std::cout << s << std::endl;
    }
}

void exercise_14() {
    {
        const std::string s = "a string";
        std::cout << s << std::endl;

        {
            const std::string s = "another string";
            std::cout << s << std::endl;
        }
    }
}

void exercise_15() {
    {
        std::string s = "a string";
        {
            std::string x = s + ", really";
            std::cout << s << std::endl;
        }
        // x is out of scope
//        std::cout << x << std::endl;
    }
}

void exercise_16() {
    std::cout << "What is your name? ";
    std::string name;

    // when first input is two words, it will not prompt a second time, input will use second word
    std::cin >> name;
    std::cout << "Hello, " << name << std::endl << "And what is yours? ";

    std::cin >> name;
    std::cout << "Hello, " << name << "; nice to meet you too!" << std::endl;
}

int main() {
//    promptName();
//    framingName();
//    exercise_11();
//    exercise_12();
//    exercise_13();
//    exercise_14();
//    exercise_15();
    exercise_16();

    return 0;
}