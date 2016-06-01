/*
 * Created By : Team Fluffy
 * File Name : fluffy.cpp
 * Creation Date : Wed 27 Jan 2016 10:16:43 AM PST
 * Last Modified : Tue 26 Apr 2016 04:33:08 PM PDT
 * Purpose :
 */

#include <fluffy.h>

#define VERNUM	1
#define DEBUG	1

/*
 * Fluffy.h
 * Addr Definitions
 */

void Addr::SetRealm(std::string newrealm){realm = newrealm;}
void Addr::SetName(std::string newname){name = newname;}
void Addr::SetGroup(std::string newgroup){group = newgroup;}

/*
 * Fluffy.h
 * Payload Definitions
 */
Payload::Payload(){
  SkdcOptions = "skdc_options"; /*JwtClaim*/
  issuetime = std::to_string(time(NULL)); /*DATE*/
  endtime = std::to_string(time(NULL) + 10); /*DATE*/
  transited = "transited";  /*URI*/
  pac = "pac_options"; /*JwtClaim*/
  tpac = "tpac_options"; /*JwtClaim*/
  x5u = "x5u_key"; /*JwtClaim*/
  x5c = "x5u_key"; /*JwtClaim*/
  x5t = "x5t_key"; /*JwtClaim*/
  x5t256 = "x5t256_key"; /*JwtClaim*/
  pk10 = "pk10_key"; /*JwtClaim*/
	spi = "spival";
}



/*
 * Fluffy.h
 * PayloadType Definitions
 */
void PayloadType::SetPayloadType(std::string inpt)
{
    if (inpt == "REQUEST"){
	  payloadType = "REQUEST";
    }
    else if (inpt == "FETCH"){
	  payloadType = "FETCH";
    }
    else if (inpt == "TICKET"){
	payloadType = "TICKET";
    }
    else if (inpt == "NTICKET"){
	payloadType = "NTICKET";
    }
    else if (inpt == "RECEIPT"){
	payloadType = "RECEIPT";
    }
    else if (inpt == "CERTIFICATE"){
	payloadType = "CERTIFICATE";
    }
    else if (inpt == "ANCHOR"){
	payloadType = "ANCHOR";
    }
    else if (inpt == "JOIN"){
	payloadType = "JOIN";
    }
    else if (inpt == "DELETE"){
	payloadType = "DELETE";
    }
    else if (inpt == "REVOKE"){
	payloadType = "REVOKE";
    }
    else if (inpt == "REVOKENOTIFY"){
	payloadType = "DELETE";
    }
    else if (inpt == "OPAQUEDATA"){
	payloadType = "OPAQUEDATA";
    }
}

/*
 * Fluffy.h
 * Security Defintions
 */
Security::Security()
{
  authtime = "default_authtime";
  khash_alg = "default_khash_alg";
  khash = "default_khash";  
  nonce = 1234;
  seqnum = 5678;
};
Security::Security(std::string newtime, int newnonce, int newseqnum,
	         std::string newalg, std::string newhash)
{
  authtime = newtime;
  nonce = newnonce;
  seqnum = newseqnum;
  khash = newhash;
  khash_alg = newalg;

};
void Security::SetAuthTime(std::string newauth){authtime = newauth;}
void Security::SetNonce(int update){nonce = update;}
void Security::SetSeqnum(int newnum){seqnum = newnum;}
void Security::SetKhashAlg(std::string alg){khash_alg = alg;}
void Security::SetKhash(std::string hash){khash = hash;}

/*
 * Fluffy.h
 * Hdr Definitions
 */

void Hdr::SetPvno(int newversion){pvno = newversion;}


/*
 * Fluffy.h
 * MsgType Definitions
 */

//maybe return 0 if sucessful, 1 if it coulnd't parse the string
void MsgType::SetMsgType(std::string inpt)
{
	if (inpt == "PSK-REQ"){
	    msgtype = "PSK-REQ";
    }
    else if (inpt == "PSK-REP"){
	    msgtype = "PSK-REP";
    }
    else if (inpt == "PSK-ESTB"){
	    msgtype = "PSK-ESTB";
    }
    else if (inpt == "PSK-ACK"){
	    msgtype = "PSK-ACK";
    }
    else if (inpt == "NUL-REQ"){
	    msgtype = "NUL-REQ";
    }
    else if (inpt == "NUL-REP"){
	    msgtype = "NUL-REP";
    }
    else if (inpt == "NUL-ESTB"){
	    msgtype = "NUL-ESTB";
    }
    else if (inpt == "NUL-ACK"){
	    msgtype = "NUL-ACK";
    }
    else if (inpt == "GSK-REQ"){
	    msgtype = "GSK-REQ";
    }
    else if (inpt == "GSK-REP"){
	    msgtype = "GSK-REP";
    }
    else if (inpt == "GSK-FET"){
	    msgtype = "GSK-FET";
    }
    else if (inpt == "GSK-DLVR"){
	    msgtype = "GSK-DLVR";
    }
    else if (inpt == "PKP-REQ"){
	    msgtype = "PKP-REQ";
    }
    else if (inpt == "PKP-REP"){
	    msgtype = "PKP-REP";
    }
    else if (inpt == "ANC-REQ"){
	    msgtype = "ANC-REQ";
    }
    else if (inpt == "ANC-REP"){
	    msgtype = "ANC-REP";
    }
    else if (inpt == "ANC-ESTB"){
	    msgtype = "ANC-ESTB";
    }
    else if (inpt == "ANC-ACK"){
	    msgtype = "ANC-ACK";
    }
    else if (inpt == "EPID-REQ"){
	    msgtype = "EPID-REQ";
    }
    else if (inpt == "EPID-REP"){
	    msgtype = "EPID-REP";
    }
    else if (inpt == "DEL-REQ"){
	    msgtype = "DEL-REQ";
    }
    else if (inpt == "DEL-REP"){
	    msgtype = "DEL-REP";
    }
    else if (inpt == "REV-REQ"){
	    msgtype = "REV-REQ";
    }
    else if (inpt == "REV_REP"){
	    msgtype = "REV-REP";
    }
    else if (inpt == "REV-REG"){
	    msgtype = "REV-REQ";
    }
    else if (inpt == "REV-NOT"){
	    msgtype = "REV-NOT";
    }
    else if (inpt == "OPQ-REQ"){
	    msgtype = "OPQ-REQ";
    }
    else if (inpt == "OPQ-REP"){
	    msgtype = "OPQ-REP";
    }
    else{
	    msgtype = -1;
    }
	return;
}
