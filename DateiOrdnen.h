#pragma once
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

class Logger{
    public:
    void writeLog(const std::string& data_name , const std::string& target_folder , 
                    const std::string& log_folder);

};

class FileManager {
    private:
    fs::path getSafePath(fs::path target);
    Logger mylogger;

    public:  
    void organize(const fs::path& path);
   
};












