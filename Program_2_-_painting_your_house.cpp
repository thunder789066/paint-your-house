
#include <iostream>
#include <cstring>
#include <tgmath.h>
#include "Header.h"
using namespace std;

double grand_ttl_cost = 0.0, int_cost = 0.0, ext_cost = 0.0;
double wall_count = 0.0, ttl_area = 0.0;
double exact_can_size = 0.0, ttl_cans = 0.0, num_of_cans_int = 0.0, num_of_cans_ext = 0.0;

void menu() {
	bool check = true;
	char option = ' ';

	cout << "Welcome to the Paint Shop." << endl;
	cout << "Please select an option for your house:" << endl;
	cout << "(1) Paint Interior Only" << endl;
	cout << "(2) Paint Exterior Only" << endl;
	cout << "(3) Paint both Interior & Exterior" << endl;
	cout << "(4) Print Receipt\n" << endl;

	while (check) {
		cout << "\nEnter Selection >>> ";
		cin >> option;

		switch (option) {
		case '1':
			int_cost += total_interior_cost();
			break;
		case '2':
			ext_cost += total_exterior_cost();
			break;
		case '3':
			int_cost += total_interior_cost();
			ext_cost += total_exterior_cost();
			break;
		case '4':
			break;
		default:
			cout << "\nInvalid Input. " << option << " isn't available." << endl;
			break;
		}
		if (option == '4') {
			ttl_cans += (num_of_cans_ext + num_of_cans_int);
			grand_ttl_cost += (int_cost + ext_cost);
			print_receipt();
			check = false;
		}
	}
}

double total_area(double length, double height) {
	return (length * height);
}

double total_paint_cans(double area) {
	// 1 can = 400 sq ft
	exact_can_size += (area / 400.0);

	return ceil(exact_can_size);
}

double total_interior_cost() {
	cout << "\nHow many walls are you painting for Interior? ";
	cin >> wall_count;
	double length = 0.0, height = 0.0, int_area = 0.0;

	for (int i = 1; i <= wall_count; i++) {
		cout << "\nWhat is the length of wall " << i << "? ";
		cin >> length;
		cout << "\nWhat is the height of wall " << i << "? ";
		cin >> height;

		int_area += total_area(length, height);
		ttl_area += int_area;
	}
	num_of_cans_int += total_paint_cans(int_area);

	return (num_of_cans_int * 100.0);
}

double total_exterior_cost() {
	cout << "\nHow many walls are you painting for Exterior? ";
	cin >> wall_count;
	double length = 0.0, height = 0.0, ext_area = 0.0;

	for (int i = 1; i <= wall_count; i++) {
		cout << "\nWhat is the length of wall " << i << "? ";
		cin >> length;
		cout << "\nWhat is the height of wall " << i << "? ";
		cin >> height;

		ext_area += total_area(length, height);
		ttl_area += ext_area;
	}
	num_of_cans_ext += total_paint_cans(ext_area);

	return (num_of_cans_ext * 150.0);
}

double total_cost() {
	return (int_cost + ext_cost);
}

void print_receipt() {
	cout << "\n   Receipt\t* 1 can / 400 Sq. Ft. *" << endl;
	cout << "========================================" << endl;
	cout << "   Exterior" << endl;
	cout << "\t# of Cans ----------- " << num_of_cans_ext << endl;
	cout << "\tPrice --------------- $" << ext_cost << endl;
	cout << "   Interior" << endl;
	cout << "\t# of Cans ----------- " << num_of_cans_int << endl;
	cout << "\tPrice --------------- $" << int_cost << endl;
	cout << "----------------------------------------" << endl;
	cout << "   Total" << endl;
	cout << "\t# of Cans (EXACT) --- " << exact_can_size << endl;
	cout << "\t          (TOTAL) --- " << ttl_cans << endl;
	cout << "\tArea (TOTAL) -------- " << ttl_area << " sq ft" << endl;
	cout << "\n   Total Price -------------- $" << grand_ttl_cost << endl;
}

int main() {
	menu();
}