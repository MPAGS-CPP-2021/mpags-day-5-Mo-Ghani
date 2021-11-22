#ifndef MPAGSCIPHER_CIPHERFACTORY_HPP
#define MPAGSCIPHER_CIPHERFACTORY_HPP

#include "ProcessCommandLine.hpp"
#include "Cipher.hpp"

#include <memory>

/**
 * \file CipherFactory.hpp
 * \brief Contains the declarations of the data structures and functions associated with the creation of cipher objects
 */

/**
 * \brief Create new cipher object from processed command-line arguments
 *
 * \param settings the settings specified for the cipher
 * \return unique pointer to the new cipher object
 */

std::unique_ptr<Cipher> cipherFactory(const ProgramSettings settings);

#endif