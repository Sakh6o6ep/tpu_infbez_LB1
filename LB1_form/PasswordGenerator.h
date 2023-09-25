#ifndef PGEN

#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <ctime>
#include <algorithm>

using namespace std;

class PasswordGenerator {
	random_device rd{};
	mt19937 rng{ rd() };
public:
	const string sample_lowercase = "abcdefghijklmnopqrstuvwxyz";
	const string sample_uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const string digits = "0123456789";
	const string symbols = "!#$%&()*+,-./|\"':;<=>?@[]^_`{}~";

	string pass(double P, double V, double T, bool flag_lower, bool flag_upper, bool flag_digits, bool flag_symbols) {

		string sample_password, password;
		double S, S_;
		int length_sample = 0, length_password = 0;

		V = V * 60 * 24 * 7;
		S_ = (V * T) / P;
		if (!flag_lower && !flag_upper && !flag_lower && !flag_digits && !flag_symbols) return "Ошибка";
		if (flag_lower) {
			sample_password += sample_lowercase;
			length_sample += 26;
		}
		if (flag_upper) {
			sample_password += sample_uppercase;
			length_sample += 26;
		}
		if (flag_digits) {
			sample_password += digits;
			length_sample += 10;
		}
		if (flag_symbols) {
			sample_password += symbols;
			length_sample += 31;
		}
		uniform_int_distribution<int> dist(0, sample_password.length() - 1);
		uniform_int_distribution<int> dist_lower(0, sample_lowercase.length() - 1);
		uniform_int_distribution<int> dist_upper(0, sample_uppercase.length() - 1);
		uniform_int_distribution<int> dist_digits(0, digits.length() - 1);
		uniform_int_distribution<int> dist_symbols(0, symbols.length() - 1);

		S = pow(length_sample, length_password);
		while (S_ > S) {
			length_password++;
			S = pow(length_sample, length_password);
		}

		int j = 0;
		string switch_flag = "0123";
		random_shuffle(switch_flag.begin(), switch_flag.end());

		for (int i = 0; i < length_password; i++) {

			if (flag_lower && switch_flag[j] == '0')
			{
				flag_lower = false;
				password += sample_lowercase[dist_lower(rng)];
				j++;
			}
			else if (flag_upper && switch_flag[j] == '1')
			{
				flag_upper = false;
				password += sample_uppercase[dist_upper(rng)];
				j++;
			}
			else if (flag_digits && switch_flag[j] == '2')
			{
				flag_digits = false;
				password += digits[dist_digits(rng)];
				j++;
			}
			else if (flag_symbols && switch_flag[j] == '3')
			{
				flag_symbols = false;
				password += symbols[dist_symbols(rng)];
				j++;
			}
			else password += sample_password[dist(rng)];
		}

		ofstream output;
		output.open("password.txt");
		if (!output.is_open())
		{
			cout << "Ошибка открытия файла" << endl;
		}
		else
		{
			output << password << endl;
		}
		output.close();

		return password;
	}
};


#define PGEN
#endif // PGEN
