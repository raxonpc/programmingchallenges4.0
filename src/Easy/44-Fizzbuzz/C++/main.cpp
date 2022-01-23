#include <iostream>
#include <cstddef>

auto main() -> int {
    constexpr auto limit = 100;

    for(auto i = 1; i<=limit; ++i) {
        if(i % 3 == 0 and i % 5 == 0) 
            std::cout << "FizzBuzz";
        else if(i % 3 == 0) 
            std::cout << "Fizz";
        else if(i % 5 == 0)
            std::cout << "Buzz";
        else 
            std::cout << i;

        std::cout << '\n';
    }
    return 0;
}
