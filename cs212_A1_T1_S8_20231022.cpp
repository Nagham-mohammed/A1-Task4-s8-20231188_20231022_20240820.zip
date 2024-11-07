//file: cs212_A1_T1_S8_20231022
//author: Asmaa Sayed Mohammed
//section: S8
//ID: 20231022
// Date: 11 Oct 2024

#include <bits/stdc++.h>
using namespace std;
struct Tile {
    int topDots;
    int bottomDots;
};

// Function to check if the input is a valid integer
bool isInteger(const string& str) {
    return !str.empty() && find_if(str.begin(), str.end(), [](unsigned char c) { return !isdigit(c); }) == str.end();
}

// Recursive function to form a tile sequence chain
bool canFormTileChain(vector<Tile>& tiles, int idx, int currentEnd, vector<Tile>& sequence) {
    if (idx == tiles.size()) {
        // Chain is complete, return true
        return true;
    }

    for (int i = idx; i < tiles.size(); ++i) {
        if (tiles[i].topDots == currentEnd) {
            swap(tiles[i], tiles[idx]);  // Swap the tiles
            sequence.push_back(tiles[idx]);   // Add the tile to the sequence

            if (canFormTileChain(tiles, idx + 1, tiles[idx].bottomDots, sequence)) {
                return true; // If valid sequence, return true
            }

            sequence.pop_back();  // Backtrack
            swap(tiles[i], tiles[idx]);
        }
    }

    return false; // No valid chain found
}

void tileProblem() {
    int numTiles;
    string inputStr;

    // Input validation for the number of tiles
    while (true) {
        cout << "Enter number of tiles: ";
        cin >> inputStr;
        if (isInteger(inputStr)) {
            numTiles = stoi(inputStr);
            break;
        } else {
            cout << "Invalid input, please enter a valid integer." << endl;
        }
    }

    vector<Tile> tiles(numTiles);
    cout << "Enter the tiles (topDots bottomDots):" << endl;

    // Input validation for each tile
    for (int i = 0; i < numTiles; ++i) {
        string top, bottom;
        while (true) {
            cout << "Tile " << i + 1 << ": ";
            cin >> top >> bottom;
            if (isInteger(top) && isInteger(bottom)) {
                tiles[i].topDots = stoi(top);
                tiles[i].bottomDots = stoi(bottom);
                break;
            } else {
                cout << "Invalid input, please enter two valid integers." << endl;
            }
        }
    }

    vector<Tile> sequence;  // To hold the tile chain
    if (canFormTileChain(tiles, 0, tiles[0].topDots, sequence)) {
        cout << "It is possible to form a tile chain.\n";
        cout << "Tile Chain: ";
        for (const auto& tile : sequence) {
            cout << tile.topDots << "|" << tile.bottomDots << " ";
        }
        cout << endl;
    } else {
        cout << "It is not possible to form a tile chain.\n";
    }
}
string sentence;
string x;
int a;

void first_upper() {
    bool first_letter_found = false;  // To check if the first alphabetic character is found

    for (char &z : x) {
        if (!first_letter_found && isalpha(z)) {
            z = toupper(z);  // Capitalize the first alphabetic character
            first_letter_found = true;  // Set flag to true after capitalizing the first letter
        } else {
            z = tolower(z);  // Lowercase all other characters
        }
    }
}
void remove_spaces(){
    while (!x.empty() && x[0] == ' ') {
        x.erase(x.begin());
    }

    // Remove spaces before the full stop
    if (!x.empty() && x.back() == '.') {
        int i = x.size() - 2;  // Start from the second-last character
        while (i >= 0 && x[i] == ' ') {
            x.erase(x.begin() + i);  // Remove spaces before the period
            --i;
        }
    }

    // Remove consecutive spaces in between the sentence
    for (int i = 0; i < x.size() - 1; ++i) {
        if (x[i] == ' ' && x[i + 1] == ' ') {
            x.erase(x.begin() + i);
            --i;
        }
    }
}
void correct_sentence(){
    while (true) {
        getline(cin, sentence);
        x += sentence;  // Add each sentence

        if (!x.empty() && x.back() == '.') {  // Check if the last character is a period
            break;  // Stop input when the sentence ends with a period
        }

        x += " ";  // Add a space between sentences
    }
    first_upper();
    remove_spaces();
    cout << x << endl;

}

