//! Unit Tests for MPAGSCipher Cipher Classes
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Cipher.hpp"
#include "CipherMode.hpp"

#include <string>

bool testCipher(const Cipher& cipher, const CipherMode mode,
                const std::string& inputText, const std::string& outputText) {

    std::string testOutputText = cipher.applyCipher(inputText, mode);
    if (testOutputText == outputText) {
        return true;
    }
    return false;

}

TEST_CASE("Cipher encryption/decryption", "[ciphers]") {

    

}