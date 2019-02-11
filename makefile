tests:
	g++ -o tests.out vectorutils.cpp primes.cpp tests.cpp
	./tests.out

euler1:
	g++ -o euler1.out euler1.cpp
	./euler1.out
	
euler2:
	g++ -o euler2.out euler2.cpp
	./euler2.out

euler3:
	g++ -o euler3.out euler3.cpp
	./euler3.out
	
euler4:
	g++ -o euler4.out primes.cpp euler4.cpp
	./euler4.out

euler5:
	g++ -o euler5.out vectorutils.cpp primes.cpp euler5.cpp
	./euler5.out

euler6:
	g++ -o euler6.out euler6.cpp
	./euler6.out

euler7:
	g++ -o euler7.out primes.cpp euler7.cpp
	./euler7.out

clean:
	@echo "Removing all *.out files"
	rm *.out

