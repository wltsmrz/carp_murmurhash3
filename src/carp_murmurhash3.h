#include "murmurhash3.h"

Uint32 murmur3_32x1(const String* key, int seed) {
  Array chars = String_chars(key);
  uint32_t out;
  size_t len = strlen(chars.data);

  MurmurHash3_x86_32(chars.data, len, seed, &out);

  CARP_FREE(chars.data);

  return out;
}

Array murmur3_32x4(const String* key, int seed) {
  Array chars = String_chars(key);
  Array out = { .len = 4, .capacity = 4, .data  = (uint32_t*)malloc(4 * sizeof(uint32_t)) };

  size_t len = strlen(chars.data);

  MurmurHash3_x86_128(chars.data, len, seed, out.data);

  CARP_FREE(chars.data);

  return out;
}

Array murmur3_64x2(const String* key, int seed) {
  Array chars = String_chars(key);
  Array out = { .len = 2, .capacity = 2, .data  = (uint64_t*)malloc(2 * sizeof(uint64_t)) };

  size_t len = strlen(chars.data);

  MurmurHash3_x64_128(chars.data, len, seed, out.data);

  CARP_FREE(chars.data);

  return out;
}
