/*Eric Wasserman
2300841
ewasserman@chapman.edu
CPSC 350 Section 3
Delimiter checker - implementation and main */


#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "GenStack.h"

using namespace std;


/* this function takes in the string and than reads it line by line in a while loop.
This function scans the source file looking for delimiters; if it finds an open delimiter it
pushes it on to the stack. If it finds a close delimiter it peeks the stack and compares the peek to the closed
delimiter. If they match in opposites (EX: '()') than it pops the the top of the stack. If they don't match it
tells the user what was expected and exits the program. At the end if the stack is empty the file is balanced.
If not, there is a delimiter missing at the beginning of your program.
*/
int num = 0;

template <class T>
T GenStack<T>::checkParenth(string test){
    string line;
    ifstream inFile;
    inFile.open(test);
    GenStack<char> myStack(10);

    bool continue_check = true;
    while(continue_check){
        while(getline(inFile, line, '\n')){
            num+= 1;
            for(int i = 0; i < line.length(); ++i){
                if(line[i] == '(' || line[i] == '{' || line[i] == '['){
                    myStack.push(line[i]);

                }
                else if(line[i] == ')' || line[i] == '}' || line[i] == ']'){
                    if(myStack.isEmpty()){
                        cout << "Missing delimiter at beginning of file" << endl;
                    }
                    else{
                        if(myStack.peek() == '('){
                            if(line[i] == ')'){
                                myStack.pop();
                            }
                            else if(line[i] == '}'){
                                cout << "Expected: ) and found: }. Line: " << num << endl;
                                exit(EXIT_FAILURE);
                            }
                            else if(line[i] == ']'){

                                cout << "Expected: ) and found: ]. Line: " << num << endl;
                                exit(EXIT_FAILURE);
                            }

                        }
                        else if(myStack.peek() == '{'){
                            if(line[i] == '}'){
                                myStack.pop();
                            }
                            else if(line[i] == ')'){
                                cout << "Expected: } and found: ). Line: " << num << endl;
                                exit(EXIT_FAILURE);
                            }
                            else if(line[i] == ']'){
                                cout << "Expected: } and found: ]. Line: " << num << endl;
                                exit(EXIT_FAILURE);
                            }

                        }

                        else if(myStack.peek() == '['){
                            if(line[i] == ']'){
                                myStack.pop();
                            }
                            else if(line[i] == ')'){
                                cout << "Expected: ] and found: ). Line: " << num << endl;
                                exit(EXIT_FAILURE);
                            }
                            else if(line[i] == '}'){
                                cout << "Expected: ] and found: }. Line: " << num << endl;
                                exit(EXIT_FAILURE);
                            }
                        }
                        else{
                            cout << "File reading error. Try again." << endl;
                            exit(EXIT_FAILURE);
                        }
                    }
                }
            }
        }
        if(myStack.isEmpty()){
            cout << "File balanced" << endl;
            continue_check = false;
        }
        else{
            cout << "Expecting delimiter at the end of file " << endl;
            return 4;
        }

    }
}



/* Main function that reads in the command line argument. I call my check parentheses function and if it returns a 4 it
means the end of the file was reached and we didn't find a closing parenthese. Otherwise ask the user to analyze another file.
If yes prompt for a file name and reset lines and command line argument */
int main(int argc, char **argv){
    if(argc > 1){
        try {
            string test = argv[1];
            while(true){
                char c;

                GenStack<int> parent;
                int check = parent.checkParenth(test);
                if(check == 4){
                    cout << "Error line: " << num << endl;
                    exit(EXIT_FAILURE);
                }
                //else if(check == 0) break;

            cout << "Would you like to analize another file? Y or N" << endl;
            num = 0;
            string options;
            cin >> options;
            if(options == "N"){
                exit(EXIT_FAILURE);;
            }
            else if(options == "Y"){
                cout << "Filename: " << endl;
                string file;
                cin >> file;
                test = file;
            }
            else
                cout << "Enter Y or N" << endl;
        }
    }
        catch (const std::bad_alloc&) {
            return -1;
        }
}
}
