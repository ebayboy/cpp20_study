using namespace std;

/*
加密：
echo -n
'{"org":"token_check","uid":"user1","clientIp":"127.0.0.2","tktLife":2000000000}'
| openssl enc -e -aes-128-cbc -nosalt -k abcdefgh12345678
vFUUnB5dTwKkWG/D8Uu/EzfzkbtWUMaCUEnAMtuqUqgF1ovVWhjnF3n5OYNedPEmKzrNLTOYUSHcDze5CSRf+l8wZKKcGD2QE6OJNN6PL9E=

# 解密
echo -n
vFUUnB5dTwKkWG/D8Uu/EzfzkbtWUMaCUEnAMtuqUqgF1ovVWhjnF3n5OYNedPEmKzrNLTOYUSHcDze5CSRf+l8wZKKcGD2QE6OJNN6PL9E=
|  base64 -d | openssl enc -d -aes-128-cbc -nosalt -k abcdefgh12345678
{"org":"token_check","uid":"user1","clientIp":"127.0.0.2","tktLife":2000000000}
*/

//  g++ aes_test.cpp  -lcryptopp -lfmt

#include <cryptopp/aes.h>
#include <cryptopp/filters.h>
#include <cryptopp/modes.h>
#include <fmt/core.h>
#include <stdio.h>

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

byte key[CryptoPP::AES::DEFAULT_KEYLENGTH], iv[CryptoPP::AES::BLOCKSIZE];
void initKV() {
    memset(key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH);
    memset(iv, 0x00, CryptoPP::AES::BLOCKSIZE);

    // 或者也可以
    /*
    char tmpK[] = "1234567890123456";
    char tmpIV[] = "1234567890123456";
    for (int j = 0; j < CryptoPP::AES::DEFAULT_KEYLENGTH; ++j)
    {
	key[j] = tmpK[j];
    }
    for (int i = 0; i < CryptoPP::AES::BLOCKSIZE; ++i)
    {
	iv[i] = tmpIV[i];
    }
    */
}

string encrypt(string plainText) {
    string cipherText;

    CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);
    CryptoPP::StreamTransformationFilter stfEncryptor(
	cbcEncryption, new CryptoPP::StringSink(cipherText));
    stfEncryptor.Put(reinterpret_cast<const unsigned char*>(plainText.c_str()),
		     plainText.length() + 1);
    stfEncryptor.MessageEnd();

    string cipherTextHex;
    for (int i = 0; i < cipherText.size(); i++) {
	char ch[3] = {0};
	sprintf(ch, "%02x", static_cast<byte>(cipherText[i]));
	cipherTextHex += ch;
    }

    return cipherTextHex;
}

void writeCipher(string output) {
    ofstream out("/tmp/cipher.data");
    out.write(output.c_str(), output.length());
    out.close();

    cout << "writeCipher finish " << endl << endl;
}

int main() {
    string text =
	R"({"org":"token_check","uid":"user1","clientIp":"127.0.0.2","tktLife":2000000000})";
    cout << "text : " << text << endl;

    initKV();
    string cipherHex = encrypt(text);
    cout << "cipher : " << cipherHex << endl;
    writeCipher(cipherHex);

    return 0;
}

