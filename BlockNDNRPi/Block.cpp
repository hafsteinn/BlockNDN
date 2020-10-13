#include "Block.h"
#include <string>

using namespace BlockNDN;

Block::Block() {

	prevBlock.resize(conf.getSHA256Size());
	s = conf.getPrefix();
	blockSize = conf.getInitBlockSize();
	time = 0;
	s = "";
};

Block::Block(std::vector<unsigned char> prevBlock, long time, long nonce, std::string s)
{
	int prevBlockSize = prevBlock.size();

	if (prevBlock.size() == conf.getSHA256Size())
	{
		this->prevBlock = prevBlock;
		blockSize = conf.getInitBlockSize() + s.length();
		this->time = time;
		this->nonce = nonce;
		this->s = s;
	}
};

Block::Block(std::vector<unsigned char> prevBlock, int blockSize, long time, long nonce, std::string s)
{
	if (prevBlock.size() == conf.getSHA256Size())
	{
		this->prevBlock = prevBlock;
		this->blockSize = blockSize;
		this->time = time;
		this->nonce = nonce;
		this->s = s;
	}
};
int Block::getBlockSize() { return blockSize; };
std::vector<unsigned char> Block::getBlockPrevHash() { return prevBlock; };
long Block::getBlockNonce() { return nonce; };
std::string Block::getBlockTxs() { return s; };
long Block::getBlockTime() { return time; };