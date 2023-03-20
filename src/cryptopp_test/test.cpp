
#include <iostream>
#include <cryptopp/base64.h>
#include <cryptopp/sha.h>
#include <cryptopp/filters.h>
#include <cryptopp/config_int.h>

using namespace std;
using namespace CryptoPP;

// g++ test.cpp -lcryptopp  -I /usr/local/include/cryptopp -L /usr/local/lib/
void test_base64() 
{
	// "CBC Mode Test", without '\0'
	unsigned char plainText[] = {67, 66, 67, 32, 77, 111, 100, 101, 32, 84, 101, 115, 116};
	string encoded;

	Base64Encoder encoder;
	encoder.Put(plainText, sizeof(plainText));
	encoder.MessageEnd();

	word64 size = encoder.MaxRetrievable();
	if (size) {
		encoded.resize(size);
		encoder.Get((CryptoPP::byte *) &encoded[0], encoded.size());
	}

	cout << "encoded:" << encoded << endl;

	string decoded;
	Base64Decoder decoder;
	decoder.Put((CryptoPP::byte*) encoded.data(), encoded.size());
	decoder.MessageEnd();

	size = decoder.MaxRetrievable();
	if (size && size <= SIZE_MAX) {
		decoded.resize(size);
		decoder.Get((CryptoPP::byte *) &decoded[0], decoded.size());
	}
	cout << "encoded:" << decoded << endl;
}

void test_md5()
{

}

void test_aes()
{

}

int main()
{
	test_base64();

	return 0;
}
