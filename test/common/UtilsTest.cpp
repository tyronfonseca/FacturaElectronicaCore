#include "pch.h"
#include "../../src/common/Utils.h"

namespace UtilsTest {

#pragma region getNumber

	TEST(getNumber, ValidNumber) {
		// arrange
		int value = 1;
		short digits = 1;
		std::string expected = "1";

		// act
		std::string result = Utils::getNumber(value, digits);

		// assert
		EXPECT_EQ(result, expected);
	}

	TEST(getNumber, ZeroNumber) {
		// arrange
		int value = 0;
		short digits = 4;
		std::string expected = "0000";

		// act
		std::string result = Utils::getNumber(value, digits);

		// assert
		EXPECT_EQ(result, expected);
	}

	TEST(getNumber, NegativeNumber) {
		// arrange
		int value = -2;
		short digits = 2;
		std::string expected = "02";

		// act
		std::string result = Utils::getNumber(value, digits);

		// assert
		EXPECT_EQ(result, expected);
	}

	TEST(getNumber, MatchingDigitsNumber) {
		// arrange
		int value = 22;
		short digits = 2;
		std::string expected = "22";

		// act
		std::string result = Utils::getNumber(value, digits);

		// assert
		EXPECT_EQ(result, expected);
	}

	TEST(getNumber, ZeroDigits) {
		// arrange
		int value = 22;
		short digits = 0;
		std::string expected = "22";

		// act
		std::string result = Utils::getNumber(value, digits);

		// assert
		EXPECT_EQ(result, expected);
	}

	TEST(getNumber, NegativeDigit) {
		// arrange
		int value = 22;
		short digits = -2;
		std::string expected = "22";

		// act
		std::string result = Utils::getNumber(value, digits);

		// assert
		EXPECT_EQ(result, expected);
	}
#pragma endregion

#pragma region isNotMatchingRegex
	TEST(isNotMatchingRegex, ValidRegex) {
		// arrange
		std::string rgx = "^([A-Z])\\w+$"; // Word start with an uppercase letter
		std::string val = "Hi";

		// act
		bool result = Utils::isNotMatchingRegex(val, rgx);

		// assert
		EXPECT_FALSE(result);
	}

	TEST(isNotMatchingRegex, InvalidRegex) {
		// arrange
		std::string rgx = "^([A-Z])\\w+$"; // Word start with an uppercase letter
		std::string val = "hi";

		// act
		bool result = Utils::isNotMatchingRegex(val, rgx);

		// assert
		EXPECT_TRUE(result);
	}
#pragma endregion

}