#include "CheckBlockUtils.h"
#include <iostream>
#include <chrono>

using namespace BlockNDN;

bool CheckBlockUtils::checkData(std::string s) {
	//tjékka hvort þetta sé alveg örugglega stærðfræðidæmi
	if (s == "")
		return true;
};

bool CheckBlockUtils::checkBlockSize(Block block) {
	if (block.blockSize < conf.getInitBlockSize() || block.blockSize > conf.getMaxBlockSize()) {
		return false;
	}
	else {
		if (block.blockSize == conf.getInitBlockSize() + block.s.length())
		{
			return true;
		}
		return false;
	}
};

bool CheckBlockUtils::checkPrevHash(std::vector<unsigned char> prevHash, Block block) {
	if (prevHash == block.prevBlock)
	{
		return true;
	}
	return false;
};

bool CheckBlockUtils::NrawCheckProofOfWork(Block block) {

	//notice that this function return FALSE after finishing the pow;
	std::vector<unsigned char> blockHash = util.digestsha256(block);

	//Just some debug stuff to write to console
	//std::string str(blockHash.begin(), blockHash.end());
	//std::cout << str << std::endl;

	//check if leading zeros are sufficient
	//if (blockHash[0] == 0 && blockHash[1] == 0 && blockHash[2] == 0 &&  blockHash[3] < 31)
	//return false;
	//else
	//return true;
	 
	//DEBUG START *********************
	//instead of doing the POW, we will just return false so the block will be accepted
	return false;
	//DEBUG END *********************
};