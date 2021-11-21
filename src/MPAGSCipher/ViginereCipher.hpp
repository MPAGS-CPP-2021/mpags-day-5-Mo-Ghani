#ifndef MPAGSCIPHER_VIGINERECIPHER_HPP
#define MPAGSCIPHER_VIGINERECIPHER_HPP

#include "Cipher.hpp"
#include "CipherMode.hpp"
#include "CaesarCipher.hpp"

#include <string>
#include <map>

/**
 * \file ViginereCipher.hpp
 * \brief Contains a declaration of the ViginereCipher class
 */

/**
 * \class ViginereCipher
 * \brief Encrypt or decrypt text using the Viginere cipher with the given key
 */
class ViginereCipher : public Cipher {
  public:
    /**
     * \brief Create a new ViginereCipher with the given key
     *
     * \param key the key to use in the cipher
     */
    explicit ViginereCipher(const std::string& key);

    /**
     * \brief Set the key to be used for the encryption/decryption
     *
     * \param key the key to use in the cipher
     */
    void setKey(const std::string& key);

    /**
     * \brief Apply the Viginere cipher to the provided text
     *
     * \param inputText the text to encrypt or decrypt
     * \param cipherMode whether to encrypt or decrypt the input text
     * \return the result of applying the cipher to the input text
     */
    std::string applyCipher(const std::string& inputText,
                            const CipherMode cipherMode) const override;

  private:
    /// The cipher key
    std::string key_{""};

    /// Lookup table 
    std::map<char, CaesarCipher> charLookup_;

};

#endif