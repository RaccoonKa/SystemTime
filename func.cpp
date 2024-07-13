#include "func.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <filesystem>

namespace mt
{
    int prog()
    {
        std::ofstream file;

        // Открываем файл в режиме append для добавления текста в конец файла
        file.open("input.txt", std::ios_base::app);

        // если файл не открыт
        if (!file.is_open())
        {
            std::cerr << "Error! File is not open(";
            return -1;
        }
        // получение даты и времени запуска файла
        auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::tm* timeInfo = std::localtime(&currentTime);
        char timeString[80];
        std::strftime(timeString, sizeof(timeString), "Date: %Y/%m/%d. Time: %H:%M:%S. ", timeInfo);

        // порядковый номер
        int lineNumber = 0;
        std::ifstream inputFile("input.txt");
        std::string line;
        while (std::getline(inputFile, line))
        {
            lineNumber++;
        }

        //дописывается строку с порядковым номером и временем запуска
        file << lineNumber + 1 << ") " << timeString << "\n";

        //закрытие файла
        file.close();

        //бэкап
        std::filesystem::path originalFile("input.txt");
        std::filesystem::path backupFile("input_backup.txt");
        std::filesystem::copy(originalFile, backupFile);

        return 0;
    }
}