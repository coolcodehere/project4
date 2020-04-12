#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "DirectedWeightedGraph.h"

DirectedWeightedGraph::DirectedWeightedGraph() {
    adjacencyMatrix = new vector<vector<int>>;
    nodeNameToIndex = new map<string, int>;
}

DirectedWeightedGraph::DirectedWeightedGraph(string graphDataFilename) {
    adjacencyMatrix = new vector<vector<int>>;
    nodeNameToIndex = new map<string, int>;
    
    ReadGraph(graphDataFilename);
}

DirectedWeightedGraph::~DirectedWeightedGraph() {
    delete adjacencyMatrix;
    delete nodeNameToIndex;
}

DirectedWeightedGraph::DirectedWeightedGraph(const DirectedWeightedGraph &other) {}
DirectedWeightedGraph DirectedWeightedGraph::operator=(const DirectedWeightedGraph &other) {}

vector<string>* parseGraphDataFile(string graphDataFilename) {
    fstream graphDataIn;
    string line;
    vector<string> *graphData = new vector<string>;

    graphDataIn.open(graphDataFilename);
    while(getline(graphDataIn, line)) 
        graphData->push_back(line);

    graphDataIn.close();
    return graphData;
}

void DirectedWeightedGraph::addNode(string nodeName) {
    vector<int> newNodeData;
    nodeNameToIndex->insert(pair<string, int>(nodeName, adjacencyMatrix->size()));

    for (int i = 0; i < adjacencyMatrix->size(); i++)
        newNodeData.push_back(-1);

    adjacencyMatrix->push_back(newNodeData);

    for (int i = 0; i < adjacencyMatrix->size(); i++) 
        adjacencyMatrix->at(i).push_back(-1);
}

vector<string>* split(const std::string& str) {
    vector<string> splitData;

    istringstream iss(str);
    copy(std::istream_iterator<std::string>(iss),
         istream_iterator<std::string>(),
         back_inserter(splitData));
}

void DirectedWeightedGraph::addEdge(string unprocessedEdgeData) {
    vector<string>* edgeData = split(unprocessedEdgeData);

    int sourceNodeIdx = nodeNameToIndex->at(edgeData->at(0));
    int destNodeIdx = nodeNameToIndex->at(edgeData->at(1));
    int weight = nodeNameToIndex->at(edgeData->at(2));

    adjacencyMatrix->at(sourceNodeIdx).at(destNodeIdx) = weight;

    delete edgeData;
}

void DirectedWeightedGraph::buildGraph(vector<string> *graphData) {
    // Add nodes to graph
    int numNodes = stoi(graphData->at(0));
    int numEdges = 1 + stoi(graphData->at(0));

    for (int i = 1; i < numNodes; i++) 
        addNode(graphData->at(i));

    for (int i = 2 + numNodes; i < numEdges; i++) 
        addEdge(graphData->at(i));
}

pair<int, int>* DirectedWeightedGraph::size() {
    return new pair<int, int>(adjacencyMatrix->size(), 
                              adjacencyMatrix->at(0).size());
}

void DirectedWeightedGraph::ReadGraph(string graphDataFilename) {
    vector<string> *parsedGraphData = parseGraphDataFile(graphDataFilename);
    buildGraph(parsedGraphData);
    delete parsedGraphData;
}

void DirectedWeightedGraph::TopologicalSort() {

}

void DirectedWeightedGraph::ShortestPath(string nodeName) {

}

void DirectedWeightedGraph::MinimumSpanningTree(string startNode) {

}