LIBS2:=Random.o Integrale.o

RFLAGS:=`root-config --cflags` `root-config --libs` 

%.o : %.cxx
	g++ -Wall -c $< -fopenmp

IntegraleMC : IntegraleMC.cxx ${LIBS2}
	g++ -Wall -o $@ $^ -fopenmp

clean :
	rm *.o