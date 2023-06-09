

#include <iostream>
#include<fstream>
#include<filesystem>

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

void create_text_file(const std::string &path_counter, const std::string &path_outdata)
{
    std::ofstream fout_counter;
    fout_counter.open(path_outdata);
    fout_counter << "0" << std::endl;
    fout_counter.close();

    std::ofstream fout_outdata;
    fout_outdata.open(path_counter);
    fout_outdata << "" << std::endl;
    fout_outdata.close();
}

int get_count_line(const std::string &path_indata) // получим количество строк в файле
{
    int count_line = 0;
    std::string line;
    std::fstream file(path_indata);
    while (getline(file, line))
        ++count_line;
    return count_line;
}


void remove_file(const std::string &path_counter, const std::string &path_outdata)
{
    namespace fs = std::filesystem;
    fs::remove(path_outdata);
    fs::remove(path_counter);
}