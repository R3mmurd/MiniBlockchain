/*
  Mini Blockchain.
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

# include <blockchain.H>
# include <algorithm>

std::string Blockchain::proof_of_work(Block & blk, int difficulty)
{
  while (true)
    {
      std::string proof = blk.generate_hash();

      std::string ss = proof.substr(0, difficulty);

      if (all_of(ss.begin(), ss.end(), [] (auto c) { return c == '0'; }))
	{
	  blk.reset_nonce();
	  return proof;
	}

      blk.inc_nonce();
    }

  return "";
}

bool Blockchain::is_valid() const
{
  auto p = chain.begin();
  auto c = std::next(p);
  auto e = chain.end();

  while (c != e)
    {
      if (c->get_hash() != c->generate_hash())
	return false;

      if (c->get_previous_hash() != p->generate_hash())
	return false;

      ++c; ++p;
    }

  return true;
}

std::string Blockchain::to_string() const
{
  std::stringstream s;

  int i = 0;
  auto b = chain.begin();
  auto e = chain.end();

  s << "["
    << "{ block: " << i << ", content: " << b->to_string() << "}";

  ++b;

  while (b != e)
    {
      s << ", { block: " << ++i << ", content: " << b->to_string() << "}";
      ++b;
    }

  s << "]";

  return s.str();
}
