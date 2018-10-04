//TicTacToe Game in C++ for Linux and MacOS
//from Fabian Regnery 2018

#include <iostream>
#include <vector>
using namespace std;


//The function takes a vector and check if someone has won, it returns a int variable.
//return 0 = game not over, 1 = Player A wins, 2 = Player B wins, 3 = draw
int gewinnerin(vector<int> gewinn) {
    int platz = 0;
    int ruck = 0;
    int zaehlerA = 0;
    int zaehlerB = 0;
    
    //Possibility of forming a line
        //Jumps into the next line 
        for (int i = 0; i < 3; i++) {
            //Reads in the line
            for (int i = 0; i < 3; i++) {
                if (gewinn[platz] == 1) {
                    zaehlerA++;
                }
                if (gewinn[platz] == 2) {
                    zaehlerB++;
                }
            platz++;
            }
            //Checks the counters
            if (zaehlerA == 3) {
                return ruck = 1;
            } else {
                zaehlerA = 0;
            }
            if (zaehlerB == 3) {
                return ruck = 2;
            } else {
                zaehlerB = 0;
            }
            
        } 
        
    //Possibility to form a column
        //Jumps into the next column
        for  (int i = 0; i < 3; i++) {
            platz = i;
            //Reads in the column
            for (int i = 0; i < 3; i++) {
                if (gewinn[platz] == 1) {
                    zaehlerA++;
                }
                if (gewinn[platz] == 2) {
                    zaehlerB++;
                }
            platz = platz + 3;
            }
            //Checks the counters
            if (zaehlerA == 3) {
                return ruck = 1;
            } else {
                zaehlerA = 0;
            }
            if (zaehlerB == 3) {
                return ruck = 2;
            } else {
                zaehlerB = 0;
            }
        } 
    
    //Possibility to make a diagonal
    platz = 0;
        //Jumps into the next line, for left to right diagonal
        for  (int i = 0; i < 3; i++) {
            //Chose the right Index for a diagonal in the line
                if (gewinn[platz] == 1) {
                    zaehlerA++;
                }
                if (gewinn[platz] == 2) {
                    zaehlerB++;
                }
            platz = platz + 4;
        }
            //Checks the counters
            if (zaehlerA == 3) {
                return ruck = 1;
            } else {
                zaehlerA = 0;
            }
            if (zaehlerB == 3) {
                return ruck = 2;
            } else {
                zaehlerB = 0;
            }
    platz = 2;
        //Jumps into the next line, for right to left diagonal
        for  (int i = 0; i < 3; i++) {
            //Chose the right Index for a diagonal in the line
                if (gewinn[platz] == 1) {
                    zaehlerA++;
                }
                if (gewinn[platz] == 2) {
                    zaehlerB++;
                }
            platz = platz + 2;
        }
            //Checks the counters
            if (zaehlerA == 3) {
                return ruck = 1;
            } else {
                zaehlerA = 0;
            }
            if (zaehlerB == 3) {
                return ruck = 2;
            } else {
                zaehlerB = 0;
            }
    
    // Possibility of a draw
    if (gewinn[0]&&gewinn[1]&&gewinn[2]&&gewinn[3]&&gewinn[4]&&gewinn[5]&&gewinn[6]&&gewinn[7]&&gewinn[8] != 0) {
        ruck = 3;
    }

	return ruck;
}

//The function takes a vector with 9 integers, returns void and gives out a 3x3 field.
void gebe_feld_aus(vector<int> feldaus) {
	//New vector for the graphic in the Terminal
	vector<char> dar;
	int i = 1;
        while (i < 10){
            dar.push_back(0);
            i++;
        }
	//Write on the new Vector
	for (int i = 0; i < 9; i++) {
		if (feldaus[i] == 0) {
			dar[i] = ' ';
		}
		if (feldaus[i] == 1) {
			dar[i] = 'X';
		}
		if (feldaus[i] == 2) {
			dar[i] = 'O';
		}
	}
	//Field graphic
    cout << endl << endl;
	cout << "                   +---+---+---+"<< endl;
	cout << "                   | " << dar[0] <<" | "<< dar[1] <<" | "<< dar[2] <<" | "<< endl;
	cout << "                   +---+---+---+"<< endl;
	cout << "                   | " << dar[3] <<" | "<< dar[4] <<" | "<< dar[5] <<" | "<< endl;
	cout << "                   +---+---+---+"<< endl;
	cout << "                   | " << dar[6] <<" | "<< dar[7] <<" | "<< dar[8] <<" | "<< endl;
	cout << "                   +---+---+---+"<< endl;
    cout << endl << endl;
}

