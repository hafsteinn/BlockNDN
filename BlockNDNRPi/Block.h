#pragma once

#include <string>
#include <vector>
#include "Configure.h"

namespace BlockNDN
{
	class Block
	{
		Configure conf;

	public:
		std::vector<unsigned char> prevBlock;	//32
		int blockSize;							//4
		long time;								//8
		long nonce;								//8
		std::string s;
		Block();
		Block(std::vector<unsigned char> prevBlock, long time, long nonce, std::string s);
		Block(std::vector<unsigned char> prevBlock, int blockSize, long time, long nonce, std::string s);
		int  getBlockSize();
		std::vector<unsigned char> getBlockPrevHash();
		long getBlockNonce();
		std::string getBlockTxs();
		long getBlockTime();

	};

}