#pragma once
#include <vector>
#include "BlockChainProxy.h"

namespace BlockNDN
{
	class Miner
	{
	private:
		std::vector<unsigned char> prevHash;
		BlockChainProxy bchainProxy;
	public:
		Miner();
		Miner(std::vector<unsigned char> prevHash);
		Miner(std::vector<unsigned char> prevHash, BlockChainProxy bchainProxy);
		void run(std::vector<unsigned char> prevHash);
	};
}