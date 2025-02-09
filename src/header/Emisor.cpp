#include "Emisor.h"

#include "../common/Utils.h"


bool Emisor::setNombre(const std::string& _nombre) {
	if (_nombre.size() > 100 || _nombre.size() < 5) {
		setError(Error::INVALID_NOMBRE, "Nombre debe ser entre 5 y 100 caracteres.");
		return false;
	}
	else {
		cleanError(Error::INVALID_NOMBRE);
	}
	this->nombre = _nombre;
	return true;
}

void Emisor::setRegistroFiscal8707(const std::string& registro) {
	if (Utils::isNotMatchingRegex(registro, "^\\d{1,12}$")) {
		throw std::invalid_argument("Numero de registro fiscal invalido: " + registro);
	}

	this->registroFiscal8707 = registro;
}

std::string Emisor::getRegistroFiscal8707() {
	return this->registroFiscal8707;
}

bool Emisor::addCorreo(const std::string& email) {
	Result<Email> emailResult = Email::CreateOrFail(email);
	if (!emailResult.isFailed() && correosElectronicos.size() < 4) {
		correosElectronicos.push_back(&emailResult.success());
		return true;
	}

	return false;
}

std::string Emisor::getCorreos() {
	std::string result = "";
	for (auto& email : correosElectronicos) {
		result += email->toString();
	}
	return result;
}