/** Try to see what an uncaught exception error looks like, run a small program that uses error()
 * without catching any exceptions 
 */
#include "../std_lib_facilities.h"

int main()
{
    error("A caught error!");
    
    std::cout << "Does it reach here?" << std::endl;

    return 0;
}