/*
  This file is part of a simple example of a Blockchain implementation.

  Copyright (C) 2018 by Alejandro J. Mujica

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

  Any user request of this software, write to 

  Alejandro Mujica

  aledrums@gmail.com
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
