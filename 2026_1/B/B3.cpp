#include <bits/stdc++.h>
using namespace std;

string clasify(string numero) {
  int n = stoi(numero);
  if ((n % 10000) == 0) {

    int count_zero = 0;
    while (n % 10 == 0) {
      n /= 10;
      count_zero++;
    }

    if (n == 1) {
      return "10^{" + to_string(count_zero) + "}";
    } else {
      string temp = to_string(n);
      if (temp.size() > 1) {
        count_zero += (temp.size() - 1);
        temp.insert(1, ".");
      }
      return temp + "\\cdot10^{" + to_string(count_zero) + "}";
    }
  }

  return numero;
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  cin.ignore();
  string output = "";

  for (int i = 0; i < n; i++) {

    string line;
    getline(cin, line);

    int count_n = 0;

    for (int j = 0; j < line.size(); j++) {

      bool act_isdigit = isdigit(line[j]);
      bool prev_isnotdigit = (j == 0) || !isdigit(line[j - 1]);

      if (act_isdigit && prev_isnotdigit)
        count_n++;
    }

    string numbers[count_n];
    int positions[count_n][2];
    int i_num = 0;

    for (int j = 0; j < count_n; j++) {
      numbers[j] = "";
      positions[j][1] = 0;
    }

    for (int j = 0; j < line.size(); j++) {

      bool act_isdigit = isdigit(line[j]);

      if (act_isdigit) {

        bool prev_isnotdigit = (j == 0) || !isdigit(line[j - 1]);
        bool next_isnotdigit = (j == line.size() - 1) || !isdigit(line[j + 1]);
        numbers[i_num] += line[j];
        positions[i_num][1]++;

        if (prev_isnotdigit)
          positions[i_num][0] = j;
        if (next_isnotdigit)
          i_num++;
      }
    }

    for (int j = (count_n - 1); j >= 0; j--) {
      string temp = numbers[j];
      bool prev_isvoid =
          (positions[j][0] == 0) || (line[positions[j][0] - 1] == ' ');
      bool next_isvoid =
          (positions[j][0] + positions[j][1] - 1 == ((int)line.size() - 1)) ||
          (line[positions[j][0] + positions[j][1]] == ' ');
      if (prev_isvoid && next_isvoid) {
        temp = clasify(numbers[j]);
      }
      line.replace(positions[j][0], positions[j][1], temp);
    }

    output = output + line + "\n";
  }

  cout << output;

  return 0;
}
