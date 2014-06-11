#include "precomp.h"
#include "decreaseVertIndicesVTS.h"

int main( int argc, char* argv[] )
{
    DecreaseVertIndicesVTS decreaser;
    decreaser.processFile( argv[1], argv[2] );
    return 0;
}