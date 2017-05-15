#include<string>
#include<vector>
#include<fstream>

using namespace std;

class handler
{
	handler* next;
public:
	handler(){
		next = 0;
	}
	void set_next(handler* n) { next = n; }
	void add(handler* n)
	{
		if (next) 
		{ next->add(n); } 
		else { next = n; } 
	}
	virtual void handle(int type, int amount)
	{
		next->handle(type, amount);
	}
	void make_paiment(int amount, int tax, int bank_tax)
	{
		fstream f;
		f.open("payments.txt", ios_base::app);
		f << "_________________________________________________________________________________________\n";
		f << "amount payed: ";
		f << amount;
		f << "; \n government tax: ";
		int gt = (amount*tax) / 100;
		int bt = (amount*bank_tax) / 100;
		int rec = amount - gt - bt;
		f << gt;
		f << "; \n tax of bank: ";
		f << bt;
		f << ";\n sum received: ";
		f << rec;
		f << "; \n___________________________________________________________________________________________________\n";
		f.close();
	}
};

class payment_simple:public handler
{
	void handle(int type, int amount)
	{
		if (type == 1)
		{
			make_paiment(amount, 8, 4);
		}
		else
			handler::handle(type, amount);
	}
};

class payment_preferential :public handler
{
	void handle(int type, int amount)
	{
		if (type == 2)
		{
			make_paiment(amount, 0, 4);
		}
		else
			handler::handle(type, amount);
	}
};

class payment_goverment :public handler
{
	void handle(int type, int amount)
	{
		if (type == 3)
		{
			make_paiment(amount, 0, 0);
		}
		else
			handler::handle(type, amount);
	}
};

class payment_bank :public handler
{
	void handle(int type, int amount)
	{
		if (type == 4)
		{
			make_paiment(amount, 8, 0);
		}
		else
			handler::handle(type, amount);
	}
};