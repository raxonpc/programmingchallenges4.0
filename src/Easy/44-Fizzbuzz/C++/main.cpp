#include <iostream>
#include <cstddef>

auto main() -> int {                    // the main function
    constexpr auto limit = 100;         // variable representing the maximum value to be checked

    for(auto i = 1; i<=limit; ++i) {    // iterate over all integer values in range [1, limit]
        if(i % 3 == 0 and i % 5 == 0)   // check, if the value is divisible by both 3 and 5
            std::cout << "FizzBuzz";    // print "FizzBuzz"
        else if(i % 3 == 0)             // check, if the value is divisible just by 3
            std::cout << "Fizz";        // print "Fizz"
        else if(i % 5 == 0)             // check, if the value is divisible just by 5
            std::cout << "Buzz";        // print "Buzz"
        else                            // if the value is divisible neither by 5 nor by 3
            std::cout << i;             // print the value

        std::cout << '\n';              // print the newline character
    }
    return 0;                           // the program ends without an error code
}
