#include "Utils.h"

#include <regex>
#include <sstream>
#include <iomanip>

std::string Utils::getNumber(int value, char numDigits) {
	std::ostringstream ss;
	ss << std::setw(numDigits < 0 ? 1 : numDigits) << std::setfill('0');
	ss << (value < 0 ? -value : value);
	return ss.str();
}

bool Utils::isNotMatchingRegex(const std::string& value, const std::string& regex) {
	std::regex isValid(regex);
	return !std::regex_match(value, isValid);
}
