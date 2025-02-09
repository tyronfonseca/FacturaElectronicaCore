#pragma once
#include <iostream>
#include <vector>
#include "../common/Persona.h"
#include "../common/Email.h"

class Emisor : public Persona
{
private:
	std::string registroFiscal8707;
	std::vector<Email*> correosElectronicos;
public:
	bool setNombre(const std::string& nombre) override;

	void setRegistroFiscal8707(const std::string& registro);
	std::string getRegistroFiscal8707();

	bool addCorreo(const std::string& email);
	std::string getCorreos();
};

