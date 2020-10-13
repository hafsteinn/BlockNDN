#include "Utils.h"
#include <iostream>
#include "sha.h"

using namespace BlockNDN;

std::vector<unsigned char> Utils::digestsha256(Block block) {
	std::vector<unsigned char> newBlockByte;
	std::vector<unsigned char> blockHash;

	newBlockByte = blockToByteArray(block);
	string hash = picosha2::bytes_to_hex_string(newBlockByte);
	std::vector<unsigned char> returnHash(hash.begin(), hash.end());


	return returnHash;
};

std::vector<unsigned char> Utils::digestsha256(std::string s) {
	std::vector<unsigned char> blockHash;

	string hash = picosha2::hash256_hex_string(s);
	std::vector<unsigned char> returnHash(hash.begin(), hash.end());

	return returnHash;
};

std::vector<unsigned char> Utils::blockToByteArray(Block newBlock) {
	std::vector<unsigned char> empty;
	std::vector<unsigned char> byteArray;
	std::vector<unsigned char> blockSize = intToBytes(newBlock.blockSize);
	std::vector<unsigned char> time = longToBytes(newBlock.time);
	std::vector<unsigned char> nonce = longToBytes(newBlock.nonce);
	std::vector<unsigned char> string(newBlock.s.begin(), newBlock.s.end());

	
	bool prevBlockCopy = byteArrayCopy(byteArray, newBlock.prevBlock, 0, newBlock.prevBlock.size());

	bool blockSizeCopy = byteArrayCopy(byteArray, blockSize, newBlock.prevBlock.size(), newBlock.prevBlock.size() + blockSize.size());

	bool timeCopy = byteArrayCopy(byteArray, time, newBlock.prevBlock.size() + blockSize.size(),newBlock.prevBlock.size() + blockSize.size()+ time.size());

	bool nonceCopy = byteArrayCopy(byteArray, longToBytes(newBlock.nonce), newBlock.prevBlock.size() + blockSize.size() + time.size(),
		newBlock.prevBlock.size() + blockSize.size() + time.size() + nonce.size());

	bool stringCopy = byteArrayCopy(byteArray, string, newBlock.prevBlock.size() + blockSize.size() + time.size() + nonce.size(),
		newBlock.prevBlock.size() + blockSize.size() + time.size() + nonce.size() + string.size());

	if (prevBlockCopy && blockSizeCopy && timeCopy && nonceCopy && stringCopy) {
		return byteArray;
	}
	else {
		return empty;
	}
};

std::vector<unsigned char> Utils::intToBytes(int data) {
	std::vector<unsigned char> bytes;

	bytes.push_back((data & 0xff));
	bytes.push_back((data & 0xff00) >> 8);
	bytes.push_back((data & 0xff0000) >> 16);
	bytes.push_back((data & 0xff000000) >> 24);

	return bytes;
};

std::vector<unsigned char> Utils::longToBytes(long data) {
	std::vector<unsigned char> bytes;

	bytes.push_back((data & 0xff));
	bytes.push_back((data >> 8) & 0xff);
	bytes.push_back((data >> 16) & 0xff);
	bytes.push_back((data >> 24) & 0xff);
	bytes.push_back((data >> 32) & 0xff);
	bytes.push_back((data >> 40) & 0xff);
	bytes.push_back((data >> 48) & 0xff);
	bytes.push_back((data >> 56) & 0xff);

	return bytes;
};

bool Utils::byteArrayCopy(std::vector<unsigned char> &array, std::vector<unsigned char> bytea, int from, int to) {
	int arraySpace = to - from;
	int byteSpace = bytea.size();
	if (arraySpace < byteSpace) {
		cout << "Error: not enough space for array copy!";
		return false;
	}
	int i, j;
	for (i = from, j = conf.getOffsetInit(); i < to && j < byteSpace; i++, j++) {
		array.push_back(bytea[j]);
	}
	return true;
};

//bool Utils::byteArrayCopy(std::vector<unsigned char>& array, std::vector<unsigned char> bytea, int from, int to) {
//	int arraySpace = to - from;
//	int byteSpace = bytea.size();
//	if (arraySpace < byteSpace) {
//		cout << "Error: not enough space for array copy!";
//		return false;
//	}
//	int i, j;
//	for (i = from, j = conf.getOffsetInit(); i < to && j < byteSpace; i++, j++) {
//		array.push_back(bytea[j]);
//	}
//	return true;
//};
