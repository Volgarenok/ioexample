#include <iostream>
#include <limits>

namespace durka
{
  struct Data
  {
    Data(int aa, int bb):
     a(aa),
     b(bb)
    {}
    int get_a() const
    {
      return a;
    }
    int get_b() const
    {
      return b;
    }
   private:
    int a, b;
  };

  std::istream & operator>>(std::istream & in, Data & value)
  {
    std::istream::sentry guard(in);
    if (!guard)
    {
      return in;
    }
    int a = 0, b = 0;
    in >> a >> b;
    if (in)
    {
      value = Data(a, b);
    }
    return in;
  }
  std::ostream & operator<<(std::ostream & out, const Data & value)
  {
    std::ostream::sentry guard(out);
    if (!guard)
    {
      return out;
    }
    out << value.get_a() << " " << value.get_b();
    return out;
  }
}

int main()
{
  durka::Data d(0, 0);
  if (!(std::cin >> d))
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
    if (!(std::cin >> d))
    {
      std::cerr << "Error\n";
      return 1;
    }
  }
  std::cout << d << "\n";
  return 0;
}
