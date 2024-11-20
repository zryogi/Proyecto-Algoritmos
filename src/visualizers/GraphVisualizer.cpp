#include "GraphVisualizer.hpp"

#include <raylib.h>

#include <cmath>
#include <iostream>
#include <queue>
#include <thread>
#include <unordered_map>
#include <unordered_set>

const int ANIMATION_WAIT = 2000;

float CalculateDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

GraphVisualizer::GraphVisualizer() : nextNodeId(0) {}

void GraphVisualizer::AddNode(int x, int y, const std::string& label) {
    nodes[nextNodeId] = GraphNode(nextNodeId, x, y, label);
    std::cout << "Added node with ID: " << nextNodeId << " at (" << x << ", "
              << y << ") with label: " << label << std::endl;
    nextNodeId++;
}

void GraphVisualizer::AddEdge(int fromId, int toId, float weight,
                              bool directed) {
    if (nodes.find(fromId) != nodes.end() && nodes.find(toId) != nodes.end()) {
        edges.emplace_back(fromId, toId, weight);
        std::cout << "Added edge from node " << fromId << " to node " << toId
                  << " with weight " << weight << std::endl;
        if (!directed) {
            edges.emplace_back(toId, fromId, weight);
            std::cout << "Added reverse edge from node " << toId << " to node "
                      << fromId << " with weight " << weight << std::endl;
        }
    } else {
        std::cout << "Invalid node IDs for edge: " << fromId << " -> " << toId
                  << std::endl;
    }
}

void GraphVisualizer::GenerateRandomGraph(int numNodes, float edgeProbability,
                                          int maxWeight) {
    // Clear existing graph
    nodes.clear();
    edges.clear();
    nextNodeId = 0;

    const int MIN_DISTANCE = 150;  // Minimum distance between nodes

    // Add nodes at random positions
    for (int i = 0; i < numNodes; i++) {
        bool validPosition = false;
        int x, y;

        // Retry until a valid position is found
        while (!validPosition) {
            x = GetRandomValue(100, GetScreenWidth() - 100);
            y = GetRandomValue(100, GetScreenHeight() - 100);

            validPosition = true;
            for (const auto& [id, node] : nodes) {
                if (CalculateDistance(x, y, node.x, node.y) < MIN_DISTANCE) {
                    validPosition = false;
                    break;
                }
            }
        }

        AddNode(x, y, "Node" + std::to_string(i));
    }

    // Add edges based on random probability
    for (int i = 0; i < numNodes; i++) {
        for (int j = i + 1; j < numNodes; j++) {
            float probability =
                static_cast<float>(GetRandomValue(0, 100)) / 100.0f;
            if (probability < edgeProbability) {
                int weight = GetRandomValue(1, maxWeight);
                AddEdge(i, j, weight, true);
            }
        }
    }

    std::cout << "Generated random graph with " << numNodes
              << " nodes and edge probability " << edgeProbability << std::endl;
}

// BFS with Animation
// BFS with Improved Highlighting
void GraphVisualizer::BFS(int startNode) {
    if (nodes.find(startNode) == nodes.end()) {
        std::cout << "Invalid start node for BFS: " << startNode << std::endl;
        return;
    }

    std::queue<int> nodeQueue;              // BFS queue
    std::unordered_map<int, bool> visited;  // Track visited nodes
    std::unordered_set<std::pair<int, int>, PairHash>
        visitedEdges;  // Track visited edges

    nodeQueue.push(startNode);
    visited[startNode] = true;

    while (!nodeQueue.empty()) {
        int currentNode = nodeQueue.front();
        nodeQueue.pop();

        // Highlight the current node as active
        HighlightNode(currentNode, YELLOW);
        std::cout << "Visiting node: " << currentNode << std::endl;

        // Traverse edges and visit neighbors
        for (const auto& edge : edges) {
            if (edge.from == currentNode && !visited[edge.to]) {
                // Highlight edge and add to visited edges
                visitedEdges.insert({edge.from, edge.to});
                HighlightEdge(edge, YELLOW);

                // Mark neighbor as visited and add to queue
                visited[edge.to] = true;
                nodeQueue.push(edge.to);

                // Animation step for edge
                BeginDrawing();
                DrawWithHighlights(visited, visitedEdges);
                EndDrawing();
                WaitForAnimationStep(ANIMATION_WAIT);
            }
        }

        // Mark current node as visited (blue) after processing
        HighlightNode(currentNode, BLUE);

        // Animation step for node
        BeginDrawing();
        DrawWithHighlights(visited, visitedEdges);
        EndDrawing();
        WaitForAnimationStep(ANIMATION_WAIT);
    }
}

