#include <iostream>
#include "model/DirectoryNode.h"
#include "controller/DirectoryGraph.h"
#include "view/PrintDirectoryTree.h"
#include <filesystem>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Missing args" << std::endl;
        return 1;
    }

    string currentPath = argv[1];
    filesystem::path directoryPath(currentPath);
    int depth = stoi(argv[2]);

    // TODO:add check to prevent overflow
    if (depth >= 60)
    {
        cout << "mask overflow!!\n";
        return 1;
    }

    DirectoryGraph builder;
    auto root = builder.BuildGraph(currentPath, depth);
    PrintDirectoryTree treeprinter;
    treeprinter.PrintGraphDFS(root, depth);
    return 0;
}
