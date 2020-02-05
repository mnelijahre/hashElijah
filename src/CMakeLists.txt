#cmake_minimum_required(VERSION 3.5)

set_source_files_properties(StudentHashRunner.c PROPERTIES LANGUAGE CXX )

project(hashlab)

add_executable(runner StudentHashRunner.c Hashes.cpp)

add_executable(smasher AvalancheTest.cpp MurmurHash1.cpp Random.cpp Stats.cpp Hashes.cpp Bitslice.cpp MurmurHash2.cpp Bitvec.cpp KeysetTest.cpp sha1.cpp MurmurHash3.cpp City.cpp  lookup3.cpp  Platform.cpp SpeedTest.cpp CityTest.cpp main.cpp SuperFastHash.cpp PMurHash.c Spooky.cpp Types.cpp crc.cpp DifferentialTest.cpp md5.cpp SpookyTest.cpp)

