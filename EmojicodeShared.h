//
//  EmojicodeSharedTypes.h
//  Emojicode
//
//  Created by Theo Weidmann on 19/07/15.
//  Copyright (c) 2015 Theo Weidmann. All rights reserved.
//

#ifndef Emojicode_EmojicodeSharedTypes_h
#define Emojicode_EmojicodeSharedTypes_h

#include <stdlib.h>
#define _GNU_SOURCE
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>

/** An Unicode codepoint */
typedef uint32_t EmojicodeChar;

typedef int_fast64_t EmojicodeInteger;
/** The bytecode file is structured into Coins. Each Coin represents a single instruction or value. */
typedef uint32_t EmojicodeCoin;

/* Using either of them in a package makes absolutely no sense */
#define packageDirectory "/usr/local/EmojicodePackages/"
#define ByteCodeSpecificationVersion 3

/** The version of a package. Must follow semantic versioning 2.0 http://semver.org */
typedef struct {
    /** The major version */
    uint16_t major;
    /** The minor version */
    uint16_t minor;
} PackageVersion;

/**
 * @defined(isWhitespace)
 * @discussion Inserts a test if @c c is a whitespace
 * http://www.unicode.org/Public/6.3.0/ucd/PropList.txt
 * @param c The character to test
 */
#define isWhitespace(c) ((0x9 <= c && c <= 0xD) || c == 0x20 || c == 0x85 || c == 0xA0 || c == 0x1680 || (0x2000 <= c && c <= 0x200A) || c == 0x2028 || c== 0x2029 || c == 0x2029 || c == 0x202F || c == 0x205F || c == 0x3000 || c == 0xFE0F)

size_t u8_wc_toutf8(char *dest, uint32_t ch);

#define ecCharToCharStack(ec, outVariable)\
char outVariable[5] = {0, 0, 0, 0, 0};\
u8_wc_toutf8(outVariable, (ec));

/**
 * 32-bit FNV-1a hash of k
 * @param k Data
 * @param length Length of @c k
 * @return Hash
 **/
uint32_t fnv32(const char *k, size_t length);

#define PORTABLE_INTLEAST64_MAX ((int_least64_t)9223372036854775807)

#endif