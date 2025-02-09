#pragma once
#include <iostream>
#include <regex>

#include "../core/FieldObject.h"
#include "../core/Result.h"

class Email : public FieldObject
{
private:
	Email(const std::string& email) : FieldObject(email) {};
public:
	static Result<Email> CreateOrFail(const std::string& _email) {
		Result<Email> result;
		std::regex validEmail("^\\s*(([^<>()\\[\\]\\.,;:\\s@\\\"]+(\\.[^<>()\\[\\]\\.,;:\\s@\\\"]+)*)|(\\\".+\\\"))@(([^ <>()\\[\\]\\., ;:\\s@\\\"]+\\.)+[^<>()\\[\\]\\.,;:\\s@\\\"]{0,})\\s*$");
		if (!std::regex_match(_email, validEmail)) {
			return result.setFail("Correo electronico invalido.");
		}
		return result.setSuccess(new Email(_email));
	}

	std::string toString() {
		return this->get();
	}

	std::string toPrintableString() {
		return this->toString();
	}
};

