#include "graph.h"
#include <algorithm>
#include <iostream>

int Graph::get_num_nodes() {
  return adj_list.size();
}

int Graph::get_num_edges() {
  int num = 0;
  for (auto const& e : adj_list) {
    Node first = e.first;
    std::vector<Node> conn = e.second;
    for (Node second : conn) {
      if (second < first && is_neighbor(second, first))
        continue;
      num++;
    } 
  }
  return num;
}

bool Graph::is_neighbor(Node u, Node v) {
  std::vector<Node> nbrs = get_neighbors(u);
  return std::find(nbrs.begin(), nbrs.end(), v) != nbrs.end();
}

std::vector<Node> Graph::get_neighbors(Node u) {
  return adj_list[u];
}

std::map<int, Node> Graph::get_id_to_node_map() {
  std::map<int, Node> id_map;
  for (auto const& e : adj_list) {
    Node node = e.first;
    id_map[node.id] = node;
  }
  return id_map;
}

Graph make_graph(int num_nodes, std::vector<int> u, std::vector<int> v) {
  Graph graph;
  count = 0;
  for(int i = 0; i < num_nodes; i++) {
    Node node;
    graph.adj_list[node] = std::vector<Node>(); 
  }
  std::map<int, Node> id_map = graph.get_id_to_node_map();
  for(int i = 0; i < u.size(); i++) {
    Node first = id_map[u[i]];
    Node second = id_map[v[i]];
    graph.adj_list[first].push_back(second);
    graph.adj_list[second].push_back(first);
  }
  return graph;
}






