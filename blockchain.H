/*
  Mini Blockchain.
  
  Author: Alejandro Mujica (aledrums@gmail.com)
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
