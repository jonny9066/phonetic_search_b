
#include "PhoneticFinder.hpp"
#define MGS 8
//#define DEBUG

using namespace std::string_literals;

struct mistype_groups {
    int num_groups = MGS;
    char g0[2] = {'v', 'w'};
    char g1[3] = {'b', 'p', 'f'};
    char g2[2] = {'g', 'j'};
    char g3[3] = {'c', 'k', 'q'};
    char g4[2] = {'s', 'z'};
    char g5[2] = {'d', 't'};
    char g6[2] = {'o', 'u'};
    char g7[2] = {'i', 'y'};
    char* groups[MGS] = {g0, g1, g2, g3, g4, g5, g6, g7};
    int group_sizes[MGS] = {2, 3, 2, 3, 2, 2, 2, 2};
} mistype_group;



// gets 2 different letters and checks if they may've been mistyped
bool check_mistype_possibility(char s, char t){
    #ifdef DEBUG
    std::cout<< "DEBUG: entered check mistype function\n"<<std::endl;
    #endif
    // step 1: convert to lowercase
    if(s < 'a'){
        s+='a'-'A';
    }
    if(t < 'a'){
        t+='a'-'A';
    }
    // check if same letter but different case
    if(t == s){
        return true;
    }
    // step 2: find the mistype groups of "s" and "t" (if any)
    int s_group = -1;
    int t_group = -1;
    for(int i=0; i < mistype_group.num_groups; i++){
        for(int j = 0; j < mistype_group.group_sizes[i]; j++){
            if(mistype_group.groups[i][j] == s)
                s_group = i;
            if(mistype_group.groups[i][j] == t)
                t_group = i;
        }
    }
    // step 3: check that both letters were found and are in the same group
    if(s_group != -1 && s_group == t_group)
        return true;
    else
        return false; 
}


// FINISH THIS
// compares 2 words with equal length
bool compare_words(string w1, string w2){
    #ifdef DEBUG
    std::cout<< "DEBUG: comparing words: \"" + w1 + "\", \"" + w2+"\""<<std::endl;
    #endif
    int word_len = w1.length();
    // if w1 = w2 i will equal word length
    int i = 0;
    while(i < word_len){
        if((w1.at(i) == w2.at(i)) || check_mistype_possibility(w1.at(i), w2.at(i))){
            i++;
        }
        else
            return false;
    }
    return true;
}
// checks input, will throw exception for bad input
bool input_check(string text, string word){
    #ifdef DEBUG
    std::cout<< "DEBUG: entered input_check function"<<std::endl;
    #endif
    //check input for word
    int text_len = text.length();
    int word_len = word.length();
    if(word_len == 0 || text_len ==0)
        return false;

    for(int i = 0; i<word_len; i++){
        // check that word consists only of letters
        if(word.at(i) < 65 || (word.at(i) > 90 && word.at(i) < 97) || word.at(i) > 122){
            return false;
        }
    }
    // check that test consists only of letters and spaces
    for(int i = 0; i<text_len; i++){
        // check that text consists only of letters and spaces
        if((text.at(i) < 65 || (text.at(i) > 90 && text.at(i) < 97) || text.at(i) > 122) &&  text.at(i) != ' '){
            return false;
        }
    }
    return true;
}

// goes over words in text and sends them for comparison
string phonetic::find(string text, string word){
    #ifdef DEBUG
    std::cout<< "DEBUG INITIATED FOR:"+"\""s + word +"\"\n"<<std::endl;
    #endif
    if(!input_check(text, word)){
        throw std::invalid_argument("Bad input");
    }

    int word_len = word.length();
    int text_len = text.length();

    // go until either text is over (will break if found)
    bool found = false;
    // i is for start of current word, j is for 1 char after its end
    int i = 0, j = 0;
    while(i < text_len && found == false){
        j = i;
        // j will be either position of space after word or text length
        while(j < text_len && text.at(j) != ' '){
            j++;
        }
        #ifdef DEBUG
        std::cout<< "DEBUG: got word length: "+ std::to_string(j-i) <<std::endl;
        #endif
        // check that the length of both words is the same and send for comparison
        if(j - i == word_len){
            found = compare_words(text.substr(i, word_len), word);
        }
        // if not found, continue to next word that starts
        // one char after j (or exit loop if j is text length)
        if(found == false){
        i = ++j;
        }
    }

    if(found == false){
        throw std::runtime_error("Did not find the word:" +"\""s + word +"\""s);
    }

    string result = text.substr(i, word_len);
    
    return result;
}

