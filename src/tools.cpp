
#include "tools.h"
#include <cmath>



int Tools::nextPowerOfTwo( float basis ) {

	return (int )pow( 2, round( (log(basis) / log( 2 )) + 0.499999) );

}