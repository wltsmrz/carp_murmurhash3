#include "murmurhash3.h"

String murmur3_32_to_hex(Uint32* hash) {
  size_t size = (sizeof(char) * 8) + 1;
  String buf = CARP_MALLOC(size);
  snprintf(buf, size, "%08x", *hash);
  return buf;
}

String murmur3_128_to_hex(const Array* hash) {
  size_t size = (sizeof(char) * 32) + 1;
  String buf = CARP_MALLOC(size);
  uint32_t* p = (uint32_t*)hash->data;
  snprintf(buf, size, "%08x%08x%08x%08x", *p, *(p+1), *(p+2), *(p+3));
  return buf;
}

Uint32 murmur3_32x1(const Array* key, int seed) {
  uint32_t out = 0;
  MurmurHash3_x86_32(key->data, key->len, seed, &out);
  return out;
}

Array murmur3_32x4(const Array* key, int seed) {
  Array out = { .len = 4, .capacity = 4, .data  = CARP_MALLOC(4 * sizeof(uint32_t)) };
  MurmurHash3_x86_128(key->data, key->len, seed, out.data);
  return out;
}

Array murmur3_64x2(const Array* key, int seed) {
  Array out = { .len = 2, .capacity = 2, .data  = CARP_MALLOC(2 * sizeof(uint64_t)) };
  MurmurHash3_x64_128(key->data, key->len, seed, out.data);
  return out;
}

String murmur3_32x1_hex(const Array* key, int seed) {
  Uint32 hash = murmur3_32x1(key, seed);
  String hex = murmur3_32_to_hex(&hash);
  return hex;
}

String murmur3_32x4_hex(const Array* key, int seed) {
  Array hash = murmur3_32x4(key, seed);
  String hex = murmur3_128_to_hex(&hash);
  CARP_FREE(hash.data);
  return hex;
}

String murmur3_64x2_hex(const Array* key, int seed) {
  Array hash = murmur3_64x2(key, seed);
  String hex = murmur3_128_to_hex(&hash);
  CARP_FREE(hash.data);
  return hex;
}

