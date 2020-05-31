#pragma once

#include <string>

enum class ErrorCode {
	Ok,
	PasswordNeedsAtLeastNineCharacters,
	PasswordNeedsAtLeastOneNumber,
	PasswordNeedsAtLeastOneSpecialCharacter,
	PasswordNeedsAtLeastOneUppercaseLetter,
	PasswordsDoesNotMatch,
};

std::string getErrorMessage(ErrorCode);

bool isNumberInPassword(const std::string&);
bool isSpecialCharInPassword(const std::string&);
bool isUppercaseInPassword(const std::string&);
bool doesPasswordsMatch(const std::string&, const std::string&);

ErrorCode checkPasswordRules(const std::string&);
ErrorCode checkPassword(const std::string&, const std::string&);