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

# ifndef BLOCKCHAIN_H
# define BLOCKCHAIN_H

# include <block.H>

// A representation for a Blockchain
class Blockchain
{
  std::list<Block> chain;

  void gen_genesis_block()
  {
    chain.push_back(Block({}, "0"));
  }

  std::string proof_of_work(Block &, int difficulty = 2);

public:
  Blockchain()
  {
    gen_genesis_block();
  }

  std::tuple<std::string, Block *> add_block(const std::list<Transaction> & ts)
  {
    Block new_block(ts, chain.back().get_hash());
    std::string proof = proof_of_work(new_block);
    chain.push_back(new_block);
    return std::make_tuple(proof, &chain.back());
  }

  bool is_valid() const;

  std::string to_string() const;
};

# endif // BLOCKCHAIN_H
