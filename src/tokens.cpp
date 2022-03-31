#include "tokens.h"

std::optional<std::smatch> t_match(const std::string& subject, const std::string& token)
{
	std::regex tok(tokens_[token]);
	std::smatch m;

	if (std::regex_match(subject, m, tok))
	{
		return m;
	}

	return std::nullopt;
}
