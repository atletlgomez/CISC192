# Lab: Menu-driven Calculator

## Challenges
1. As I was creating the cases for the switch condition, I was getting an error code. I could not understand but it was a simple syntax error that I was able to fix by a quick search. I forgot the brackets that wrap around the case.

   case 1  {
     code.....
   }

2. The next challenge I faced was I kept getting an error in my code becaue I initiliazed input early. input = "" because of this, it was an already invalid input before the user had a choice. I removed the initialization and instead created the variable only.

3. Another challenge was to keep the program running was input invlidation, I am still new on validation in C++ so I used cin.fail status to check if the input was a number in a while loop to conintue loopig until a valid number was inputted.

## Calculator Code

```c++

#include <iostream>
#include <string>

int main() {

    enum class Operation { Add, Subtract, Multiply, Divide, Quit };

    double num1 = 0, num2 = 0, result;


    std::string input;

    bool running = true;

    while (running) {

        std::cout << "choose an operation! :)" << std::endl;
        std::cout << "1. Add?" << std::endl;
        std::cout << "2. Subtract?" << std::endl;
        std::cout << "3. Multiply?" << std::endl;
        std::cout << "4. Divide?" << std::endl;
        std::cout << "5. Quit?" << std::endl;

        std::cin >> input;

        Operation chosenOperation;

        if (input == "Add" || input == "1" ||  input == "+" || input == "add" || input == "ADD") {
            chosenOperation = Operation::Add;
        } else if (input == "Subtract" || input == "2" || input == "-" || input == "subtract" || input == "SUBTRACT") {
            chosenOperation = Operation::Subtract;
        } else if (input == "Multiply" || input == "3" || input == "*" || input == "multiply" || input == "MULTIPLY") {
            chosenOperation = Operation::Multiply;
        } else if (input == "Divide" || input == "4" || input == "/" || input == "divide" || input == "DIVIDE") {
            chosenOperation = Operation::Divide;
        } else if (input == "Quit" || input == "5" || input == "quit" || input == "QUIT") {
            chosenOperation = Operation::Quit;
        } else {
            std::cout << "does not match any of the options, try again" << std::endl;
            continue;
        }

        switch (chosenOperation) {
            case Operation::Add:{
                std::cout << "first Number:" << std::endl;
                std::cin >> num1;
                while (std::cin.fail())
                {
                    std::cout << "not a number try again" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "first Number:" << std::endl;
                    std::cin >> num1;
                }
                std::cout << "second Number:" << std::endl;
                std::cin >> num2;
                while (std::cin.fail())
                {
                    std::cout << "not a number try again" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "first Number:" << std::endl;
                    std::cin >> num1;
                }
                result = num1 + num2;
                std::cout << "result: " << result << std::endl;
                break;
            }
            case Operation::Subtract: {
                std::cout << "first Number:" << std::endl;
                std::cin >> num1;
                while (std::cin.fail())
                {
                    std::cout << "not a number try again" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "first Number:" << std::endl;
                    std::cin >> num1;
                }                
                std::cout << "second Number:" << std::endl;
                std::cin >> num2;
                while (std::cin.fail())
                {
                    std::cout << "not a number try again" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "first Number:" << std::endl;
                    std::cin >> num1;
                }
                result = num1 - num2;
                std::cout << "result: " << result << std::endl;
                break;
            }
            case Operation::Multiply: {
                std::cout << "first Number:" << std::endl;
                std::cin >> num1;
                while (std::cin.fail())
                {
                    std::cout << "not a number try again" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "first Number:" << std::endl;
                    std::cin >> num1;
                }
                std::cout << "second Number:" << std::endl;
                std::cin >> num2;
                while (std::cin.fail())
                {
                    std::cout << "not a number try again" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "first Number:" << std::endl;
                    std::cin >> num1;
                }
                result = num1 * num2;
                std::cout << "result: " << result << std::endl;
                break;
            }
            case Operation::Divide: {
                std::cout << "first Number:" << std::endl;
                std::cin >> num1;
                while (std::cin.fail())
                {
                    std::cout << "not a number try again" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "first Number:" << std::endl;
                    std::cin >> num1;
                }
                std::cout << "second Number:" << std::endl;
                std::cin >> num2;
                while (std::cin.fail())
                {
                    std::cout << "not a number try again" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "first Number:" << std::endl;
                    std::cin >> num1;
                }
                if (num2 != 0) {
                    result = num1 / num2;
                    std::cout << "result: " << result << std::endl;
                } else {
                    std::cout << "ERROR cannot divide by zero" << std::endl;
                }
            break;
            }
            case Operation::Quit: {
                running = false;
                break;
            default:
                std::cout << "invalid operation choice. try again." << std::endl;
                break;
            }
        }
    }
}

```

## Video Link

https://sdccd.us-west-2.instructuremedia.com/embed/c79de7b6-03b4-46ab-8fbe-19ba7170ab02

