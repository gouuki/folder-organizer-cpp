#pragma once
#include <filesystem>

namespace fs = std::filesystem;

namespace FileManager {

    void organize(const fs::path& path);
    fs::path getSafePath(fs::path target);

}












