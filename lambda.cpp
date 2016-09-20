#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct isOdd
{
  bool operator() (std::pair<int,string> pair)
  {
    return (pair.first%2);
  }
};

struct isMultipleOf
{
  isMultipleOf(int x): m_multiple(x) { }

  bool operator() (std::pair<int,string> pair)
  {
    return (pair.first%m_multiple);
  }

  private:
    int m_multiple;
};

struct sumUP
{
  sumUP(int &sum):m_sum(sum) { }
  void operator() (int val)
  {
    m_sum += val;
  }
  private:
    int &m_sum;
};

int main()
{

  size_t count, multiple=3;
  int a=19, b=20, sum=0;
  std::map<int, string> m_ref = { {10, "SG"}, {2, "RE"}, {30, "ER"}, {4, "HH"}, {33, "LK"} };
  std::set<int> m_set = { 12, 34, 23, 12, 444, 1344 };
  std::vector<int> m_vec = { 12, 34, 23, 12, 444, 1344 };


  cout << "----------- USE OPERAND ----------- " << endl;

  count = count_if( m_ref.begin(), m_ref.end(), isOdd());
  cout << "Number of references having odd number are : " << count << endl;
  count = count_if( m_ref.begin(), m_ref.end(), isMultipleOf(multiple));
  cout << "Number of references having 5 multipliers are : " << count << endl;
  for_each(m_set.begin(), m_set.end(), sumUP(sum));
  cout << "Sum of set varibles is : " << sum << endl;
  
  cout << "\n----------- USE LAMBDA ----------- " << endl;

  count = count_if( m_ref.begin(), m_ref.end(), [](std::pair<int, string> pair) { return pair.first%2; } );
  cout << "Number of references having odd number are : " << count << endl;
  count = count_if( m_ref.begin(), m_ref.end(), [=](std::pair<int, string> pair) { return pair.first%multiple; } );
  cout << "Number of references having 5 multipliers are : " << count << endl;
  sum = 0;
  for_each(m_set.begin(), m_set.end(), [&sum](int val) { sum += val; } );
  cout << "Sum of set varibles is : " << sum << endl;

  m_vec.erase(std::remove_if(m_vec.begin(), m_vec.end(), [b]( int val ) {  return b < val ; } ), m_vec.end());
  // Generic function call
  //std::auto isGreater = [](std::auto x, std::auto y) { return x>y; }; /* C++14 requires cc5.2 version */
  auto isGreater = [](int a, int b) ->decltype(a>b) { return (a>b); };
  cout << "a is greater than b ? : " << isGreater(1,2) << endl;

  return 0;
}
