#ifndef DIRECTORYNODE_H
#define DIRECTORYNODE_H

#include <vector>
#include <string>

using namespace std;

class DirectoryNode
{
public:
    string name;
    string path;
    vector<DirectoryNode *> children;

    string getFileName(string path);
    string shortenDirectoryName(string name);
    string shortenFileName(string name);

    DirectoryNode(const string &path);
};

#endif