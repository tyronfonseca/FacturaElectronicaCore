#include "pch.h"
#include "../../src/common/Identificador.h"

namespace IdentificadorTest {

#pragma region Contructor

#pragma region Cedulafisica
	TEST(Constructor, ValidCedulaFisica) {
		// arrange
		std::string id = "123456789";

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::CedulaFisica);

		// assert
		EXPECT_FALSE(result.isFailed());
	}

	TEST(Constructor, ZeroFirstCedulaFisica) {
		// arrange
		std::string id = "023456789";
		std::string errMsg = "Cedulas fisicas deben seguir 9 digitos sin guiones y sin empezar con cero.";

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::CedulaFisica);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

	TEST(Constructor, LettersCedulaFisica) {
		// arrange
		std::string id = "12-345678";
		std::string errMsg = "Cedulas fisicas deben seguir 9 digitos sin guiones y sin empezar con cero.";

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::CedulaFisica);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

	TEST(Constructor, BelowMinCedulaFisica) {
		// arrange
		std::string id = "12345678";
		std::string errMsg = "Cedulas fisicas deben seguir 9 digitos sin guiones y sin empezar con cero.";

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::CedulaFisica);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

	TEST(Constructor, AboveMaxCedulaFisica) {
		// arrange
		std::string id = "1234567890";
		std::string errMsg = "Cedulas fisicas deben seguir 9 digitos sin guiones y sin empezar con cero.";

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::CedulaFisica);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

#pragma endregion

#pragma region DIMEX

	TEST(Constructor, ValidDIMEX11) {
		// arrange
		std::string id = "12345678901"; // 11 digits

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::DIMEX);

		// assert
		EXPECT_FALSE(result.isFailed());
	}

	TEST(Constructor, ValidDIMEX12) {
		// arrange
		std::string id = "123456789012"; // 12 digits

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::DIMEX);

		// assert
		EXPECT_FALSE(result.isFailed());
	}

	TEST(Constructor, ZeroFirstDIMEX) {
		// arrange
		std::string id = "01234567890";
		std::string errMsg = "DIMEX deben tener entre 11 y 12 digitos sin guiones y sin empezar con cero.";

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::DIMEX);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

	TEST(Constructor, LettersDIMEX) {
		// arrange
		std::string id = "12-34567891";
		std::string errMsg = "DIMEX deben tener entre 11 y 12 digitos sin guiones y sin empezar con cero.";

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::DIMEX);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

	TEST(Constructor, BelowMinDIMEX) {
		// arrange
		std::string id = "1234567890"; // 10 digits
		std::string errMsg = "DIMEX deben tener entre 11 y 12 digitos sin guiones y sin empezar con cero.";

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::DIMEX);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

	TEST(Constructor, AboveMaxDIMEX) {
		// arrange
		std::string id = "1234567890123"; // 13 digits
		std::string errMsg = "DIMEX deben tener entre 11 y 12 digitos sin guiones y sin empezar con cero.";

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::DIMEX);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

#pragma endregion

#pragma region CedulaJuridica

	TEST(Constructor, ValidCedulaJuridica) {
		// arrange
		std::string id = "1234567890"; // 10 digits

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::CedulaJuridica);

		// assert
		EXPECT_FALSE(result.isFailed());
	}

	TEST(Constructor, ZeroFirstCedulaJuridica) {
		// arrange
		std::string id = "0234567891";
		std::string errMsg = "Cedulas juridicas y NITE deben tener 10 digitos sin guiones y sin empezar con cero.";

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::CedulaJuridica);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

	TEST(Constructor, LettersCedulaJuridica) {
		// arrange
		std::string id = "12-3456789";
		std::string errMsg = "Cedulas juridicas y NITE deben tener 10 digitos sin guiones y sin empezar con cero.";

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::CedulaJuridica);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

	TEST(Constructor, BelowMinCedulaJuridica) {
		// arrange
		std::string id = "123456789";
		std::string errMsg = "Cedulas juridicas y NITE deben tener 10 digitos sin guiones y sin empezar con cero.";

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::CedulaJuridica);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

	TEST(Constructor, AboveMaxCedulaJuridica) {
		// arrange
		std::string id = "12345678901";
		std::string errMsg = "Cedulas juridicas y NITE deben tener 10 digitos sin guiones y sin empezar con cero.";

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::CedulaJuridica);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

#pragma endregion

#pragma region NITE
	TEST(Constructor, ValidNITE) {
		// arrange
		std::string id = "1234567890"; // 10 digits

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::NITE);

		// assert
		EXPECT_FALSE(result.isFailed());
	}

	TEST(Constructor, ZeroFirstNITE) {
		// arrange
		std::string id = "0234567891";
		std::string errMsg = "Cedulas juridicas y NITE deben tener 10 digitos sin guiones y sin empezar con cero.";

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::NITE);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

	TEST(Constructor, LettersNITE) {
		// arrange
		std::string id = "12-3456789";
		std::string errMsg = "Cedulas juridicas y NITE deben tener 10 digitos sin guiones y sin empezar con cero.";

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::NITE);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

	TEST(Constructor, BelowMinNITE) {
		// arrange
		std::string id = "123456789";
		std::string errMsg = "Cedulas juridicas y NITE deben tener 10 digitos sin guiones y sin empezar con cero.";

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::NITE);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

	TEST(Constructor, AboveMaxNITE) {
		// arrange
		std::string id = "12345678901";
		std::string errMsg = "Cedulas juridicas y NITE deben tener 10 digitos sin guiones y sin empezar con cero.";

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::NITE);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

