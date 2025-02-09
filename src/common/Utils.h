#pragma once
#include <iostream>

class Utils
{
public:
	static std::string getNumber(int value, char numDigits);

	static bool isNotMatchingRegex(const std::string& value, const std::string& regex);

	template<typename T>
	static int getCodeValue(T value) {
		return static_cast<int>(value);
	}
};

