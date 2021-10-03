#include <iostream>
#include <ranges>
#include <sstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <string_view>

namespace rgs = std::ranges;

auto count_occurences(std::wstring_view str) {
  auto characters_map = std::unordered_map<wchar_t, int>{};

  rgs::for_each(str,  [&characters_map](const auto character){ characters_map[character]++; });
  return characters_map;
}

auto pretty_print_occurences(const auto& map) {
  const auto printer = [](const auto& arg) { std::wcout << arg; };

  const auto pretty_format_occurence = [](const auto& pair) {
    auto stream = std::wostringstream{};

    stream << L"Character: [" << pair.first << L"] occured " << pair.second << L" times.\n";
    return stream.str();
  };


  std::wcout << "Occurences: \n";
  rgs::for_each(map, printer, pretty_format_occurence);
}

auto main() -> int {
  std::setlocale(LC_ALL, ""); // sets the C locale to the systems' default

  auto input = std::wstring{};
  std::getline(std::wcin, input);

  const auto occurences_map = count_occurences(input);

  pretty_print_occurences(occurences_map);
}
