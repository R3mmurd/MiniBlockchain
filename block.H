/*
  Mini Blockchain.
  
  Author: Alejandro Mujica (aledrums@gmail.com)
*/

# ifndef BLOCK_H
# define BLOCK_H

# include <sha256.H>

# include <transaction.H>
# include <datetime.H>

/// Represents a block in the Blockchain
class Block
{
  std::list<Transaction> transactions;
  std::string hash;
  std::string previous_hash;
  std::string timestamp;
  int nonce;

public:
  Block(const std::list<Transaction> & _transactions,
	const std::string & _previous_hash, int _nonce = 0)
    : transactions(_transactions), hash(), previous_hash(_previous_hash),
      timestamp(s_now()), nonce(_nonce)
  {
    hash = generate_hash();
  }

  Block(std::list<Transaction> && _transactions,
	std::string && _previous_hash, int _nonce = 0)
    : transactions(std::forward<std::list<Transaction>>(_transactions)), hash(),
      previous_hash(std::forward<std::string>(_previous_hash)),
      timestamp(s_now()), nonce(_nonce)
  {
    hash = generate_hash();
  }

  std::string generate_hash() const
  {
    std::string block_contents = timestamp + to_str(transactions) +
      std::to_string(nonce) + previous_hash;
    return sha256(block_contents);
  }

  std::string to_string() const
  {
    std::stringstream s;
    s << "{"
      << "(timestamp: " << timestamp << "), "
      << "(transactions: " << to_str(transactions) << "), "
      << "(current hash: " << generate_hash() << ")"
      << "(previous hash: " << previous_hash << ")"
      << "}";
    return s.str();
  }

  const std::string & get_hash() const
  {
    return hash;
  }

  const std::string & get_previous_hash() const
  {
    return previous_hash;
  }

  void inc_nonce()
  {
    ++nonce;
  }

  void reset_nonce()
  {
    nonce = 0;
  }
};

# endif // BLOCK_H
