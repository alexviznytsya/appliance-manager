make:
	g++ ApplianceManager.cpp LinkedList.cpp AppliancePtr.cpp Appliance.cpp -std=c++11 -o ApplianceManager

run:
	clear
	./ApplianceManager

clean:
	rm ApplianceManager
