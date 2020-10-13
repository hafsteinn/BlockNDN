#include "Configure.h"

using namespace BlockNDN;


int* Configure::getPublicKey() { return DEFAULT_RSA_PUBLIC_KEY_DER; };
int* Configure::getPrivateKey() { return DEFAULT_RSA_PRIVATE_KEY_DER; };
int Configure::getInitBlockSize() { return INITBLOCKSIZE; };
string Configure::getPrefix() { return blockNDNGetBlockPrefix; };
int Configure::getMaxBlockSize() { return MAXBLOCKSIZE; };
int Configure::getOffsetInit() { return OFFSETINIT; };
int Configure::getSHA256Size() { return SHA256SIZE; };
int Configure::getSizeOfInt() { return SIZEOFINT; };
int Configure::getSizeOfLong() { return SIZEOFLONG; };


