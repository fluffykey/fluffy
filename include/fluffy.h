#ifndef FLUFFY_H
#define FLUFFY_H

#include <string>
#include <map>
#include <cstdlib>
#include <pthread.h>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <ctime>
#include "keys.h"

#define VERNUM 1
#define DEBUG 1

/*
 * Class Addr
 * Represents a unique device
 * by realm, name and group
 */
class Addr
{
	public:
		Addr ()
		{
			realm = "/a/Fluffy";
			name = "/deviceUID";
			group = "/sensors";
		};
		Addr (std::string newrealm, std::string, std::string){};

		void SetRealm(std::string);
		void SetName(std::string);
		void SetGroup(std::string);

		std::string GetRealm() {return realm;}
		std::string GetName()  {return name;}
		std::string GetGroup() {return group;}
	protected:
		std::string realm;
		std::string name;
		std::string group;
};

/*
 * Class PayloadType
 * 
 */
class PayloadType
{
	public:
		PayloadType() {};

		void SetPayloadType(std::string);
		std::string GetPayloadType() {return payloadType;}
	protected:
		std::string payloadType;
};


/*
 * Class Payload
 * 
 */
class Payload
{
	public:
		Payload ();

		PayloadType type;
		KeyData kd;

		/*Setters*/
		void SetSkdcOptions();
		void SetIssuetime();
		void SetEndtime();
		void SetTransited();
		void SetPac();
		void SetTpac();
		void SetX5u();
		void SetX5c();
		void SetX5t();
		void SetX5t256();
		void SetPk10();
		void SetSpi();

		/*Getters*/
		std::string GetSkdcOptions(){return SkdcOptions;}
		std::string GetIssuetime(){return issuetime;}
		std::string GetEndtime(){return endtime;}
		std::string GetTransited(){return transited;}
		std::string GetPac(){return pac;}
		std::string GetTpac(){return tpac;}
		std::string GetX5u(){return x5u;}
		std::string GetX5c(){return x5c;}
		std::string GetX5t(){return x5t;}
		std::string GetX5t256(){return x5t256;}
		std::string GetPk10(){return pk10;}
		std::string GetSpi(){return spi;}
	protected:
		std::string SkdcOptions; /*JwtClaim*/
		std::string issuetime; /*DATE*/
		std::string endtime; /*DATE*/
		std::string transited;  /*URI*/
		std::string pac; /*JwtClaim*/
		std::string tpac; /*JwtClaim*/
		std::string x5u; /*JwtClaim*/
		std::string x5c; /*JwtClaim*/
		std::string x5t; /*JwtClaim*/
		std::string x5t256; /*JwtClaim*/
		std::string pk10; /*JwtClaim*/
		std::string spi;
};


/*
 * Class Security
 * 
 */
class Security
{
	public:
		Security();
		Security(std::string newtime, int newnonce, int newseqnum,
				std::string newalg, std::string newhash);

		void SetAuthTime(std::string);
		void SetNonce(int);
		void SetSeqnum(int);
		void SetKhashAlg(std::string);
		void SetKhash(std::string);

		std::string GetAuthTime(){return authtime;}
		int GetNonce(){return nonce;}
		int GetSeqnum(){return seqnum;}
		std::string GetKhashAlg(){return khash_alg;}
		std::string GetKhash(){return khash;}
	protected:
		std::string authtime;
		std::string khash_alg;
		std::string khash;
		int nonce;
		int seqnum;
};


class MsgType
{
	public:
		MsgType() {};
		MsgType(std::string) {};

		void SetMsgType(std::string inpt);
		std::string GetMsgType() {return msgtype;}

	protected:
		std::string msgtype;
};


class Hdr
{
	public:
		Hdr() {pvno = VERNUM;};
		Hdr(int newversion) {pvno = newversion;};

		MsgType msg_type;

		void SetPvno(int);
		int GetPvno(){return pvno;}
	protected:
		int pvno;
};


class FluffyMsg
{
	public:
		Hdr hdr;
		Security security;
		Addr to;
		Addr from;
		Addr target;
		Payload pyld;

		FluffyMsg(){};

	protected:
};


#endif
