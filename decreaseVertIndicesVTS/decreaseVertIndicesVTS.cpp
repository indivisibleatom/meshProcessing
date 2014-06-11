// decreaseVertIndicesVTS.cpp : Defines the entry point for the console application.
//

#include "precomp.h"
#include "helpers.h"
#include <fstream>
#include <iostream>
#include "decreaseVertIndicesVTS.h"

using namespace std;

void DecreaseVertIndicesVTS::processFile( const std::string& fileName, const std::string& newFileName )
{
	ifstream inputFile;
	ofstream outputFile;

	inputFile.exceptions( ios_base::failbit );
	outputFile.exceptions( ios_base::failbit );

	try
	{
		inputFile.open( fileName, ios::in | ios::binary );
		outputFile.open( newFileName, ios::out | ios::binary );
	}
	catch ( fstream::failure ex )
	{
		std::cout<<__FILE__<<" "<<__FUNCTION__<<" "<<__LINE__<<" failed to open file "<<fileName<<" or "<<newFileName;
		return;
	}

	int numVerts;
	inputFile>>numVerts; 
	outputFile<<numVerts<<'\n';

	std::string vertexData;
	for (int i = 0; i < numVerts; i++ )
	{
		inputFile>>vertexData;
		outputFile<<vertexData<<'\n';
	}

	int numTriangles;
	inputFile>>numTriangles;
	outputFile<<numTriangles<<'\n';
	
	std::string incidenceData;
	std::vector<std::string> items;
	int vertexIndex;
	for (int i = 0; i < numTriangles; i++ )
	{
		items.clear();
		inputFile>>incidenceData;
		split( incidenceData, ',', items );
		
		for ( std::vector<std::string>::iterator iter = items.begin(); iter != items.end(); iter++ )
		{
			vertexIndex = atoi( (*iter).c_str() );
			std::vector<std::string>::iterator dupe = iter;
			++dupe;
			vertexIndex--;
			
			if ( dupe != items.end() )
			{
				outputFile<<vertexIndex<<',';
			}
			else
			{
				outputFile<<vertexIndex<<'\n';
			}
		}
	}

	inputFile.close();
	outputFile.close();
}