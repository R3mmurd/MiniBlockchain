/*
 * Updated to use fixed width integer types, Alejandro Mujica 2018
 * (aledrums@gmail.com)
 *
 * Updated to C++, zedwood.com 2012
 * Based on Olivier Gay's version
 * See Modified BSD License below: 
 *
 * FIPS 180-2 SHA-224/256/384/512 implementation
 * Issue date:  04/30/2005
 * http://www.ouah.org/ogay/sha2/
 *
 * Copyright (C) 2005, 2007 Olivier Gay <olivier.gay@a3.epfl.ch>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

# ifndef SHA256_H
# define SHA256_H

# include <string>

class SHA256
{
protected:
  static const uint32_t sha256_k[];
  static constexpr unsigned int SHA224_256_BLOCK_SIZE = (512/8);
  
public:
  SHA256()
  {
    init();
  }
  void init();
  void update(const unsigned char * message, unsigned int len);
  void final(unsigned char * digest);
  static constexpr unsigned int DIGEST_SIZE = (256 / 8);
 
protected:
  void transform(const unsigned char * message, unsigned int block_nb);
  unsigned int m_tot_len;
  unsigned int m_len;
  unsigned char m_block[2 * SHA224_256_BLOCK_SIZE];
  uint32_t m_h[8];
};
 
std::string sha256(const std::string & input);

# ifndef SHA2_SHFR
# define SHA2_SHFR(x, n)    (x >> n)
# endif
# ifndef SHA2_ROTR
# define SHA2_ROTR(x, n)   ((x >> n) | (x << ((sizeof(x) << 3) - n)))
# endif
# ifndef SHA2_ROTL
# define SHA2_ROTL(x, n)   ((x << n) | (x >> ((sizeof(x) << 3) - n)))
# endif
# ifndef SHA2_CH
# define SHA2_CH(x, y, z)  ((x & y) ^ (~x & z))
# endif
# ifndef SHA2_MAJ
# define SHA2_MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
# endif
# ifndef SHA256_F1
# define SHA256_F1(x) (SHA2_ROTR(x,  2) ^ SHA2_ROTR(x, 13) ^ SHA2_ROTR(x, 22))
# endif
# ifndef SHA256_F2
# define SHA256_F2(x) (SHA2_ROTR(x,  6) ^ SHA2_ROTR(x, 11) ^ SHA2_ROTR(x, 25))
# endif
# ifndef SHA256_F3
# define SHA256_F3(x) (SHA2_ROTR(x,  7) ^ SHA2_ROTR(x, 18) ^ SHA2_SHFR(x,  3))
# endif
# ifndef SHA256_F4
# define SHA256_F4(x) (SHA2_ROTR(x, 17) ^ SHA2_ROTR(x, 19) ^ SHA2_SHFR(x, 10))
# endif
# ifndef SHA2_UNPACK32
# define SHA2_UNPACK32(x, str)		  \
  {                                       \
    *((str) + 3) = (uint8_t) ((x));	  \
    *((str) + 2) = (uint8_t) ((x) >>  8); \
    *((str) + 1) = (uint8_t) ((x) >> 16); \
    *((str) + 0) = (uint8_t) ((x) >> 24); \
  }
# endif
# ifndef SHA2_PACK32
# define SHA2_PACK32(str, x)		 \
  {                                      \
    *(x) =   ((uint32_t) *((str) + 3))	 \
      | ((uint32_t) *((str) + 2) <<  8)	 \
      | ((uint32_t) *((str) + 1) << 16)	 \
      | ((uint32_t) *((str) + 0) << 24); \
  }
# endif

# endif // SHA256_H
