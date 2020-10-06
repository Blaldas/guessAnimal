#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector> 
#include <cmath>

//comand to help me pass thing to ubunto and publish them xD
//cp -r /mnt/c/Users/P/Desktop/AdivinhaAnimal guessAnimal

//to the sleep function
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

//to the rand function
#include <time.h>       /* time */


using namespace std;

//it was a good idea tho...
/*
#define GET_VAR_NAME(name) getVarName(#name)		//Recives varibale and returns it's name

string getVarName(const char *name) {				//function used to return a Dtring with the variable's name, complements the #define above
	string s(name);
	return s;
}
*/

class Animal {
private:
	string name;
	bool fourLegs;
	bool domestic;
	bool carnivor;
	bool mamifer;
	bool topFoodChain;
	bool fly;
	bool feline;

public:

	//construtor using the inputs
	Animal(string name, bool fourLegs, bool domestic, bool carnivor, bool mamifer, bool topFoodChain, bool fly, bool feline) {
		this->name = name;
		this->fourLegs = fourLegs;
		this->domestic = domestic;
		this->carnivor = carnivor;
		this->mamifer = mamifer;
		this->topFoodChain = topFoodChain;
		this->fly = fly;
		this->feline = feline;
	}

	//constructor by copy
	Animal(Animal* other) {
		this->name = other->getName();
		this->fourLegs = other->getFourLegs();
		this->domestic = other->getDomestic();
		this->carnivor = other->getCarnivor();
		this->mamifer = other->getMamifer();
		this->topFoodChain = other->getTopFoodChain();
		this->fly = other->getFly();
		this->feline = other->getFeline();
	}



	string getName() { return this->name; }
	bool getFourLegs() { return this->fourLegs; }
	bool getDomestic() { return this->domestic; }
	bool getCarnivor() { return this->carnivor; }
	bool getMamifer() { return this->mamifer; }
	bool getTopFoodChain() { return this->topFoodChain; }
	bool getFly() { return this->fly; }
	bool getFeline() { return this->feline; }

	//gets a String and recognizes wich variable is it being asked for based on the string
	//literally makes all the other gets useless
	bool getByString(string s) {
		if (s == "fourLegs") return fourLegs;
		else if (s == "domestic") return domestic;
		else if (s == "carnivor") return carnivor;
		else if (s == "mamifer") return mamifer;
		else if (s == "topFoodChain") return topFoodChain;
		else if (s == "fly") return fly;
		else if (s == "feline") return feline;

	}

	int HashCode() {
		return (fourLegs * pow(2,1) + domestic * pow(2, 2) + carnivor * pow(2, 3) + mamifer * pow(2, 4) + topFoodChain * pow(2, 5) + fly * pow(2, 6) + feline * pow(2, 7));
	
	}


};


//this classe saves a question and the related variable's name
//edit 1: this clas will only save the question, the variable's name will be used as the Animal's variable name
//edit 2: press F for the ideia that I had on edit 1 xD
class Question {
	string question;			//the question, ex: "is it a mamifer?"
	string caracteristic;		//the name of the Animal's variable name, ex: "mamifer"

public:
	Question(string question, string caracteristic) {
		this->question = question;
		this->caracteristic = caracteristic;
	}

	string getQuestion() { return question; }
	string getCaracteristic() { return caracteristic; }
};



bool checksIfCanBeAdded(vector <Animal*> list, Animal newAnimal);

