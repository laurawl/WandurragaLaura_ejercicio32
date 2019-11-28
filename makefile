resultado.png : grafica.py datos.dat
	python grafica.py 

datos.dat : ejercicio.x
	./ejercicio.x 10 > datos.dat
	./ejercicio.x 20 >> datos.dat
	./ejercicio.x 30 >> datos.dat
	./ejercicio.x 40 >> datos.dat
	./ejercicio.x 50 >> datos.dat
	./ejercicio.x 60 >> datos.dat
	./ejercicio.x 70 >> datos.dat
	./ejercicio.x 80 >> datos.dat
	./ejercicio.x 90 >> datos.dat
	./ejercicio.x 100 >> datos.dat

ejercicio.x : ejercicio.cpp
	c++ ejercicio.cpp -o ejercicio.x

clean:
	rm -f datos.dat resultado.png ejercicio.x