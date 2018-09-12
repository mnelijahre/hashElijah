The manual for this exercise is on Google Drive at:

https://docs.google.com/document/d/1EsM4mnw1EQNi2srDxazJyJicQU_fXKECpAjW86x2UJQ/edit

`shak/` contains numbered chunks of the compleat works of Wm.
Shakespeare, `orig/` containing the original chunks, and `mod/`
containing the same numbered chunks but with one byte changed.

`zero/` contains files made of all zeros with slight changes between
`mod/` and `orig/`, while `random/` contains files of random data with
slight changes between `mod/` and `orig/`. `a/` contains files that are
a single byte. The files in `a/orig/` are all the character `a`; in
`mod/` they are some other byte.

samples/ has some files that should help test the strength of your hash
(because they either have very little or a lot of entropy).

 * `0` is a large file of all zeroes
 * `01` is a large file of alternating `0`s and `1`s
 * `0-prime` is like `0` but with one byte changed
 * `random` is a large random file

## This version of SMHasher is edited for a hash lab
The student hash goes into src/StudentHash.cpp. You can then compile both the individual runner and SMhasher by running "make". 

To run the individual runner, run ./runner filename
to run SMhasher against the student hash, run ./smhasher StudentHash

You can change which tests are run in the main.cpp file for SMhasher and recompiling.

The SMHasher wiki has [information about what the individual tests](https://github.com/aappleby/smhasher/wiki/SMHasher) are doing and how to to interpret the results.


## [SMHasher](https://github.com/aappleby/smhasher/wiki) is a test suite designed to test the distribution, collision, and performance properties of non-cryptographic hash functions.

This is the home for the [MurmurHash](https://github.com/aappleby/smhasher/tree/master/src) family of hash functions along with the [SMHasher](https://github.com/aappleby/smhasher/tree/master/src) test suite used to verify them. SMHasher is released under the MIT license. All MurmurHash versions are public domain software, and the author disclaims all copyright to their code.

SMHasher is a test suite designed to test the distribution, collision, and performance properties of non-cryptographic hash functions - it aims to be the [DieHarder](http://www.phy.duke.edu/~rgb/General/dieharder.php) of hash testing, and does a pretty good job of finding flaws with a number of popular hashes.

The SMHasher suite also includes [MurmurHash3](https://github.com/aappleby/smhasher/blob/master/src/MurmurHash3.cpp), which is the latest version in the series of MurmurHash functions - the new version is faster, more robust, and its variants can produce 32- and 128-bit hash values efficiently on both x86 and x64 platforms.


## Updates

### 1/8/2016

Woo, we're on Github! I've been putting off the migration for a few, uh, years or so, but hopefully Github won't be shutting down any time soon so I don't have to move things again. MurmurHash is still used all over the place, SMHasher is still the defacto hash function test suite, and there are all sorts of interesting new hash functions out there that improve bulk hashing speed and use new shiny hardware instructions for AES and whatnot. Interesting times. :)

I've copied the few wiki pages from code.google.com/p/smhasher to this wiki, though I haven't reformatted them to Markdown yet. The MurmurHash page on Wikipedia should also be linking here now as well. Feel free to send me pull requests.
