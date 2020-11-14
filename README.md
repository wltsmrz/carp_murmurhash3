# carp_murmurhash3

Carp bindings for murmurhash3

```clojure
(load "https://github.com/wltsmrz/carp_murmurhash3@v0.2.0")

(defn-do main []
 (IO.println &(Uint32.str (Murmur3.hash-32x1 "whatever" 90210)))
 (IO.println &(Array.str &(Murmur3.hash-32x4 "whatever" 90210)))
 (IO.println &(Array.str &(Murmur3.hash-64x2 "whatever" 90210)))
)
```

