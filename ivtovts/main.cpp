#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

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
	fstream newfile;
	file.open(argv[1], ios::in);
	if (argc > 2)
	{
		scale = ::atof(argv[2]);
	}
	newfile.open("new.vts", ios::out);
	char line[MAX_LINE];
	vector<string> output;
	while (!file.eof())
	{
		file.getline(line, MAX_LINE);
		if (strstr(line, "point") != NULL)
		{
			beginPoint = true;
		}
		else if (!beginPoint && (strstr(line, "coordIndex") != NULL))
		{
			beginTriangle = true;
			output.clear();
		}
		else if (beginPoint && (strstr(line, "]") != NULL) )
		{
			beginPoint = false;
			newfile<<numVert<<endl;
			for (int i = 0; i < output.size(); i++)
			{
				newfile<<output[i];
			}
		}
		else if (beginTriangle && (strstr(line, "]") != NULL) )
		{
			beginTriangle = false;
			newfile<<numTriangle<<endl;
			for (int i = 0; i < output.size(); i++)
			{
				newfile<<output[i];
			}
		}
		else if (beginPoint)
		{
			string coord;
			string currentLine;
			stringstream oss(currentLine);
			stringstream ss(line);
			for (int i = 0; i < 3; i++)
			{
				ss>>coord;
				if (i!=2)
				{
					float num = ::atof(coord.c_str()) * scale;
					oss<<num<<",";
				}
				else
				{
					coord.replace(coord.length()-1, 1,"");
					float num = ::atof(coord.c_str()) * scale;
					oss<<num;
				}
			}
			oss<<endl;
			currentLine = oss.str();
			output.push_back(currentLine);
			numVert++;
		}
		else if (beginTriangle)
		{
			string index;
			string currentLine;
			stringstream oss(currentLine);
			stringstream ss(line);
			for (int i = 0; i < 3; i++)
			{
				ss>>index;
				if (i!=2)
				{
					oss<<index;
				}
				else
				{
					index.replace(index.length()-1, 1,"");
					oss<<index;
				}
			}
			oss<<endl;
			currentLine = oss.str();
			output.push_back(currentLine);
			numTriangle++;
		}
	}
	return 0;
}