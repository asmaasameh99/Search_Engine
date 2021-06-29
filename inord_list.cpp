/*
 * inord_list.cpp
 *
 *  Created on: May 6, 2021
 *      Author: student
 */
#include "inord_list.h"
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>

using namespace std;

inord_list::inord_list()
{
	head = NULL;
	tail=NULL;
	current = NULL;
}

/*////////////////////////////////////////////////////////////*/
bool inord_list::add_element(const ListElemType& item,const int& number)
{
    string str;
    stringstream ss;
    ss<<number;
    ss>>str;
	nodeptr NewNode = new node;
	nodeptr pred;
	if (NewNode == NULL)
    {
		return false; // allocation failed
	}
	else {
		NewNode->data = item;
		NewNode->Line_Number=str;
		NewNode->Line_Number_Buffer=str;
		NewNode->occurred++;
		if (head == NULL || item < head->data)
        {
			NewNode->next = head;
			head = NewNode;
			return true;
		}
		else if (item == head->data)
		{
			++head->occurred;
			if(head->Line_Number_Buffer!=NewNode->Line_Number)
			{
				head->Line_Number_Buffer=NewNode->Line_Number_Buffer;
				head->Line_Number=head->Line_Number+" "+NewNode->Line_Number;
			}
			return true;
		}
		else {
			pred = head;
			while (pred->next != NULL && pred->next->data < item) {
				pred = pred->next;
			}
			if(pred->next != NULL && pred->next->data == item)
			{
				++pred->next->occurred;
				if(pred->next->Line_Number_Buffer!=NewNode->Line_Number)
				{
					pred->next->Line_Number_Buffer=NewNode->Line_Number_Buffer;
					pred->next->Line_Number=pred->next->Line_Number+" "+NewNode->Line_Number;
				}
				return true;
			}
			NewNode->next = pred->next;
			pred->next = NewNode;
			return true;
		}
	}
}
/*//////////////////////////////////////////////////*/
void inord_list::print_list()
{
    current=head;
    while (current!=NULL)
    {
        cout<<current->data<<" ";
        cout<<current->Line_Number <<endl;
        cout<<current->occurred<<endl;
        current=current->next;

    }
}
/*////////////////////////////////////////////////*/
bool inord_list::wordCount()
{
    int WordCount=0;
    if (head == NULL) /*empty list*/
    {
		return false; // allocation failed
	}
    current=head; /* Start of list*/
	while(current!=tail) /*not at the end*/
	{
		WordCount=WordCount+current->occurred;
		current=current->next;
	}

	if(WordCount!=0)
	{
		cout<<WordCount<<" "<<"words"<<endl;
	}
	else
	{
		WordCount=0;
		cout<<WordCount<<" "<<"words"<<endl;
	}

	return true;

}
/*////////////////////////////////////////////////*/
bool inord_list::disWords()
{
    int WordCount=0;
    if (head == NULL) /*empty list*/
    {
		return false; // allocation failed
	}
    current=head; /* Start of list*/
	while(current!=tail) /*not at the end*/
	{
		WordCount++;
		current=current->next;
	}

	if(WordCount!=0)
	{
		cout<<WordCount<<" "<<"distinct words"<<endl;
	}
	else
	{
		WordCount=0;
		cout<<WordCount<<" "<<"words"<<endl;
	}

	return true;

}

/*////////////////////////////////////////////////*/
bool inord_list::frequentWord()
{
    int freq=0;
    string word = " ";
    if (head == NULL) /*empty list*/
    {
		return false; // allocation failed
	}
	current=head;
	while(current!=tail)
    {
        if (freq<current->occurred)
        {
            freq=current->occurred;
        }
        current=current->next;
    }
    current=head;
    while(current!=tail)
    {
        if(freq==current->occurred)
        {
            if (!common_language(current->data))
            {
                word=word;
            }
            else
                word=word+current->data+" ";
        }
        current=current->next;
    }
    cout<<"Most frequent word is:"<<word<<endl;
    return true;

}
/*////////////////////////////////////////////////*/
bool inord_list::countWord(const ListElemType & element)
{
    bool word=false;
    if (head == NULL) /*empty list*/
    {
		return false; // allocation failed
	}
	current=head;
	while(current!=tail)
    {
        if(element == current->data)
        {
            cout<<current->data<<" is repeated "<< current->occurred<< " times"<<endl;
            word=true;

        }
        current=current->next;
    }
    if(!word)
    {
        cout<<element<<" is repeated 0 times"<<endl;
    }
    return true;
}
/*//////////////////////////////////////////////////////*/
bool inord_list::starting(const ListElemType & element)
{
	bool notfound=false;
    current=head;
    while (current!=tail)
    {
        size_t start = current->data.find(element);
        if (start != string::npos)
        {
            if (start==0)
                {
                    cout<<current->data<<": "<<current->occurred<<"	";
                    notfound=true;
                }

        }
        current=current->next;
    }
    if(!notfound)
    {
    	cout<<"Word not found";
    }
    cout<<endl;

}
/*/////////////////////////////////////////////////////*/
bool inord_list::containing(const ListElemType &element)
{
	bool notfound=false;
    current=head;
    while (current!=tail)
    {

        if (current->data.find(element) != std::string::npos)
        {
            cout<<current->data<<": "<<current->occurred<<"	" ;
            notfound=true;
        }

        current=current->next;
    }
    if(!notfound)
            {
            	cout<<"Word not found";
            }
    cout<<endl;
}
/*/////////////////////////////////////////////*/
bool inord_list::Search(const ListElemType &element)
{
	bool notfound=false;
    current=head;
    while (current!=tail)
    {

        if (current->data.find(element) != std::string::npos)
        {
            cout<<current->data<<":	lines "<<current->Line_Number<<endl ;
            notfound=true;
        }

        current=current->next;
    }
    if(!notfound)
            {
            	cout<<"Word not found"<<endl;
            }

}

/*/////////////////////////////////////////////////////////////////////////*/
inord_list::~inord_list()
{
	while(head!=tail){
			current=head;
			head=head->next;
			delete current;

		}
		delete tail;

}


