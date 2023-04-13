
#include <cryptopp/filters.h>
#include <fmt/core.h>

#include <iostream>
#include <string>
#include <string_view>
#include <utility>

using CryptoPP::HashFilter;
using CryptoPP::StringSink;
using CryptoPP::StringSource;

#include <cryptopp/hmac.h>
using CryptoPP::HMAC;

#include <cryptopp/sha.h>
using CryptoPP::SHA1;
using CryptoPP::SHA256;

#include <cryptopp/hex.h>
using CryptoPP::HexEncoder;

// HMAC在线加密解密工具，用于在线使用HMAC算法将明文转换成密文。HAMC是建立在哈希算法之上的加密算法，也是一种不可逆的加密算法
// g++ hmac_test.cpp  -lcryptopp

std::string CalcHmacSHA1(std::string_view decodedSecretKey,
			 std::string_view request) {
    // Calculate HMAC
    HMAC<SHA1> hmac(
	reinterpret_cast<CryptoPP::byte const*>(decodedSecretKey.data()),
	decodedSecretKey.size());

    std::string calculated_hmac;
    auto sink = std::make_unique<StringSink>(calculated_hmac);

    auto filter = std::make_unique<HashFilter>(hmac, sink.get());
    sink.release();

    StringSource(reinterpret_cast<CryptoPP::byte const*>(request.data()),
		 request.size(), true, filter.get());  // StringSource
    filter.release();

    return calculated_hmac;
}

std::string CalcHmacSHA256(std::string_view decodedSecretKey, std::string_view request) {
    HMAC<SHA256> hmac(
	reinterpret_cast<CryptoPP::byte const*>(decodedSecretKey.data()),
	decodedSecretKey.size());

    std::string calculated_hmac;
    auto sink = std::make_unique<StringSink>(calculated_hmac);

    auto filter = std::make_unique<HashFilter>(hmac, sink.get());
    sink.release();

    StringSource(reinterpret_cast<CryptoPP::byte const*>(request.data()),
		 request.size(), true, filter.get());  // StringSource
    filter.release();

    return calculated_hmac;
}


/*
tkt_keys:
- 61435768-b03tktk
- 1ad8be5c-a5etktk
*/
int main() {
    std::string data{
	R"({"intent":"knock","msgId":"64362f80-d9c9-11ed-b4bb-c1452a497124","org":"org-jndqfvtssg","user":"wxm_zt_employee","otp":"531142","hostName":"patent.jd.com","os":"macOS","timeStamp":1681369451,"fingerPrint":"ba175838d6913122b26ec65e2d829347","hmac":"45d8b3eba217ca1b658d0d0025b10a6d11f62209fd9a7dd961b01049145153ca","deviceInfo":""})"};

    std::string result{
	"45d8b3eba217ca1b658d0d0025b10a6d11f62209fd9a7dd961b01049145153ca"};

    std::string key1{"61435768-b03tktk"};
    std::string key2{"1ad8be5c-a5etktk"};


	std::cout << "result:" << result << std::endl;

	std::string mac, encoded;	

	/// SHA1 HMAC哈希算法
	mac = CalcHmacSHA1(key1, data);
	encoded.clear();
	StringSource ss1(mac, true, new HexEncoder(new StringSink(encoded)));
	std::cout << "key1-sha1: " << encoded << std::endl;

	mac = CalcHmacSHA1(key2, data);
	encoded.clear();
	StringSource ss2(mac, true, new HexEncoder(new StringSink(encoded)));
	std::cout << "key2-sha1: " << encoded << std::endl;

	/// SHA256 HMAC哈希算法
	mac = CalcHmacSHA256(key1, data);
	encoded.clear();
	StringSource ss3(mac, true, new HexEncoder(new StringSink(encoded)));
	std::cout << "key1-sha256: " << encoded << std::endl;

	mac = CalcHmacSHA256(key2, data);
	encoded.clear();
	StringSource ss4(mac, true, new HexEncoder(new StringSink(encoded)));
	std::cout << "key2-sha256: " << encoded << std::endl;

	return 0;
}
/*
输出:
result:45d8b3eba217ca1b658d0d0025b10a6d11f62209fd9a7dd961b01049145153ca
key1-sha1: 0321B02717F92B4D3F24929CD746F06D9CB2BB8D
key2-sha1: DBCABEF33E4A6718D37ECABAD2B03108971274F2
key1-sha256: F23EDD53FAB4490A58ED7CD27AACD45A4254B0F82B67ABEF632AF6E17774CBB9
key2-sha256: 25F2FFBCF630808DA9780E8805F236D0C579845A2E4843DB7DC14F25179639AB
*/


