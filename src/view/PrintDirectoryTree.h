#ifndef PRINTDIRECTORYTREE_H
#define PRINTDIRECTORYTREE_H

#include <vector>
#include <string>
#include <filesystem>
#include "../model/DirectoryNode.h"

using namespace std;

class PrintDirectoryTree{
    public:
        void PrintGraphDFS(DirectoryNode *node, long long depth);

    private:
        bool isDirectory(const std::string &pathStr);
        void PrintGraphDFS(DirectoryNode *node, long long depth, long long currentDepth, bool isLastChild, long long mask);
};

#endif