#pragma endregion

#pragma region ExtranjeroNoDomiciliado
	TEST(Constructor, ValidExtranjeroNoDomiciliado) {
		// arrange
		std::string id = "C234567890"; // alphanumeric

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::ExtranjeroNoDomiciliado);

		// assert
		EXPECT_FALSE(result.isFailed());
	}

	TEST(Constructor, ValidExtranjeroNoDomiciliado1) {
		// arrange
		std::string id = "C"; // alphanumeric

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::ExtranjeroNoDomiciliado);

		// assert
		EXPECT_FALSE(result.isFailed());
	}

	TEST(Constructor, ValidExtranjeroNoDomiciliado20) {
		// arrange
		std::string id = "C123456789a12345678"; // 20 chars

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::ExtranjeroNoDomiciliado);

		// assert
		EXPECT_FALSE(result.isFailed());
	}

	TEST(Constructor, AboveMaxExtranjeroNoDomiciliado) {
		// arrange
		std::string id = "C123456789C12345678ab"; // 21 chars
		std::string errMsg = "Campo debe de ser de un maximo de 20 caracteres.";

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::ExtranjeroNoDomiciliado);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

	TEST(Constructor, SymbolsExtranjeroNoDomiciliado) {
		// arrange
		std::string id = "C1234-789@12345678a";
		std::string errMsg = "Identificacion deben tener un minimo de 1 y maximo de 20 caracteres alfanumericos.";

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::ExtranjeroNoDomiciliado);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

#pragma endregion

#pragma region NoContribuyente


	TEST(Constructor, ValidNoContribuyente) {
		// arrange
		std::string id = "C234567891"; // alphanumeric

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::NoContribuyente);

		// assert
		EXPECT_FALSE(result.isFailed());
	}

	TEST(Constructor, ValidNoContribuyente1) {
		// arrange
		std::string id = "C"; // alphanumeric

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::NoContribuyente);

		// assert
		EXPECT_FALSE(result.isFailed());
	}

	TEST(Constructor, ValidNoContribuyente20) {
		// arrange
		std::string id = "C123456789a12345678"; // 20 chars

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::NoContribuyente);

		// assert
		EXPECT_FALSE(result.isFailed());
	}

	TEST(Constructor, AboveMaxNoContribuyente) {
		// arrange
		std::string id = "C123456789C12345678ab"; // 21 chars
		std::string errMsg = "Campo debe de ser de un maximo de 20 caracteres.";


		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::NoContribuyente);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

	TEST(Constructor, SymbolsNoContribuyente) {
		// arrange
		std::string id = "C1234-789@12345678a";
		std::string errMsg = "Identificacion deben tener un minimo de 1 y maximo de 20 caracteres alfanumericos.";


		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, TipoIdentificacion::NoContribuyente);

		// assert
		EXPECT_TRUE(result.isFailed());
		EXPECT_EQ(result.getFailMsg(), errMsg);
	}

#pragma endregion

#pragma endregion

#pragma region getTipo
	TEST(GetTipo, ValidTipo) {
		// arrange
		std::string id = "C234567891"; // alphanumeric
		TipoIdentificacion tipo = TipoIdentificacion::NoContribuyente;

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, tipo);

		// assert
		EXPECT_FALSE(result.isFailed());
		EXPECT_EQ(result.success().getTipo(), tipo);
	}
#pragma endregion

#pragma region toString
	TEST(toString, GetCompleteIdentificadorNoContribuyente) {
		// arrange
		std::string id = "C234567891"; // alphanumeric
		TipoIdentificacion tipo = TipoIdentificacion::NoContribuyente;
		std::string expected = "06" + id;

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, tipo);

		// assert
		EXPECT_FALSE(result.isFailed());
		EXPECT_EQ(result.success().toString(), expected);
	}

	TEST(toString, GetCompleteIdentificadorCedulaFisica) {
		// arrange
		std::string id = "123456789";
		TipoIdentificacion tipo = TipoIdentificacion::CedulaFisica;
		std::string expected = "01" + id;

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, tipo);

		// assert
		EXPECT_FALSE(result.isFailed());
		EXPECT_EQ(result.success().toString(), expected);
	}
#pragma endregion

#pragma region toPrintableString
	TEST(toPrintableString, GetCompleteIdentificadorNoContribuyente) {
		// arrange
		std::string id = "C234567891"; // alphanumeric
		TipoIdentificacion tipo = TipoIdentificacion::NoContribuyente;
		std::string expected = "06" + id;

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, tipo);

		// assert
		EXPECT_FALSE(result.isFailed());
		EXPECT_EQ(result.success().toPrintableString(), expected);
	}

	TEST(toPrintableString, GetCompleteIdentificadorCedulaFisica) {
		// arrange
		std::string id = "123456789";
		TipoIdentificacion tipo = TipoIdentificacion::CedulaFisica;
		std::string expected = "01" + id;

		// act
		Result<Identificador> result = Identificador::CreateOrFail(id, tipo);

		// assert
		EXPECT_FALSE(result.isFailed());
		EXPECT_EQ(result.success().toPrintableString(), expected);
	}
#pragma endregion

}