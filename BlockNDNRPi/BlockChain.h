#include <vector>
#include "Block.h"
#include "sha.h"
#include "Utils.h"

namespace BlockNDN
{
	class BlockChain
	{
	private:
		std::vector<Block> blockChain;
		std::vector<unsigned char> genesisHash;
		Utils util;

	public:
		BlockChain();
		void addBlock(Block newBlock);
		Block getBlockFromBlockChain(int index);
		int getBlockChainLength();
		int getBlockChainCapacity();
		void clearBlockChain();
		Block getLastLocalBlock();
		std::vector<unsigned char> getGenesisHash();
		Block genesisBlockLoad();
		unsigned char* VarToBytes(Block& data);
	};
}


