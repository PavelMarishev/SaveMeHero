#pragma once
#pragma comment(lib, "../packages/jsoncpp.0.6.0.1/build/native/lib/Win32/v110/Release/jsoncpp.lib")
#include "../packages/jsoncpp.0.6.0.1/build/native/include/json/json.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
using namespace Json;

class FileWork 
{
public:
	string** getJSON(int* replValsize)
	{
		fstream stream("assets/text/replicas.json");
		
		Json::Value root;
		Json::Reader *reader = new Reader();
		bool parsingSuccessful = reader->parse(stream, root);
		if (!parsingSuccessful)
		{
			std::cout << "Failed to parse configuration\n"<< reader->getFormattedErrorMessages();
			return NULL;
		}
		//string encoding = root.get("encoding", "UTF-8").asCString();
		const Json::Value replVal = root["multiply1"];
		string** buf = new string*[2]; 
		buf[0] = new string[replVal.size()];
		buf[1] = new string[replVal.size()];
		*replValsize = replVal.size();
		cout << replVal.size() << " - replVal.size()" << endl;
		for (int index = 0; index < replVal.size(); index++)
		{
			buf[0][index] = (replVal[index]["en"].asCString());
			buf[1][index] = (replVal[index]["context"].asCString());
			cout << (replVal[index]["en"].asCString()) << " - " << (replVal[index]["context"].asCString()) << endl;
		}
		return buf;
		//setIndentLength(root["indent"].get("length", 3).asInt());
		//setIndentUseSpace(root["indent"].get("use_space", true).asBool());

		// ...
		// At application shutdown to make the new configuration document:
		// Since Json::Value has implicit constructor for all value types, it is not
		// necessary to explicitly construct the Json::Value object:
		/*root["encoding"] = getCurrentEncoding();
		root["indent"]["length"] = getCurrentIndentLength();
		root["indent"]["use_space"] = getCurrentIndentUseSpace();*/

		//Json::StyledWriter writer;
		// Make a new JSON document for the configuration. Preserve original comments.
		//std::string outputConfig = writer.write(root);

		// You can also use streams.  This will put the contents of any JSON
		// stream at a particular sub-value, if you'd like.
		//std::cin >> root["subtree"];

		// And you can write to a stream, using the StyledWriter automatically.
		//std::cout << root;
	}
};