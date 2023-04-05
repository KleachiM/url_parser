#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H
#include <string>
#include <optional>

enum class Protocol
{
	HTTP,
	HTTPS,
	FTP
};


bool ParseURL(std::string const& url, Protocol &  protocol, int & port, std::string & host, std::string & document);

bool ParseProtocol(const std::string& url, Protocol& protocol);

std::optional<Protocol> GetProtocolStringMapping(std::string& protocolAsString);

void PrintParsedUrl(const std::string& url, const Protocol& protocol,
	const int port, const std::string& host, const std::string& document);

#endif //PARSER_PARSER_H
