//
//  main.cpp
//  gradeTest
//
//  Created by Affiq Mohammed on 12/2/22.
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//passes data from key file into array
bool keyFile(string &x, char arr[], int &count){
    fstream newFile;
    newFile.open(x);
    int i = 0;


    if(!newFile){
        cout << "\"" << x << "\"" << " could not be opened." << endl;
        return false;
    }
    else if(newFile.peek() == EOF){
        cout << "The file containing the key was empty." << endl;
        return false;
    }
    else{
        while (!newFile.eof())
        {
            newFile >> arr[i];
            i++;
            count++;
        }
        count = count - 1;
        newFile.close();

        return true;
    }
}

//passes data from response file into array
bool responseFile(string &textFile, char arrr[], int &count){
    fstream file;
    file.open(textFile);
    int y = 0;

    if(!file){
        cout << "\"" << textFile << "\"" << " could not be opened." << endl;
        return false;
    }
    else if(file.peek() == EOF){
        cout << "File error! There is a mismatch between the number of questions and answers." << endl;
        return false;
    }
    else{
        while (!file.eof())
        {
            file >> arrr[y];
            y++;
            count++;
        }
        count = count - 1;
        file.close();

        return true;
    }
}

//claculates correct student responses and returns the percentage
void displayResults(char character[], char arr[], int &w){
    int t = 0;
    double d = 0;

    for(int i = 0; i <= w - 1; i++){
        if(arr[i] != character[i]){
            cout << "Question " << i + 1 << " has incorrect answer '" << arr[i] << "', the correct answer is '" << character[i] << "'.";
            t++;
            cout << endl;
        }
    }

    cout << t << " questions were missed out of " << w << "." << endl;
    d = w - t;
    d = (d / w) * 100;
    cout << "The student grade is " << fixed << setprecision(2) << d << "%" << endl;
    
    if(d >= 72.50){
        cout << "The student has passed the quiz." << endl;
    }
    else{
        cout << "The student has failed the quiz." << endl;
    }

}

int main() {
    string basicString, name;
    char character[50];
    char t[50];
    int x = 0;
    int p = 0;
    bool b;
    bool f = true;
    fstream firstFile;


    cout << "Enter the name of the file containing the key." << endl;
    cin >> basicString;

    b = keyFile(basicString, character, x);

    if(b == true){
        cout << "Enter the name of the file containing the student's responses." << endl;
        cin >> name;

        f = responseFile(name, t, p);
    }
    if(b == true && f == true){
        displayResults(character, t, x);
    }
}
