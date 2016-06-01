/*
* File Name : usage.cpp
* Creation Date : Sun 24 Apr 2016 10:57:31 AM PDT
* Last Modified : Wed 01 Jun 2016 02:11:17 PM PDT
* Purpose : 
*
* This program should show how any arbitrary
* c++ file can make use of the fluffy cpp library
* to generate an Encrypted GSK*
*
* Todo: currently there aren't cpp function calls
* which directly call the encrypt and decrypt functions
* in the python library.
*
*/

#include <iostream>
#include "gsk.h"

int main(int argc, const char *argv[]){
	
	std::cout << "*********************"
	std::cout << "C++ GSK Generation test\n";
	std::cout << "*********************"
	
	//This is the GSK we want to encrypt
	Gsk p;


	//TODO:Here we could call a couple of setters.
	//Doing this mimics what the SP/SKDC will do
	//if it needs to set a specific value like
	//the realm or keyid for example.


	//Here we print out the message with all
	//the values we want to set
	std::string out = GenericGskPrint(p);
	std::cout << out;


	//TODO: Here we call the encrypt function,
	//we pass it the Gsk we just made, this
	//should make an encrypted file
		
	//TODO: Here we call the decrypt function,
	//we should pass it the name of the encrypted
	//txt file and it should return the unencrypted
	//gsk, (in json?)
	
	return 0;
}
