#include "validation.hpp"
#include <string>
#include <algorithm>
#include <cctype>
//
std::string getErrorMessage(ErrorCode err) {
	switch (err) {
	case ErrorCode::Ok:
		return "OK";
		break;
	case ErrorCode::PasswordsDoesNotMatch:
		return "Passwords do not match";
		break;
	case ErrorCode::PasswordNeedsAtLeastNineCharacters:
		return "Password needs at least nine characters";
		break;
	case ErrorCode::PasswordNeedsAtLeastOneNumber:
		return "Password needs at least one number";
		break;
	case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
		return "Password needs at least one special character";
		break;
	case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
		return "Password needs at least one uppercase letter";
		break;
	default:
		return "";
	}
}
//
bool isCharSpecial(char ch) {
	char special[] {'#', '$', '%', '&', '!', '?', '@', '^', '(', ')', '<', '>'};
	for (const char& c : special) {
		if (c == ch)
			return true;
	}
	return false;
}
//
bool isNumberInPassword(const std::string& pass) {
	return std::any_of(pass.begin(), pass.end(), ::isdigit);
}
bool isSpecialCharInPassword(const std::string& pass) {
	return std::any_of(pass.begin(), pass.end(), ::isCharSpecial);
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