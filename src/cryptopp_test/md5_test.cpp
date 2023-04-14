
#include <iostream>
#include <sstream>
#include <utility>
#include <iomanip>
#include <fmt/core.h>

#include <cryptopp/md5.h>
#include <cryptopp/hex.h>

using namespace std;
using namespace CryptoPP;

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#define MD5_CRYPT_LEN 16

inline std::string encode_md5(const std::string& data)
{
	//计算MD5 digest hash
	CryptoPP::MD5 hash;
	CryptoPP::byte digest[CryptoPP::MD5::DIGESTSIZE];
	hash.CalculateDigest(digest, (CryptoPP::byte*)data.c_str(), data.size());

	// 将md5 digest转换成hex string 格式
	std::string res;
	CryptoPP::HexEncoder encoder;
	encoder.Attach(new CryptoPP::StringSink(res));
	encoder.Put(digest, sizeof(digest));
	encoder.MessageEnd();

	return res;
}

int main(int argc, char **argv)
{
	string s2 = encode_md5("hello world");
	fmt::println("s2:{}", s2);

	return 0;
}

