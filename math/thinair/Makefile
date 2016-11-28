headers=environ.h erndmcnm.h modarith.h rand_rng.h randcomp.h randcong.h randgen.h randmcon.h rndmconm.h

all        : modarith.o rand_rng.o randcomp.o randcong.o randgen.o randmcon.o rndmconm.o
modarith.o : ${headers} modarith.cpp
	g++ ${CFLAGS} -c modarith.cpp
rand_rng.o : ${headers} rand_rng.cpp
	g++ ${CFLAGS} -c rand_rng.cpp
randcomp.o : ${headers} randcomp.cpp
	g++ ${CFLAGS} -c randcomp.cpp
randcong.o : ${headers} randcong.cpp
	g++ ${CFLAGS} -c randcong.cpp
randgen.o  : ${headers} randgen.cpp
	g++ ${CFLAGS} -c randgen.cpp 
randmcon.o : ${headers} randmcon.cpp
	g++ ${CFLAGS} -c randmcon.cpp
rndmconm.o : ${headers} rndmconm.cpp
	g++ ${CFLAGS} -c rndmconm.cpp

clean      : 
	rm -f modarith.o rand_rng.o randcomp.o randcong.o randgen.o randmcon.o rndmconm.o
