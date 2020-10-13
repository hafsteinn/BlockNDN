#include "Mining.h"
#include "CheckBlockUtils.h"
#include <chrono>
#include <iostream>

using namespace BlockNDN;

Mining::Mining() {
	block = Block();
};

Mining::Mining(std::vector<unsigned char> prevHash) {
	block = Block();
	block.prevBlock = prevHash;
};

bool Mining::createNewBlock(std::string txs) {
	block.s = txs; //simple math equation instead of transactions for simplicity
	block.blockSize = conf.getInitBlockSize() + block.s.length();

	bool flag = false;

	while (!flag) {
		block.time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch()).count();
		std::cout << block.time << std::endl;
		std::srand(block.time);
		block.nonce = std::rand();
		flag = miningBlock();
	}
};

bool Mining::miningBlock() {
	long max = std::numeric_limits<long long int>::max();
	long min = std::numeric_limits<long long int>::min();

	CheckBlockUtils cbu;

	while (cbu.NrawCheckProofOfWork(block)) {
		std::cout << block.nonce << std::endl;
		if (block.nonce < max - 2 && block.nonce > min) {
			block.nonce++;
		}
		else return false;
	}
	return true;
};

Block Mining::getMiningBlock() {
	return block;
};
bool Mining::getResult() {
	return result;
};

bool isBlockLegal(Block block, std::vector<unsigned char> prevBlockHash) {
	bool checkSize = false;
	bool checkPrevB = false;
	bool checkData = false;

	CheckBlockUtils cbu;

	checkSize = cbu.checkBlockSize(block);
	checkPrevB = cbu.checkPrevHash(prevBlockHash, block);
	checkData = cbu.checkData(block.s);

	return checkSize && checkPrevB && checkData;
};