int main()
{

	Animal dolphin = Animal("Dolphin", false, false, true, true, true, false, false);
	Animal codfish = Animal("Codfish", false, false, true, false, false, false, false);
	Animal dog = Animal("Dog", true, true, true, true, true, false, false);
	Animal cat = Animal("Cat", true, true, true, true, true, false, true);
	Animal elephant = Animal("Elephant", true, false, false, true, true, false, false);
	Animal lion = Animal("Lion", true, false, true, true, true, false, true);
	Animal sheep = Animal("Sheep", true, true, false, true, false, false, false);
	Animal bee = Animal("Bee", false, true, false, false, false, true, false);
	Animal eagle = Animal("Eagle", false, false, true, false, true, true, false);
	Animal chicken = Animal("Chicken", false, true, false, false, false, false, false);

	vector <Animal*> animalList;			//has all the animals

	animalList.push_back(&dolphin);
	animalList.push_back(&codfish);
	animalList.push_back(&dog);
	animalList.push_back(&cat);
	animalList.push_back(&elephant);
	animalList.push_back(&lion);
	animalList.push_back(&sheep);
	animalList.push_back(&bee);
	animalList.push_back(&eagle);
	animalList.push_back(&chicken);



	Question fourLegs("Does the animal have four legs?", "fourLegs");
	Question domestic("Is it a domesticated animal?", "domestic");
	Question carnivor("Is the animal a carnivor?", "carnivor");
	Question mamifer("Is the animal a mamifer?", "mamifer");
	Question topFoodChain("Is the animal on the top of the food chain?", "topFoodChain");
	Question fly("Does the animal fly?", "fly");
	Question feline("Is the animal a feline?", "feline");

	vector <Question*> questions{};			//has all the questions

	questions.push_back(&fourLegs);
	questions.push_back(&domestic);
	questions.push_back(&carnivor);
	questions.push_back(&mamifer);
	questions.push_back(&topFoodChain);
	questions.push_back(&fly);
	questions.push_back(&feline);


	vector <Animal*> cpyAnimalList(animalList);
	vector <Question*> cpyQuestions(questions);

	int opt = 0;

	while (1) {
		do {
			cout << endl << "Select an option" << endl;
			cout << endl << "1- start the game";
			cout << endl << "2- add an animal";
			cout << endl << "3- See the available animals list";
			cout << endl << "0- exit the game" << endl;

			cin >> opt;
			if (!cin) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				opt = 0;
			}
		} while (opt != 1 && opt != 2 && opt != 3 && opt != 0);


		//starts the game
		if (opt == 1) {
			//codding for windows and for linux
			//this just clears the console
			#ifdef _WIN32
				system("cls");
			#endif
			#ifdef linux
				system("clear");
			#endif

			//shows the animal list to the user

			cout << "\nA list with animal names will be shown:\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));

			for (auto i = animalList.begin(); i != animalList.end(); ++i) {
				cout << (*i)->getName() << endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(200));
			}

			cout << "\nChoose an animal an then answer the following questions, I will try to guess wich one did you choose";
			cout << endl << "Please anwer ""y"" to ""yes"" and ""n"" to ""no""" << endl; // shows a help

			/* initialize random seed: */
			srand(time(NULL));


			//questiones the user until has a single answer
			do {
				//random question index
				int randomIndex = rand() % cpyQuestions.size();
				char answer;
				auto questIndex = cpyQuestions[randomIndex];


				//shows questions and gets the input
				bool flag = false;
				do {

					//in case of repetition, shows the controls again
					if (flag == true)
						cout << endl << "Please anwer ""y"" to ""yes"" and ""n"" to ""no"""; // shows a help
					cout << endl << questIndex->getQuestion() << endl;		//shows the question

																		   //gets answer
					cin >> answer;
					if (!cin) {
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						answer = 'f';
					}

					flag = true;	//puts the falg = true to the case where the user gives wrong input
				} while (answer != 'y' && answer != 'n');

				//Transforms the answer in a bool
				bool answerAsBool = answer == 'y' ? true : false;


				//removes all the animals that do not respect the user indications
				for (int i = 0; i < cpyAnimalList.size(); i++) {

					if (cpyAnimalList[i]->getByString(questIndex->getCaracteristic()) != answerAsBool)
					{

						cpyAnimalList.erase(cpyAnimalList.begin() + i);
						i--;
					}

					//case the user gives an answer that removes all the animals
					if (cpyAnimalList.size() == 0) {
						cout << "I can not find an animal with such caracteristics." << endl;
						return 0;
					}
				}


				//removes the question done
				cpyQuestions.erase(cpyQuestions.begin() + randomIndex);



			} while (cpyAnimalList.size() > 1);

			//finally shows the answer
			cout << endl << "The animal must be:\t" << (*cpyAnimalList.begin())->getName() << endl;

		}
		//ads a animal to the game
		else if (opt == 2) {
			string name;
			bool fourLegCar;
			bool domesticatedCar;
			bool carnivourCar;
			bool mamiferCar;
			bool topFoodChainCar;
			bool canFlyCar;
			bool felineCar;

			char info;

			char add;
			
			//codding for windows and for linux
			//this just clears the console
			#ifdef _WIN32
				system("cls");
			#endif
			#ifdef linux
				system("clear");
			#endif

			//name
			cout << "What is the new animal's name?" << endl;
			cin >> name;

#ifdef _WIN32
			system("cls");
#endif
#ifdef linux
			system("clear");
#endif

			//forlegs
			do {
				cout << endl << fourLegs.getQuestion() << endl;
				cin >> info;
				if (!cin) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					info = 'f';
				}


				if (info == 'y')
					fourLegCar = true;
				else {
					fourLegCar = false;
				}

#ifdef _WIN32
				system("cls");
#endif
#ifdef linux
				system("clear");
#endif
			} while (info != 'y' && info != 'n');
			//domestic
			do {
				cout << endl << domestic.getQuestion() << endl;
				cin >> info;
				if (!cin) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					info = 'f';
				}

				if (info == 'y')
					domesticatedCar = true;
				else {
					domesticatedCar = false;
				}
#ifdef _WIN32
				system("cls");
#endif
#ifdef linux
				system("clear");
