#include "pch.h"
#include "../../src/common/Email.h"

namespace EmailTest {
	TEST(Constructor, ValidEmail) {
		// arrange
		std::string mail = "testStr@test.com";

		// act
		Result<Email> result = Email::CreateOrFail(mail);

		// assert
		EXPECT_FALSE(result.isFailed());
	}

	TEST(Constructor, ValidAllUppercaseEmail) {
		// arrange
		std::string mail = "TESTUPPER@TEST.COM";

		// act
		Result<Email> result = Email::CreateOrFail(mail);

		// assert
		EXPECT_FALSE(result.isFailed());
	}
	

	TEST(Constructor, ValidUpperLowerCaseEmail) {
		// arrange
		std::string mail = "teST@Test.com";

		// act
		Result<Email> result = Email::CreateOrFail(mail);

		// assert
		EXPECT_FALSE(result.isFailed());
	}

	TEST(Constructor, ValidAlphanumericEmail) {
		// arrange
		std::string mail = "test12@23test.com";

		// act
		Result<Email> result = Email::CreateOrFail(mail);

		// assert
		EXPECT_FALSE(result.isFailed());
	}

	TEST(Constructor, ValidNumericEmail) {
		// arrange
		std::string mail = "1223@23.net";

		// act
		Result<Email> result = Email::CreateOrFail(mail);

		// assert
		EXPECT_FALSE(result.isFailed());
	}

	TEST(Constructor, ValidEspecialCharactersEmail) {
		// arrange
		std::string mail = "t.e-s_sd@Test.com";

		// act
		Result<Email> result = Email::CreateOrFail(mail);

		// assert
		EXPECT_FALSE(result.isFailed());
	}

	TEST(Constructor, ValidSubdomainsEmail) {
		// arrange
		std::string mail = "te-s_sd@dev.Test.com";

		// act
		Result<Email> result = Email::CreateOrFail(mail);

		// assert
		EXPECT_FALSE(result.isFailed());
	}

	TEST(Constructor, DoubleAtEmail) {
		// arrange
		std::string mail = "te-s@sd@dev.Test.com";

		// act
		Result<Email> result = Email::CreateOrFail(mail);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), "Correo electronico invalido.");
	}

	TEST(Constructor, EmptySpaceEmail) {
		// arrange
		std::string mail = "te-s @dev.Test.com";

		// act
		Result<Email> result = Email::CreateOrFail(mail);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), "Correo electronico invalido.");
	}

	TEST(toString, GetValidEmail) {
		// arrange
		std::string mail = "te-s@dev.Test.com";

		// act
		Result<Email> result = Email::CreateOrFail(mail);

		// assert
		EXPECT_FALSE(result.isFailed());
		EXPECT_EQ(result.success().toString(), mail);
	}
}