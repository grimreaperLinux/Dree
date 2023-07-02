#include "DirectoryGraph.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool DirectoryGraph::isDirectory(const string &pathStr)
{
    filesystem::path path(pathStr);
    return filesystem::is_directory(path);
}

DirectoryNode *DirectoryGraph::BuildGraph(const string &directoryName, long long depth)
{
    DirectoryNode *graph = new DirectoryNode(directoryName);
    TraverseDirectoriesDFS(graph, depth, 0);
    return graph;
}

void DirectoryGraph::TraverseDirectoriesDFS(DirectoryNode *node, long long depth, long long currentDepth)
{
    if (currentDepth > depth)
        return;

    for (const auto &entry : filesystem::directory_iterator(node->path))
    {
        // if (entry.is_directory())
        if (true)
        {
            string childDirectory = entry.path().string();
            DirectoryNode *child = new DirectoryNode(childDirectory);
            node->children.push_back(child);
        }
    }
    for (auto ch : node->children)
    {
        if (isDirectory(ch->path))
        {
            TraverseDirectoriesDFS(ch, depth, currentDepth + 1);
        }
    }
}