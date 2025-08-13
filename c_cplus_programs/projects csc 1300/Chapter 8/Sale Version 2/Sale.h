// Specification file for the Sale class.
#ifndef SALE_H
#define SALE_H

class Sale
{
	private:
	double itemCost;     // Cost of the item
	double taxRate;      // Sales tax rate
	public:
	Sale(double cost, double rate)
	{
		this->itemCost = cost;
		this->taxRate = rate; 
	}

	double getItemCost() const
	{ 
		return this->itemCost; 
	}

	double getTaxRate() const
	{ 
		return this->taxRate; 
	}

	double getTax() const
	{ 
		return (this->itemCost * this->taxRate); 
	}

	double getTotal() const
	{ 
		return (this->itemCost + this->getTax()); 
	}
};
#endif
