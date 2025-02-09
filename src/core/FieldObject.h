#pragma once
#include <iostream>
#include <type_traits>

#include "./Result.h"

class FieldObject
{
private:
	std::string value;
protected:
	FieldObject(const std::string& val) {
		this->value = val;
	}
public:
	/// <summary>
	/// Get the string representation of the field value.
	/// </summary>
	/// <returns>Representation used in the XML file.</returns>
	virtual std::string toString() = 0;
	/// <summary>
	/// Get the string representation of the field value.
	/// </summary>
	/// <returns>Representation used for printable formats.</returns>
	virtual std::string toPrintableString() = 0;
	/// <summary>
	/// Get value of field
	/// </summary>
	/// <returns></returns>
	std::string get() {
		return value;
	}
	/// <summary>
	/// Create a Result that checks if the value is empty or does not comply with the length (min and max).
	/// This function checks that the template class T has a base of type FieldObject.
	/// </summary>
	/// <typeparam name="T">Class that inherits from FieldObject</typeparam>
	/// <param name="val">Value to check</param>
	/// <param name="nMinLength">Min length</param>
	/// <param name="nMaxLength">Max length</param>
	/// <returns>Result with no value set and/or an error message.</returns>
	template<class T>
	static Result<T> CreateRequiredOrFail(const std::string& val, int nMinLength, int nMaxLength) {

		static_assert(std::is_base_of<FieldObject, T>::value);

		Result<T> result;
		if (val.empty()) {
			return result.setFail("Campo esta vacio.");
		}
		int size = val.size();
		if (size > nMaxLength) {
			return result.setFail("Campo debe de ser de un maximo de " + std::to_string(nMaxLength) + " caracteres.");
		}

		if (size < nMinLength) {
			return result.setFail("Campo debe de ser de un minimo de " + std::to_string(nMinLength) + " caracteres.");
		}

		return result;
	}
};