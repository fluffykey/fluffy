/*
 * Created By : Team Fluffy
 * File Name : gsk.h
 * Creation Date : Wed 27 Jan 2016 10:16:43 AM PST
 * Last Modified : Mon 01 Feb 2016 02:59:23 PM PST
 * Purpose : Header for gsk parent classes.
 */


/* Notes:
 * For now I implemented the default constructors
 * inside this file so there is no gsk.cpp.
 *
 * This will probably change over time when we 
 * decide we want to provide complex constructors
 * that set the values in the FluffyMsg object. 
 *
 */
#ifndef GSK_H
#define GSK_H
#include <string>
#include <map>
#include <cstdlib>
#include <pthread.h>
#include <mutex>
#include <condition_variable>
#include <iostream> 
#include <ctime>
#include <boost/python.hpp>
#include "fluffy.h"
#include <json/json.h>

#define DEBUG	1

class Gsk
{
 public:
	FluffyMsg Msg;
	Gsk();
	Gsk(std::string msgtype, std::string key, std::string keyid);
	//~Gsk();
};
std::string GenericGskPrint(Gsk &InputMsg);
std::string GskReqJsonPrint(Gsk &Msg);
std::string GskRepJsonPrint(Gsk &Msg);
std::string GskFetJsonPrint(Gsk &Msg);
std::string GskDlvrJsonPrint(Gsk &Msg);
#endif
