#include <algorithm>
#include <iostream>
#include <cstddef>
#include <iomanip>
#include <string>
#include <span>

auto to_bin(const std::byte b) {
	auto s = std::string();
	auto n = std::to_integer<int>(b);
	while(n != 0) {
		s += (n % 2) + '0';
		n /= 2;
	}

	std::ranges::reverse(s);
	return s;
}

void print(auto const& thing, std::span<const std::byte> const bytes) {
	std::cout << "Thing: " << thing << '\n';

	std::cout << "{ ";
	for (auto const b : bytes) {
		std::cout << std::hex << std::setw(2) << std::to_integer<int>(b) << ' ';
	}
	std::cout << std::dec << "}\n";

	std::cout << "{ ";
	for (auto const b : bytes) {
		std::cout << std::setw(8) << to_bin(b) << ' ';
	}
	std::cout << std::dec << "}\n";
}


auto main() -> int {
	auto str = std::string();
	std::getline(std::cin, str);

	auto s = std::span{str};

	print(str[0], std::as_bytes(s));
}
