#include <iostream>

void start_less(bool& run_main) // запустим less
{ 
    std::system("less /tmp/outdata.txt");
    run_main = false;
    // std::cout << "run_main = " << RUN_MAIN << std::endl;
}

void start_tail(bool& run_main) // запустим tail
{
    std::system("tail -f /tmp/outdata.txt");
    run_main = false;
}
