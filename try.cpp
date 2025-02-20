#include<iostream>
#include <cstdlib>//ensure proper declaration of rand() and srand() 
#include<ctime>//ensure that selection is different everytime code run
#include<string>
using namespace std;
void start();
void display_wrongone(int wrongone);//show the misses numbers 
void display_status(const char incorrect[], int incorrect_count, string answer);//give details
void end_game(string answer, string codeword);//for ending

void start(){//for greeting & instruction for game
  cout<<"<<<<<<HANGMAN GAME>>>>>>>"<<endl;
	cout<<"========================="<<endl;
	cout<<" ________________________"<<endl;
	cout<<"|              |        \n";
	cout<<"|              O        \n";
	cout<<"|             /|\\      \n";
	cout<<"|             / \\      \n";
	cout<<"|                       \n";
	cout<<"|_______________________\n";
	cout<<"========================\n";
	cout<<"INSTRUCTIONS:Save your friend from being hanged by guessing the letters in the codeword"<<endl;
	cout<<"========================="<<endl;
	
}
void display_wrongone(int wrongone) {//print hang man according to your wrong guesses
    if (wrongone == 0) {
        cout << "  +---+ \n"
             << "  |   | \n"
             << "      | \n"
             << "      | \n"
             << "      | \n"
             << "      | \n"
             << " ========= \n";
    } else if (wrongone == 1) {
        cout << "  +---+ \n"
             << "  |   | \n"
             << "  O   | \n"
             << "      | \n"
             << "      | \n"
             << "      | \n"
             << " ========= \n";
    } else if (wrongone == 2) {
        cout << "  +---+ \n"
             << "  |   | \n"
             << "  O   | \n"
             << "  |   | \n"
             << "      | \n"
             << "      | \n"
             << " ========= \n";
    } else if (wrongone == 3) {
        cout << "  +---+ \n"
             << "  |   | \n"
             << "  O   | \n"
             << " /|   | \n"
             << "      | \n"
             << "      | \n"
             << " ========= \n";
    } else if (wrongone == 4) {
        cout << "  +---+ \n"
             << "  |   | \n"
             << "  O   | \n"
             << " /|\\  | \n"
             << "      | \n"
             << "      | \n"
             << " ========= \n";
    } else if (wrongone == 5) {
        cout << "  +---+ \n"
             << "  |   | \n"
             << "  O   | \n"
             << " /|\\  | \n"
             << " /    | \n"
             << "      | \n"
             << " ========= \n";
    } else if (wrongone == 6) {
        cout << "  +---+ \n"
             << "  |   | \n"
             << "  O   | \n"
             << " /|\\  | \n"
             << " / \\  | \n"
             << "      | \n"
             << " ========= \n";
    }
}
//const char is const to reduce the chances of any modification can happen during function.
void display_status(const char incorrect[], int incorrect_count, string answer) {
    cout << "Incorrect Guesses:\n";
    for (int i = 0; i < incorrect_count; i++) {//loop work till the number of wrong letters
        cout << incorrect[i] << " ";//Each incorrect letter is printed, separated by spaces.
    }
    cout << "\nCodeword:\n";
   for (int i = 0; i < answer.length(); i++) {//loop work till the length of guess word
    cout << answer[i] << " ";//print the current answer
    }
    cout << endl;
}

