#include "project3.h"
#include "graph.h"
#include <iostream>
#include <fstream>

void out_degree_dist(int n, std::map<int, int> dd) {
  std::ofstream f;
  std::string fname("dd-");
  fname = fname + std::to_string(n) + ".csv";
  f.open(fname, std::ios::trunc);
  f << "degree,count" << std::endl;
  for (auto const& e : dd) {
    int degree = e.first;
    int count = e.second;
    f << degree << "," << count << std::endl;
  }
  f.close();
}

void out_diam_cc(std::ofstream& f, int n, float diam, float cc) {
  f << n << "," << diam << "," << cc << std::endl;
}

int main() {

  int reps = 5;
  int d = 5;
  std::vector<int> N1{2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};

  std::ofstream f;
  f.open("diam_cc.csv", std::ios::trunc);
  f << "n,diameter,cc" << std::endl;
  
  for (int n : N1) {
    float avg_diameter = 0.0;
    float avg_cc = 0.0;
    for (int i = 0; i < reps; i++) {
      Graph graph = create_barabasi_albert_graph(n, d);
      avg_diameter += (float) get_diameter(graph);
      avg_cc += get_clustering_coefficient(graph);
    }
    avg_diameter /= (float) reps;
    avg_cc /= (float) reps;
    out_diam_cc(f, n, avg_diameter, avg_cc);
  }

  f.close();

  std::vector<int> N2{1000, 10000, 100000};

  for (int n : N2) {
    Graph graph = create_barabasi_albert_graph(n, d);
    std::map<int, int> dd = get_degree_distribution(graph);
    out_degree_dist(n, dd);
  }
  
  return 0;
}
