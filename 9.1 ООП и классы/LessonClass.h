#pragma once
#include <string>

namespace kalich
{
	class Bank
	{
		private:
			unsigned int Number;
			std::string Name;
			double Money;

		public:
			Bank(unsigned int n, const std::string str, double m);
			Bank();

			~Bank();

			void SetMoney(double m){ Money = m; }
			void SetNumber(unsigned int n){ Number = n; }
			void SetName(const std::string &str){ Name = str; }

			void AddMoney(double m);
			bool SubMoney(double m);
			void Show();

			const Bank& BiggerMoney(const Bank& acc);
	};

	typedef int Data;
	class Stack
	{
	private:
		Data* data;
		int top;
		int limit;

	public:
		Stack(int l);
		~Stack();
		bool Push(const Data& i);
		bool Poop(Data& i);
		int Size(){ return top; }
		int Limit(){ return limit;  }
	};

}