#endif
			} while (info != 'y' && info != 'n');
			//carnivour
			do {
				cout << endl << carnivor.getQuestion() << endl;
				cin >> info;
				if (!cin) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					info = 'f';
				}

				if (info == 'y')
					carnivourCar = true;
				else {
					carnivourCar = false;
				}
#ifdef _WIN32
				system("cls");
#endif
#ifdef linux
				system("clear");
#endif
			} while (info != 'y' && info != 'n');
			//mamifer
			do {
				cout << endl << mamifer.getQuestion() << endl;
				cin >> info;
				if (!cin) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					info = 'f';
				}

				if (info == 'y')
					mamiferCar = true;
				else {
					mamiferCar = false;
				}
#ifdef _WIN32
				system("cls");
#endif
#ifdef linux
				system("clear");
#endif
			} while (info != 'y' && info != 'n');
			//topFoodChain
			do {
				cout << endl << topFoodChain.getQuestion() << endl;
				cin >> info;
				if (!cin) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					info = 'f';
				}

				if (info == 'y')
					topFoodChainCar = true;
				else {
					topFoodChainCar = false;
				}
#ifdef _WIN32
				system("cls");
#endif
#ifdef linux
				system("clear");
#endif
			} while (info != 'y' && info != 'n');
			//canFly
			do {
				cout << endl << fly.getQuestion() << endl;
				cin >> info;
				if (!cin) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					info = 'f';
				}

				if (info == 'y')
					canFlyCar = true;
				else {
					canFlyCar = false;
				}
#ifdef _WIN32
				system("cls");
#endif
#ifdef linux
				system("clear");
#endif
			} while (info != 'y' && info != 'n');
			//feline
			do {
				cout << endl << feline.getQuestion() << endl;
				cin >> info;
				if (!cin) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					info = 'f';
				}

				if (info == 'y')
					felineCar = true;
				else {
					felineCar = false;
				}
#ifdef _WIN32
				system("cls");
#endif
#ifdef linux
				system("clear");
#endif
			} while (info != 'y' && info != 'n');

			//shows the inputs
			cout << endl << "Please review your data " << endl << endl;
			cout << "name:\t" << name << endl;
			cout << fourLegs.getQuestion() << (fourLegCar ? "\ttrue" : "\tfalse") << endl;
			cout << domestic.getQuestion() << (domesticatedCar ? "\ttrue" : "\tfalse") << endl;
			cout << carnivor.getQuestion() << (carnivourCar ? "\ttrue" : "\tfalse") << endl;
			cout << mamifer.getQuestion() << (mamiferCar ? "\ttrue" : "\tfalse") << endl;
			cout << topFoodChain.getQuestion() << (topFoodChainCar ? "\ttrue" : "\tfalse") << endl;
			cout << fly.getQuestion() << (canFlyCar ? "\ttrue" : "\tfalse") << endl;
			cout << feline.getQuestion() << (felineCar ? "\ttrue" : "\tfalse") << endl;

			//asks for confirmation before adding
			do {
				cout << endl << "Do you want to add this animal? (y/n)" << endl;
				cin >> add;
			} while (add != 'y' && add != 'n');

			//case wants to add the animal
			if (add == 'y') {

				Animal newAnimal = Animal(name, fourLegCar, domesticatedCar, carnivourCar, mamiferCar, topFoodChainCar, canFlyCar, felineCar);

				//verify if there is no other animal with the same caracteristics
				if (checksIfCanBeAdded(animalList, newAnimal)) {
					animalList.push_back(new Animal(&newAnimal));
					cout << endl << name << "was added to the list!";
					
				}
				else {
					cout << endl << name << "was not added to the list, there is a animal with the same caracteristics there!";
				}
				
				//free(&newAnimal);
			}

		}
		//see the animals list
		else if (opt == 3) {
		//codding for windows and for linux
		//this just clears the console
		#ifdef _WIN32
			system("cls");
		#endif
		#ifdef linux
			system("clear");
		#endif

			cout << endl;	//just to look better

			//show animals names' loop
			for (auto a = animalList.begin(); a < animalList.end(); ++a) {
				cout << (*a)->getName() << endl;
			}


			this_thread::sleep_for(std::chrono::milliseconds(1500));
		}
		//leaves the game
		else if (opt == 0)
			return 0;


	}
}

/*
	checks if there is another animal with the same caracteristics already in the List
	return false if there is an animal with the same caracteristics
	returns true if there is no animal with the same caracteristics
*/
bool checksIfCanBeAdded(vector <Animal*> list, Animal newAnimal) {

	for (auto a = list.begin(); a < list.end(); ++a) {
		printf("\n%d", (*a)->HashCode());
		if (newAnimal.HashCode() == (*a)->HashCode())
			return false;
	}

	return true;

}


