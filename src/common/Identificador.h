#pragma once
#include <iostream>
#include <regex>

#include "../common/codigos/Codigos.h"
#include "../core/RequiredField.h"
#include "../core/FieldObject.h"
#include "./Utils.h"

class Identificador : public FieldObject
{
private:
	static const int maxLength = 20;
	static const int minLength = 1;
	TipoIdentificacion _tipo;

	Identificador(const std::string& val, TipoIdentificacion tipo) : FieldObject(val) {
		this->_tipo = tipo;
	}

public:
	static Result<Identificador> CreateOrFail(const std::string& val, TipoIdentificacion tipo, int nMinLength = minLength, int nMaxLength = maxLength) {
		Result<Identificador> result = FieldObject::CreateRequiredOrFail<Identificador>(val, minLength, maxLength);

		if (result.isFailed()) {
			return result;
		}

		if (tipo == TipoIdentificacion::CedulaFisica && Utils::isNotMatchingRegex(val, "^[1-9]\\d{8}$")) {
			return result.setFail("Cedulas fisicas deben seguir 9 digitos sin guiones y sin empezar con cero.");
		}

		if ((tipo == TipoIdentificacion::CedulaJuridica || tipo == TipoIdentificacion::NITE) 
			&& Utils::isNotMatchingRegex(val, "^[1-9]\\d{9}$")) {
			return result.setFail("Cedulas juridicas y NITE deben tener 10 digitos sin guiones y sin empezar con cero.");
		}

		if ((tipo == TipoIdentificacion::ExtranjeroNoDomiciliado || tipo == TipoIdentificacion::NoContribuyente)
			&& Utils::isNotMatchingRegex(val, "^[a-zA-Z0-9]{1,20}$")) {
			return result.setFail("Identificacion deben tener un minimo de 1 y maximo de 20 caracteres alfanumericos.");
		}

		if (tipo == TipoIdentificacion::DIMEX && Utils::isNotMatchingRegex(val, "^[1-9]\\d{10,11}$")) {
			return result.setFail("DIMEX deben tener entre 11 y 12 digitos sin guiones y sin empezar con cero.");
		}

		return result.setSuccess(new Identificador(val, tipo));
	}

	TipoIdentificacion getTipo() {
		return this->_tipo;
	}

	std::string toString() {
		int tipo = Utils::getCodeValue<TipoIdentificacion>(this->getTipo());
		return Utils::getNumber(tipo, 2) + this->get();
	}

	std::string toPrintableString() {
		return this->toString();
	}
};

