#ifndef _HELPERS_H_

#define _HELPERS_H_

#include <vector>
#include <string>
#include <sstream>

std::vector<std::string>& split( const std::string& str, char delim, std::vector<std::string>& elements )
{
    std::stringstream strStream( str );
    std::string item;

    while ( std::getline( strStream, item, delim ) )
    {
        elements.push_back( item );
    }
    return elements;
}

#endif//_HELPERS_H_