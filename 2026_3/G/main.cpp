#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Node {
  int next[4];
  int link;

  // Most relevant gene ending at this node.
  int gene;
  int len;

  Node() {
    fill(next, next + 4, -1);
    link = 0;
    gene = INF;
    len = 0;
  }
};

int id(char c) {
  if (c == 'A')
    return 0;
  if (c == 'C')
    return 1;
  if (c == 'G')
    return 2;
  return 3; // T
}

struct Query {
  int l, r, idx;

  bool operator<(const Query &other) const { return r < other.r; }
};

struct SegmentTree {
  int n;
  vector<int> tree;

  SegmentTree(int n) : n(n) { tree.assign(4 * n, INF); }

  void update(int node, int l, int r, int pos, int value) {
    if (l == r) {
      tree[node] = min(tree[node], value);
      return;
    }

    int mid = (l + r) / 2;

    if (pos <= mid)
      update(node * 2, l, mid, pos, value);
    else
      update(node * 2 + 1, mid + 1, r, pos, value);

    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
  }

  void update(int pos, int value) { update(1, 0, n - 1, pos, value); }

  int query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql)
      return INF;

    if (ql <= l && r <= qr)
      return tree[node];

    int mid = (l + r) / 2;

    return min(query(node * 2, l, mid, ql, qr),
               query(node * 2 + 1, mid + 1, r, ql, qr));
  }

  int query(int l, int r) {
    if (l > r)
      return INF;

    return query(1, 0, n - 1, l, r);
  }
};

void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  fast_io();

  string T;
  cin >> T;

  int G;
  cin >> G;

  vector<Node> trie;
  trie.reserve(500005);
  trie.emplace_back();

  /*
   * Build trie.
   *
   * Genes are inserted in relevance order:
   * gene 1, gene 2, ...
   *
   * Therefore if a node receives a gene, the first
   * one is automatically the most relevant one.
   */
  for (int gene = 1; gene <= G; gene++) {
    string s;
    cin >> s;

    int v = 0;

    for (char c : s) {
      int x = id(c);

      if (trie[v].next[x] == -1) {
        trie[v].next[x] = trie.size();
        trie.emplace_back();
      }

      v = trie[v].next[x];
    }

    if (gene < trie[v].gene) {
      trie[v].gene = gene;
      trie[v].len = s.size();
    }
  }

  /*
   * Build Aho-Corasick failure links.
   */
  queue<int> q;

  for (int c = 0; c < 4; c++) {
    int u = trie[0].next[c];

    if (u == -1) {
      trie[0].next[c] = 0;
    } else {
      trie[u].link = 0;
      q.push(u);
    }
  }

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    /*
     * A gene can also be matched through a failure link.
     */
    int f = trie[v].link;

    if (trie[f].gene < trie[v].gene) {
      trie[v].gene = trie[f].gene;
      trie[v].len = trie[f].len;
    }

    for (int c = 0; c < 4; c++) {
      int u = trie[v].next[c];

      if (u == -1) {
        trie[v].next[c] = trie[f].next[c];
      } else {
        trie[u].link = trie[f].next[c];
        q.push(u);
      }
    }
  }

  int N = T.size();

  /*
   * For every starting position i:
   *
   * bestGene[i] = most relevant gene starting at i
   * endPos[i]   = its ending position
   */
  vector<int> bestGene(N, INF);
  vector<int> endPos(N, INF);

  int state = 0;

  for (int i = 0; i < N; i++) {
    state = trie[state].next[id(T[i])];

    if (trie[state].gene != INF) {
      int len = trie[state].len;

      int start = i - len + 1;

      bestGene[start] = trie[state].gene;
      endPos[start] = i;
    }
  }

  /*
   * Sort queries by their right endpoint.
   */
  int Q;
  cin >> Q;

  vector<Query> queries(Q);

  for (int i = 0; i < Q; i++) {
    int L, R;
    cin >> L >> R;

    --L;
    --R;

    queries[i] = {L, R, i};
  }

  sort(queries.begin(), queries.end());

  /*
   * Sort/activate starting positions according to their
   * ending position.
   */
  vector<int> positions;

  for (int i = 0; i < N; i++) {
    if (bestGene[i] != INF) {
      positions.push_back(i);
    }
  }

  sort(positions.begin(), positions.end(),
       [&](int a, int b) { return endPos[a] < endPos[b]; });

  SegmentTree seg(N);

  vector<int> answer(Q, -1);

  int ptr = 0;

  for (const Query &query : queries) {

    /*
     * Activate every gene occurrence whose ending position
     * is inside the current right boundary.
     */
    while (ptr < (int)positions.size() && endPos[positions[ptr]] <= query.r) {
      int start = positions[ptr];

      seg.update(start, bestGene[start]);

      ptr++;
    }

    /*
     * We now need a gene whose starting position is inside
     * [L, R].
     *
     * Since only occurrences with end <= R have been
     * activated, every result is completely contained
     * within [L, R].
     */
    int result = seg.query(query.l, query.r);

    if (result != INF)
      answer[query.idx] = result;
  }

  for (int x : answer) {
    cout << x << '\n';
  }

  return 0;
}
