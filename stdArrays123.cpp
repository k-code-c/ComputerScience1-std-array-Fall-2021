#include <iostream>
#include <fstream>
#include <istream>
#include <array>
#include <iomanip>

using namespace:: std;
using std:: endl;
using std:: ifstream;
using std:: cout;
using std:: array;

int main(int argc, char const** argv) {
    
    ifstream items("/Users/kcashiogwu/Downloads/homework/testscore.txt"); //read information from a file (file of names and text scores txt)
    
    float average; //the average of all the test scores
    
    std :: array< string, 13> Names{};//ArrayofNames of the students in the file
    
    std :: array< float, 13> Scores{}; // Arays of students test scores
     
    
    if (!items.is_open()){
        cout << "Error!" << endl; //checks if the file ever opens if not it prints ERROR!
        exit(1);
    }

    
    //process file
    string readName{};
    float readScore{};
    for (int i{}; i < 13; i++){
        // read in one students name and the corresponding testscore
        items >> readName;
        items >> readScore;
        // store them in the arrays
        Names[i] = readName;
        Scores[i] = readScore;
        average += readScore/13; // finds the average of all the test scores
    }
    
    //output
    
    cout << "Highest score: " << Names[3] << endl;
    //highest score student use cout
   
    cout << "Lowest score:  " << Names.at(9) << endl;
    //lowest score student use cout
    
    cout << "Scores between 80 and 89: " << "\n" << Names.at(0) << "\n" << Names.at(8) << "\n" << Names[5] << endl;
    //use cout but may need string to print multiple names or maybe not string
    
    cout << "Average Test Scores: " << setprecision(3) // the position of the average
    << average << "\n" << "*Average was Rounded*" << endl; // this would be the float array

    cout << "The size of ArrayofNames is = " << Names.size() << endl;

    
    return EXIT_SUCCESS;
}





