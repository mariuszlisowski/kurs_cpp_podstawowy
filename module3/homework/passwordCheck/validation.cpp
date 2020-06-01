#include "validation.hpp"

#include <algorithm>
#include <cctype>
#include <string>
//
std::string getErrorMessage(ErrorCode err) {
	switch (err) {
	case ErrorCode::Ok:
		return "OK";
	case ErrorCode::PasswordsDoesNotMatch:
		return "Passwords do not match";
	case ErrorCode::PasswordNeedsAtLeastNineCharacters:
		return "Password needs at least nine characters";
	case ErrorCode::PasswordNeedsAtLeastOneNumber:
		return "Password needs at least one number";
	case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
		return "Password needs at least one special character";
	case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
		return "Password needs at least one uppercase letter";
	default:
		return "";
	}
}
//
bool isNumberInPassword(const std::string& pass) {
	return std::any_of(pass.begin(), pass.end(), ::isdigit);
}
bool isSpecialCharInPassword(const std::string& pass) {
	return std::any_of(pass.begin(), pass.end(), ::ispunct);
}
bool isUppercaseInPassword(const std::string& pass) {
	return std::any_of(pass.begin(), pass.end(), ::isupper);
}
bool doesPasswordsMatch(const std::string& passA, const std::string& passB) {
	return passA == passB;
}
//
ErrorCode checkPasswordRules(const std::string& pass) {
	if (pass.size() < 9) {
		return ErrorCode::PasswordNeedsAtLeastNineCharacters;
	}
	else if (!isNumberInPassword(pass)) {
		return ErrorCode::PasswordNeedsAtLeastOneNumber;	
	}
	else if (!isSpecialCharInPassword(pass)) {
		return ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;	
	}
	else if (!isUppercaseInPassword(pass)) {
		return ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;	
	}
	else {
		return ErrorCode::Ok;
	}
}
//
ErrorCode checkPassword(const std::string& passA, const std::string& passB) {
	if (doesPasswordsMatch(passA, passB))
		return checkPasswordRules(passA);
	else
		return ErrorCode::PasswordsDoesNotMatch;
}
