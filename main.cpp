/*
 * main.cpp
 *
 *  Created on: May 6, 2021
 *      Author: student
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstddef>
#include <cctype>
#include <bits/stdc++.h>
#include "inord_list.h"
using namespace std;

void charNumberCount(string ,int& );

int main(int argc, char *argv[])
{
    string line ;
    string word;
    int lineNumber=1;
    int chars=0;
    inord_list List;
    string const delim = " \b\r\n,:;'&.[()>={}/*!?" ;

    if(argc!=3)
        {
            cout<<"Incorrect number of arguments"<<endl;

        }
	ifstream file_name(argv[1]);
    /*Reading file*/
    if (file_name.is_open())
    {
        while(getline(file_name,line))
        {
            charNumberCount(line ,chars );
            size_t beg ,pos=0;
            while((beg=line.find_first_not_of(delim,pos)) != std::string::npos)
                  {
                      pos=line.find_first_of(delim,beg+1);
                      word = line.substr(beg,pos-beg);
                      transform(word.begin(),word.end(),word.begin(),::tolower);
                     //cout<<word << " " << lineNumber<<endl;
                     List.add_element(word,lineNumber);

                  }
                  lineNumber++;


        }
    }




///*////////////////////////////////////////////////////*/////////////*/

    string line1;
    string word3,word1,word2;
    string argu[2];

    ifstream commandfile(argv[2]);
    /*Reading file*/
    if (commandfile.is_open())
    {
        while(getline(commandfile,line1))
        {
            stringstream ss(line1);
            string word3;
            int counter=0;
            while(ss>>word3)
            {
                counter++;

            }
             //cout<<counter<<endl;
            if (counter>2)
            {
                cout<<"Incorrect number of arguments"<<endl;
            }
            else if(counter==2)
            {
                istringstream ss(line1);
                int i=0;
                while(ss>>word1)
                {
                    argu[i]=word1;
                    i++;
                }
                if (argu[0]=="countWord")
                    {
                        transform(argu[1].begin(),argu[1].end(),argu[1].begin(),::tolower);
                        List.countWord(argu[1]);
                    }
                else if (argu[0]=="starting")
                    List.starting(argu[1]);
                else if (argu[0]=="search")
                    List.Search(argu[1]);
                else if (argu[0]=="containing")
                    List.containing(argu[1]);
                else if (argu[0]=="wordCount" || argu[0]== "distWords" || argu[0] =="charCount" || argu[0]=="frequentWord")
                        cout<<"Incorrect number of arguments"<<endl;
                else
                    cout<<"Undefined command"<<endl;
            }
            else if (counter==1)
            {
               istringstream ss(line1);
               while(ss>>word2)
               {
                    if (word2=="wordCount")
                        List.wordCount();
                    else if (word2=="distWords")
                        List.disWords();
                    else if (word2=="charCount")
                        cout<<chars<<" characters"<<endl;
                    else if (word2=="frequentWord")
                        List.frequentWord();
                    else if (word2=="containing" || word2=="search" || word2 =="starting"|| word2=="countWord")
                        cout<<"Incorrect number of arguments"<<endl;
                    else
                        cout<<"Undefined command"<<endl;
               }
            }


        }
    }


}

///*///////////////////////////////////////////////////////////////////*/

void charNumberCount(string line ,int& charNumber )
{
    charNumber=charNumber+line.length()+1;

}

/*///////////////////////////////////////////////////////////////*/







