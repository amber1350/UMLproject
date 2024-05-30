main : Account.o



______
trajets : trajets.o Trajet.o TrajetSimple.o TrajetCompose.o Catalogue.o Liste.o Maillon.o
		g++ -o trajets trajets.o Trajet.o TrajetSimple.o TrajetCompose.o Catalogue.o Liste.o Maillon.o -ansi -pedantic -Wall -std=c++11

trajets.o : trajets.cpp
		g++ -c trajets.cpp

Catalogue.o : Catalogue.cpp
		g++ -c Catalogue.cpp #-DMAP

Liste.o : Liste.cpp
		g++ -c Liste.cpp #-DMAP

Maillon.o : Maillon.cpp
		g++ -c Maillon.cpp #-DMAP		

Trajet.o : Trajet.cpp
		g++ -c -g Trajet.cpp #-DMAP

TrajetCompose.o : TrajetCompose.cpp 
		g++ -c TrajetCompose.cpp #-DMAP

TrajetSimple.o : TrajetSimple.cpp 
		g++ -c -g TrajetSimple.cpp #-DMAP

clean :
	rm -f trajets trajets.o Trajet.o TrajetSimple.o TrajetCompose.o Catalogue.o Liste.o Maillon.o

