Fluffy Key Management
----------------------------------
## Description
Fluffy is a [draft](https://datatracker.ietf.org/doc/draft-hardjono-ace-fluffy/)
key exchange protocol designed for constrained environments. This project is a preliminary 
implementation of Fluffy, focusing on message authoring and encoding into JWT/JWE compliant data structures. 

Currently C++ GSK messages are serialized and passed into a python library for JOSE mapping. 
While this is not ideal it should work as C/C++ implementations of JOSE are developed.

## Dependencies
- GNU C++11
- Python2.7
- LibBoost/boost_python

In Ubuntu/Debian based Linux distribution, this command should get you most of the way there:
```
sudo apt-get install update && sudo apt-get install python-dev libboost1.55-all-dev libssl-dev g++
```

## Initial Setup
Currently, running make builds a executable that calls a python script, thus you must set your PYTHONPATH
environment variable. Edit your .bashrc (or whatever shell you are using) and add the next two lines:
```
- PYTHONPATH=/path/to/fluffy/pywrap/ (Mine is PYTHONPATH=$HOME/projects/fluffy/pywrap/)
- export PYTHONPATH
```

## Build/Run
Building
```
make
cd bin/
```
Format
```
./test encrypt_fluffy fluffymessagetype key groupkey(optional) groupkeyid(optional, but should be made required)

./test decrypt_fluffy filetodecrypt key
```
Example: Generating and encrypting a GSK-DLVR, and then decrypting the generated message:
```
./test encrypt_fluffy GSK-DLVR 1234567891234567

./test decrypt_fluffy ENC_GSK-DLVR\ 1.txt 1234567891234567
```
Message with MessageType, Encryption Key, Group Key, and Group Id specified

Note: A Group Key and Group Id will only be inserted if the message is a GSK-REP or GSK-DLVR (Will be fixed to be just GSK-REP)
**The passed encryption key must be specified and of valid length (at least 16 characters!)**
```
./test encrypt_fluffy GSK-DLVR 1234567891234567 xthisisagroupkey GroupKeyId

./test decrypt_fluffy ENC_GSK-DLVR\ 1.txt 1234567891234567
```

Todo:
* Swap Python JOSE library for a C/C++ implementation
* Add support for cbor and COSE
* Add more keying scenarios, [see draft for ideas](https://tools.ietf.org/html/draft-hardjono-ace-fluffy-02#section-3)
