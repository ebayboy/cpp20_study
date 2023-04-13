
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
using CryptoPP::SHA256;

std::string CalcHmacSHA256(std::string_view decodedSecretKey,
			   std::string_view request) {
    // Calculate HMAC
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

int main() { std::cout << CalcHmacSHA256("key", "data"); }
