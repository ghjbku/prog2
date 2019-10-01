#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

void fight(int intel, int d)
{
	int i = 0;
	int j = 0;
	int k = 0;
	if (intel == 1)
	{
		cout << "you remember the paper you found had a bear drawing on it with three numbers: 5 2 4\n";
	}
	else if (intel == 0)
	{
	}
	cout << "the bear attacks first with a rush attack\nyou: 1.defend\n 2.side step to the right and try to hit its knee\n 3. back step\n 4.slash it with your sword \n5.side step to the left\n";
	cin >> i;
	if (i == 1)
	{
		cout << "you can`t defend without a shield, you died.";
	}
	else if (i == 2)
	{
		cout << "you try to dodge by sidestepping to right, but the bear somehow knows you would do that\nit slashes you and deals critical damage\nyou died.";
	}
	else if (i == 3)
	{
		cout << "you try to backstep, but why? \nthe bear doesn`t even have to turn anywhere, it easily kills you.\n";
	}
	else if (i == 4)
	{
		cout << "you slash the bear with your dagger as it reaches you\nyou dealt almost no damage.\nthe bear bites you with unbearable strength\nyou died";
	}
	else if (i == 5)
	{
		d++;
		cout << "you sidestep to the left,the bear, surprised lounges to the right.\nit hits nothing but air.\nthe bear,enraged even further try to attack you from the right.\n[decision making " << d << "]\nyou: ";
		cout << "1.defend\n 2.side step to the right and try to hit its knee\n 3. back step\n 4.slash it with your sword \n5.side step to the left\n";
		cin >> j;
		if (j == 1)
		{
			cout << "you can`t defend without a shield, you died.";
		}

		if (j == 2)
		{
			d++;
			cout << " you sidestep to the right,the bear surprised again, you use the momentum to slash its knees.\nthe bear falls to the ground.\n[decision making " << d << "]\n ";

			cout << "\nyou: 1.defend\n 2.side step to the right and try to hit its knee\n 3. back step\n 4.slash it with your sword \n5.side step to the left\n";
			cin >> k;
			if (k == 1)
			{
				cout << "why would you..?,you died...";
			}

			else if (k == 2)
			{
				cout << "why would you..?,you died...";
			}

			else if (k == 4)
			{
				d = d + 2;
				cout << "you slash the head of the bear while its down.\nyou dealt monsterous amount of damage.\nyou 1hit killed the bear.[decision making " << d << "]\n\n\nCongratulations, \nYou Won The Game!";
			}

			else if (k == 3)
			{
				cout << "why would you..?,you died...";
			}

			else if (k == 5)
			{
				cout << "why would you..?,you died...";
			}
		}

		if (j == 3)
		{
			cout << "you try to back step,and you succeed, but the bear somehow kicks you in the head and you die.";
		}

		if (j == 4)
		{
			cout << "you try to slash it with your sword, but do you think you hit harder than a bear?\nyou died from a pawn hit in the head.";
		}

		if (j == 5)
		{
			cout << "you try to sidestep to the left,but the bear remebers you doing that before,it turns toward you and slashes...\nyou died.";
		}
	}
}

void fwd(int c, int weap, int intel, int d)
{
	cout << "\nafter half an hour of walking, you reach a clearance.\nyou see a bear walking slowly towards you with blood red eyes.\n\nyou: 1.try to fight 2.try to run\n";
	cin >> c;
	if (c == 1)
	{
		if (weap == 1)
		{
			cout << "you pull out the dagger you found back then, and start fighting the bear\n";
			fight(intel, d);
		}
		else if (weap == 0)
		{
			cout << "\nyou don`t have a weapon, you died\n";
		}
	}
	else if (c == 2)
	{
		cout << "the moment you start running, it does too.\nyou can`t outrun a bear, you died";
	}
}

void choose1(int intel, int weap, int i, int valaszt, int d, int j)
{
	string l = "1.look around ";
	string f = "2. go forward ";
	string b = "3.go backward ";
	string left = "4.go left ";
	string r = "5.go right ";
	i = 0;
	j = 0;
	weap = 0;
	d = 0;
	int k = 0;
	int c = 0;
	while (i != 1)
	{
		cout << "\n choose something to do:\n"
			 << l << f << b << left << r << "\n";
		valaszt = 0;
		cin >> valaszt;
		if (valaszt == 1)
		{
			if (intel == 0)
			{
				cout << "you choose to look around.\n";
				cout << "you found a piece of paper with important looking things on it.\n [intelligence]+1\nthere is nothing else here\n";
				intel = 1;
			}
			else if (intel == 1)
			{
				cout << "there is nothing else here";
			}
		}
		else if (valaszt == 2)
		{
			cout << "you choose to move forward\n";
			fwd(c, weap, intel, d);
			i++;
		}
		else if (valaszt == 3)
		{
			cout << "you try to move bacwards but you can not, so you decide to go elsewhere\n";
		}
		else if (valaszt == 4)
		{
			if (weap == 0)
			{
				cout << "you decide to walk left.\n you find a dagger.\n you think it may come handy sometime soon, so you put it into your belt.\n [weapon acquired]\n";
				weap = 1;
				cout << "there is nothing else this way, so you head back to the crossroads.\n";
			}
			else if (weap == 1)
			{
				cout << "you have been here already";
			}
		}
		else if (valaszt == 5)
		{
			cout << "you decide to walk right.\n there is a lake before you\nyou think about: \n";
			cout << "1.looking around "
				 << "before doing anything stupid "
				 << "2. jump into the river, you are sweating like crazy \n";
			cin >> j;
			if (j == 1)
			{
				d++;
				cout << "after searching for a bit,\n you find a sign that warns you about\n piranhas in the lake.\n[decision making " << d << "] ";
				cout << "\n\nafter you finished reading the signboard, you hear a roar from ahead\nyou decide to:\n1.go and take a look 2.run back to the crossroads\n";
				cin >> k;
				if (k == 1)
				{
					fwd(c, weap, intel, d);
					break;
				}
				else if (k == 2)
				{
				}
			}
			else if (j == 2)
			{
				cout << "some piranhas appeared the moment you jumped it.\n you died.\n[decision making 0]";
				break;
			}
		}
		else
		{
			cout << "try again\n";
		}
	}
}

void choose2()
{
}

void cross1(int i, int valaszt)
{
	string frst = "1.forest";
	string vill = "2.village";
	int d = 0;
	valaszt = 0;
	i = 0;
	int intel = 0;
	int j = 0;
	int weap = 0;
	while (i != 1 | valaszt == 3)
	{
		cout << "you start your journey in a:"
			 << "\n"
			 << frst << " " << vill << " or press 3 to quit\n";

		cin >> valaszt;

		if (valaszt == 1)
		{
			cout << "you start your journey in a forest \nthere is a crossroads in front of you\n";
			i++;
			choose1(intel, weap, i, valaszt, d, j);
		}
		else if (valaszt == 2)
		{
			cout << "you start your journey in a village \n";
			i++;
			choose2();
		}
		else if (valaszt == 3)
		{
			break;
		}
		else
		{
			cout << "you have to write either 1 2 or 3\n\n";
		}
	}
}

int main()
{
	int valaszt = 0;
	int i = 0;

	cross1(i, valaszt);
	return 0;
}

