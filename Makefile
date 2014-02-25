CPP=g++    #Commande du compilateur
CFLAGS=-O3 #Option d'optimisation du programme
LDFLAGS=-lSDL -lSDL_mixer -lGLU -lglut -lGL -lserial -lstdc++ #Linker

all: KII clean

	
####################################################################

KII : Interface.o IMU.o Environnement.o Global.o Matrice.o Graph.o Enr.o Graph3D.o
	${CPP} $(CFLAGS) -g -Wall -o KII Interface.o IMU.o Graph.o Enr.o Graph3D.o Environnement.o Global.o Matrice.o ${LDFLAGS}  
	
Enr.o : 
	${CPP} $(CFLAGS) -g -Wall -o Enr.o -c EnregIMU.cpp ${LDFLAGS} 

IMU.o : IMU.cpp
	${CPP} $(CFLAGS) -g -Wall -o IMU.o -c IMU.cpp ${LDFLAGS} 
	
Global.o : Global.cpp
	${CPP} $(CFLAGS) -g -Wall -o Global.o -c Global.cpp ${LDFLAGS} 

Interface.o : Interface.cpp
	${CPP} $(CFLAGS) -g -Wall -o Interface.o -c Interface.cpp ${LDFLAGS}
	
Environnement.o : Environnement.cpp
	${CPP} $(CFLAGS) -g -Wall -o Environnement.o -c Environnement.cpp ${LDFLAGS}
	
Matrice.o : Matrices.cpp
	${CPP} $(CFLAGS) -g -Wall -o Matrice.o -c Matrices.cpp ${LDFLAGS}
	
Graph.o : Graph.cpp
	${CPP} $(CFLAGS) -g -Wall -o Graph.o -c Graph.cpp ${LDFLAGS}
	
Graph3D.o : Graph3D.cpp
	${CPP} $(CFLAGS) -g -Wall -o Graph3D.o -c Graph3D.cpp ${LDFLAGS}
	

clean:	
	rm -fr *.o
	rm -fr *~

mrproper: clean
	rm -fr Point
