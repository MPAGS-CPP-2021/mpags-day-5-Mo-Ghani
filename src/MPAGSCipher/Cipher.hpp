#ifndef CIPHER_HPP
#define CIPHER_HPP

#include "CipherMode.hpp"

#include <string>

/**
 * \file Cipher.hpp
 * \brief Contains the Cipher abstract base class 
 */

/**
 * \class Cipher
 * \brief Encrypt or decrypt text using some cipher object
 */
class Cipher {

    public: 

        /**
         * \brief Rules to copy/move/destruct a Cipher
         *
         * \param rhs the Cipher to be copied/moved/destructed
         */
        Cipher() = default;
        Cipher(const Cipher& rhs) = default;
        Cipher(Cipher&& rhs) = default;
        Cipher& operator=(const Cipher& rhs) = default;
        Cipher& operator=(Cipher&& rhs) = default;
        virtual ~Cipher() = default;

        /**
         * \brief Apply the cipher to the provided text
         *
         * \param inputText the text to encrypt or decrypt
         * \param cipherMode whether to encrypt or decrypt the input text
         * \return the result of applying the cipher to the input text
         */
        virtual std::string applyCipher(const std::string& input,
                                        const CipherMode mode ) const = 0;


};

#endif // CIPHER_HPP