#include <array>
#include <iostream>
#include <iterator>
#include <string>
#include <ranges>
#include <charconv>
#include <concepts>
#include <bitset>

template <typename First, typename... Rest>
concept any_same = (std::same_as<First, Rest> or ...);

template <typename T>
concept character = any_same<T, char, signed char, unsigned char, wchar_t, char16_t, char32_t>;

template <typename T>
concept character_ptr = character<std::remove_pointer_t<T>>;

auto char_to_bin(char single_char) -> std::string {
    return std::bitset<8>{static_cast<unsigned long long>(single_char)}.to_string();
}

auto char_to_hex(char single_char) noexcept -> std::string {
    using namespace std::string_literals;

    const auto digits = std::array {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
    };

    auto retval = ""s;
    retval.resize(2);

    retval[1] = digits[single_char%16];
    single_char /= 16;

    retval[0] = digits[single_char%16];

    return retval;
}

namespace rgs = std::ranges;

template <typename Iterator, typename OutIterator>
    requires(std::forward_iterator<Iterator> and character<typename std::iterator_traits<Iterator>::value_type>)
auto generate_bin(Iterator beg, const Iterator end, OutIterator out_beg) -> void {
    std::transform(beg, end, out_beg, char_to_bin);
}

template <typename OutIterator>
auto generate_bin(const rgs::range auto& range, OutIterator out_beg) -> void {
    generate_bin(rgs::cbegin(range), rgs::cend(range), out_beg);
}

template <typename Iterator, typename OutIterator>
    requires(std::forward_iterator<Iterator> and character<typename std::iterator_traits<Iterator>::value_type>)
auto generate_hex(Iterator beg, const Iterator end, OutIterator out_beg) -> void {
    std::transform(beg, end, out_beg, char_to_hex);
}

template <typename OutIterator>
auto generate_hex(const rgs::range auto& range, OutIterator out_beg) -> void {
    generate_hex(rgs::cbegin(range), rgs::cend(range), out_beg);
}

template <typename Iterator>
    requires(std::forward_iterator<Iterator> and character_ptr<typename std::iterator_traits<Iterator>::value_type>)
auto make_string_from_cstrs(Iterator beg, const Iterator end) -> std::string {
    using namespace std::string_literals;

    auto str = ""s;
    for(; beg != end; ++beg) {
        str += *beg;
    }

    return str;
}

auto main(int argc, char** argv) -> int {
    auto str = [argc, argv]() {
        if(argc > 1) {
            return make_string_from_cstrs(argv + 1, argv + argc);
        } else {
            return std::string{std::istreambuf_iterator<char>{std::cin}, {}};
        }
    }();
    
    std::cout << "Text in binary: \n";
    generate_bin(str.cbegin(), str.cend(), std::ostream_iterator<std::string>{std::cout, " "});

    std::cout << "\n\nText in hexadecimal: \n";
    generate_hex(str.begin(), str.end(), std::ostream_iterator<std::string>{std::cout, " "});
}
