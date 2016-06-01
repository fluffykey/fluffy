#ifndef KEYS_H
#define KEYS_H

#include <string>
#include <map>
#include <cstdlib>
#include <pthread.h>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <sstream>
#include <openssl/rand.h>

#define VERNUM 1
#define DEBUG 1



class KeyType
{
public:
	KeyType () {keytype = "SYMGROUP";};
    
    void SetKeyType(std::string);
    std::string GetKeyType() {return keytype;}
protected:
    std::string keytype;
};
class SymGrpKeyData
{
public:
	SymGrpKeyData()
	{
		symkey = "adefaultgroupkey";
	};
	SymGrpKeyData(std::string newkey)
	{
		symkey = newkey;
	};
  
	void SetSymKey(std::string);
	std::string GetSymKey(){return symkey;}
 
protected:
	std::string symkey;
};

/********************UNIMPLEMENTED********************/
class AsymKeyData
{
public:
  AsymKeyData () {};
  AsymKeyData (std::string, std::string, std::string) {};

  /*Setters*/
  void SetPubKey(std::string);
  void SetPrivKey(std::string);
  void SetPkUse(std::string);
  /*Getters*/
  std::string GetKeyId(){return pubkey;}
  std::string GetPkUse(){return pkuse;}
protected:
  std::string pubkey;
  std::string privkey;
  std::string pkuse;
};



class KeyData
{
 public:
  KeyType keytype;
  AsymKeyData asym;
  SymGrpKeyData symgrp;
 public:
  KeyData ()
  {
	  keyid = "This is the Id of the key";
      keyops = "parameters necessary to operate keys";
      algid = "A128CBC-HS256";
  };
  KeyData (std::string, std::string, std::string){};

  /*Setters*/
  void SetKeyId(std::string);
  void SetKeyOps(std::string);
  void SetAlgId(std::string);
  /*Getters*/
  std::string GetKeyId(){return keyid;}
  std::string GetKeyOps(){return keyops;}
  std::string GetAlgId(){return algid;}
protected:
  std::string keyid;
  std::string keyops;
  std::string algid;
};
std::string GenSymKey(int size);

#endif
