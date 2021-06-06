#include <iostream>
#include <cstddef>

// yes, std::size_t will be unsigned long (long) on modern platforms
consteval auto operator""_u(unsigned long long num) -> std::size_t {
    return static_cast<std::size_t>(num);
}

auto main() -> int {
    constexpr auto limit = 100_u;

    for(auto i = 1_u; i<=limit; ++i) {

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

}
