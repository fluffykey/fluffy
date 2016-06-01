#include "keys.h"

/*
 * Keys.h
 * Keytype Definitions
 */

void KeyType::SetKeyType(std::string inpt)
{
    if (inpt == "SYMMETRIC"){
	keytype = "SYMMETRIC";
    }
    else if (inpt == "SYMGROUP"){
	keytype = "SYMGROUP";
    }
    else if (inpt == "ASYMSIGN"){
	keytype = "ASYMSIGN";
    }
    else if (inpt == "ASYMKEK"){
	keytype = "ASYMKEK";
    }
    else if (inpt == "EPID"){
	keytype = "EPID";
    }
}

/*
 * Keys.h
 * SymGrpKeyData Definitions
 */
void SymGrpKeyData::SetSymKey(std::string setkey){symkey = setkey;}

/*
 * Keys.h
 * Keydata Definitions
 */
void KeyData::SetKeyId(std::string kid){keyid = kid;}
void KeyData::SetKeyOps(std::string kops){keyops = kops;}
void KeyData::SetAlgId(std::string newid){algid = newid;}

/*
 * Keys.h
 * Generate Symmetric Key 
 * Input: number of bits
 * Output: symmetric key as string
 */
std::string GenSymKey(int size){
  size = size / 8;
  int i;
  unsigned char key[size];
  char keystr[size * 2 + 1];
  //Openssl, secure PRNG
  RAND_bytes(key, size);
  for ( i = 0; i < size; ++i){
    sprintf(keystr + 2*i, "%02X", key[i]);
  }
  return keystr;
}

/*
 * Keys.h
 * AsymKeyData Defintions
 */
void AsymKeyData::SetPubKey(std::string newpub){pubkey = "3";}
void AsymKeyData::SetPrivKey(std::string newpriv){privkey = "17";}
void AsymKeyData::SetPkUse(std::string newpk){pkuse = "usage?";}


