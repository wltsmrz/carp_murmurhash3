# carp_murmurhash3

Carp bindings for murmurhash3

```clojure
(load "https://github.com/wltsmrz/carp_murmurhash3@v0.5.0")

(defn main []
  (let-do [bytes (String.to-bytes "whatever") seed (Uint32.from-long 90210l)]
    (IO.println &(Uint32.str (Murmur3.hash-32x1 &bytes seed)))
    ; Uint32(97406411)

    (IO.println &(Array.str &(Murmur3.hash-32x4 &bytes seed)))
    ; [Uint32(2298281217) Uint32(1543099115) Uint32(474608795) Uint32(474608795)]

    (IO.println &(Array.str &(Murmur3.hash-64x2 &bytes seed)))
    ; [Uint64(14767214306599027301) Uint64(6621516002895348310)]

    (IO.println &(Murmur3.hash-32x1-hex &bytes seed))
    ; 05ce4dcb

    (IO.println &(Murmur3.hash-32x4-hex &bytes seed))
    ; 88fcfd015bf9d2eb1c49f49b1c49f49b

    (IO.println &(Murmur3.hash-64x2-hex &bytes seed))
    ; fae6c265ccefaf2beb2442565be459b8
))
```

