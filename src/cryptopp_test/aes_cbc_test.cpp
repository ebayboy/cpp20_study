
#include <aes.h>
#include <cryptopp/hex.h>
#include <cryptopp/base64.h>
#include <cryptopp/modes.h>
#include <fmt/core.h>

#include <iostream>
#include <utility>

using namespace std;
using namespace CryptoPP;

/*
加密：
echo -n
'{"org":"token_check","uid":"user1","clientIp":"127.0.0.2","tktLife":2000000000}'
| openssl enc -e -aes-128-cbc -nosalt -k abcdefgh12345678
vFUUnB5dTwKkWG/D8Uu/EzfzkbtWUMaCUEnAMtuqUqgF1ovVWhjnF3n5OYNedPEmKzrNLTOYUSHcDze5CSRf+l8wZKKcGD2QE6OJNN6PL9E=

openssl && iv : 若是指定了-K，那么一定要指定-iv，否则就要靠自动生成的，也就是-k, 小写-k并不是指定密码，而是用于生成key和iv的一串序列

# 解密
echo -n
vFUUnB5dTwKkWG/D8Uu/EzfzkbtWUMaCUEnAMtuqUqgF1ovVWhjnF3n5OYNedPEmKzrNLTOYUSHcDze5CSRf+l8wZKKcGD2QE6OJNN6PL9E=
|  base64 -d | openssl enc -d -aes-128-cbc -nosalt -k abcdefgh12345678
{"org":"token_check","uid":"user1","clientIp":"127.0.0.2","tktLife":2000000000}
*/

//TODO: 不使用IV加密

std::string CBC_AESEncryptStr(std::string sKey, std::string sIV,
			      const char *plainText) {
    std::string outstr;

    // 填key
    SecByteBlock key(AES::MAX_KEYLENGTH);
    memset(key, 0x30, key.size());
    sKey.size() <= AES::MAX_KEYLENGTH
	? memcpy(key, sKey.c_str(), sKey.size())
	: memcpy(key, sKey.c_str(), AES::MAX_KEYLENGTH);

    // 填iv
    CryptoPP::byte iv[AES::BLOCKSIZE];
    memset(iv, 0x30, AES::BLOCKSIZE);
    sIV.size() <= AES::BLOCKSIZE ? memcpy(iv, sIV.c_str(), sIV.size())
				 : memcpy(iv, sIV.c_str(), AES::BLOCKSIZE);

    AES::Encryption aesEncryption((CryptoPP::byte *)key, AES::MAX_KEYLENGTH);

    CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);

    StreamTransformationFilter cbcEncryptor(
	//cbcEncryption, new HexEncoder(new StringSink(outstr))); //输出hex编码
	cbcEncryption, new Base64Encoder(new StringSink(outstr))); //输出base64编码
    cbcEncryptor.Put((CryptoPP::byte *)plainText, strlen(plainText));
    cbcEncryptor.MessageEnd();

    return outstr;
}

int main(int argc, char **argv) {
	std::string key{"abcdefgh12345678"};
	std::string iv {"cbe449bca48bd36d"};
	std::string data{ R"({"org":"token_check","uid":"user1","clientIp":"127.0.0.2","tktLife":2000000000})" };
	std::string outstr = CBC_AESEncryptStr(key, iv, data.data());
	fmt::println("out:{}", outstr);

    return 0;
}

