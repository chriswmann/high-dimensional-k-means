#include <Rcpp.h>
#include <algorithm>
#include <vector>

// [[Rcpp::export]]
Rcpp::NumericMatrix permutations(int n)
{

  std::vector<int> v;
  std::vector<std::vector<int>> data;

  for (int i = 1; i <= n; i++) {
    v.push_back(i);
    do {
      if (i == n)
        data.push_back(v);
        Rcpp::checkUserInterrupt();
    }
    while(std::next_permutation(v.begin(), v.end()));
  }
  Rcpp::NumericMatrix output(data.size(), data[0].size());
  for (auto i = 0; i < data.size(); i++) {
    for (auto j = 0; j < data[0].size(); j++) {
      output(i, j) = data[i][j];
    }
  }
  return output;
}


// [[Rcpp::export]]
float maxC(std::vector<float> v) {
  return *std::max_element(v.begin(), v.end());
}