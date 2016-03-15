#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class PizzaOrder {
public:

	static string const toppings_offered[]; //list of toppings offered 
	static double const topping_base_cost; //base price of a single topping 
	static double const base_price; //base price of a small pizza with 0 toppings 
	static int const num_toppings_offered;//an int with the number of toppings offered. 
	double GetPrice(); //Method must compute the price since there is no total price stored. 
	string StringizeSize(); // returns a string version of "size" ( 0=small, 1=medium, 2=large ) 
	string GetToppings(); //returns a string containing a list of toppings for current order. 
	void AddTopping(string topping); //append a topping to the order (multiple toppings of the same ingredient allowed). This is a mutator that will take the parameter, topping, and place it into the next available location of the toppings[] array.
	void AddTopping(int n); // an overload version of Addtopping() that takes an int: "n", instead of the string "topping". The int would represent the position in the "toppings_offered[]" array of the topping that is to be added. Can use either AddTopping()
	int GetSize(); //Accessor for "size". Use int values for this. 
	void SetSize(int sizeProvided); //Mutator for "size". Use int values for this. 
	void DisplayPizza(); //shows the PizzaOrder, with the size, all toppings, and price.
	PizzaOrder(); //default constructor 
	PizzaOrder(int sizeProvided); //non-default constructor 
	void ClearOrder(); // This clears out the order after customer has selected 0 in the innerLoop
	
private:
	int size;
	int num_toppings;
	string toppings[12];


};

PizzaOrder::PizzaOrder(int sizeProvided)
{
	//non-default constructor
	int i = 0;
	
	size = sizeProvided;
	num_toppings = 0;
	
	for ( i = 0; i < 12 ; i++)
	{
		toppings[i] = "";
	}
}

PizzaOrder::PizzaOrder()
{
	//default constructor

	int i = 0;
	
	size = 0;
	num_toppings = 0;
	
	for ( i = 0; i < 12 ; i++)
	{
		toppings[i] = "";
	}
}

void PizzaOrder::ClearOrder()
{
	// Clears order.

	int i = 0;
	
	size = 0;
	num_toppings = 0;
	
	for ( i = 0; i < 12 ; i++)
	{
		toppings[i] = "";
	}
}

int PizzaOrder::GetSize()
{
	//gets the size of the pizza. 
	return size;
	
}

void PizzaOrder::SetSize(int sizeProvided)
{
	//sets the size of the pizza. 
	if (sizeProvided >= 0 && sizeProvided < 3)
	{
		size = sizeProvided;

	}
	else 
		cout << "Invalid Size";
}

void PizzaOrder::DisplayPizza()
{
	//Must get current pizza size, all toppings, and price. 
	cout << "Thank you for your order" << endl;
	cout << "Your pizza size is " << StringizeSize() << endl;
	cout << "The toppings you selected are " << GetToppings() << endl;
	cout << "Your price is " << GetPrice() << endl;
}

void PizzaOrder::AddTopping (string topping)
{
	//Adds a topping
	if (num_toppings < num_toppings_offered)
	{
		toppings[num_toppings] = topping;
		num_toppings++;
	}
	else 
	{
		//dont add topping because array is full.
	}

}

void PizzaOrder::AddTopping (int n)
{
	//Adds a topping v2
	if (num_toppings < num_toppings_offered)
	{
		toppings[num_toppings] = toppings_offered[n];
		num_toppings++;
	}
	else 
	{
		//dont add topping because array is full.
	}
}

double PizzaOrder::GetPrice()
{
	//Calculates the price of a small, medium or large pizza including toppings. 
	double totalPrice = 0;
	double smallPrice = base_price;
	double mediumPrice = (base_price * 1.15);
	double largePrice = (base_price * 1.25);
	
	switch (size)
	{
		case 0:
			totalPrice = (smallPrice + (topping_base_cost * num_toppings));
			break;
			
		case 1:
			totalPrice = (mediumPrice + (topping_base_cost * num_toppings));
			break;
			
		case 2:
			totalPrice = (largePrice + (topping_base_cost * num_toppings));
			break;
	}
	
	return totalPrice;
}

string PizzaOrder::GetToppings()
{
	int i;
	string currentToppings = "";
	
	//returns a string containing all the toppings on the current order. 
	for (i = 0; i < num_toppings ; i++) 
	{
		currentToppings = currentToppings + toppings[i] + " ";
	}
	return currentToppings;
}

