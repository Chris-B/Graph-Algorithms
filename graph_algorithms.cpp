#include "graph.h"
#include <queue>
#include <algorithm>

int lsp(Graph graph, Node start) {
  std::queue<std::pair<Node, int>> q;
  q.push(std::pair<Node, int>(start, 0));
  std::map<Node, bool> visited;
  visited[start] = true;
  int longest = 0;
  
  while(!q.empty()) {
    std::pair<Node, int> front = q.front();
    q.pop();
    std::vector<Node> nbrs = graph.get_neighbors(front.first);
    int dist = front.second + 1;
    if (dist > longest)
      longest = dist;
    for (Node nbr : nbrs) {
      if (!visited[nbr]) {
        q.push(std::pair<Node, int>(nbr, dist));
        visited[nbr] = true;
      }
    }
  }
  
  return longest;
}

int get_diameter(Graph graph) {
  int diameter = 0;
  std::map<Node, std::vector<Node>> map = graph.adj_list;
  for (auto const& e : map) {
    Node start = e.first;
    int longest = lsp(graph, start);
    if (longest > diameter)
      diameter = longest;
  }
  return diameter;
}

float get_clustering_coefficient(Graph graph) {
  std::map<Node, std::vector<Node>> map = graph.adj_list;
  float closed = 0;
  float all = 0;
  for (auto const& e : map) {
    Node node = e.first;
    std::vector<Node> nbrs = e.second;
    if (nbrs.size() < 2)
      continue;
    for (Node nbr1 : nbrs) {
      for (Node nbr2 : nbrs) {
        if (nbr2 == nbr1)
          continue;
        std::vector<Node> thirds = graph.get_neighbors(nbr1);
        if (std::find(thirds.begin(), thirds.end(), nbr2) != thirds.end())
          closed += 1.0;
        all += 1.0;
      }
    }
  }
  return closed/all;
}

std::map<int, int> get_degree_distribution(Graph graph) {
  int n = graph.get_num_nodes();
  std::map<Node, std::vector<Node>> map = graph.adj_list;
  std::map<int, int> dd;
  for (auto const& e : map) {
    int degree = e.second.size();
    dd[degree] += 1;
  }
  return dd;
}




