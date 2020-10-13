#pragma once
#include "CheckBlock.h"
#include "BlockChain.h"
#include "CheckBlockUtils.h"
#include <vector>

namespace BlockNDN
{

	class BlockChainProxy : public CheckBlock
	{
	protected:
		BlockChain bChain;
		CheckBlockUtils cbu;
		Utils util;
	public:
		BlockChainProxy();
		BlockChainProxy(BlockChain bChain);
		std::vector<unsigned char> getBlockChainGenesisHash();
		Block getBlock(std::vector<unsigned char> previousBlock);
		bool addBlock(Block block);
		std::vector<unsigned char> getPreviousHash();
		int getBlockHeight();
		bool isBlockLegal(Block block, std::vector<unsigned char> prevBlockHash);
	};

}
