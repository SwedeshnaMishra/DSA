//3203. Find Minimum Diameter After Merging Two Trees

// There exist two undirected trees with n and m nodes, numbered from 0 to n - 1 and from 0 to m - 1, respectively. You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
// You must connect one node from the first tree with another node from the second tree with an edge.
// Return the minimum possible diameter of the resulting tree.
// The diameter of a tree is the length of the longest path between any two nodes in the tree.

// Example 1:
// Input: edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]
// Output: 3
// Explanation:
// We can obtain a tree of diameter 3 by connecting node 0 from the first tree with any node from the second tree.

// Example 2:
// Input: edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], edges2 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]
// Output: 5
// Explanation:
// We can obtain a tree of diameter 5 by connecting node 0 from the first tree with node 0 from the second tree.

// Constraints:
// 1 <= n, m <= 105
// edges1.length == n - 1
// edges2.length == m - 1
// edges1[i].length == edges2[i].length == 2
// edges1[i] = [ai, bi]
// 0 <= ai, bi < n
// edges2[i] = [ui, vi]
// 0 <= ui, vi < m
// The input is generated such that edges1 and edges2 represent valid trees.

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> adjList1 = buildAdjList(n, edges1);
        vector<vector<int>> adjList2 = buildAdjList(m, edges2);

        int diameter1 = findDiameter(n, adjList1);
        int diameter2 = findDiameter(m, adjList2);

        int combinedDiameter =
            ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

        return max({diameter1, diameter2, combinedDiameter});
    }

private:
    vector<vector<int>> buildAdjList(int size, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(size);
        for (auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    }

    int findDiameter(int n, vector<vector<int>>& adjList) {
        auto [farthestNode, _] = findFarthestNode(n, adjList, 0);

        auto [_, diameter] = findFarthestNode(n, adjList, farthestNode);
        return diameter;
    }

    
    pair<int, int> findFarthestNode(int n, vector<vector<int>>& adjList, int sourceNode) {
        queue<int> nodesQueue;
        vector<bool> visited(n, false);
        nodesQueue.push(sourceNode);
        visited[sourceNode] = true;

        int maximumDistance = 0, farthestNode = sourceNode;

        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            for (int i = 0; i < size; ++i) {
                int currentNode = nodesQueue.front();
                nodesQueue.pop();
                farthestNode = currentNode;

                for (int neighbor : adjList[currentNode]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        nodesQueue.push(neighbor);
                    }
                }
            }
            if (!nodesQueue.empty()) maximumDistance++;
        }
        return {farthestNode, maximumDistance};
    }
};
