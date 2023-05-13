#include <iostream>
#include <fstream>
#include <thread>
#include <filesystem>
#include <unistd.h>

#include"func.h"

// знаю что так плохо, но мне кажется для этой программы так норм :)

bool RUN_MAIN = true;                          // основной цикл программы
bool RUN_PROGRAMM = false;                     // понимать что запушена программа
std::string PATH_INDATA = "/tmp/indata.txt";   // файл сторонней программы
std::string PATH_OUTDATA = "/tmp/outdata.txt"; ////файл нашей программы
std::string PATH_COUNTER = "/tmp/counter.txt"; ////файл вспомогательный, хранит число строк от файла стронней программы



int get_count_line() // получим количество строк в файле
{
    int count_line = 0;
    std::string line;
    std::fstream file(PATH_INDATA);
    while (getline(file, line))
        ++count_line;
    return count_line;
}

void start_less() // запустим less
{
    std::system("less /tmp/outdata.txt");
    RUN_MAIN = false;
}

void start_tail() // запустим tail
{
    std::system("tail -f /tmp/outdata.txt");
    RUN_MAIN = false;
}

int main()
{
    create_text_file(PATH_COUNTER, PATH_OUTDATA);
    int counter_watch, counter_file;
    char user_answer;
    bool tail = false, less = false;
    while (true)
    {
        std::system("clear"); // небольшое меню с чем работать, не совсем понял задание, поэтому сделал так
        std::cout << "Which application will we launch?" << std::endl;
        std::cout << "1. LESS" << std::endl;
        std::cout << "2. TAIL" << std::endl;
        std::cin >> user_answer;
        if ((int(user_answer) == 50) || (int(user_answer) == 49)) // небольшая проверка на дурака
        {
            if (user_answer == '1')
            {
                less = true;
            }
            else
            {
                tail = true;
            }
            break;
        }
        else
        {
            std::cout << "You need to enter the numbers 1 or 2" << std::endl;
            sleep(1);
            continue;
        }
    }
    while (RUN_MAIN)
    {
        counter_watch = get_counter_watch(PATH_COUNTER); // получим кол-во просмотренных строк
        counter_file = get_count_line();     // получим колво строк
        if (counter_watch != counter_file)
        {
            std::string line;
            std::fstream fin(PATH_INDATA);

            std::ofstream fout;
            fout.open(PATH_OUTDATA);

            while (getline(fin, line)) // пишем в наш файл
            {
                fout << line << std::endl;
            }
            fin.close();
            fout.close();

            std::ofstream fout_count; // меняем счетчик
            fout_count.open(PATH_COUNTER);
            fout_count << counter_file << std::endl;
            fout_count.close();
        }
        if (!RUN_PROGRAMM)
        {
            if (less)
            {
                std::thread th(start_less);
                th.detach();
                RUN_PROGRAMM = true;
            }
            else if (tail)
            {
                std::thread th(start_tail);
                th.detach();
                RUN_PROGRAMM = true;
            }
        }
    }
    namespace fs = std::filesystem;
    fs::remove(PATH_OUTDATA);
    fs::remove(PATH_COUNTER);
}