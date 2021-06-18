#include <array>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <ranges>
#include <concepts>
#include <bitset>

template <typename First, typename... Rest>
concept any_same = (std::same_as<First, Rest> or ...);

template <typename T>
concept character = any_same<T, char, signed char, unsigned char, wchar_t, char8_t, char16_t, char32_t>;

template <typename T>
concept character_ptr = character<std::remove_pointer_t<T>>;

template <std::input_or_output_iterator Iterator>
using iter_type = typename std::iterator_traits<Iterator>::value_type;

auto char_to_bin(char single_char) -> std::string {
    return std::bitset<8>{static_cast<unsigned long long>(single_char)}.to_string();
}

auto char_to_hex(char single_char) noexcept -> std::string {
    static constexpr auto digits = std::array {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
    };

    return std::string {
        digits[(single_char / 16) % 16],
        digits[single_char % 16]
    };
}

template <std::input_iterator BegIterator,
          std::sentinel_for<BegIterator> Sentinel>
    requires(character_ptr<iter_type<BegIterator>>)
auto make_string_from_cstrs(BegIterator beg, const Sentinel end) -> std::string {
    auto str = std::string{};

    for(; beg != end; ++beg) {
        str += *beg;
    }

    return str;
}

auto main(int argc, char** argv) -> int {
    namespace rgs = std::ranges;

    auto str = [argc, argv]() {
        if(argc > 1) return make_string_from_cstrs(argv + 1, argv + argc);

        auto str = std::string{};
        std::getline(std::cin, str);

        return str;
    }();
    
    std::cout << "Text in binary: \n";
    rgs::transform(str, std::ostream_iterator<std::string>{std::cout, " "}, char_to_bin);

    std::cout << "\n\nText in hexadecimal: \n";
    rgs::transform(str, std::ostream_iterator<std::string>{std::cout, " "}, char_to_hex);

    std::cout << '\n';
}
