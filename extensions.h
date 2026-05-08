#pragma once
#include <map>
#include <string>



inline const std::map< std::string , std::string> extensions = 
{
    {".jpg" , "Images"} , {".png" , "Images"},{".gif" , "Images"},
    {".jpeg" , "Images"}, {".bmp" ,"Images"} , {".tif" , "Images"},
    {".webp" , "Images"}  , {".svg", ".Images"}, {".heic", "Images"},
    {".ico" , "Images"}, {".psd" , "Images"} , {".ai", "Images"},
    {".raw" , "Images"}, {".icns" , "Images"},

    {".pdf","Documents"} , {".docx" , "Documents"},{".txt", "Documents"},
    {".doc" , "Documents"} , {".xls" , "Documents"}, {".xlsx" , "Documents"},
    {".ppt" , "Documents"}, {".pptx" , "Documents"}, {".rtf" , "Documents"},
    {".md" , "Documents"}, {".odt" , "Documents"}, {".epub" , "Documents"},
    {".mobi" , "Documents"}, {".azw3" , "Documents"}, {".pages" , "Documents"},
    {".numbers" , "Documents"}, {".key" , "Documents"}, {".plist" , "Documents"},

    {".mp4", "Videos"},{".mkv", "Videos"} , {".avi" , "Videos"},
    {".mov" , "Videos"}, {".wmv" , "Videos"}, {".flv" , "Videos"},
    {".webm" , "Videos"}, {".mpg" , "Videos"}, {".mpeg" , "Videos"},
    {".3gp" , "Videos"},

    {".mp3" , "Audio"}, {".aac" , "Audio"}, {".ogg" , "Audio"},{".m4a" , "Audio"},
    {".wav" , "Audio"}, {"-flac" , "Audio"}, {"alac" , "Audio"},

    {".zip" , "Archives"}, {".rar" , "Archives"}, {".7z" , "Archives"},
    {".tar" , "Archives"},{".gz" , "Archives"}, {".iso" , "Archives"},

    {".exe" , "Programs"}, {".msi" , "Programs"}, {".bat" , "Programs"},
    {".py" ,"Programs"}, {".js" ,"Programs"} , {".cpp" , "Programs"},
    {".sh" , "Programs"} , {".dmg", "Programs"} , {".pkg" , "Programs"},
    {".app", "Programs"}
};
    

