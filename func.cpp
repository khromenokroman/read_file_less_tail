

#include <iostream>
#include<fstream>

int get_counter_watch(const std::string &path) // узнаем сколько строк мы уже смотрели
{
    int counter_watch = 0;
    std::ifstream fin;
    fin.open(path);
    while (!fin.eof())
    {
        fin >> counter_watch;
    }
    fin.close();
    return counter_watch;
}