#pragma once
#include <string>

#include "./FieldObject.h"
#include "./Result.h"


class RequiredField : public FieldObject {

protected:
	static const int maxLength = 100;
	static const int minLength = 1;

	RequiredField(const std::string& val) : FieldObject(val) {}
public:

	static Result<RequiredField> CreateOrFail(const std::string& val, int nMinLength = minLength, int nMaxLength = maxLength) {
		Result<RequiredField> result = FieldObject::CreateRequiredOrFail<RequiredField>(val, nMinLength, nMaxLength);
		if (result.isFailed()) {
			return result;
		}
		return result.setSuccess(new RequiredField(val));
	}
	std::string toString() {
		return this->get();
	}

	std::string toPrintableString() {
		return this->toString();
	}
};