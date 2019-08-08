#include "node.h"

class Graph : public AbstractGraph
{

  public:

    std::map<Node, std::vector<Node>> adj_list;

    int get_num_nodes();
    int get_num_edges();
    bool is_neighbor(Node u, Node v);
    std::vector<Node> get_neighbors(Node u);

    std::map<int, Node> get_id_to_node_map();

};


