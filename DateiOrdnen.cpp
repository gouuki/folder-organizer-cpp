#include <iostream>
#include <filesystem>
#include "extensions.h"
#include <format>
#include <string>
#include "DateiOrdnen.h"
#include <ctime>
#include <chrono>
#include <fstream>

namespace fs = std::filesystem;

void FileManager::organize(const fs::path& path)
{
    std::string target_folder;

    if(!(fs::exists(path)))
    {
        return;
    }

    std::string  mk_folder;

    for(const auto& entry : fs::directory_iterator(path))
    {

        if( !entry.is_regular_file() || entry.is_directory() ||
        entry.path().filename().string()[0] == '.' ){continue;}

        std::string ext = entry.path().extension().string();

        if(extensions.count(ext))
        {
            mk_folder = extensions.at(ext);
        }
        else
        {
            mk_folder = "Others";
        }
        mk_folder = fs::path(path) / mk_folder;
        fs::create_directory(mk_folder);
        fs::path target_path = mk_folder / entry.path().filename();
        
        target_path = getSafePath(target_path);

        try
        {
            fs::rename(entry.path() , target_path );
            mylogger.writeLog(entry.path().filename().string() , target_path.string()
                                ,path.string());
        }
        catch(const fs::filesystem_error & e)
        {
            mylogger.writeLog(entry.path().filename().string(), "Error :" + std::string(e.what()),
                            path.string());
            std::cerr << e.what() << '\n';
        }

        
    

    }

}

fs::path FileManager::getSafePath(fs::path target)
{
    if(!fs::exists(target))
    {
        return target ;
    }
    fs::path base = target.parent_path();
    std::string data_name = target.stem().string();
    std::string extension = target.extension().string();
    int counter = 1 ; 
    fs::path new_path = target;


    while(fs::exists(new_path))
    {
        std::string new_name = data_name + "(" + std::to_string(counter) + ")" + extension;
        new_path = base / new_name;
        counter++;
    }

    return new_path;
}

void Logger::writeLog(const std::string& data_name , const std::string& target_folder,
                const std::string& log_folder)
{ 
    auto time = std::chrono::system_clock::now();
    auto time_now = std::chrono::floor<std::chrono::seconds>(time);
    std::string date = std::format({":%d-%m-%Y %H:%M:%S"}, time_now);

    fs::path log_path = fs::path(log_folder) / "history.log";

    std::ofstream log(log_path, std::ios::app);
    if(!log.is_open())
    {
        std::cerr<< "Error: cannot log file open!";
        return;
    }

    log<< time_now << " " << data_name << " to "<< target_folder<< "\n";
    log.close();


}