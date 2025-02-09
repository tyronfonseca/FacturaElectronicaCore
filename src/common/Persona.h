#pragma once
#include <iostream>
#include <type_traits>
#include <map>

#include "./codigos/Codigos.h"
#include "./Identificador.h"

class Persona
{
protected:
	std::string nombre = "";
	std::unique_ptr<Identificador> identificador = nullptr;
	std::string nombreComercial = "";
	std::string ubicacion = ""; //TODO: see page 21
	short provincia = 0;
	short canton = 0;
	short distrito = 0;
	std::string barrio = "";
	std::string otrasSenas = "";
	std::string otrasSenasExtranjero = "";
	std::string numCodigoPais = "";
	std::string numTelefono = "";
public:
	enum class Error {
		NONE,
		INVALID_NOMBRE,
		INVALID_IDENTIFICADOR,
		INVALID_NOMBRE_COMERCIAL,
		INVALID_PROVINCIA,
		INVALID_CANTON,
		INVALID_DISTRITO,
		INVALID_BARRIO,
		INVALID_OTRAS_SENAS,
		INVALID_OTRAS_SENAS_EXTRANJERO,
		INVALID_TELEFONO
	};

	std::string getNombre();

	bool setIdentificador(const std::string& id, TipoIdentificacion tipo);
	std::string getIdentificador();

	bool setNombreComercial(const std::string& nombre);
	std::string getNombreComercial();

	bool setProvincia(short provincia);
	std::string getProvincia();

	bool setCanton(short canton);
	std::string getCanton();

	bool setDistrito(short distrito);
	std::string getDistrito();

	bool setBarrio(const std::string& barrio);
	std::string getBarrio();

	bool setOtrasSenas(const std::string& senas);
	std::string getOtrasSenas();

	bool setOtrasSenasExtranjero(const std::string& senas);
	std::string getOtrasSenasExtranjero();

	bool setTelefono(const std::string& codigo, const std::string& numero);
	std::string getTelefono();

	std::string getErrorMsg(const Error& error);

protected:
	std::map<Error, std::string> errorMsgs;

	void cleanError(const Error& error);
	void setError(const Error& error, const std::string& msg);
	virtual bool setNombre(const std::string& nombre);
};