void primarynumbers(){
    int a;
    cout << "Please, insert a positive number\n";
    cin >> a; //insert the number that you want to end your series at it
    deque<int> dq;
    while (true)//using the loop to let user insert number many times until insert a correct number
    {
        if (a > 1) //check if the number can start from it or not
        {
            for (int i = 2; i <= a; ++i)
            {
                dq.push_back(i);// insert numbers from 2 to a in a container(dq)
            }
            break;
        }
        else if (a == 1){
            cout << "[]" ;
        }
        else
        {
            cout << "Please, insert a number bigger than 1 --> " << "\n";
            cin >> a;
        }
    }
    for (int i = 2; i * i <= a; ++i)//loop on the container from i to square of ib(to increase the quality of code)
    {
        for (auto it = dq.begin(); it != dq.end(); ) // make an iterator from the begin to the end
        {
            if (*it % i == 0 && *it != i) // check if the number that iterator is pointing on it divisible by i or not
                //prime number can devise by 1 or the same number
            {
                it = dq.erase(it);//delete the number if it devisible by i
            }
            else
            {
                ++it;//if it not divisible by i let the iterator move to the next number
            }
        }
    }
    cout << "[";
    for (int x : dq)
    {
        cout << x << ",";  // print the primary number
    }
    cout << "]";
    cout << "\n";
}
void file_problem(){
    string name;
    cout << "please insert the name of the file which has a sentence(arabic.txt): ";
    while (true) {
        cin >> name;
        for (char &i : name) {
            i = tolower(i);//let user insert the input in upper or lower case
        }
        if (name == "arabic.txt"){
            break;
        }
        else
        {
            cout << "please. insert a correct name: ";
        }
    }

    locale::global(locale(""));

    // Open arabic.txt for reading
    wifstream input_file("arabic.txt");
    input_file.imbue(locale(input_file.getloc(), new codecvt_utf8<wchar_t>));

    // Open table1.txt for reading
    wifstream table("table1.txt");
    table.imbue(locale(table.getloc(), new codecvt_utf8<wchar_t>));

    // Check if files are opened successfully
    if (!input_file.is_open()) {
        cout << "arabic file didn't open" << endl;
    }
    if (!table.is_open()) {
        wcerr << L"Unable to open table1.txt" << endl;
    }

    wstring sentence;
    map<wstring, wstring> map1;

    // Read the translation table
    while (getline(table, sentence)) {
        wstringstream s1(sentence);
        wstring s2, s3;
        s1 >> s2 >> s3; // Extract words
        map1[s2] = s3;   // Add to the map
    }

    wstringstream result;
    wstring line;

    // Replace words according to the map and print directly to console
    while (getline(input_file, line)) {
        wstringstream s6(line);
        wstring a1;

        while (s6 >> a1) {
            // Check for replacement
            if (map1.find(a1) != map1.end()) {
                result << map1[a1] << L" "; // Add space after each word
                wcout << map1[a1] << L" ";  // Print replacement to console
            } else {
                result << a1 << L" "; // Add space after each word
                wcout << a1 << L" ";  // Print original word to console
            }
        }
        result << L"\n"; // Add newline after each line processed
        wcout << L"\n";  // Print newline to console
    }

    // Write the result to the output file
    wofstream output("result.txt");
    output.imbue(locale(output.getloc(), new codecvt_utf8<wchar_t>));

    // Check if output file is opened successfully
    if (!output.is_open()) {
        wcerr << L"Unable to open result.txt" << endl;
    }

    output << result.str();  // Write the result to the file
    output.close();  // Close the file after writing

    // Close all input files
    table.close();
    input_file.close();

}
int main() {
    string g;
    while (true){
        cout << "1)start\n";
        cout << "2)end\n";
        cout << "insert your choice: ";
        cin >> g;
        if(g == "1")
        {
            cout << "welcome to my program , please enter the number of problem that you want\n";
            cout << "1)Correct the sentence\n";
            cout << "2)Find primary numbers\n";
            cout << "3)Domino chain\n";
            cout << "4)Replacing words\n";
            cout << "Program's number is:";
            string n;
            while (true)
            {
                cin >> n;
                if (n == "1")
                {

                    correct_sentence();
                    break;
                }
                else if (n == "2")
                {

                    primarynumbers();
                    break;
                }
                else if (n == "3")
                {
                    tileProblem();
                    break;
                }
                else if (n == "4")
                {

                    file_problem();
                    break;
                }
                else
                {
                    cout << "please insert only integer number between 1 and 4 (1,2,3,4):";

                }
            }
        }
        else if (g == "2")
        {
            break;
        }
        else
        {
            cout << "please insert a suitable number only 1 or 2\n ";
        }

    }
    cout << "Thank you for using my program\n";
    return 0;
}
