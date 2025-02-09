#include "pch.h"
#include "../../src/core/RequiredField.h"

namespace RequireStringTest {
	TEST(Constructor, ValidConstructor) {
		// arrange
		std::string id = "testStr";

		// act
		Result<RequiredField> result = RequiredField::CreateOrFail(id);

		// assert
		EXPECT_FALSE(result.isFailed());
	}

	TEST(Constructor, EmptyString) {
		// arrange
		std::string id = "";
		std::string msg = "Campo esta vacio.";

		// act
		Result<RequiredField> result = RequiredField::CreateOrFail(id);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), msg);
	}

	TEST(Constructor, AboveMaxLength) {
		// arrange
		int min = 1;
		int max = 3;
		std::string id = "testStr";
		std::string msg = "Campo debe de ser de un maximo de " + std::to_string(max) + " caracteres.";

		// act
		Result<RequiredField> result = RequiredField::CreateOrFail(id, min, max);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), msg);
	}

	TEST(Constructor, BelowMinLength) {
		// arrange
		int min = 3;
		std::string id = "te";
		std::string msg = "Campo debe de ser de un minimo de " + std::to_string(min) + " caracteres.";

		// act
		Result<RequiredField> result = RequiredField::CreateOrFail(id, min);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), msg);
	}

	TEST(toString, GetValue) {
		// arrange
		std::string id = "testStr";

		// act
		Result<RequiredField> result = RequiredField::CreateOrFail(id);

		// assert
		EXPECT_FALSE(result.isFailed());
		EXPECT_EQ(result.success().toString(), id);
	}

	TEST(toPrintableString, GetValue) {
		// arrange
		std::string id = "testStr";

		// act
		Result<RequiredField> result = RequiredField::CreateOrFail(id);

		// assert
		EXPECT_FALSE(result.isFailed());
		EXPECT_EQ(result.success().toPrintableString(), id);
	}
	
}