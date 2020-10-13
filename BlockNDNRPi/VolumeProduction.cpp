#include "VolumeProduction.h"
#include "BlockChainProxy.h"
#include <iostream>
#include "Utils.h"

using namespace BlockNDN;

void VolumeProduction::initVolumeProduction(BlockChainProxy bchainProxy) {
	std::cout << "Starting initVolumeProduction..." << std::endl;

	int height = bchainProxy.getBlockHeight();
	std::cout << height << std::endl;
	Utils util;

	std::vector<unsigned char> prevBlockHash = bchainProxy.getBlockChainGenesisHash();
	Block block = bchainProxy.getBlock(prevBlockHash);
	
	if (height > 1) {
		while (&block != 0) { //nullcheck

			//create a producer that will listed to the prefix of prevBlockHash

			prevBlockHash = util.digestsha256(block); //create a hash from the current block
			block = bchainProxy.getBlock(prevBlockHash); //use the hash to get the next block in the chain, if it exists
		}
	}

	std::cout << "End of initVolumeProduction" << std::endl;
};