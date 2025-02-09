#pragma once
#include <memory>

#include "../common/Persona.h"
#include "../common/Email.h"

class Receptor : public Persona
{
private:
	std::unique_ptr<Email> correoElectronico;
public:
	bool setNombre(const std::string& nombre) override;
	void addEmail(const std::string& email);
};

