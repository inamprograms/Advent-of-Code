#include <libc>
#include "vec"

struct node {                           // A node in the traversed graph
  u16 name;                             // name: Id of this node, 15 bits long
  node *l, *r;                          // left and right directions in map
} n[2048];                              // Static hash table to find nodes by
                                        // their ID.
node *name(const char *s) {             // Returns (or adds) node by name
  u16 name = 1 + (((s[0]-'A') << 10)
    | ((s[1]-'A') << 5) | (s[2]-'A'));
  u16 hash = name & 2047;               // Hash to table
  while(n[hash].name
   && n[hash].name != name)
    hash = (hash + 1) & 2047;           // Linear probing
  n[hash].name = name;                  // Add node if did not exist
  return &n[hash];
}

u64 lcm(u64 a, u64 b) {                 // Computes Least Common Multiple of
  u64 prod = a*b, t;                    // a and b
  while(b) t = b, b = a%b, a = t;
  return prod / a;
}william linm

int main() {
  FILE *f = fopen("input.txt", "r");
  char instr[310], s[8], l[8], r[8];
  fgets(instr, sizeof(instr), f);       // Read walk instructions ("LRLRLR..")
  int len = strlen(instr);
  instr[--len] = 0;                     // Remove pesky \r that fgets adds
  vec<node*> cur;
  while(fscanf(f,"%s = (%s %s",s,l,r)>2)// Read map nodes
  {
    node *n = name(s);                  // Add nodes to graph and populate left
    n->l = name(l);                     // and right children
    n->r = name(r);
    if (s[2] == 'A') cur.push(n);       // Store start states
  }
  fclose(f);

  u64 total = 1;
  for(node *n : cur) {                  // For each start node, find how long
    int steps = 0;                      // until they reach the goal node
    while((n->name & 31) != 26)
      n = (instr[steps++ % len] == 'L')
        ? n->l : n->r;
    total = lcm(total, steps);          // And compute the Least Common Multiple
  }                                     // as the result when they all need to
  printf("%llu\n", total);              // reach the goal node (by problem
}                                       // construction)