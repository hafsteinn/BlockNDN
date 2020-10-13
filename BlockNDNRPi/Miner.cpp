#include "Miner.h"
#include "Mining.h"
#include <iostream>
#include <chrono>
#include <string>

using namespace BlockNDN;

Miner::Miner() {
	prevHash; //TODO: this is supposted to be this.prevHash = null
};

Miner::Miner(std::vector<unsigned char> prevHash)
{
	prevHash = prevHash;
};

Miner::Miner(std::vector<unsigned char> prevHash, BlockChainProxy bchainProxy)
{
	prevHash = prevHash;
	bchainProxy = bchainProxy;
};

void Miner::run(std::vector<unsigned char> prevHash)
{
	Mining newBlock = Mining(prevHash);

	if (newBlock.createNewBlock("10 + 7 = 17")) {

		if (bchainProxy.isBlockLegal(newBlock.getMiningBlock(), bchainProxy.getPreviousHash())) {
			Block miningANewBlock = newBlock.getMiningBlock();
			int time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch()).count();
			cout << "[***LOCAL***] A new block comes out: [SUCCESS] : {Time}: " << time << endl; 
			cout << "                                               : {Transaction}: " << miningANewBlock.s << endl;
			cout << "                                               : {Nonce}: " << miningANewBlock.nonce << endl;
			//TODO: create a producer with correct prefix (conf.prefix + mininganewblock.prevblock)
			//TODO: run the producer
		}
	}
};
