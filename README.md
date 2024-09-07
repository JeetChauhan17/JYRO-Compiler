this compiler runs a language which i created. every file with this language must end with a .jj extension.

run 
```sh
mkdir build
cmake -S . -B build/
cmake --build build/
./build/jyro test.jj
./build/out
echo $? // returns the return number specified in the test.jj file.
```
base version v1 working.

to run, build with the test file or your own .jj file. then in the build/ folder, run the out.

### functionality:
- parses .jj file
- tokenises them
- converts to assembly
- exports assembly out
- builds obj file
- linkes it (using GNU ld so only linux supported for now.)
- runs it
