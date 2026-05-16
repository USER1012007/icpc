#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

const int ALPHABET_SIZE = 26;

struct AhoCorasick {
  struct Node {
    int next[ALPHABET_SIZE] = {0};
    int fail = 0;
    int count = 0;
  };

  vector<Node> nodes;
  vector<string> strings;

  AhoCorasick() { clear(); }

  void clear() {
    nodes.clear();
    nodes.emplace_back();
    strings.clear();
  }

  void insert(const string &s) {
    int u = 0;
    for (char c : s) {
      int idx = c - 'a';
      if (!nodes[u].next[idx]) {
        nodes[u].next[idx] = nodes.size();
        nodes.emplace_back();
      }
      u = nodes[u].next[idx];
    }
    nodes[u].count++;
  }

  void build() {
    queue<int> q;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
      if (nodes[0].next[i]) {
        q.push(nodes[0].next[i]);
      }
    }

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (int i = 0; i < ALPHABET_SIZE; i++) {
        int v = nodes[u].next[i];
        if (v) {
          nodes[v].fail = nodes[nodes[u].fail].next[i];
          nodes[v].count += nodes[nodes[v].fail].count;
          q.push(v);
        } else {
          nodes[u].next[i] = nodes[nodes[u].fail].next[i];
        }
      }
    }
  }

  long long query(const string &text) {
    int u = 0;
    long long matches = 0;
    for (char c : text) {
      int idx = c - 'a';
      u = nodes[u].next[idx];
      matches += nodes[u].count;
    }
    return matches;
  }
};

struct DynamicAhoCorasick {
  vector<AhoCorasick> sub_automata;

  void insert(const string &s) {
    AhoCorasick new_ac;
    new_ac.strings.push_back(s);

    int pos = 0;
    while (pos < sub_automata.size() && !sub_automata[pos].strings.empty()) {
      for (const string &str : sub_automata[pos].strings) {
        new_ac.strings.push_back(str);
      }
      sub_automata[pos].clear();
      pos++;
    }

    for (const string &str : new_ac.strings) {
      new_ac.insert(str);
    }
    new_ac.build();

    if (pos == sub_automata.size()) {
      sub_automata.push_back(move(new_ac));
    } else {
      sub_automata[pos] = move(new_ac);
    }
  }

  long long query(const string &text) {
    long long total = 0;
    for (auto &ac : sub_automata) {
      if (!ac.strings.empty()) {
        total += ac.query(text);
      }
    }
    return total;
  }
};

int main() {
  fast_io();

  int m;
  cin >> m;

  DynamicAhoCorasick ac_add;
  DynamicAhoCorasick ac_del;

  while (m--) {
    int type;
    string s;
    cin >> type >> s;

    if (type == 1) {
      ac_add.insert(s);
    } else if (type == 2) {
      ac_del.insert(s);
    } else if (type == 3) {
      long long ans = ac_add.query(s) - ac_del.query(s);
      cout << ans << "\n";
      cout.flush();
    }
  }

  return 0;
}
