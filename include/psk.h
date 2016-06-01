/*
 * Created By : Team Fluffy
 * File Name : psk.h
 * Creation Date : Wed 27 Jan 2016 10:16:43 AM PST
 * Last Modified : Mon 01 Feb 2016 02:59:23 PM PST
 * Purpose : Header for psk parent classes.
 */


/* Notes:
 * For now I implemented the default constructors
 * inside this file so there is no psk.cpp.
 *
 * This will probably change over time when we 
 * decide we want to provide complex constructors
 * that set the values in the FluffyMsg object. 
 *
 */

#ifndef PSK_H
#define PSK_H
#define VERNUM 1
#define DEBUG  1	


#include <string>
#include <map>
#include <cstdlib>
#include <pthread.h>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <fluffy.h>
#include <json/json.h>

class PskAck 
{
	public:
		FluffyMsg AckMsg;
	public:
		PskAck (){};
};

class PskEstb
{
	public:
		FluffyMsg EstbMsg;
	public:
		PskEstb (){};		
};

class PskRep
{
	public:
		FluffyMsg RepMsg;
	public:
		PskRep (){};
};

class PskReq
{
	public:
		FluffyMsg ReqMsg;
	public: 
		PskReq (){};
};
#endif