void end_game(string answer, string codeword) {
    if (answer == codeword) {//
        cout << "Hooray! You saved the person from being hanged and earned a medal of honor!\n";
        cout << "Congratulations!\n";
    } else {
        cout << "Oh no! The man is hanged!\n";
        cout << "The correct word was: " << codeword << endl;
    }
}
int main(){
	srand(time(0));
	string play_again;
	do{//do while to play game till  user say no
	start();
	string codeword,answer;//declaration of variables and array
	int wrongone=0;
	char incorrect[26];
	int incorrect_count=0;
	bool guess= false;
	char letter;
	cout<<"SELECT THE LEVEL OF GAME: \n ";//select level
	string a;
	cout<<"EASY || MEDIUM  || HARD:";
	cin>>a;
		if(a=="easy"){//for easy level
		cout<<"WELCOME TO  EASY LEVEL"<<endl;
		cout<<"HINT: >ANIMAL<"<<endl;
		string name[8]={"goat","cow","lion","tiger","hen","stag","lizard","frog"};
	
		codeword = name[rand()%8];//randomly select name
    answer = string(codeword.length(), '_');

    while (answer != codeword && wrongone < 7) {//condition till user give guess
        display_wrongone(wrongone);
        display_status(incorrect, incorrect_count, answer);

        cout << "\n\nPlease enter your guess: ";//take guess from user
        cin >> letter;

        // Convert to lowercase for consistency
        letter = tolower(letter);

        guess = false;  // Reset guess flag
        for (int i = 0; i < codeword.length(); i++) {
            if (letter == codeword[i]) {//check if guess character matches codeword character
                answer[i] = letter;
                guess = true;
            }
        }

        if (guess) {//when guess true
            cout << "\nCorrect!\n";
        } else {//when guess false
            cout << "\nIncorrect! Another portion of the person has been drawn.\n";
            incorrect[incorrect_count] = letter;
            incorrect_count++;
            wrongone++;
        }
    }
    end_game(answer, codeword);
  }
    else if(a=="medium"){
    	cout<<"WELCOME TO MEDIUM LEVEL"<<endl;
    	cout<<"HINT: >COUNTRY<"<<endl;
    	string words[8]={"london","switzerland","europe","australia","pakistan","india","newyork","kuwait"};
		codeword = words[rand()%8];
    answer = string(codeword.length(), '_');
   
    while (answer != codeword && wrongone < 7) {
        display_wrongone(wrongone);
        display_status(incorrect, incorrect_count, answer);

        cout << "\n\nPlease enter your guess: ";
        cin >> letter;

        // Convert to lowercase for consistency
        letter = tolower(letter);

        guess = false;  // Reset guess flag
        for (int i = 0; i < codeword.length(); i++) {
            if (letter == codeword[i]) {
                answer[i] = letter;
                guess = true;
            }
        }

        if (guess) {
            cout << "\nCorrect!\n";
        } else {
            cout << "\nIncorrect! Another portion of the person has been drawn.\n";
            incorrect[incorrect_count] = letter;
            incorrect_count++;
            wrongone++;
        }
    }
    end_game(answer, codeword);
  }
    else if(a=="hard"){
    	cout<<"WELCOME TO HARD LEVEL"<<endl;
    	cout<<"HINT: < RANDOM VERB>"<<endl;
   	string verb[8]={"manupulating","dancing","attracting","eating","replicating","working","coding","communicating"};
		codeword = verb[rand()%8];
    answer = string(codeword.length(), '_');
   
    while (answer != codeword && wrongone < 7) {
        display_wrongone(wrongone);
        display_status(incorrect, incorrect_count, answer);

        cout << "\n\nPlease enter your guess: ";
        cin >> letter;

        // Convert to lowercase for consistency
        letter = tolower(letter);

        guess = false;  // Reset guess flag
        for (int i = 0; i < codeword.length(); i++) {
            if (letter == codeword[i]) {
                answer[i] = letter;
                guess = true;
            }
        }

        if (guess) {
            cout << "\nCorrect!\n";
        } else {
            cout << "\nIncorrect! Another portion of the person has been drawn.\n";
            incorrect[incorrect_count] = letter;
            incorrect_count++;
            wrongone++;
        }
    }
    end_game(answer, codeword);
  }
  	else {
    	cout<<"you type wrong word check that!!!"<<endl;
	}
	
	cout<<"do you want to play again??(yes/no)"<<endl;
	cin>>play_again;
	}
	while(play_again == "yes" || play_again == "Yes" || play_again == "YES");
	cout<<"thanks for playing!!!"<<endl;

    return 0;
	
}
