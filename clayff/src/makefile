CC=mpic++
CFLAGS=-c -std=c++0x
dest=/home/$(USER)/clayff/bin

all: simulate thermalize noseHoover potentialTest

clean:
	rm $(dest)/*.o $(dest)/simulate $(dest)/thermalize $(dest)/noseHoover -f

simulate: MDsimWrapper.o
	$(CC) $(dest)/MDsimWrapper.o $(dest)/MDcalculation.o $(dest)/Particle.o $(dest)/ParticleList.o $(dest)/IntList.o $(dest)/ParticleContainer.o $(dest)/Potential.o -o $(dest)/simulate

thermalize: MDthermWrapper.o
	$(CC) $(dest)/MDthermWrapper.o $(dest)/MDcalculation.o $(dest)/Particle.o $(dest)/ParticleList.o $(dest)/IntList.o $(dest)/ParticleContainer.o $(dest)/Potential.o -o $(dest)/thermalize

noseHoover: MDnoseHooverWrapper.o
	$(CC) $(dest)/MDnoseHooverWrapper.o $(dest)/MDcalculation.o $(dest)/Particle.o $(dest)/ParticleList.o $(dest)/IntList.o $(dest)/ParticleContainer.o $(dest)/Potential.o -o $(dest)/noseHoover

potentialTest: MDPotentialTestWrapper.o
	$(CC) $(dest)/MDPotentialTestWrapper.o $(dest)/MDcalculation.o $(dest)/Particle.o $(dest)/ParticleList.o $(dest)/IntList.o $(dest)/ParticleContainer.o $(dest)/Potential.o -o $(dest)/potentialTest

MDsimWrapper.o: MDsimWrapper.cpp MDcalculation.o
	$(CC) $(CFLAGS) MDsimWrapper.cpp -o $(dest)/MDsimWrapper.o

MDthermWrapper.o: MDthermWrapper.cpp MDcalculation.o
	$(CC) $(CFLAGS) MDthermWrapper.cpp -o $(dest)/MDthermWrapper.o

MDnoseHooverWrapper.o: MDnoseHooverWrapper.cpp MDcalculation.o
	$(CC) $(CFLAGS) MDnoseHooverWrapper.cpp -o $(dest)/MDnoseHooverWrapper.o
	
MDPotentialTestWrapper.o: MDPotentialTestWrapper.cpp MDcalculation.o
	$(CC) $(CFLAGS) MDPotentialTestWrapper.cpp -o $(dest)/MDPotentialTestWrapper.o

MDcalculation.o: MDcalculation.cpp ParticleList.o Particle.o ParticleContainer.o Potential.o
	$(CC) $(CFLAGS) MDcalculation.cpp -o $(dest)/MDcalculation.o

Potential.o: Potential.cpp Particle.o
	$(CC) $(CFLAGS) Potential.cpp -o $(dest)/Potential.o

Particle.o: Particle.cpp IntList.o
	$(CC) $(CFLAGS) Particle.cpp -o $(dest)/Particle.o

ParticleList.o: ParticleList.cpp ParticleContainer.o
	$(CC) $(CFLAGS) ParticleList.cpp -o $(dest)/ParticleList.o

IntList.o: IntList.cpp
	$(CC) $(CFLAGS) IntList.cpp -o $(dest)/IntList.o

ParticleContainer.o: ParticleContainer.cpp
	$(CC) $(CFLAGS) ParticleContainer.cpp -o $(dest)/ParticleContainer.o

