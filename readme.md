# Смотрим в файл

## Задача сделать программу по условию

I Общие требования к разрабатываемому приложению
1.1 Разрабатываемое приложение должно функционировать в ОС GNU/Linux Debian 11
1.2 Разрабатываемое приложение должно быть разработано на языке программирования С++, используемая система сборки — Cmake
1.3 Разрабатываемое приложение должно быть разработано только с использованием стандартных библиотек (без Boost, Qt и т.п.)
II Функциональное описание разрабатываемого приложения
2.1 Некое стороннее приложение пишет в файл /tmp/indata.txt текстовые данные
2.2 Во время работы стороннего приложения  запускают разрабатываемое приложение, которое должно производить следующие действия:
2.2.1  при запуске создаёт файл /tmp/outdata.txt и запускает приложение less (https://man7.org/linux/man-pages/man1/less.1.html) для просмотра файла /tmp/outdata.txt
2.2.2 считывает из файла /tmp/indata.txt текстовые данные по мере их добавления
2.2.3 дописывает вычитанные добавленные данные из файла /tmp/indata.txt в файл /tmp/outdata.txt 
2.2.4 завершает работу при завершении работы ранее запущенного приложения less, а также возникновении ошибок ввода-вывода и других, при этом удаляет файл /tmp/outdata.txt
2.3 Разрабатываемое приложение осуществляет запись сообщений в системный журнал о своём запуске и закрытии (с указанием причины), в том числе по сигналам.
III Требования к функционированию разрабатываемого приложения
3.1 Разрабатываемое приложение при необходимости запуска дочерних потоков должно обеспечить их работу на разных ядрах процессора (включая основной поток)
3.2 Разрабатываемое приложение должно функционировать без привилегий суперпользователя 

## Инструкция по сборке

Требуется компиялтор с поддержкой C++17

Для сборки проекта необходимо выполнить следующую команду
```
cd /tmp
git clone ...
cd read_file_less_tail
mkdir build && cd build
cmake ..
cmake --build .
```
