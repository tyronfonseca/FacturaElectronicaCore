#include "pch.h"
#include "../../src/common/Persona.h"
#include "../../src/common/Utils.h"

namespace PersonaTest {

#pragma region setGetIdentificador

	TEST(setGetIdentificador, ValidIdentificador) {
		// arrange
		std::string expected = "123456789";
		TipoIdentificacion tipo = TipoIdentificacion::CedulaFisica;
		std::string codeTipo = Utils::getNumber(Utils::getCodeValue<TipoIdentificacion>(tipo), 2);

		// act
		Persona p;
		bool result = p.setIdentificador(expected, tipo);
		std::string errorMsg = p.getErrorMsg(Persona::Error::INVALID_IDENTIFICADOR);

		// assert
		EXPECT_TRUE(result);
		EXPECT_EQ(codeTipo + expected, p.getIdentificador());
		EXPECT_EQ("", errorMsg);
	}

	TEST(setGetIdentificador, InvalidIdentificador) {
		// arrange
		std::string expected = "1234567890";
		TipoIdentificacion tipo = TipoIdentificacion::CedulaFisica;
		std::string expectedErrMsg = "Cedulas fisicas deben seguir 9 digitos sin guiones y sin empezar con cero.";

		// act
		Persona p;
		bool result = p.setIdentificador(expected, tipo);
		std::string errorMsg = p.getErrorMsg(Persona::Error::INVALID_IDENTIFICADOR);

		// assert
		EXPECT_FALSE(result);
		EXPECT_EQ(expectedErrMsg, errorMsg);
	}
#pragma endregion

#pragma region setGetNombreComercial

	TEST(setGetNombreComercial, ValidNombreComercial) {
		// arrange
		std::string expected = "Nombre Comercial";
		std::string expectedErrMsg = "";

		// act
		Persona p;
		bool result = p.setNombreComercial(expected);
		std::string errorMsg = p.getErrorMsg(Persona::Error::INVALID_NOMBRE_COMERCIAL);

		// assert
		EXPECT_TRUE(result);
		EXPECT_EQ(expected, p.getNombreComercial());
		EXPECT_EQ(expectedErrMsg, errorMsg);
	}

	TEST(setGetNombreComercial, InvalidNombreComercial3) {
		// arrange
		std::string expected = "No";
		std::string expectedErrMsg = "Nombre debe ser entre 3 y 80 caracteres.";

		// act
		Persona p;
		bool result = p.setNombreComercial(expected);
		std::string errorMsg = p.getErrorMsg(Persona::Error::INVALID_NOMBRE_COMERCIAL);

		// assert
		EXPECT_FALSE(result);
		EXPECT_EQ(expectedErrMsg, errorMsg);
	}

	TEST(setGetNombreComercial, InvalidNombreComercial80) {
		// arrange
		std::string expected = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt.";
		std::string expectedErrMsg = "Nombre debe ser entre 3 y 80 caracteres.";

		// act
		Persona p;
		bool result = p.setNombreComercial(expected);
		std::string errorMsg = p.getErrorMsg(Persona::Error::INVALID_NOMBRE_COMERCIAL);

		// assert
		EXPECT_FALSE(result);
		EXPECT_EQ(expectedErrMsg, errorMsg);
	}

#pragma endregion
}