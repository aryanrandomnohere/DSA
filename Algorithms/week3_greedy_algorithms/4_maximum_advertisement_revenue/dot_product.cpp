#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  std::cout << "\nOriginal vectors:\n";
  std::cout << "A: ";
  for (auto val : a) std::cout << val << " ";
  std::cout << "\nB: ";
  for (auto val : b) std::cout << val << " ";
  std::cout << "\n";

  // Sort both arrays in descending order to maximize dot product
  std::sort(a.begin(), a.end(), std::greater<int>());
  std::sort(b.begin(), b.end(), std::greater<int>());

  std::cout << "\nSorted vectors:\n";
  std::cout << "A (sorted): ";
  for (auto val : a) std::cout << val << " ";
  std::cout << "\nB (sorted): ";
  for (auto val : b) std::cout << val << " ";
  std::cout << "\n";

  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    long long product = (long long)a[i] * b[i];
    std::cout << "a[" << i << "] * b[" << i << "] = "
              << a[i] << " * " << b[i] << " = " << product << "\n";
    result += product;
  }

  std::cout << "Final dot product: " << result << "\n\n";
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);

  std::cout << "Enter vector A:\n";
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  std::cout << "Enter vector B:\n";
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  std::cout << "\nCalculating maximum dot product...\n";
  std::cout << max_dot_product(a, b) << std::endl;
}

