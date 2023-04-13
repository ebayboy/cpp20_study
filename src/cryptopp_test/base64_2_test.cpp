
#include <cryptopp/base64.h>
#include <fmt/core.h>

// 官方wiki: https://www.cryptopp.com/wiki/Base64Decoder

// g++ base64_2_test.cpp -lcryptopp -lfmt

using namespace std;
using namespace CryptoPP;

using word64 = size_t;

int main(int argc, char **argv) {

	CryptoPP::byte decoded[] = {0xFF, 0xEE, 0xDD, 0xCC, 0xBB, 0xAA, 0x99, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x00};
    string encoded;

    Base64Encoder encoder;
    encoder.Put(decoded, sizeof(decoded));
    encoder.MessageEnd();

    word64 size = encoder.MaxRetrievable();
    if (size) {
	encoded.resize(size);
	encoder.Get((CryptoPP::byte *)&encoded[0], encoded.size());
    }

	fmt::println("encoded:{}", encoded);

    return 0;
}

