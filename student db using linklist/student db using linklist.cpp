#include<iostream>
using namespace std;
class database {
private:
	int regno, english, oop, marksobt;
	string name, fathername;
	char grade;
	float percentage;
	database* next;
	database* cur, * first, * prev;

public:
	int counter = 0;
	void setter();
	void getter();
	void append();
	void searching();
	void update();
	void deletion();
	void sorting();
};
void database::setter() {
	char choice;
	if (counter == 0) {
		cur = new database;
		cur->next = NULL;
		cout << "ENTER THE REG NO OF THE STUDENT NO. " << counter + 1 << endl;
		cin >> cur->regno;
		cout << "ENTER THE NAME OF THE REGISTRATION NUMBER " << cur->regno << endl;
		cin >> cur->name;
		cout << "ENTER THE FATHER NAME OF " << cur->name << endl;
		cin >> cur->fathername;
		cout << "ENTER MARKS IN ENGLISH OF " << cur->regno << " NAME " << cur->name << endl;
		cin >> cur->english;
		cout << "ENTER MARKS IN OBJECT ORIENTED PROGRAMMING OF " << cur->regno << " NAME " << cur->name << endl;
		cin >> cur->oop;
		cur->marksobt = cur->english + cur->oop;
		cur->percentage = (cur->marksobt * 100.0) / 200.0;
		if (cur->percentage >= 80)
			cur->grade = 'A';
		else if (cur->percentage > 75 && cur->percentage < 80)
			cur->grade = 'B';
		else
			cur->grade = 'F';
		first = prev = cur;
		cout << "DO YOU HAVE MORE STUDENTS Y or N" << endl;
		cin >> choice;
		counter++;
	}
	if (counter > 0 && choice == 'Y' || choice == 'y') {
		do {
			cur = new database;
			cur->next = NULL;
			cout << "ENTER THE REG NO OF THE STUDENT NO. " << counter + 1 << endl;
			cin >> cur->regno;
			cout << "ENTER THE NAME OF THE REGISTRATION NUMBER " << cur->regno << endl;
			cin >> cur->name;
			cout << "ENTER THE FATHER NAME OF " << cur->name << endl;
			cin >> cur->fathername;
			cout << "ENTER MARKS IN ENGLISH OF " << cur->regno << " NAME " << cur->name << endl;
			cin >> cur->english;
			cout << "ENTER MARKS IN OBJECT ORIENTED PROGRAMMING OF " << cur->regno << " NAME " << cur->name << endl;
			cin >> cur->oop;
			cur->marksobt = cur->english + cur->oop;
			cur->percentage = (cur->marksobt * 100.0) / 200.0;
			if (cur->percentage >= 80)
				cur->grade = 'A';
			else if (cur->percentage > 75 && cur->percentage < 80)
				cur->grade = 'B';
			else
				cur->grade = 'F';
			prev->next = cur;
			prev = cur;
			cout << "DO YOU HAVE MORE STUDENTS Y or N" << endl;
			cin >> choice;
			counter++;
		} while (choice == 'Y' || choice == 'y');
	}
}
void database::getter() {
	cur = first;
	while (cur != NULL) {
		cout << "TOTAL STUDENT IN LIST IS " << counter << endl;
		cout << "-------------------- RESULT IN BAD FORMAT ---------------------" << endl;
		cout << "Regno. is: " << cur->regno << endl;
		cout << "Name is: " << cur->name << endl;
		cout << "Father Name is: " << cur->fathername << endl;
		cout << "Marks in english is: " << cur->english << endl;
		cout << "Marks in oop is: " << cur->oop << endl;
		cout << "Marks obt. is: " << cur->marksobt << endl;
		cout << "Percentage is: " << cur->percentage << "%" << endl;
		cout << "Grade is: " << cur->grade << endl;
		cur = cur->next;
	}
}
void database::append() {
	cur = new database;
	cur->next = NULL;
	cout << "ENTER THE REG NO OF THE STUDENT NO. " << counter + 1 << endl;
	cin >> cur->regno;
	cout << "ENTER THE NAME OF THE REGISTRATION NUMBER " << cur->regno << endl;
	cin >> cur->name;
	cout << "ENTER MARKS IN ENGLISH OF " << cur->regno << " NAME " << cur->name << endl;
	cin >> cur->english;
	cout << "ENTER MARKS IN OBJECT ORIENTED PROGRAMMING OF " << cur->regno << " NAME " << cur->name << endl;
	cin >> cur->oop;
	cur->marksobt = cur->english + cur->oop;
	cur->percentage = (cur->marksobt * 100.0) / 200.0;
	if (cur->percentage >= 80)
		cur->grade = 'A';
	else if (cur->percentage > 75 && cur->percentage < 80)
		cur->grade = 'B';
	else
		cur->grade = 'F';
	prev->next = cur;
	prev = cur;
	counter++;
}
void database::searching() {
	bool present;
	int search;
	cout << "ENTER REGISTRATION NUMBER THAT YOU WANT TO SEARCH" << endl;
	cin >> search;
	cur = first;
	while (cur != NULL) {
		if (search == cur->regno) {
			cout << "-------------------- RESULT IN BAD FORMAT ---------------------" << endl;
			cout << "Regno. is: " << cur->regno << endl;
			cout << "Name is: " << cur->name << endl;
			cout << "Father Name is: " << cur->fathername << endl;
			cout << "Marks in english is: " << cur->english << endl;
			cout << "Marks in oop is: " << cur->oop << endl;
			cout << "Marks obt. is: " << cur->marksobt << endl;
			cout << "Percentage is: " << cur->percentage << "%" << endl;
			cout << "Grade is: " << cur->grade << endl;
			cur = cur->next;
			present = true;
			break;
		}
		else {
			present = false;
			cur = cur->next;
		}
	}
	if (present == false)
		cout << "NOT PRESENT" << endl;
}
void database::deletion() {
	int reg;
	cout << "ENTER REG NO. THAT YOU WANT TO DELETE" << endl;
	cin >> reg;
	cur = prev = first;
	if (reg == first->regno) {
		first = first->next;
		delete(prev);
		prev = first;
		cur = first;
	}
	else {
		while (cur != NULL) {
			if (reg == cur->regno) {
				prev->next = cur->next;
				delete(cur);
				cur = cur->next;
				break;
			}
			else {
				prev = cur;
				cur = cur->next;
			}

		}
	}
}
void database::update() {
	int search;
	cout << "ENTER REGISTRATION NUMBER FOR WHOM YOU WANT TO UPDATE DATA" << endl;
	cin >> search;
	cur = first;
	while (cur != NULL) {
		if (search == cur->regno) {
			cout << "ENTER UPDATED REG NO OF THE STUDENT NO. " << counter << endl;
			cin >> cur->regno;
			cout << "ENTER UPDATED NAME OF THE REGISTRATION NUMBER " << cur->regno << endl;
			cin >> cur->name;
			cout << "ENTER UPDATED FATHER NAME OF " << cur->name << endl;
			cin >> cur->fathername;
			cout << "ENTER UPDATED MARKS IN ENGLISH OF " << cur->regno << " NAME " << cur->name << endl;
			cin >> cur->english;
			cout << "ENTER UPDATED MARKS IN OBJECT ORIENTED PROGRAMMING OF " << cur->regno << " NAME " << cur->name << endl;
			cin >> cur->oop;
			cur->marksobt = cur->english + cur->oop;
			cur->percentage = (cur->marksobt * 100.0) / 200.0;
			if (cur->percentage >= 80)
				cur->grade = 'A';
			else if (cur->percentage > 75 && cur->percentage < 80)
				cur->grade = 'B';
			else
				cur->grade = 'F';
			break;
		}
		else
		cur = cur->next;
	}
}
void database::sorting() {
	cur = prev = first;
	while (cur != NULL) {
		if (prev->regno > cur->regno) {
			swap(prev->regno, cur->regno);
			swap(prev->name, cur->name);
			swap(prev->fathername, cur->fathername);
			swap(prev->english, cur->english);
			swap(prev->oop, cur->oop);
			swap(prev->marksobt, cur->marksobt);
			swap(prev->percentage, cur->percentage);
			swap(prev->grade, cur->grade);
		}
		cur = cur->next;
	}
}
int main() {
	system("color 3F");
	database students;

	int option = 0, ts = 0;
	while (option != 8) {
		cout << endl;
		cout << "                       |-----------------------------------------------------------|" << endl;
		cout << "                       |                    -:|:- MENUE! -:|:-                     |" << endl;
		cout << "                       |-----------------------------------------------------------|" << endl << endl;
		cout << "ENTER 1 TO CREATE DATABASE OF STUDENTS" << endl;
		cout << "ENTER 2 TO APPEND NEW RECORD" << endl;
		cout << "ENTER 3 TO SEARCH RESULT" << endl;
		cout << "ENTER 4 TO UPDATE RESULT" << endl;
		cout << "ENTER 5 TO DELETE RESULT" << endl;
		cout << "ENTER 6 TO SORT DATA" << endl;
		cout << "ENTER 7 TO DISPLAY RESULT" << endl;
		cout << "ENTER 8 TO EXIT" << endl;
		cout << "\n****************************************************************************************" << endl;
		cout << "\n			       ____INSTRUCTIONS____" << endl << endl;
		cout << "FIRST CREATE DATA BASE TO ACCESS ALL OTHER OPTIONS INSIDE THE ABOVE MENUE THANKS :)" << endl << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
		do {
			cout << "ENTER YOUR CHOICE" << endl;
			cin >> option;
		} while (option > 8 || option < 1);
		system("CLS");
		switch (option) {
		case 1:
			system("color 3F");
			students.setter();
			break;
			system("CLS");
		case 2:
			system("color DF");
			if (students.counter > 0) {
				students.append();
			}
			else
				cout << "\n                     ~~~~~~~~~~~~~~~~~ ERROR FIRST CREATE DATA BASE ~~~~~~~~~~~~~~~~\n" << endl;
			break;
		case 3:
			system("color 2F");
			if (students.counter > 0)
				students.searching();
			else
				cout << "\n                     ~~~~~~~~~~~~~~~~~ ERROR FIRST CREATE DATA BASE ~~~~~~~~~~~~~~~~~\n" << endl;
			break;
		case 5:
			system("color 6F");
			if (students.counter > 0) {
				students.deletion();
				students.counter--;
			}
			else
				cout << "\n                    ~~~~~~~~~~~~~~~~~ ERROR FIRST CREATE DATA BASE ~~~~~~~~~~~~~~~~\n" << endl;
			break;
		case 4:
			system("color 4B");
			if (students.counter > 0) {
				students.update();
			}
			else
				cout << "\n                    ~~~~~~~~~~~~~~~~ ERROR FIRST CREATE DATA BASE ~~~~~~~~~~~~~~~~~\n" << endl;
			break;
		case 6:
			system("color 3F");
			if (students.counter > 0) {
				students.sorting();
				cout << "\n                 ~~~~~~~~~~~~~~~~~~~ SORTED ACCORDING TO REG NUMBERS ~~~~~~~~~~~~~~~~~~~~\n" << endl;
			}
			else if (students.counter == 1)
				cout << "\n             ~~~~~~~~~~~~~~~~~~~ THERE IS ONLY ONE STUDENT (ALREADY SORTED) ~~~~~~~~~~~~~~~~~~~~\n" << endl;
			else
				cout << "\n                   ~~~~~~~~~~~~~~~~~ ERROR FIRST CREATE DATA BASE ~~~~~~~~~~~~~~~~~\n" << endl;
			break;
		case 7:
			system("color DF");
			if (students.counter > 0)
				students.getter();
			else
				cout << "\n                   ~~~~~~~~~~~~~~~~~ ERROR FIRST CREATE DATA BASE ~~~~~~~~~~~~~~~~~\n" << endl;
			break;

		}
	}
	system("pause");
	return 0;
}