string PizzaOrder::StringizeSize()
{
	//Returns a string version of size. 
    switch (size)
	{
		case 0:
			return "Small";
			break;
			
		case 1:
			return "Medium";
			break;
			
		case 2:
			return "Large";
			break;
	}
	return "Invalid Size";
}

string const PizzaOrder::toppings_offered[] = {"Anchovies","Bell Peppers","Bacon","Beef Sausage","Chedder Cheese","Feta Cheese","Italian Sausage","Jalepenos","Onion","Pepperoni","Raindeer Sausage","Tomatoes"};

int const PizzaOrder::num_toppings_offered = 12;

double const PizzaOrder::base_price = 9.99;

double const PizzaOrder::topping_base_cost = 0.50;

int main () {
	//outer loop
	bool stageOne = true;
	bool stageTwo = false;
	string customerInput = "";
	string toppingsInputString = "";
	char firstcharacter;
	int toppingsInput;
	int i;
	PizzaOrder Order;


	while (stageOne) {
		cout << "Size of pizza (small,medium,large) or quit.\n";
		getline(cin, customerInput);
		
		firstcharacter = customerInput[0];
		
		if ((firstcharacter == 'q') || (firstcharacter == 'Q'))
		{
			//if customerSelection is "q" or "Q" then we quit the program.// 
			cout << "Quiting program. \n";
			stageOne = false;
		}
		else if ((firstcharacter == 's') || (firstcharacter == 'S'))
		{
			//if customerSelection is "s" or "S" then start a pizza order with the size "Small"//
			cout << "Small Pizza selected. \n";
			Order.SetSize(0);
			stageTwo = true;
		}
		else if ((firstcharacter == 'm') || (firstcharacter == 'M'))
		{
			//if customerSelection is "m" or "M" then start a pizza order with the size "Medium"//
			cout << "Medium pizza selected. \n";
			Order.SetSize(1);
			stageTwo = true;
		}
		else if ((firstcharacter == 'l') || (firstcharacter == 'L'))
		{
			//if customerSelection is "l" or "L" then start a pizza order with the size "Large"//
			cout << "Large pizza selected. \n";
			Order.SetSize(2);
			stageTwo = true;
		}
		else 
		{
			//the customer has entered a string that does not start with a "q", "s", "m", or "l", therefore it is an invalid selection.// 
			cout << "That's an invalid selection. Please choose quit, small, medium, or large. \n";
		}
		
		while (stageTwo) 
		{
			//Inner Loop asks customer for Toppings. 
			cout << "Thank you.\n";
			cout << endl;
			cout << endl;
			cout << "Current Pizza: " << Order.StringizeSize() << " " << Order.GetToppings();
			cout << endl;
			cout << "Select an item by number ( 0 when done):";
			cout << endl;
			
			for (i = 0; i < Order.num_toppings_offered ; i++) 
			{
				cout << i+1 << ":" << Order.toppings_offered[i] << endl;
			}
			
			cout << endl;
			cout << "Selection?";
			getline(cin, toppingsInputString);
			stringstream myStream(toppingsInputString);
			
			if (myStream >> toppingsInput)
			{
				if ((toppingsInput > 0) && (toppingsInput < Order.num_toppings_offered + 1))
				{
					//If we are within this "else" then the customer input must be between 1-12. Check value of customerInput and add the correct topping to the current order.// 
					Order.AddTopping(Order.toppings_offered[toppingsInput - 1]);
				}
				else if ( toppingsInput == 0)
				{
					//customer has enter 0, so exit inner loop and transition back to the outer loop asking for another pizza order or to quit.// 
					Order.DisplayPizza();
					Order.ClearOrder();
					stageTwo = false;
				}
				else
				{
					//The customer has entered a number outside of the 0-12 options, keep running loop until customer enters "0" or a valid selection.//
					cout << "That was an invalid selection. Choose from the available toppings offered."; 
				}
			}
			else 
			{
				//The customer has entered a number outside of the 0-12 options, keep running loop until customer enters "0" or a valid selection.//
				cout << "That was an invalid selection. Choose from the available toppings offered."; 
			}

			
		}
		
		
	}

	
    return 0;
}
