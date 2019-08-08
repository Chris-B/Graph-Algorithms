#include "project3.h"

static int count = 0;

class Node {

  public:
    int id;
 
    Node() {
      id = ++count;
    }

    bool operator==(const Node& other) const {
      return id == other.id;
    }

    bool operator<(const Node& other) const {
      return id < other.id;
    }

};
