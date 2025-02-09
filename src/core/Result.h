#pragma once
#include <iostream>
#include <stdexcept>
#include <memory>

template<class T>
class Result {
protected:
    std::string errorMsg;
    std::unique_ptr<T> value;
public:
    Result() : value(nullptr), errorMsg("") {}

    Result(const Result<T>& res) {
        this->errorMsg = res.errorMsg;
        if (res.value) {
            this->value = std::make_unique<T>(*res.value);
        }
        else {
            this->value = nullptr;
        }
    }

    Result& setFail(const std::string& _errorMsg) {
        this->errorMsg = _errorMsg;
        return *this;
    }

    Result& setSuccess(T* val) {
        if (val == nullptr) {
            throw std::invalid_argument("Value can't be null.");
        }
        this->value = std::make_unique<T>(*val);
        return *this;
    }

    bool isFailed() const {
        return !errorMsg.empty();
    }

    T& success() {
        if (isFailed()) {
            throw std::logic_error("Can't get value, result has failed.");
        }
        return *this->value;
    }

    std::string getFailMsg() const {
        return errorMsg;
    }
};

