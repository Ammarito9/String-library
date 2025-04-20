#pragma once
#include <iostream>
#include <vector>
using namespace std;

class myString
{
  private:
    string _value;

    static bool isVowel(char character){

      string vowel = "aioeuAIOEU";
    
      return vowel.find(character) != vowel.npos;
    
    }

    static char invertCase(char character){
    
      return isupper(character) ? tolower(character) : toupper(character); 
    
    }
  
    static string trimRight(string str){

      for(int i = str.length() - 1; i >= 0; i--){
    
        if(!isspace(str[i])){
    
          return str.substr(0,i+1);
    
        }
    
      }
    
      return "";
    
    }
    
    static string trimLeft(string str){
    
      for(int i = 0; i < str.length(); i++)
      {
        if(!isspace(str[i]))
        {
          return str.substr(i,str.length()-i);
        }
    
      }
    
      return "";
    }
    
    static string trimBoth(string str){
    
      return trimRight(trimLeft(str));
    }

  public:
    myString(){_value = "";}
    myString(string value){_value = value;}

    void setValue(string value){_value = value;}
    string getValue(){return _value;}
    
    static int countVowel(string str)
    {
      int count = 0;
    
      for(char character : str){
        if(isVowel(character)) count++;
      }
    
      return count;
    }

    int countVowel()
    {
      return countVowel(_value);
    }

    static void printVowel(string str)
    {
      for(char character : str){
        if(isVowel(character)) cout << character << ' ';
      }
    }

    void printVowel()
    {
      printVowel(_value);
    }

    static int countWord(string str)
    {
     vector<string> word = split(str," ");
      return word.size();
    }

    int countWord()
    {
      return countWord(_value);
    }

    static string lowerFirstLetter(string str)
    {

      bool isFirstLetter = true;
    
      for(int i = 0; i < str.length(); i++){
    
        if(str[i] != ' ' && isFirstLetter)
        {
    
          str[i] = tolower(str[i]);
    
          isFirstLetter = false;
    
        }
        
        if(str[i] == ' '){
    
          isFirstLetter = true;
    
        }
  
      } 
      return str;
    }
    
    string lowerFirstLetter()
    {
      return lowerFirstLetter(_value);
    }

    static string upperFirstLetter(string str)
    {

      bool isFirstLetter = true;
      string upperCased = str;
    
      for(int i = 0; i < str.length(); i++){
    
        if(str[i] != ' ' && isFirstLetter){
    
          if(islower(str[i])){
            upperCased[i] = toupper(str[i]);
          }
    
          isFirstLetter = false;
    
        }
        
        if(str[i] == ' '){
    
          isFirstLetter = true;
    
        }
    
      } 
    
      return upperCased;
    
    }
  
    string upperFirstLetter()
    {
      return upperFirstLetter(_value);
    }
    
    static string upperAllLetter(string str){

      for(char &character : str){
        
        character = toupper(character);
    
      }
    
      return str;
    
    }
    
    string upperAllLetter()
    {
      return upperAllLetter(_value);
    }

    static string lowerAllLetter(string str){
    
      for(char &character : str){
        
        character = tolower(character);
    
      }
    
      return str;
    
    }
  
    string lowerAllLetter()
    {
      return lowerAllLetter(_value);
    }

    static string invertCase(string str)
    {
      for(char &character : str){
        
        character = invertCase(character);
    
      }
    
      return str;
    
    }
    
    string invertCase()
    {
      return invertCase(_value);
    }

    enum enWhatToCount {
      upperCase = 1,
      lowerCase,
      all,
    };
    
    static int countLetter(string str, enWhatToCount caseWanted = enWhatToCount::all){
    
      if(caseWanted == enWhatToCount::all) return str.length();
    
      int counter = 0;
    
      for(char character : str){
    
        if (islower(character) && caseWanted == enWhatToCount::lowerCase) counter++;
    
        if (isupper(character) && caseWanted == enWhatToCount::upperCase) counter++;
    
      }
    
      return counter;
    
    }

    int countLetter(enWhatToCount caseWanted = enWhatToCount::all)
    {
      return countLetter(_value,caseWanted);
    }

