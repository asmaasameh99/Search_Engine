/*
 * inorder_list.h
 *
 *  Created on: May 6, 2021
 *      Author: student
 */


#ifndef INORD_LIST_H_
#define INORD_LIST_H_

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

typedef string ListElemType;

class inord_list
{
	public:
	inord_list();
	bool add_element(const ListElemType & element,const int& number);
	bool wordCount();
	bool disWords();
	bool frequentWord();
	bool countWord (const ListElemType & element);
	bool starting(const ListElemType & element);
	bool containing(const ListElemType &element);
	bool Search(const ListElemType &element);
	void print_list();
	~inord_list();




	private:
    struct node; // Forward declaration of structure

    typedef node* nodeptr;
    struct node {
        ListElemType data;
        nodeptr next;
        //int line_number;
        string Line_Number_Buffer;
        string Line_Number;
        int occurred=0;

    };
    bool common_language(string str)
    {
        if(str=="a" || str=="an" || str=="the" || str=="in" || str=="on" || str=="of" || str=="and" || str=="is" || str=="are")
        {
            return false;
        }
        else
            return true;
    }
    nodeptr head;
    nodeptr tail;
    nodeptr current;

};



#endif /* INORD_LIST_H_ */
