#include <catch2/catch_test_macros.hpp>
#include "../Parser.h"
#include <string>

using namespace std;
TEST_CASE("parse protocol (bad url)")
{
	string url = "www.mysite.com/docs/document1.html?page=30&lang=en#title";
	Protocol aProtocol = Protocol::HTTP;
	REQUIRE(ParseProtocol(url, aProtocol) == false);

	url = "asdf://www.mysite.com/docs/document1.html?page=30&lang=en#title";
	REQUIRE(ParseProtocol(url, aProtocol) == false);
}

TEST_CASE("parse protocol (normal url)")
{
	string url = R"(http://www.mysite.com/docs/document1.html?page=30&lang=en#title)";
	Protocol aProtocol = Protocol::HTTPS;
	REQUIRE(ParseProtocol(url, aProtocol) == true);
	REQUIRE(aProtocol == Protocol::HTTP);
}

TEST_CASE("get protocol type")
{
	std::string str = "http";
	auto protocol = GetProtocolStringMapping(str);
	REQUIRE(protocol == Protocol::HTTP);

	str = "hello";
	protocol = GetProtocolStringMapping(str);
	REQUIRE(protocol == std::nullopt);
}