    static int countLetter(string str, char letterToCheck, bool matchCase = true){

      int counter = 0;
      char invertedLetterToCheck = tolower(letterToCheck);
    
    
      for(char character : str){
    
        if(matchCase){
          if (tolower(character) == invertedLetterToCheck) counter++;
        } else {
          if (character == letterToCheck) counter++;
        }
      }
    
      return counter;
    
    }

    int countLetter(char letterToCheck, bool matchCase = true)
    {
      return countLetter(_value,letterToCheck,matchCase);
    }

    static void printEachWord(string str){

      string delimiter = " ", sWord = "";
      short pos = 0;
    
      while((pos = str.find(delimiter)) != str.npos){
    
        sWord = str.substr(0,pos);
    
        str.erase(0,pos + delimiter.length());
    
        if(sWord != "") cout << sWord << endl;
    
      }
    
      if(str != " ") cout << str << endl;
    
    }

    void printEachWord()
    {
      printEachWord(_value);
    }    

    static vector <string> split(string str, string deli = " "){

      vector <string> splitString;
      short pos = 0;
      string sWord;
    
      while((pos = str.find(deli)) != string::npos){
    
        sWord = str.substr(0,pos);
    
        str.erase(0,pos+deli.size());
    
        if(sWord != "")
          splitString.push_back(sWord);
    
      }
    
      if(str != "")
        splitString.push_back(str);
    
      return splitString;
    
    }
    
    vector <string> split(string deli = " ")
    {
      return split(_value,deli);
    }

    enum WhatToTrim
    {
      trimRight,
      trimLeft,
      trimBoth  
    };

    static string trim(string str, WhatToTrim whatToTrim = WhatToTrim::trimBoth)
    {
      switch(whatToTrim)
      {
        case WhatToTrim::trimRight:
          return trimRight(str);
        case WhatToTrim::trimLeft:
          return trimLeft(str);
        default:
          return trimBoth(str);
      }
    }

    string trim(WhatToTrim whatToTrim = WhatToTrim::trimBoth)
    {
      return trim(_value,whatToTrim);
    }

    static string joinString(const vector <string> &separatedWords, string deli = " ")
    {
      string sentence = "";
    
      for(const string &word : separatedWords){
    
        sentence += word + deli;
    
      }
    
      return sentence.substr(0,sentence.length()-deli.length());
    
    }
    
    static string joinString(string separatedWords[],int arrLength, string deli = " "){

      string sentence = "";
    
      for(int i = 0; i < arrLength; i++){
    
        sentence += separatedWords[i] + deli;
    
      }
    
      return sentence.substr(0,sentence.length()-deli.length());
    
    }
    
    static string reverseWord(string str){

      string reversedString = "";
    
      vector <string> splitString = split(str," ");
      vector <string>::iterator iter = splitString.end();

      while(iter != splitString.begin()){
    
        iter--;
    
        reversedString += *iter + " ";
      }
    
      return reversedString.substr(0,reversedString.length()-1);
    
    }

    string reverseWord()
    {
      return reverseWord(_value);
    }

    static string replaceWord(string originalString, string originalWord, string replacement, bool matchCase = true){

      vector <string> splittedString = split(originalString," ");
      short pos;
    
      for(string &word : splittedString){
    
          string testWord, testOriginal;
    
        if(matchCase){
    
          testWord = word, testOriginal = originalWord;
    
        } else{
    
          testWord = lowerAllLetter(word), testOriginal = lowerAllLetter(originalWord);
    
        }
    
        pos = testWord.find(testOriginal);  
    
        while (pos != string::npos)
        {
          string tempWord = word.substr(0,pos);
    
          word.erase(0,pos+originalWord.length());
          tempWord += replacement;
          word = tempWord + word;
    
          testWord = lowerAllLetter(word), testOriginal = lowerAllLetter(originalWord);
          if(matchCase == false) pos = testWord.find(testOriginal);  
          else pos = word.find(originalWord);
    
        }
        
      }
    
      return joinString(splittedString);
    
    }
    
    string replaceWord(string originalWord, string replacement, bool matchCase = true)
    {
      return replaceWord(_value,originalWord,replacement,matchCase );
    }

    static string removePunctuation(const string& str){

      string withOutPunct;
    
      for(const char ch : str){
    
        if(!ispunct(ch)) withOutPunct += ch; 
    
      }
    
      return withOutPunct;
    }

    string removePunctuation()
    {
      return removePunctuation(_value);
    }
};
