#include "graph.h"
#include <random>

Graph create_barabasi_albert_graph(int n, int d) {
  std::random_device rd{};
  std::mt19937 eng{rd()};

  std::vector<int> us;
  std::vector<int> vs;

  std::vector<int> M(2*n*d);

  for (int v = 0; v < n; v++) {
    for (int i = 0; i < d; i++) {
      int index = 2*((v*d) + i);
      M[index] = v;
      std::uniform_int_distribution<int> dist{0, index};
      int r = dist(eng);
      M[index+1] = M[r];
    }
  }

  for (int i = 0; i < (n*d); i++) {
    int index = 2 * i;
    int u = M[index];
    int v = M[index+1];
    us.push_back(u+1);
    vs.push_back(v+1);
  }

  return make_graph(n, us, vs);
}


