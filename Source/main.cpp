#define TEMPER_IMPLEMENTATION
#include "ThirdParty/temper.h"
#include "floats.h"
#include "tests.h"

const bool RunTests = false;

int main(int argc, char** argv)
{
    if(RunTests)
    {
        TEMPER_RUN( argc, argv );
	    return TEMPER_GET_EXIT_CODE();
    }

    FloatTestingMain();
    return 0;
}