//The function takes a vector with 9 integers, and asks the player for their next fieldnumber 
//it looks if this number is legal and returns in this case the number.
int frage_feld_nummer(vector<int> feld) {
	int feldnum;
	int i = 0;
	//Repeats until there is a valid number
	while (i == 0) {
 		cout << "Please choose a free field between 0 and 8:    ";
 		cin >> feldnum;
 		//looks if number is valid
 			if (feldnum > 8) {
 				cout << "Sorry, the existens of this field is not possible" << endl;
 			} else {
 			//looks if field is free
 				if (feld[feldnum] == 0) {
 					i = 1;
 					return feldnum;
 				} else {
 					cout << "Hey, this field is full" << endl;
 				}
 			}
 	}
return feldnum;
}

//Start Logo
void start() {
        cout << "                                                                  " << endl;
        cout << "                                                                  " << endl;
        cout << "     XX    XXXXXXXXX      X          XXXX    XXXXXXXXX      " << endl;
        cout << "   X    X      X         X X         X   X       X          " << endl;
        cout << "  X            X        X   X        X   X       X          " << endl;
        cout << "   XX          X       X     X       XXXX        X          " << endl;
        cout << "     X         X      XXXXXXXXX      X X         X          " << endl;
        cout << " X    X        X     X         X     X  X        X          " << endl;
        cout << "   XX          X    X           X    X   X       X          " << endl;
        cout << "                                                                  " << endl;
        cout << "                                                                  " << endl;
}

//End Logo
void end() {
        cout << "                                                                  " << endl;
        cout << "                                                                  " << endl;
        cout << "           XXXXXX    XX     X    XXXX          " << endl;
        cout << "           X         X X    X    X    X         " << endl;
        cout << "           X         X  X   X    X     X        " << endl;
        cout << "           XXX       X   X  X    X      X       " << endl;
        cout << "           X         X    X X    X     X        " << endl;
        cout << "           X         X     XX    X    X        " << endl;
        cout << "           XXXXXX    X      X    XXXXX         " << endl;
        cout << "                                                                  " << endl;
        cout << "                                                                  " << endl;
}



//The main function connects the three functions
int main() {
//Used vectors
	vector<int> feld;
	vector<int> feldaus;
	vector<int> gewinn;
	// Setup the empty field
    		int i = 1;
        		while (i < 10){
        			feld.push_back(0);
        			i++;
        	}
            start();
//Run the Game
	int zugfeld;
	int gew;
	int wastu;
	bool ende = true;
		while (ende) {
	
		//Input Player A
			//Ask  Player A
				cout << "Player A:" << endl;
				zugfeld = frage_feld_nummer(feld);
		//Update Vector
				feld[zugfeld] = 1;
		//Display Field
				gebe_feld_aus(feld);
		//Looks if somebody wins
				gew = gewinnerin(feld);
					switch (gew) {
						case 1: wastu = gew; ende = false; 
								break;
						case 2: wastu = gew; ende = false; 
								break;
						case 3: wastu = gew; ende = false; 
								break;
						default: ende = true; 
								break;
					}
		//Looks if Player B is in the Game
			if (ende) {
			 
        //Input Player B
			//Ask  Player B
				cout << "Player B:" << endl;
				zugfeld = frage_feld_nummer(feld);
		//Update vector
				feld[zugfeld] = 2;
		//Display Field
				gebe_feld_aus(feld);
        //Looks if somebody wins
				gew = gewinnerin(feld);
					switch (gew) {
						case 1: wastu = gew; ende = false; 
								break;
						case 2: wastu = gew; ende = false; 
								break;
						case 3: wastu = gew; ende = false; 
								break;
						default: ende = true; 
								break;
					}
			} else {
			end();
			} 
			}
//End, calls the Winner
	switch (wastu) {
		case 1: cout << "               Player A won the Game" << endl << endl << endl;
				break;
		case 2:	cout << "               Player B won the Game" << endl << endl << endl;
				break;
		case 3:	cout << "               It is a draw" << endl << endl << endl;
				break;
		default: cout << "Error, this is not possible, please contact the developer" << endl;
				break;
	}
    
    return 0;
}

