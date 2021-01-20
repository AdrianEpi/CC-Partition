#include <vector>
#include <iostream>
class BitNumber {

	private:
		// Attributes
		int bitAmmount_;
		int numberAmmount_;
		int setAmmount_;
		std::vector<bool> number_;

	public:
		// Builders & destroyer
		BitNumber (void);
		BitNumber (int number, int bitAmmount);
		~BitNumber (void);

		// Getters & Setters
		int get_BitAmmount (void) const;
		int get_NumberAmmount (void) const;
		int get_SetAmmount (void) const;
		std::vector<bool> get_Number (void) const;

		void set_BitAmmount (int newBitAmmount);
		void set_NumberAmmount (int newNumberAmmount);
		void set_SetAmmount (int newSetAmmount);
		void set_Number (std::vector<bool> newNumber);

		// Methods
		int toInt (void);
		void writeBit (int position, int numberPos, bool bit);

		// Operators Overload
		BitNumber operator+ (const BitNumber& number);

};