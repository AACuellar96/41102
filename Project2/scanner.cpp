
#include <stdio.h>
#include  "scanner.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

//Methods from flex
extern int yylex();
extern int yylineno;
extern char* yytext;
//Global variables so they do not have to be passed as arguments
//Symbol vector, holds the characters for the trie table.
vector<char> symbol(0); 
// NextO vector, holds the numbers of the next characters for the trie table. 
vector<int> nextO(0);
// Ids vector, holds all the ids and keywords used in the input. A vector is used for the purpose of sorting all of the inputted words.
vector<string> ids(0);
// SwitchT array holds the locations of the next symbol after this particular character in the array.
int switchT [52]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
// Ptr, index used in the algorithm for comparison purposes
int ptr;
// Place, index used to see which particular word is being observed.
int place;

//Methods used in this class
void create(int ind);
void printSwitch();
void printSymNext();
void completeCreation();

//Main method, calls all relevant methods. 
int main(int argc,const char*argv[]){
	completeCreation();
	printSwitch();
	cout << endl;
	printSymNext();
	return 0;
}
/*
*Method that loads all of the scanned input. Adds the id's and keywords used to the vector ids. A vector is used for the sake of sorting all of the entries alphabetically. Ignores duplicate entries.
*Method also creates the trie table with the given algorithm.
*/
void completeCreation(){
	int valuet = yylex();
	string id;
	while(valuet>0){
		valuet=yylex();
		if(valuet>=1 && valuet <=21){
			string temp=yytext;
			temp+="*";
			bool tempV(false);
			for(int i=0;i<ids.size();i++){
				if(ids.at(i).compare(temp)==0){
					tempV=true;
					break;
				}
			}
			if(!tempV){
				ids.push_back(temp);
			}
		}
	}
	sort(ids.begin(),ids.end());

	place=0;
	while(place<ids.size()){
		int ind=0;
		valuet=(int) ids.at(place).at(ind);
		if(valuet<=90)
			valuet-=65;
		else
			valuet-=71;
		bool exit(false);
		ptr=switchT[valuet];
		if(ptr==-1)
			create(ind);
		else{
			ind++;
			valuet=(int) ids.at(place).at(ind);
			while(!exit){
				if(ptr!=-1 && symbol.at(ptr)==valuet){
					if(valuet!='*'){
					ptr++;
					ind++;
					valuet=(int) ids.at(place).at(ind);
					}
					else{
						exit=true;
					}
				}
				else if(nextO.at(ptr)!=-1){
					ptr=nextO.at(ptr);
				}
				else{
					create(ind);
					exit=true;
				}	
			}		
		}
	}
}
/*
*Method that adds an entry to the trie.
*Takes in the index of the currently being examined char in the string at the place index in the ids vector.
*Looks at the first character of the word and sees if it must make it based off of the switchT array or another word already in the trie. 
* Pushes back all characters in the word that are not already present in a branch in the trie.
*/
void create(int ind){
	
	char c=ids.at(place).at(0);

	int placement=symbol.size();
	int index=0;
	if((int) c<=90){
		index=((int) c-65);
	}
	else
		index=((int) c-71);
	if(switchT[index]==-1){
		switchT[index]=placement;
		ind++;
		while(ids.at(place).at(ind)!='*'){
			symbol.push_back(ids.at(place).at(ind));
			nextO.push_back(-1);
			ind++;
		}
	}


	else{
		nextO.at(ptr)=placement;
		while(ids.at(place).at(ind)!='*'){
			symbol.push_back(ids.at(place).at(ind));
			nextO.push_back(-1);
			ind++;
		}
		
	}
	symbol.push_back(ids.at(place).at(ind));
	nextO.push_back(-1);
	place++;
}
/*
*Method that prints out the switchT array table. Prints the array with 20 columns of entries per row.
*/
void printSwitch(){
	for(int i=0;i<3;i++){
		cout<< setw(8) << " ";
		for(int j=(0+(i*20));j<(20+(i*20)) && j<52;j++){
			if(j<26)
				cout << setw(3) << ((char) (j+65)) <<" ";
			else
				cout << setw(3) << ((char) (j+71)) <<" ";
		}
		cout << endl;
		cout<< setw(7) << "switch: ";
		for(int j=(0+(i*20));j<(20+(i*20)) && j<52;j++){
			cout << setw(3) << switchT[j] <<" ";
		}
		cout << endl;
		cout << endl;

	}
}
/*
*Method that prints out the symbol and next table. Prints the vectors with 20 columns of entries per row.
*/
void printSymNext(){
	int times = symbol.size()/20;
	if(symbol.size()%20!=0)
		times++;
	for(int i=0;i<times;i++){
		cout<< setw(8) << " ";
		for(int j=(0+(i*20));j<(20+(i*20)) && j<symbol.size();j++){
			cout << setw(4) << j <<" ";
		}	
		cout << endl;
		cout<< setw(8) << "symbol: ";
		for(int j=(0+(i*20));j<(20+(i*20)) && j<symbol.size();j++){
			cout << setw(4) << symbol[j] <<" " ;
		}
		cout << endl;
		cout<< setw(8) << "next: ";
		for(int j=(0+(i*20));j<(20+(i*20)) && j<symbol.size();j++){
			if(nextO[j]!=-1)
				cout << setw(4) << nextO[j] <<" " ;
			else
				cout << setw(4) <<" " <<" ";
		}	
		cout << endl;
		cout << endl;

	}
}

