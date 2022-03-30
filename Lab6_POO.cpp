#include <iostream>

class Car
{
private:
	int fuel_capacity, fuel_consumption, average_speed;
protected:
	Car(int average_speed_value):average_speed(average_speed_value) {}
public:
	virtual Car(int fuel_capacity_value) :fuel_capacity(fuel_capacity_value) {}
	virtual Car(int fuel_consumption_value) : fuel_consumption(fuel_consumption_value) {}
};

enum Weather
{
	Rain, 
	Sunny, 
	Snow
};

class Dacia : public Car
{
public:
	Dacia(int dacia_fuel_capacity) :Car(dacia_fuel_capacity) {}
	Dacia(int dacia_fuel_consumption) :Car(dacia_fuel_consumption) {}
};

class Toyota : public Car
{
public:
	Toyota(int toyota_fuel_capacity) :Car(toyota_fuel_capacity) {}
	Toyota(int toyota_fuel_consumption) :Car(toyota_fuel_consumption) {}
};

class Mercedes : public Car
{
public:
	Mercedes(int mercedes_fuel_capacity) :Car(mercedes_fuel_capacity) {}
	Mercedes(int mercedes_fuel_consumption) :Car(mercedes_fuel_consumption) {}
};

class Circuit
{
	Car* cars[3];
	int count, max_count;
public:
	Circuit
	{
		max_count = 3;
		count = 0;
	}
	bool AddCar(Car* car)
	{
		if (count < max_count)
		{
			cars[count++] = car;
			return true;
		}
		return false;
	}
	int SetLenght(int set_lenght) : Circuit(set_lenght)
	{
		return set_lenght;
	}
	int SetWeather(int weather) : Weather(weather)
	{
		return weather;
	}
};

int main()
{
	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather::Rain);
	c.AddCar(new Dacia());
	c.AddCar(new Toyota());
	c.AddCar(new Mercedes());
	c.AddCar(new Ford());
	c.AddCar(new Mazda());
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the   slowest.
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit

	return 0;

}