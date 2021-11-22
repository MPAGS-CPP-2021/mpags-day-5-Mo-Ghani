#include "ViginereCipher.hpp"

#include "CaesarCipher.hpp"
#include "Alphabet.hpp"

#include <iostream>
#include <string>
#include <algorithm>

ViginereCipher::ViginereCipher(const std::string& key)
{
    this->setKey(key);
}
void ViginereCipher::setKey(const std::string& key)
{
    key_ = key;

    // transform key to upper case
    std::transform(std::begin(key_), std::end(key_), std::begin(key_),
                   ::toupper);
    // erase any non alpha characters
    key_.erase(std::remove_if(std::begin(key_), std::end(key_),
                              [](char c) { return !std::isalpha(c); }),
               std::end(key_));

    
    for (size_t i = 0; i < key_.size(); i++) {

        // A = 65, ... , Z = 90
        // position [A] = 0, ... , position [Z] = 25 
        size_t position = key_[i] - 65;

        // create Caesar Cipher
        CaesarCipher letterCipher{position};

        // insert pair of char and CaesarCipher into charLookup_
        charLookup_.insert({key_[i], letterCipher});
    }    
}

std::string ViginereCipher::applyCipher(const std::string& inputText,
                                        const CipherMode cipherMode) const
{

    size_t keyLength = key_.size();
    if (keyLength == 0) {
        return inputText;
    }

    std::string outputText;
    for (size_t i = 0; i < inputText.size(); i++) {

        // find ith letter, considering wrapping
        char ithLetter = key_[i % keyLength];

        // find cipher for ithLetter
        const CaesarCipher& ithCipher{charLookup_.at(ithLetter)};

        // cast ithLetter to string, find output from ithCipher
        std::string ithInputLetter = std::string(1, inputText[i]);
        std::string outputLetter = ithCipher.applyCipher(ithInputLetter,
                                                         cipherMode);

        // concatenate outputText and outputLetter
        outputText += outputLetter;
    }

    return outputText;
}
