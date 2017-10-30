CC=g++
CFLAGS= 

all: runner smhasher

runner: StudentHash* 
	$(CC) $(CFLAGS) StudentHashRunner.c StudentHash.cpp -o runner

smhasher: *.cpp *.c
	$(CC) $(CFLAGS) AvalancheTest.cpp MurmurHash1.cpp Random.cpp Stats.cpp Hashes.cpp Bitslice.cpp MurmurHash2.cpp StudentHash.cpp Bitvec.cpp KeysetTest.cpp sha1.cpp MurmurHash3.cpp City.cpp  lookup3.cpp  Platform.cpp SpeedTest.cpp CityTest.cpp main.cpp SuperFastHash.cpp PMurHash.c Spooky.cpp Types.cpp crc.cpp DifferentialTest.cpp md5.cpp SpookyTest.cpp -o smhasher

clean: 
	rm -rf *.o smhasher runner

