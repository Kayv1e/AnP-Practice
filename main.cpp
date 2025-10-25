#include <climits>
#include <iostream>

bool isOverflowed(unsigned n)
{
  if (n > 0 && n > UINT_MAX / n) {
    return 1;
  }
  return 0;
}

bool isPyth(unsigned a, unsigned b, unsigned c)
{
  bool p = a * a + b * b == c * c;
  p = p || b * b + c * c == a * a;
  p = p || a * a + c * c == b * b;
  return p;
}

int main()
{
  using u_t = unsigned;
  size_t count = 0;
  u_t a = 0, b = 0, c = 0;
  std::cin >> c >> b;

  while (std::cin >> a) {
    count += isPyth(a, b, c) ? 1 : 0;
    if (isOverflowed(a) || isOverflowed(b) || isOverflowed(c)) {
      std::cerr << "Unsigned integer overflow\n";
      return 2;
    }
    c = b;
    b = a;
  }

  if (std::cin.eof()) {
    std::cout << count;
    std::cout << "\n";
  } else if (std::cin.fail()) {
    std::cerr << "Input error\n";
    return 1;
  }
}
