#include "Receptor.h"

#include "../core/Result.h"


bool Receptor::setNombre(const std::string& _nombre) {
	if (_nombre.size() > 100 || _nombre.size() < 3) {
		setError(Error::INVALID_NOMBRE, "Nombre debe ser entre 3 y 100 caracteres.");
		return false;
	}
	else {
		cleanError(Error::INVALID_NOMBRE);
	}
	this->nombre = _nombre;
	return true;
}

void Receptor::addEmail(const std::string& email) {

	Result<Email> emailResult = Email::CreateOrFail(email);

	if (!emailResult.isFailed()) {

		this->correoElectronico = std::make_unique<Email>(emailResult.success());
	}
}