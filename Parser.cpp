#include "Parser.h"
#include <iostream>
#include <optional>
#include <regex>



bool ParseProtocol(const std::string& url, Protocol& protocol)
{
	std::regex pattern(R"(^.+(?=:))");
	std::smatch match;
	std::regex_search(url, match, pattern);
	if (match.size() != 1)
	{
		return false;
	}
	std::string matchedString(match[0].first, match[0].second);
	auto protocolStringMapping = GetProtocolStringMapping(matchedString);
	if (!protocolStringMapping)
	{
		return false;
	}
	protocol = *protocolStringMapping;
	return true;
}

bool ParseURL(const std::string& url, Protocol& protocol, int& port,
	std::string& host, std::string& document)
{
	if (!ParseProtocol(url, protocol))
	{
		return false;
	}

	return true;
}

std::optional<Protocol> GetProtocolStringMapping(std::string& protocolAsString)
{
	std::transform(protocolAsString.begin(), protocolAsString.end(),
		protocolAsString.begin(), tolower);
	if (protocolAsString == "http")
	{
		return Protocol::HTTP;
	}
	else if (protocolAsString == "https")
	{
		return Protocol::HTTPS;
	}
	else if (protocolAsString == "ftp")
	{
		return Protocol::FTP;
	}
	return std::nullopt;
}

void PrintParsedUrl(const std::string& url, const Protocol& protocol,
	const int port, const std::string& host, const std::string& document)
{
	std::cout << "Printing results" << std::endl;
}