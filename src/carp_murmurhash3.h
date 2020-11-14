#include "murmurhash3.h"

Uint32 murmur3_32x1(const String* key, int seed) {
  Array bytes = String_to_MINUS_bytes(key);
  uint32_t out;

  MurmurHash3_x86_32(bytes.data, bytes.len, seed, &out);

  return out;
}

Array murmur3_32x4(const String* key, int seed) {
  Array bytes = String_to_MINUS_bytes(key);
  Array out = { .len = 4, .capacity = 4, .data  = (uint32_t*)malloc(4 * sizeof(uint32_t)) };

  MurmurHash3_x86_128(bytes.data, bytes.len, seed, out.data);

  CARP_FREE(bytes.data);

  return out;
}

Array murmur3_64x2(const String* key, int seed) {
  Array bytes = String_to_MINUS_bytes(key);
  Array out = { .len = 2, .capacity = 2, .data  = (uint64_t*)malloc(2 * sizeof(uint64_t)) };

  MurmurHash3_x64_128(bytes.data, bytes.len, seed, out.data);

  CARP_FREE(bytes.data);

  return out;
}
