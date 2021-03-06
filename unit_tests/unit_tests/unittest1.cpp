#include "stdafx.h"
#include "CppUnitTest.h"

#include "catch.hpp"
#include "chain_of_responsibility.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{		
	TEST_CASE("simple")
	{
		handler* pay = new payment_simple();
		payment_preferential* p2 = new payment_preferential();
		payment_goverment* p3 = new payment_goverment();
		payment_bank* p4 = new payment_bank();
		pay->add(p2);
		pay->add(p3);
		pay->add(p4);
		p4->set_next(pay);
		fstream pre; pre.open("payments.txt", ios_base::out); pre.clear(); pre.close();
		string l1, l2, l3, l4, l5;
		pay->handle(1, 1000);
		fstream f; f.open("payments.txt");
		getline(f, l1);
		getline(f, l2);
		getline(f, l3);
		getline(f, l4);
		getline(f, l5);
		bool res = true;
		f.close();
		if (l2 != "amount payed: 1000; " || l3 != " government tax: 80; " || l4 != " tax of bank: 40;" || l5 != " sum received: 880; ") res = false;
		REQUIRE(res==true);
	};

	TEST_CASE("preferential")
	{
		handler* pay = new payment_simple();
		payment_preferential* p2 = new payment_preferential();
		payment_goverment* p3 = new payment_goverment();
		payment_bank* p4 = new payment_bank();
		pay->add(p2);
		pay->add(p3);
		pay->add(p4);
		p4->set_next(pay);
		fstream pre; pre.open("payments.txt", ios_base::out); pre.clear(); pre.close();
		string l1, l2, l3, l4, l5;
		pay->handle(2, 1000);
		fstream f; f.open("payments.txt");
		getline(f, l1);
		getline(f, l2);
		getline(f, l3);
		getline(f, l4);
		getline(f, l5);
		bool res = true;
		f.close();
		if (l2 != "amount payed: 1000; " || l3 != " government tax: 0; " || l4 != " tax of bank: 40;" || l5 != " sum received: 960; ") res = false;
		REQUIRE(res == true);
	};

	TEST_CASE("goverment")
	{
		handler* pay = new payment_simple();
		payment_preferential* p2 = new payment_preferential();
		payment_goverment* p3 = new payment_goverment();
		payment_bank* p4 = new payment_bank();
		pay->add(p2);
		pay->add(p3);
		pay->add(p4);
		p4->set_next(pay);
		fstream pre; pre.open("payments.txt", ios_base::out); pre.clear(); pre.close();
		string l1, l2, l3, l4, l5;
		pay->handle(3, 1000);
		fstream f; f.open("payments.txt");
		getline(f, l1);
		getline(f, l2);
		getline(f, l3);
		getline(f, l4);
		getline(f, l5);
		bool res = true;
		f.close();
		if (l2 != "amount payed: 1000; " || l3 != " government tax: 0; " || l4 != " tax of bank: 0;" || l5 != " sum received: 1000; ") res = false;
		REQUIRE(res == true);
	};

	TEST_CASE("bank")
	{
		handler* pay = new payment_simple();
		payment_preferential* p2 = new payment_preferential();
		payment_goverment* p3 = new payment_goverment();
		payment_bank* p4 = new payment_bank();
		pay->add(p2);
		pay->add(p3);
		pay->add(p4);
		p4->set_next(pay);
		fstream pre; pre.open("payments.txt", ios_base::out); pre.clear(); pre.close();
		string l1, l2, l3, l4, l5;
		pay->handle(4, 1000);
		fstream f; f.open("payments.txt");
		getline(f, l1);
		getline(f, l2);
		getline(f, l3);
		getline(f, l4);
		getline(f, l5);
		bool res = true;
		f.close();
		if (l2 != "amount payed: 1000; " || l3 != " government tax: 80; " || l4 != " tax of bank: 0;" || l5 != " sum received: 920; ") res = false;
		REQUIRE(res == true);
	};
}