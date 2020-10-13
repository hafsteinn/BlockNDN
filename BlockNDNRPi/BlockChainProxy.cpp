#include "BlockChainProxy.h"
#include "sha.h"
#include <iostream>


using namespace BlockNDN;

BlockChainProxy::BlockChainProxy() {
	std::cout << "[BlockChainProxy]: creating a new blockchain..." << std::endl;
	bChain = BlockChain();
};

BlockChainProxy::BlockChainProxy(BlockChain bChain) {
	bChain = bChain;
};

std::vector<unsigned char> BlockChainProxy::getBlockChainGenesisHash() {
	return bChain.getGenesisHash();
};

Block BlockChainProxy::getBlock(std::vector<unsigned char> previousBlock) {
	
	for (int i = 0; i < bChain.getBlockChainLength(); i++)
	{
		if (previousBlock == bChain.getBlockFromBlockChain(i).prevBlock)
			return bChain.getBlockFromBlockChain(i);
	}

	Block empty;
	return empty;
};

bool BlockChainProxy::addBlock(Block block) {
	if (isBlockLegal(block, getPreviousHash()))
	{
		bChain.addBlock(block);
		return true;
	}
	return false;
};

std::vector<unsigned char> BlockChainProxy::getPreviousHash() {
	return util.digestsha256(bChain.getLastLocalBlock());
};

int BlockChainProxy::getBlockHeight() {
	return bChain.getBlockChainLength();
};

bool BlockChainProxy::isBlockLegal(Block block, std::vector<unsigned char> prevBlockHash) {
	bool checkSize, checkPrevB, checkData, checkPOW;

	checkPOW = !cbu.NrawCheckProofOfWork(block);
	if (block.prevBlock == bChain.getGenesisHash())
	{
		return checkPOW;
	}
	checkSize = cbu.checkBlockSize(block);
	checkPrevB = cbu.checkPrevHash(prevBlockHash, block);
	checkData = cbu.checkData(block.s);
	return checkSize && checkPrevB && checkData && checkPOW;
};