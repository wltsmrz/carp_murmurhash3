# carp_murmurhash3

Carp bindings for murmurhash3

```clojure
(load "https://github.com/wltsmrz/carp_murmurhash3@v0.3.0")

(defn-do main []
  ; 32 bit hash, returns uint32
 (IO.println &(Uint32.str (Murmur3.hash-32x1 (String.to-bytes "whatever") 90210)))
  ; 128 bit hash, returns array of four uint32
 (IO.println &(Array.str &(Murmur3.hash-32x4 (String.to-bytes "whatever") 90210)))
  ; 128 bit hash, returns array of 2 uint64
 (IO.println &(Array.str &(Murmur3.hash-64x2 (String.to-bytes "whatever") 90210)))

  ; 32 bit hash, returns hex string
 (IO.println &(Murmur3.hash-32x1-hex (String.to-bytes "whatever") 90210))
  ; 128 bit hash, returns hex string
 (IO.println &(Murmur3.hash-32x4-hex (String.to-bytes "whatever") 90210))
  ; 128 bit hash, returns hex string
 (IO.println &(Murmur3.hash-64x2-hex (String.to-bytes "whatever") 90210))
)
```

