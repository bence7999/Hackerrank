#include "Inheritance.h"

using namespace std;

class Triangle {
public:
	void triangle() {
		cout << "I am a triangle\n";
	}
};

class Isosceles : public Triangle {
public:
	void isosceles() {
		cout << "I am an isosceles triangle\n";
	}
	//Write your code here.
	void description() {
		cout << "In an isosceles triangle two sides are equal\n";
	}
};

// input: 
void InheritanceIntroduction() {
	Isosceles isc;
	isc.isosceles();
	isc.description();
	isc.triangle();
}

class Rectangle {
public:
	int width, height;

	void display() {
		cout << width << " " << height << endl;
	}
};

class RectangleArea : public Rectangle {
public:
	void read_input() {
		cin >> width;
		cin >> height;
	}
	void display() {
		cout << width * height << endl;
	}
};

// input: 10 5
void RectangleAreaTask() {
	/*
	* Declare a RectangleArea object
	*/
	RectangleArea r_area;

	/*
	* Read the width and height
	*/
	r_area.read_input();

	/*
	* Print the width and height
	*/
	r_area.Rectangle::display();

	/*
	* Print the area
	*/
	r_area.display();
}

class Triangle2 {
public:
	void triangle() {
		cout << "I am a triangle\n";
	}
};

class Isosceles2 : public Triangle2 {
public:
	void isosceles() {
		cout << "I am an isosceles triangle\n";
	}
};

class Equilateral : public Isosceles2 {
public:
	void equilateral() {
		cout << "I am an equilateral triangle" << endl;
	}
};

// input: 
void MultiLevelInheritance() {
	Equilateral eqr;
	eqr.equilateral();
	eqr.isosceles();
	eqr.triangle();
}

class A
{
public:
	A() {
		callA = 0;
	}
private:
	int callA;
	void inc() {
		callA++;
	}

protected:
	void func(int & a)
	{
		a = a * 2;
		inc();
	}
public:
	int getA() {
		return callA;
	}
};

class B
{
public:
	B() {
		callB = 0;
	}
private:
	int callB;
	void inc() {
		callB++;
	}
protected:
	void func(int & a)
	{
		a = a * 3;
		inc();
	}
public:
	int getB() {
		return callB;
	}
};

class C
{
public:
	C() {
		callC = 0;
	}
private:
	int callC;
	void inc() {
		callC++;
	}
protected:
	void func(int & a)
	{
		a = a * 5;
		inc();
	}
public:
	int getC() {
		return callC;
	}
};

class D : public A, public B, public C
{

	int val;
public:
	//Initially val is 1
	D()
	{
		val = 1;
	}


	//Implement this function
	void update_val(int new_val)
	{
		int loc_val = new_val;
		while (true) {
			if (loc_val % 2 == 0) {
				A::func(val);
				loc_val /= 2;
			}
			if (loc_val % 3 == 0) {
				B::func(val);
				loc_val /= 3;
			}
			if (loc_val % 5 == 0) {
				C::func(val);
				loc_val /= 5;
			}
			if (loc_val == 1)
				break;
		}
	}
	//For Checking Purpose
	void check(int); //Do not delete this line.
};

void D::check(int new_val)
{
	update_val(new_val);
	cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}

// input: 30
void AccessingInheritedFunctions() {
	D d;
	int new_val;
	cin >> new_val;
	d.check(new_val);
}
/*
class Spell {
private:
	string scrollName;
public:
	Spell() : scrollName("") { }
	Spell(string name) : scrollName(name) { }
	virtual ~Spell() { }
	string revealScrollName() {
		return scrollName;
	}
};

class Fireball : public Spell {
private: int power;
public:
	Fireball(int power) : power(power) { }
	void revealFirepower() {
		cout << "Fireball: " << power << endl;
	}
};

class Frostbite : public Spell {
private: int power;
public:
	Frostbite(int power) : power(power) { }
	void revealFrostpower() {
		cout << "Frostbite: " << power << endl;
	}
};

class Thunderstorm : public Spell {
private: int power;
public:
	Thunderstorm(int power) : power(power) { }
	void revealThunderpower() {
		cout << "Thunderstorm: " << power << endl;
	}
};

class Waterbolt : public Spell {
private: int power;
public:
	Waterbolt(int power) : power(power) { }
	void revealWaterpower() {
		cout << "Waterbolt: " << power << endl;
	}
};

class SpellJournal {
public:
	static string journal;
	static string read() {
		return journal;
	}
};

string SpellJournal::journal = "";

void counterspell(Spell *spell) {
	Fireball* fire = dynamic_cast<Fireball*>(spell);
	Frostbite* frost = dynamic_cast<Frostbite*>(spell);
	Thunderstorm* thunder = dynamic_cast<Thunderstorm*>(spell);
	Waterbolt* water = dynamic_cast<Waterbolt*>(spell);
	SpellJournal* journal = dynamic_cast<SpellJournal*>(spell);

	if (fire != NULL) {
		fire->revealFirepower();
	}
	else if (frost != NULL) {
		frost->revealFrostpower();
	}
	else if (thunder != NULL) {
		thunder->revealThunderpower();
	}
	else if (water != NULL) {
		water->revealWaterpower();
	}
	else if (journal->read() != "") {
		string spellN = spell->revealScrollName();
		string spellJ = SpellJournal::read();
		int m = spellN.length();
		int n = spellJ.length();
		int array[m + 1][n + 1];

		// solve for LCS
		for (int i = 0; i <= m; i++) array[i][0] = 0;
		for (int j = 0; j <= n; j++) array[0][j] = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (spellN[i - 1] == spellJ[j - 1])
					array[i][j] = array[i - 1][j - 1] + 1;
				else
					array[i][j] = max(array[i][j - 1], array[i - 1][j]);
			}
		}
		cout << array[m][n] << endl;
	}
}

class Wizard {
public:
	Spell *cast() {
		Spell *spell;
		string s; 
		cin >> s;
		int power; cin >> power;
		if (s == "fire") {
			spell = new Fireball(power);
		}
		else if (s == "frost") {
			spell = new Frostbite(power);
		}
		else if (s == "water") {
			spell = new Waterbolt(power);
		}
		else if (s == "thunder") {
			spell = new Thunderstorm(power);
		}
		else {
			spell = new Spell(s);
			cin >> SpellJournal::journal;
		}
		return spell;
	}
};

void MagicSpells() {
	int T;
	cin >> T;
	Wizard Arawn;
	while (T--) {
		Spell *spell = Arawn.cast();
		counterspell(spell);
	}
}
*/