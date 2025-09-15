## Task A1 Precedence Check

```c++
#include <iostream>

int main() {

    int a, b, c;
    std::cout << "Enter values for a, b and c: with a space in between:";
    std::cin >> a >> b >> c;


    std::cout << "Input a = " << a << " b = " << b << " c = " << c << "\n";

    std::cout << "multiplication comes before addition \n";
    std::cout << "a + b * c = " << a + b * c << "\n";

    std::cout << "parantheses comes before multiplication \n";
    std::cout << "(a + b) * c = " << (a + b) * c << "\n";

    std::cout << "division comes before multiplication \n";
    std::cout << "a / b * c = " << a / b * c << "\n";

    std::cout << "parantheses comes before division \n";
    std::cout << "a / (b * c) = " << a / (b * c) << "\n";
    
}

```

## Task A2 Compound Assignment

```c++
#include <iostream>

int main() {

    int a, b, c;
    std::cout << "Enter values for a, b and c: with a space in between:";
    std::cin >> a >> b >> c;


    std::cout << "Input a = " << a << " b = " << b << " c = " << c << "\n";

    std::cout << "multiplication comes before addition \n";
    std::cout << "a + b * c = " << a + b * c << "\n";

    std::cout << "parantheses comes before multiplication \n";
    std::cout << "(a + b) * c = " << (a + b) * c << "\n";

    std::cout << "division comes before multiplication \n";
    std::cout << "a / b * c = " << a / b * c << "\n";

    std::cout << "parantheses comes before division \n";
    std::cout << "a / (b * c) = " << a / (b * c) << "\n";
    
}

```

## Task B1 The 'average trap'

```c++

#include <iostream>
#include <iomanip>

int main() {

    int test1, test2, test3;

    std::cout << "Enter three test scores separated by spaces: ";
    std:: cin >> test1 >> test2 >> test3;

    int sum = test1 + test2 + test3;

        std::cout << "raw average of test1, test2 and test3 = " << sum / 3 << "\n";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "correct average of test1, test2 and test3 = " << static_cast<double>(sum) / 3 << "\n";

}

```

## Task B2 Percentage with safe casting

```c++

#include <iostream>
#include <iomanip>

int main() {

    int win, games;
    std::cout << "enter number of wins: ";
    std::cin >> win;
    std::cout << "enter number of games: ";
    std::cin >> games;

    if (games == 0) {
        std::cout << "no games played.\n";
    } else {
        double win_percentage = (static_cast<double>(win) / games) * 100;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "winning percentage: " << win_percentage << "%\n";
        }
    }

```

## PayCheck Caclulator

```c++

#include <iostream>
#include <algorithm>
#include <iomanip>

int main() {
    double hours, rate;
    double benefits = 35.00;

    std::cout << "how many hours have you worked? ";
    std::cin >> hours;
    std::cout << "what is your rate? ";
    std::cin >> rate;

    double regHours = std::min(hours, 40.0);
    double overtimeHours = std::max(hours - 40.0, 0.0);
    double gross = regHours * rate + overtimeHours * rate * 1.5;
    double net = gross - (0.18 * gross) - benefits;
    std::cout << std::fixed << std::setprecision(2);

    if (hours > 40) {
        std::cout << "You worked " << regHours << " regular hours and " << overtimeHours << " overtime hours.\n";
        std::cout << "Gross: " << gross << "`\n";
        std::cout << "Tax (18%): " << 0.18 * gross << "\n";
        std::cout << "Benefits: " << benefits << "\n";
        std::cout << "Net: " << net << "\n";
    } else {
        std::cout << "hours: " << regHours << " regular hours and no overtime hours.\n";
        std::cout << "gross: " << gross << "\n" << "net:" << net << "\n";
    }
    
}

```

## Debugging

```c++
#include <iostream>
#include <iomanip>
int main() {
    int items; double price;
    std::cout << "Enter items and price: ";
    std::cin >> items >> price;

    // BUG 1: uninitialized total
    double total = items * price; 

    // BUG 2: integer division
    int discountPercent = 15;
    double discount = total * (static_cast<double>(discountPercent) / 100.0);

    // BUG 3: precedence & shipping
    double shipping = 5 + 2 * items;
    double afterDiscount = total - discount;
    if (afterDiscount >= 100.0) shipping = 0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Total: $" << total << "\n";
    std::cout << "Discount: $" << discount << "\n";
    std::cout << "Shipping: $" << shipping << "\n";
    std::cout << "Grand Total: $" << (afterDiscount + shipping) << "\n";
}

```
