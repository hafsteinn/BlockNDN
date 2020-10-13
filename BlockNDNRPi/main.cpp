#include <iostream>
#include "BlockChainProxy.h"
#include "VolumeProduction.h"
#include "Miner.h"

using namespace BlockNDN;

int main(void)
{
	std::cout << "**********************Starting BlockNDNRPi**********************" << std::endl;

	BlockChainProxy blockChainProxy; //Create a new blockchain with one block (the genesis block)
	VolumeProduction vp;

	try
	{
		//This should (probably) be run as a seperate thread
		vp.initVolumeProduction(blockChainProxy);

		bool minerFlag = false;
		std::vector<unsigned char> flag;

		while (true)
		{
			 
			//Check if a new block has been created
			if (flag == blockChainProxy.getPreviousHash()) {
				minerFlag = true;
			}
			else {
				minerFlag = false;
			}

			flag = blockChainProxy.getPreviousHash(); //get the last block on the blockchain

			//create a prefix with flag as the local latest block
			//issue an interest with this prefix


			//Miners
			if (!minerFlag)
			{
				//add "if timeout" for this specific consumer
				Miner miner = Miner(flag, blockChainProxy); //give the newest block to the miner
				miner.run(flag); //start a miner (TODO: change this to a thread)
			}
		}

	}
	catch (const std::exception&)
	{
		//error handling
	}

	int asdf;
	std::cout << "**********************End of BlockNDNRPi**********************" << std::endl;
	std::cin >> asdf;
}
