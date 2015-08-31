#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <helpers.h>

using namespace std;
const int MAX_LINE = 2058;

//Usage ivtovts <filename> scale
int main(int argc, char* argv[])
{
	int numVert = 0;
	int numTriangle = 0;
	float scale = 1.0f;
	bool beginPoint = false;
	bool beginTriangle = false;
	fstream file;
	fstream newFile;
	file.open(argv[1], ios::in);
	if (argc > 2)
	{
		scale = ::atof(argv[2]);
	}
	newFile.open("new.vts", ios::out);
	char line[MAX_LINE];
	vector<string> output;
	long lineCount = 0;
	while (!file.eof())
	{
		file.getline(line, MAX_LINE);
		std::vector<std::string> splitValues;
		split( line, ' ', splitValues);
		if ( lineCount == 1 )
		{
			numVert = ::atoi(splitValues[0].c_str());
			numTriangle = ::atoi(splitValues[1].c_str());
			newFile<<numVert<<"\n";
		}
		else if ( lineCount == 2 )
		{
			beginPoint = true;
		}
		else if ( lineCount == numVert + 2)
		{
			newFile<<numTriangle<<"\n";
			beginTriangle = true;
		}
		if ( beginTriangle )
		{
			for (int i = 1; i < splitValues.size(); i++)
			{
				newFile<<splitValues[i]<<((i == splitValues.size() -1 )? "\n":",");
			}
		}
		else if ( beginPoint )
		{
			for (int i = 0; i < splitValues.size(); i++)
			{
				newFile<<splitValues[i]<<((i == splitValues.size() -1 )? "\n":",");
			}
		}
    	lineCount++;
	}
	return 0;
}