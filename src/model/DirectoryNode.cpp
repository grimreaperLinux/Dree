#include "DirectoryNode.h"

using namespace std;

string DirectoryNode::getFileName(string path)
{
    size_t lastSlash = path.find_last_of('/');
    if (lastSlash != std::string::npos)
    {
        return path.substr(lastSlash + 1);
    }
    return path;
}

string DirectoryNode::shortenDirectoryName(string name){
    if (name.length() <= 30) {
        return name;
    } else {
        return name.substr(0, 10) + "..." + name.substr(name.length() - 3);
    }
}

string DirectoryNode::shortenFileName(string filename){
    std::string convertedFilename;
    size_t dotIndex = filename.find_last_of('.');
    
    if (dotIndex != std::string::npos && filename.length() > 30) {
        std::string fileType = filename.substr(dotIndex-1);
        convertedFilename = filename.substr(0, 10) + "..." + fileType;
    } else if (filename.length() > 30){
        convertedFilename = name.substr(0, 10) + "..." + name.substr(name.length() - 3);
    } else {
        convertedFilename = filename;
    }
    
    return convertedFilename;
}

DirectoryNode::DirectoryNode(const string &path)
    : path(path)
{
    this->name = this->getFileName(path);
}