void GraphVisualizer::DFS(int startNode) {
    if (nodes.find(startNode) == nodes.end()) {
        std::cout << "Invalid start node for DFS: " << startNode << std::endl;
        return;
    }

    std::stack<std::pair<int, int>>
        nodeStack;  // Stack now tracks edges as (from, to)
    std::unordered_map<int, bool> visited;  // Track visited nodes
    std::unordered_set<std::pair<int, int>, PairHash>
        visitedEdges;  // Track visited edges

    nodeStack.push(
        {-1, startNode});  // Start with (-1, startNode) to represent the root

    while (!nodeStack.empty()) {
        auto [fromNode, currentNode] = nodeStack.top();
        nodeStack.pop();

        // Highlight the edge leading to this node (if it exists)
        if (fromNode != -1 &&
            visitedEdges.count({fromNode, currentNode}) == 0) {
            visitedEdges.insert({fromNode, currentNode});
            HighlightEdge({fromNode, currentNode, 0}, YELLOW);

            // Animation step for edge
            BeginDrawing();
            DrawWithHighlights(visited, visitedEdges);
            EndDrawing();
            WaitForAnimationStep(500);  // Adjust delay as needed
        }

        if (!visited[currentNode]) {
            // Highlight the current node as active
            HighlightNode(currentNode, YELLOW);
            std::cout << "Visiting node: " << currentNode << std::endl;
            visited[currentNode] = true;

            // Animation step for node
            BeginDrawing();
            DrawWithHighlights(visited, visitedEdges);
            EndDrawing();
            WaitForAnimationStep(500);  // Adjust delay as needed
        }

        // Push unvisited neighbors onto the stack
        for (const auto& edge : edges) {
            if (edge.from == currentNode && !visited[edge.to]) {
                nodeStack.push({currentNode, edge.to});
            }
        }

        // Mark the current node as visited (blue) after processing neighbors
        HighlightNode(currentNode, BLUE);
    }

    // Final render
    BeginDrawing();
    DrawWithHighlights(visited, visitedEdges);
    EndDrawing();
}

// Wait for animation step
void GraphVisualizer::WaitForAnimationStep(int milliseconds) {
    std::this_thread::sleep_for(
        std::chrono::milliseconds(milliseconds));  // 500 ms delay
}

void GraphVisualizer::Draw() {
    // Draw nodes
    for (const auto& [id, node] : nodes) {
        DrawNode(node);
    }

    // Draw edges
    for (const auto& edge : edges) {
        DrawEdge(edge, LIGHTGRAY);
    }
}

void GraphVisualizer::DrawNode(const GraphNode& node) {
    DrawCircle(node.x, node.y, 20, LIGHTGRAY);
    DrawText(std::to_string(node.id).c_str(), node.x - 10, node.y - 10, 20,
             BLACK);

    // Draw the label if it exists
    if (!node.label.empty()) {
        DrawText(node.label.c_str(), node.x - 20, node.y + 25, 20, GREEN);
    }
}

void GraphVisualizer::DrawEdge(const GraphEdge& edge, Color color) {
    const GraphNode& fromNode = nodes[edge.from];
    const GraphNode& toNode = nodes[edge.to];

    // Draw the edge line
    Vector2 startPos = {static_cast<float>(fromNode.x),
                        static_cast<float>(fromNode.y)};
    Vector2 endPos = {static_cast<float>(toNode.x),
                      static_cast<float>(toNode.y)};
    DrawLineEx(startPos, endPos, 2.0f, color);

    // Calculate the position for the direction indicator
    float fraction = 0.95f;  // Position closer to the target node
    float dx = endPos.x - startPos.x;
    float dy = endPos.y - startPos.y;
    Vector2 indicatorPos = {startPos.x + dx * fraction,
                            startPos.y + dy * fraction};

    // Draw a circle as the direction indicator
    DrawCircle(static_cast<int>(indicatorPos.x),
               static_cast<int>(indicatorPos.y), 5, YELLOW);
}

void GraphVisualizer::DrawArrow(int startX, int startY, int endX, int endY) {
    float angle = atan2(endY - startY, endX - startX);
    float arrowLength = 20.0f;

    // Calculate arrowhead points
    float arrowX1 = endX - arrowLength * cos(angle - M_PI / 6);
    float arrowY1 = endY - arrowLength * sin(angle - M_PI / 6);
    float arrowX2 = endX - arrowLength * cos(angle + M_PI / 6);
    float arrowY2 = endY - arrowLength * sin(angle + M_PI / 6);

    // Draw the arrowhead with enhanced visibility
    DrawLine(endX, endY, arrowX1, arrowY1, RED);
    DrawLine(endX, endY, arrowX2, arrowY2, RED);
}

// Highlight a single node with a specific color
void GraphVisualizer::HighlightNode(int nodeId, Color color) {
    if (nodes.find(nodeId) != nodes.end()) {
        const GraphNode& node = nodes[nodeId];
        DrawCircle(node.x, node.y, 25, color);
        DrawText(std::to_string(node.id).c_str(), node.x - 10, node.y - 10, 20,
                 BLACK);
    }
}

// Highlight a single edge with a specific color
void GraphVisualizer::HighlightEdge(const GraphEdge& edge, Color color) {
    const GraphNode& fromNode = nodes[edge.from];
    const GraphNode& toNode = nodes[edge.to];

    Vector2 startPos = {static_cast<float>(fromNode.x),
                        static_cast<float>(fromNode.y)};
    Vector2 endPos = {static_cast<float>(toNode.x),
                      static_cast<float>(toNode.y)};
    DrawLineEx(startPos, endPos, 2.0f, color);
}

void GraphVisualizer::DrawWithHighlights(
    const std::unordered_map<int, bool>& visited,
    const std::unordered_set<std::pair<int, int>, PairHash>& visitedEdges) {
    // Draw edges
    for (const auto& edge : edges) {
        if (visitedEdges.count({edge.from, edge.to})) {
            DrawEdge(edge, RED);  // Visited edges are red
        } else {
            DrawEdge(edge, LIGHTGRAY);  // Unvisited edges are gray
        }
    }

    // Draw nodes
    for (const auto& [id, node] : nodes) {
        if (visited.count(id) && visited.at(id)) {
            HighlightNode(id, BLUE);  // Visited nodes are blue
        } else {
            HighlightNode(id, LIGHTGRAY);  // Unvisited nodes are gray
        }
    }
}
