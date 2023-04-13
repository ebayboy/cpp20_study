
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

///BUILD:  g++ hmac_test.cpp  -lcryptopp -lfmt

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

    std::string key1{"b3d16048-25btktk"};
    std::string key2{"61435768-b03tktk"};

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

	/* 
	   2) "nf1.zt.fw"
	   3) "{\"Ip\":\"10.226.143.198\",\"Judge\":\"A06-R08-I138-135-534VANB.JD.LOCAL\",\"TimeStamp\":\"1681377282\",\"Hmac\":\"68a891d5cbf8800902f217991e4ce7e62e8ae632\"}"
	   1) "message"
	   2) "nf1.zt.fw"
	   3) "{\"Judge\":\"A06-R08-I138-135-534VANB.JD.LOCAL\",\"Hmac\":\"2359d78f2e06017490aba2ee03456d2c355ab747\",\"TimeStamp\":\"1681377285\",\"Ip\":\"10.226.143.198\"}"
	*/

	/*
        hash.Write([]byte(t.Ip))
        hash.Write([]byte(t.TimeStamp))
        hash.Write([]byte(t.Judge))
        token := hex.EncodeToString(hash.Sum(nil))
	*/	
	std::string Ip {"10.226.143.198"};
	std::string TimeStamp {"1681377282"};
	std::string Judge {"A06-R08-I138-135-534VANB.JD.LOCAL"};
	
	data = Ip + TimeStamp + Judge;

	//验证方法：通过openssl命令 echo -n "10.226.143.1981681377282A06-R08-I138-135-534VANB.JD.LOCAL" | openssl dgst -sha1 -hmac "b3d16048-25btktk"
	//SHA1(stdin)= 68a891d5cbf8800902f217991e4ce7e62e8ae632
	std::cout << "hmac:68a891d5cbf8800902f217991e4ce7e62e8ae632\n";
	mac = CalcHmacSHA1(key1, data);
	encoded.clear();
	StringSource ss11(mac, true, new HexEncoder(new StringSink(encoded)));
	fmt::println("key:{} data:{} hmac:{}", key1, data, encoded);

	mac = CalcHmacSHA1(key2, data);
	encoded.clear();
	StringSource ss12(mac, true, new HexEncoder(new StringSink(encoded)));
	fmt::println("key:{} data:{} hmac:{}", key2, data, encoded);

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


