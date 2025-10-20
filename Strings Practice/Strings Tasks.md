``` c++

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string email, username, domain, pos, phrase, palindromePhrase;

bool isPalindrome(string s) {
    /*goes through the characters in the string and lowercases them */
    string lowercase; 
    for (char c : s) {
        lowercase += tolower(c);
    }
    /*from start to end remove all white spaces*/
    lowercase.erase(remove(lowercase.begin(), lowercase.end(), ' '), lowercase.end());

    /*pointers from left to right check for equal value*/
    int start = 0;
    int end = s.length() - 1;

    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
    }
    end--;
    return true;
}

int longestWordLength(string s) {
    /*value holder for longest word*/
    int maxword = 0;
    /*current pointer*/
    int current = 0;
    string longestWrd;

    string tempWrd;
    /*looping through chars in string if not equal to empty space*/
    for (char c : s) {

        if (c != ' ') {
            tempWrd += c;
            current++;
        } else {
            /*if empty space appears and current counts is larger than max holder */
            if (current > maxword) {
                /*hold the new count and new woird*/
                maxword = current;
                longestWrd = tempWrd;
            }
            /*reset values*/
            current = 0;
            tempWrd = "";
        }
    }
    maxword = max(maxword, current);
    std::cout << "Longest word length: " << maxword << endl;
    std::cout << "Longest word: " << longestWrd << endl;
}

int main() {

    /*TASK 1 Extract Domain from email*/
    std::cout << "Email: " << endl;
    std::cin >> email;

    /*This will find the postion and divide it the @ symbol */
    int symbolPostion = email.find('@'); 

    username = email.substr(0, symbolPostion);

    // isPalindrome function removed from inside main (defined above)
    /*adding one to move ahead the @ symbol, no end needed because it will end by no longer having anything else to extract*/
    domain = email.substr(symbolPostion + 1);


    std::cout << "User:" << username << endl;
    std::cout << "Domain:" << domain << endl;

    /*TASK 2 Replace a word*/
    // std::cout << "Input Phrase with 'Miramar' included: " << endl;
    // std::cin >> phrase;


    // std::cout << "Phrase Output: " << phrase << endl;

    /*TASK 3 Check Palindrome*/
    std::cout << "Input an invalid or valid palindrome: " << endl;
    std::cin >> palindromePhrase;

    isPalindrome(palindromePhrase) ? std::cout << "its a palindrome" << endl : std::cout << "Its not a palindrome" << endl;


    /*Task 6 Mask Email*/
    std::cout << "Input: " << email << endl;

    /*Censored email skips first letter and stops before the last*/
    string censoredEmail = email.replace(1, symbolPostion - 2, string(symbolPostion - 2, '*'));

    std::cout << "Censored Email: " << censoredEmail << endl;



	return 0;
}

