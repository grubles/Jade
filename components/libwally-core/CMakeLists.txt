set(COMPONENT_SRCS "upstream/src/address.c"
                   "upstream/src/aes.c"
                   "upstream/src/base58.c"
                   "upstream/src/bip32.c"
                   "upstream/src/bip38.c"
                   "upstream/src/bip39.c"
                   "upstream/src/bech32.c"
                   "upstream/src/ecdh.c"
                   "upstream/src/elements.c"
                   "upstream/src/blech32.c"
                   "upstream/src/hex.c"
                   "upstream/src/hmac.c"
                   "upstream/src/internal.c"
                   "upstream/src/mnemonic.c"
                   "upstream/src/pbkdf2.c"
                   "upstream/src/psbt.c"
                   "upstream/src/script.c"
                   "upstream/src/scrypt.c"
                   "upstream/src/sign.c"
                   "upstream/src/symmetric.c"
                   "upstream/src/transaction.c"
                   "upstream/src/wif.c"
                   "upstream/src/wordlist.c"
                   "upstream/src/ccan/ccan/base64/base64.c"
                   "upstream/src/ccan/ccan/crypto/ripemd160/ripemd160.c"
                   "upstream/src/ccan/ccan/crypto/sha256/sha256.c"
                   "upstream/src/ccan/ccan/crypto/sha512/sha512.c"
                   "upstream/src/ccan/ccan/str/hex/hex.c"
                   "upstream/src/secp256k1/src/secp256k1.c")

set(COMPONENT_ADD_INCLUDEDIRS "upstream"
                              "upstream/src"
                              "upstream/src/ccan"
                              "upstream/include"
                              "upstream/src/secp256k1"
                              "upstream/src/secp256k1/src"
                              "upstream/src/secp256k1/src/modules/rangeproof"
                              "upstream/src/secp256k1/src/modules/ecdh"
                              "upstream/src/secp256k1/src/modules/surjection"
                              "upstream/src/secp256k1/src/modules/generator"
                              "upstream/src/secp256k1/src/modules/whitelist"
                              "upstream/src/secp256k1/src/modules/recovery"
                              "upstream/src/secp256k1/src/modules/musig"
                              ".")


register_component()

set_source_files_properties(
    upstream/src/secp256k1/src/secp256k1.c
    upstream/src/secp256k1/src/modules/rangeproof/rangeproof_impl.h
    upstream/src/bip32.c
    PROPERTIES COMPILE_FLAGS
    "-Wno-nonnull-compare -Wno-unused-function -Wno-error=maybe-uninitialized"
    )
target_compile_definitions(${COMPONENT_TARGET} PUBLIC "-DHAVE_CONFIG_H")
target_compile_definitions(${COMPONENT_TARGET} PUBLIC "-DBUILD_ELEMENTS=1")
