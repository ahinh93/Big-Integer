#include "BigInteger.h"
#include <string>
#include <climits>
#include <iostream>
#include <sstream>
#include <algorithm>


using namespace std;

BigInteger::BigInteger()
{
	head = new Node(INT_MIN,NULL,NULL);
	tail = head;
	isNegative = false;
	size = 0;
}

BigInteger::~BigInteger()
{
	Node* temp;
	while(head != NULL)
	{
		temp = head-> next;
		delete head;
		head = temp;
	}
}

void BigInteger::init(string passedNum)
{	
	for(int i = 0; i< passedNum.length(); i++)
	{
		char temp = passedNum[i];	
		int tempNum;
		//string a = temp;
		//istringstream("123") >> tempNum;	

		//check if first index is negative sign
		if((passedNum[0] == '-') && (i == 0))
		{
			//cout<<"flagged as negative"<<endl;
			isNegative = true;	
		}
		else if ((passedNum[0] == '-') && (i == 1))
		{
			//cout<<" " << passedNum[i];
			head-> data = passedNum[i];
			size++;
		}
		else if((passedNum[0] != '-') && (i == 0))
		{
			//cout<<" " << passedNum[i];
			head->data = passedNum[i];
			size++;
		}
		else
		{
			//cout<<" " << passedNum[i];
			tail->next = new Node(passedNum[i],NULL,tail);
			tail = tail->next;
			size++;
		}
	}

	if(passedNum.length() > 1)
	{
		if(passedNum[0] == '-')
		{
			isNegative = true;
		}
	}
}

string BigInteger::toString()
{
	Node *temp = head;
	string out = "";
	if(isNegative)
		out+= '-';
	for(int i = 0; i < size; i++)
	{
		out += temp-> data;
		temp = temp-> next;
	}
	return out;
}

BigInteger BigInteger::operator+(BigInteger b) 
{
	int result;
	int carry = 0;
	int paddedSize;
	
	//determine greatest length and add 2
	paddedSize = max(this->size,b.size) + 2;
	
	//add padded zeroes to both lists til both are of size max+2
	while(paddedSize != b.size)
	{
		b.head->prev = new Node(0,b.head,NULL);
		b.head = b.head->prev;
		b.size++;
	}

	while(paddedSize != this->size)
	{
		this->head->prev = new Node(0,this->head,NULL);
		this->head = this->head->prev;
		this->size++;
	}
	cout<<"padded lists: " << this->toString() << " " << b.toString() << endl;
	//determine which list needs to be converted to 10's complement
	/*
	if(this->isNegative)
	{
		Node *temp = this->head;
		for(int i = 0; i < this->size; i++)
		{
			temp->data = (9 - temp->data);
			temp = temp->next;
		}
		cout<<"a's converted data before +1: "<<this->toString()<<endl;
	}	
	if(b.isNegative)
	{
		Node *temp = b.head;
		for(int i = 0; i < b.size; i++)
		{
			temp->data = (9 - temp->data);
			temp = temp-> next;
		}
		cout<<"b's converted data before +1: "<<b.toString()<<endl;
	}
	*/

	//dummy code for return
	BigInteger temp;
	temp.init("123");
	return temp;
}

BigInteger BigInteger::operator=(BigInteger b) 
{
	//copy constructor that will deep copy the result of a+b and return correct BigInteger object

	//dummy code
	BigInteger temp;
	temp.init("123");
	return temp;
}
