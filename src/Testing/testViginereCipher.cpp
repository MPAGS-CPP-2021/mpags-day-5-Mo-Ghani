//! Unit Tests for MPAGSCipher ViginereCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


#include "ViginereCipher.hpp"

#include <string>

TEST_CASE("Viginere Cipher encryption/decryption", "[viginere]")
{
    // test default
    ViginereCipher vc{""};
    std::string outputText = vc.applyCipher("HELLOWORLD",
                                            CipherMode::Encrypt); 
    REQUIRE(outputText == "HELLOWORLD");

    // test encryption with key
    ViginereCipher vc{"key"};
    std::string outputText = vc.applyCipher("HELLOWORLD",
                                            CipherMode::Encrypt);
    REQUIRE(outputText == "RIJVSUYVJN");

    // test decryption with key
    ViginereCipher vc{"key"};
    std::string outputText = vc.applyCipher("RIJVSUYVJN",
                                            CipherMode::Encrypt);
    REQUIRE(outputText == "HELLOWORLD");

}
