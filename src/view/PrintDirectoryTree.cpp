#include "PrintDirectoryTree.h"
#include <iostream>
#include "../model/DirectoryNode.h"

using namespace std;

bool PrintDirectoryTree::isDirectory(const string &pathStr)
{
    filesystem::path path(pathStr);
    return filesystem::is_directory(path);
}

void PrintDirectoryTree::PrintGraphDFS(DirectoryNode *node, long long depth, long long currentDepth, bool isLastChild, long long mask)
{
    if (currentDepth == depth)
        return;

    for (long long i = 0; i < currentDepth; i++)
    {
        if (((mask >> i) & 1ll) == 0ll)
            cout << "│    ";
        else
            cout << "     ";
    }
    isLastChild ? cout << "└── " : cout << "├── ";

    if(isDirectory(node->path))
        cout << node->shortenDirectoryName(node->name) << "\n";
    else
        cout << node->shortenFileName(node->name) << "\n";
    
    for (size_t i = 0; i < node->children.size(); i++)
    {
        DirectoryNode *child = node->children[i];
        if (i == node->children.size() - 1)
        {
            mask = mask | (1ll << (currentDepth + 1));
        }
        PrintGraphDFS(child, depth, currentDepth + 1, i == node->children.size() - 1, mask);
    }
}

void PrintDirectoryTree::PrintGraphDFS(DirectoryNode *node, long long depth)
{
    this->PrintGraphDFS(node, depth, 0ll, true, 1ll);
}