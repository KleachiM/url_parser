#include <iostream>
#include "Parser.h"

using namespace std;

void PrintStartMessage()
{
    cout << "Введите url в формате: протокол://хост[:порт][/документ] (q для завершения)" << endl;
}

void PrintParsedUrl(string& url, Protocol& protocol, int port, string& host, string& document)
{
}
int main() {
    PrintStartMessage();
    string line;
    while (getline(cin, line))
    {
        if ((line == "q") || (line == "Q"))
		{
			break;
		}
		Protocol protocol;
		int port;
		string host, document;
		if (ParseURL(line, protocol, port, host, document))
		{
			PrintParsedUrl(line, protocol, port, host, document);
		}
        PrintStartMessage();
    }
    return EXIT_SUCCESS;
}
