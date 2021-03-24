#include<bits/stdc++.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>

int isKeyword(char buffer[]){
    std::vector<std::string> keywords =
    {"auto","break","case","char","const","continue","default",
    "do","double","else","enum","extern","float","for","goto",
    "if","int","long","register","return","short","signed",
    "sizeof","static","struct","switch","typedef","union",
    "unsigned","void","volatile","while"};


    for(long unsigned int i = 0; i < keywords.size(); ++i){
        if(strcmp(keywords[i].c_str(), buffer) == 0){
            return true;
        }
    }
    return false;
}

int main(){
    char ch, buffer[15];
    char listOperateur[]="+-*/=><:?.", listPunctuation[]=",;\(){}[]";

    std::ifstream inputFile("program.txt");
    int j = 0;

    std::vector <std::string> vecMotCles;
    std::vector<std::string>vecIdentificateur;
    std::vector<char>vecOperateur;
    std::vector<char>vecSymbole;
    std::vector<char>vecAutre;

    if(!inputFile.is_open()){
        std::cout<<"error while opening the file\n";
        exit(0);
    }

    while(!inputFile.eof()){
        ch = inputFile.get();
        for(long unsigned int i = 0; i < (sizeof(listPunctuation)/sizeof(listPunctuation[0])); ++i){
            if(ch == listPunctuation[i]){
                vecSymbole.push_back(ch);
            }
        }

        for(long unsigned int i = 0; i < (sizeof(listOperateur)/sizeof(listOperateur[0])); ++i){
            if(ch == listOperateur[i]){
                vecOperateur.push_back(ch);
            }
        }

        if(isalnum(ch)){
            buffer[j++] = ch;
        }
        else if((ch == ' ' || ch == '\n') && (j != 0)){

            buffer[j] = '\0';
            j = 0;

            if(isKeyword(buffer) == 1){
                vecMotCles.push_back(buffer);
            }
            else{
                vecIdentificateur.push_back(buffer);
            }
        }
    }
    inputFile.close();

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //remove duplicates
    std::sort( vecMotCles.begin(), vecMotCles.end() );
    vecMotCles.erase( std::unique( vecMotCles.begin(), vecMotCles.end() ), vecMotCles.end() );
    std::sort( vecIdentificateur.begin(), vecIdentificateur.end() );
    vecIdentificateur.erase( std::unique( vecIdentificateur.begin(), vecIdentificateur.end() ), vecIdentificateur.end() );

    // print arrays
    printf("Mots Cles:\n\t");
    for(long unsigned int i = 0; i < vecMotCles.size(); ++i){
        std::cout<<vecMotCles[i]<<" ";
    }
    printf("\nIdentificateur:\n\t");
     for(long unsigned int i = 0; i < vecIdentificateur.size(); ++i){
        std::cout<<vecIdentificateur[i] << " ";
    }
    printf("\nOperators:\n\t");
    for(long unsigned int i = 0; i < vecOperateur.size(); ++i){
        std::cout<<vecOperateur[i] << " ";
    }
    printf("\nSymbole De Punctuation:\n\t");
    for(long unsigned int i = 0; i < vecSymbole.size(); ++i){
        std::cout<<vecSymbole[i] << " ";
    }
    printf("\nAutre:\n\t");
    for(long unsigned int i = 0; i < vecAutre.size(); ++i){
        std::cout<<vecAutre[i] << " ";
    }

    std::cout << std::endl;
    return 0;
}