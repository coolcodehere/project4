#ifndef DIRECTED_WEIGHTED_GRAPH_H_
#define DIRECTED_WEIGHTED_GRAPH_H_

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class DirectedWeightedGraph {
private:
    vector<vector<int>> *adjacencyMatrix;
    map<string, int> *nodeNameToIndex;

    void addNode(string nodeName);
    void addEdge(string edgeData);
    void buildGraph(vector<string> *graphData);
public:
    DirectedWeightedGraph();
    DirectedWeightedGraph(string graphDataFilename);
    ~DirectedWeightedGraph();
    DirectedWeightedGraph(const DirectedWeightedGraph &other);
    DirectedWeightedGraph operator=(const DirectedWeightedGraph &other);

    pair<int, int>* size();
    void ReadGraph(string graphDataFilename);
    void TopologicalSort();
    void ShortestPath(string nodeName);
    void MinimumSpanningTree(string startNode);
};

#endif