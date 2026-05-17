#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

template <int ALPHA = 26, char BASE = 'a'> struct Trie {
  struct Node {
    int next[ALPHA];
    int pass = 0;
    int end = 0;

    Node() { memset(next, -1, sizeof(next)); }
  };

  vector<Node> nodes;

  Trie() { nodes.emplace_back(); }

  void clear() {
    nodes.clear();
    nodes.emplace_back();
  }

  void reserve(int total_expected_nodes) {
    nodes.reserve(total_expected_nodes + 1);
  }

  void insert(const string &s) {
    int u = 0;
    nodes[u].pass++;
    for (char c : s) {
      int idx = c - BASE;
      if (nodes[u].next[idx] == -1) {
        nodes[u].next[idx] = nodes.size();
        nodes.emplace_back();
      }
      u = nodes[u].next[idx];
      nodes[u].pass++;
    }
    nodes[u].end++;
  }

  int count_words(const string &s) const {
    int u = 0;
    for (char c : s) {
      int idx = c - BASE;
      if (nodes[u].next[idx] == -1)
        return 0;
      u = nodes[u].next[idx];
    }
    return nodes[u].end;
  }

  int count_prefix(const string &s) const {
    int u = 0;
    for (char c : s) {
      int idx = c - BASE;
      if (nodes[u].next[idx] == -1)
        return 0;
      u = nodes[u].next[idx];
    }
    return nodes[u].pass;
  }
};

Trie<> trie;

int main() {
  fast_io();
  trie.reserve(1e5);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    trie.insert(s);
  }

  vector<int> tmp;
  for (int i = 0; i <= 25; i++) {
    tmp.push_back(trie.count_prefix(string(1, 'a' + i)));
  }
  sort(tmp.rbegin(), tmp.rend(), greater<int>());
  int counter = 0;

  for (int i = 0; i < 26 && counter < k; i++) {
    if (tmp[i] > 0) {
      counter++;
      k -= tmp[i];
    }
  }

  cout << counter;
}
