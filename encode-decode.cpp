#include <iostream>
#include <cstdlib>
using namespace std;

void encoder(string a){
    char y[2][14]={
        {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'},
        {'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '.', '_'}
    };
    string z[2][14]={
        {".-", "-...", "-.-.", "-..", ".", ".-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-."},
        {"---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".-.-.-", "/"}

    };
    int size = a.length();
    for(int h= 0; h < size; h++){
        for(int i= 0; i < 2; i++){
            for(int j= 0; j < 14; j++){
                if(a[h] == y[i][j]) cout << z[i][j] << " ";
            }
        }
    }
}

void decoder(string a){
    char y[2][14]={
        {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'},
        {'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '.', '_'}
    };
    string z[2][14]={
        {".-", "-...", "-.-.", "-..", ".", ".-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-."},
        {"---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".-.-.-", "/"}

    };

    int c = a.find("+");
    string f;
    for(int d = 0; d < c; d++){
        f += a[d];
    }
    for(int i= 0; i < 2; i++){
            for(int j= 0; j < 14; j++){
                if(f == z[i][j]) cout << y[i][j];
            }
    }
    string k = a.substr(c+1);
    bool yes = true;
    if(k == "x") yes = false;
    if(yes == true) decoder(k);
}


int main(){

    cout << "Instructions: " << endl;
    cout << "   - Encoder: " << endl;
    cout << "       While using the encoder, replace all spaces between words with an underscore(_)." << endl;
    cout << "   - Decoder: " << endl;
    cout << "       While using the decoder, after you write the code for every letter, insert a plus sign (+)." << endl;
    cout << "       When you are finished writing all your coded letters, insert an 'x' at the end of your code." << endl;
    cout << endl;
    cout << endl;

    string ans;
    cout << "Would you like to encode a message or decode a message? (encode or decode) ";
    cin >> ans;
    cout << endl;

    string input;
    cout << "Please input the string of letters or Morse Code: ";
    cin >> input;
    cout << endl;

    if(ans == "encode"){
        encoder(input);
        cout << endl;
    }

    if(ans == "decode"){
        decoder(input);
        cout << endl;
    }

    string ans1;
    cout << "Would you like to run the program again? (Yes or No)";
    cin >> ans1;
    cout << endl;

    while (ans1 == "Yes"){
        string ans;
        cout << "Would you like to encode a message or decode a message? (encode or decode) ";
        cin >> ans;
        cout << endl;

        string input;
        cout << "Please input the string of letters or Morse Code: ";
        cin >> input;
        cout << endl;

        if(ans == "encode"){
            encoder(input);
            cout << endl;
        }

        if(ans == "decode"){
            decoder(input);
            cout << endl;
        }

        cout << "Would you like to run the program again? (Yes or No)";
        cin >> ans1;
        cout << endl;
    }

    return 0;
}
