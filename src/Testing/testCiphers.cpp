//! Unit Tests for MPAGSCipher Cipher Classes
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Cipher.hpp"
#include "CipherFactory.hpp"
#include "ProcessCommandLine.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "ViginereCipher.hpp"

#include <memory> 
#include <string>
#include <vector>

bool testCipher(const std::unique_ptr<Cipher>& cipher, const CipherMode mode,
                const std::string& inputText, const std::string& outputText) {

    std::string testOutputText = cipher->applyCipher(inputText, mode);
    if (testOutputText == outputText) {
        return true;
    }
    return false;
}

std::string testInput = "HELLOWORLD";
std::vector<std::unique_ptr<Cipher>> inventory;
std::vector<std::string> testOutputs = {"MJQQTBTWQI", "OBQKHQVPQMFX", "AIDEYAMKPV"};
std::string pDecryptOutput = "HELXLOWORLDZ";


ProgramSettings tempSettings{
    false, false, "", "", 
    "5", CipherMode::Encrypt, CipherType::Caesar
};

TEST_CASE("Cipher encryption/decryption", "[ciphers]") {

    inventory.push_back(cipherFactory(tempSettings));
    tempSettings.cipherKey = "testkey";
    tempSettings.cipherType = CipherType::Playfair;
    inventory.push_back(cipherFactory(tempSettings));
    tempSettings.cipherType = CipherType::Viginere;
    inventory.push_back(cipherFactory(tempSettings));

    for (size_t i; i < inventory.size(); i++) {
        
        // test encrypt
        REQUIRE(testCipher(inventory[i], CipherMode::Encrypt, 
                           testInput, testOutputs[i]));
        if (i == 1) {
            // test playfair decryption
            REQUIRE(testCipher(inventory[i], CipherMode::Decrypt, 
                               testOutputs[i], pDecryptOutput));
        }
        else {
            // test other cipher decryption
            REQUIRE(testCipher(inventory[i], CipherMode::Decrypt,
                               testOutputs[i], testInput));
        }
    }
}