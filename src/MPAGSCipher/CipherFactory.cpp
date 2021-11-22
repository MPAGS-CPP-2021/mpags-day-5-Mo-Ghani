#include "ProcessCommandLine.hpp"
#include "CipherType.hpp"
#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "ViginereCipher.hpp"

#include <memory>

std::unique_ptr<Cipher> cipherFactory(const ProgramSettings settings) {

    switch (settings.cipherType) {
    case CipherType::Playfair:
        return std::make_unique<PlayfairCipher>(settings.cipherKey);
    case CipherType::Viginere:
        return std::make_unique<ViginereCipher>(settings.cipherKey);
    default:
        return std::make_unique<CaesarCipher>(settings.cipherKey);
    }
}
