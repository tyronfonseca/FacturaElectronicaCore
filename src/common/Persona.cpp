#include <stdexcept>

#include "./Persona.h"
#include "./Utils.h"


void Persona::cleanError(const Error& error) {
	this->errorMsgs[error] = "";
}

void Persona::setError(const Error& error, const std::string& msg) {
	this->errorMsgs[error] = msg;
}

std::string Persona::getErrorMsg(const Error& error) {
	return this->errorMsgs[error];
}

bool Persona::setNombre(const std::string& _nombre) {
	this->nombre = _nombre;
	return true;
}

std::string Persona::getNombre() {
	return this->nombre;
}

bool Persona::setIdentificador(const std::string& id, TipoIdentificacion tipo) {
	Result<Identificador> result = Identificador::CreateOrFail(id, tipo);
	if (result.isFailed()) {
		setError(Error::INVALID_IDENTIFICADOR, result.getFailMsg());
		return false;
	}
	else {
		cleanError(Error::INVALID_IDENTIFICADOR);
	}
	this->identificador = std::make_unique<Identificador>(result.success());
	return true;
}
std::string Persona::getIdentificador() {
	return this->identificador->toString();
}

bool Persona::setNombreComercial(const std::string& _nombre) {
	if (_nombre.size() > 80 || _nombre.size() < 3) {
		setError(Error::INVALID_NOMBRE_COMERCIAL, "Nombre debe ser entre 3 y 80 caracteres.");
		return false;
	}
	else {
		cleanError(Error::INVALID_NOMBRE_COMERCIAL);
	}
	this->nombreComercial = _nombre;	
	return true;
}
std::string Persona::getNombreComercial() {
	return this->nombreComercial;
}

bool Persona::setProvincia(short _provincia) {
	if (_provincia < 1 || _provincia > 7) {
		setError(Error::INVALID_PROVINCIA, "Provincia invalida.");
		return false;
	}
	else {
		cleanError(Error::INVALID_PROVINCIA);
	}
	this->provincia = _provincia;	
	return true;
}
std::string Persona::getProvincia() {
	return std::to_string(this->provincia);
}

bool Persona::setCanton(short _canton) {
	if (_canton < 1 || _canton > 50) {
		setError(Error::INVALID_CANTON, "Canton invalido.");
		return false;
	} else {
		cleanError(Error::INVALID_CANTON);
	}
	this->canton = _canton;	
	return true;
}
std::string Persona::getCanton() {
	return Utils::getNumber(this->canton, 2);
}

bool Persona::setDistrito(short _distrito) {
	if (_distrito < 1 || _distrito > 100) {
		setError(Error::INVALID_DISTRITO, "Distrito invalido.");
		return false;
	}
	else {
		cleanError(Error::INVALID_DISTRITO);
	}
	this->distrito = _distrito;	
	return true;
}
std::string Persona::getDistrito() {
	return Utils::getNumber(this->distrito, 2);
}

bool Persona::setBarrio(const std::string& _barrio) {
	if (_barrio.size() < 5 || _barrio.size() > 50) {
		setError(Error::INVALID_BARRIO, "Barrio invalido. Debe ser entre 5 y 50 caracteres.");
		return false;
	}
	else {
		cleanError(Error::INVALID_BARRIO);
	}
	this->barrio = _barrio;	
	return true;
}
std::string Persona::getBarrio() {
	return this->barrio;
}

bool Persona::setOtrasSenas(const std::string& _senas) {
	if (_senas.size() < 5 || _senas.size() > 250) {
		setError(Error::INVALID_OTRAS_SENAS, "Otras senas invalida. Debe ser entre 5 y 250 caracteres.");
		return false;
	}
	else {
		cleanError(Error::INVALID_OTRAS_SENAS);
	}
	this->otrasSenas = _senas;	
	return true;
}
std::string Persona::getOtrasSenas() {
	return this->otrasSenas;
}

bool Persona::setOtrasSenasExtranjero(const std::string& _senas) {
	if (_senas.size() < 5 || _senas.size() > 300) {
		setError(Error::INVALID_OTRAS_SENAS_EXTRANJERO, "Otras senas invalida. Debe ser entre 5 y 300 caracteres.");
		return false;
	}
	this->otrasSenas = _senas;	
	return true;
}
std::string Persona::getOtrasSenasExtranjero() {
	return this->otrasSenas;
}

bool Persona::setTelefono(const std::string& codigo, const std::string& numero) {
	if (Utils::isNotMatchingRegex(codigo, "^\\d{1,3}$")) {
		setError(Error::INVALID_TELEFONO, "Codigo Pais invalido: " + codigo);
		return false;
	}

	if (Utils::isNotMatchingRegex(numero, "^\\d{8,20}$")) {
		setError(Error::INVALID_TELEFONO, "Numero invalido: " + codigo);
		return false;
	}

	this->numCodigoPais = codigo;
	this->numTelefono = numero;	
	return true;
}
std::string Persona::getTelefono() {
	return this->numCodigoPais + this->numTelefono;
}