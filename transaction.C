/*
  Mini Blockchain.
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

# include <transaction.H>

Transaction transaction(const std::string & s, const std::string & r, double a)
{
  return std::make_tuple(s, r, a);
}

std::string to_str(const Transaction & t)
{
  std::stringstream s;
  s << "{"
    << "(sender: " << std::get<0>(t) << "), "
    << "(receiver: " << std::get<1>(t) << "), "
    << "(amount: " << std::get<2>(t) << ")"
    << "}";
  return s.str();
}

std::string to_str(const std::list<Transaction> & ts)
{
  std::stringstream s;
  s << "[";
  
  auto b = ts.begin();
  auto e = ts.end();

  if (b != e)
    {
      s << to_str(*b);
      ++b;
    }

  while (b != e)
    {
      s << ", " << to_str(*b);
      ++b;
    }

  s << "]";
  return s.str();
}
