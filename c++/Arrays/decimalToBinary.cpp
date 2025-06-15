#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int decimal;
    std::cin >> decimal;

    std::string binary = "";

    // Handle the case when input is 0
    if (decimal == 0) {
        binary = "0";
    } else {
        while (decimal > 0) {
            binary += (decimal % 2) + '0';  // Append remainder as character
            decimal /= 2;
        }
        std::reverse(binary.begin(), binary.end());  // Reverse the string
    }
    std::cout << binary << std::endl;
    return 0;
}
