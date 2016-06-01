#!/usr/bin/python
import os
import gsk
import copy
import jose
import json
import logging
logging.getLogger('jose').addHandler(logging.NullHandler())


def encrypt_fluffy(msgtype, key, groupkey="", keyid=""):
    #print "MsgType: ", msgtype
    #print "GroupKey: ", groupkey
    #print "KeyId: ", keyid	
    print '*****************************'
    print 'Performing Encryption on a ' + msgtype
    print '*****************************'

    msg = gsk.Gsk(msgtype, groupkey, keyid)
    s = gsk.printGsk(msg)
    j_obj = json.loads(s)
    
    #add and map fluffy claims into jwt claims
    pyld = map_payload(j_obj)
   
    print "Pretty output: " 
    print json.dumps(pyld, indent=4)
    print "--------------"

    j_obj['header']['msgtyp'] = msgtype
    
    header = {
            'kid': str(j_obj['payload']['keydata']['kid']),
            'typ': str(j_obj['header']['msgtyp']) + ' ' + str(j_obj['header']['pvno']),
	    'cty': j_obj['payload']['type'],
            }
    aad = {
            'aut': j_obj['security']['authtime'],
            'non': j_obj['security']['nonce'],
            'snu': j_obj['security']['seqnum']
            }
    
    header['aad'] = aad

    jwe = jose.encrypt(pyld, '', add_header = header, alg='dir', dir_key=str(key))

    print(jose.serialize_compact(jwe))
    f = open ("ENC_" + header['typ'] +".txt", "w")
    f.write(jose.serialize_compact(jwe));
    f.close();

def decrypt_fluffy(jwe, key):
    print '\n*****************************'
    print 'Performing Decryption on ' + jwe
    print '*****************************'
    print "OPENING FILE"
    f = open(jwe, "r")
    data = f.read()
    f.close()
    os.remove(jwe)

    dec = jose.decrypt(jose.deserialize_compact(data), '', dir_key=key)
    out = json.dumps(dec, indent=4, separators=(', ', ': '), sort_keys=True)
    print out
    print '*****************************'



def map_payload(j_obj):
    msgtype = j_obj['header']['msgtyp']
    payload = copy.deepcopy(j_obj['payload'])

    #Mapping payload elements common to all GSKs:
    payload['iss']  = j_obj['from']['realm'] + j_obj['from']['group'] + j_obj['from']['name']
    payload['sub'] = j_obj['to']['realm'] + j_obj['to']['group'] + j_obj['to']['name']
    payload['aud'] = j_obj['target']['realm'] + j_obj['target']['group'] + j_obj['target']['name']
    payload['kop'] = j_obj['payload']['skdcopts']
    payload['iat'] = int(j_obj['payload']['iat'])
    payload['exp'] = int(j_obj['payload']['exp'])
     
    payload['jwk'] =  map_key(j_obj)
    
    if msgtype == 'GSK-DLVR' or msgtype == 'GSK-REP':
        payload['tpa'] = j_obj['payload']['tpac']
        payload['trn'] = j_obj['payload']['transited']
        del payload['tpac']
        del payload['transited']

    # Type is in the header, keydata is remapped by map_key(j_obj)
    del payload['type']
    del payload['keydata']
    del payload['skdcopts']

   # print("TEST PAYLOAD:\n")
   # print json.dumps(payload, indent=4)
   # print("***************:\n")
    return payload


def map_key(j_obj):
    print j_obj['header']['msgtyp']
    if j_obj['header']['msgtyp'] == 'GSK-FET':
        jwk = {
            'kid':  j_obj['payload']['keydata']['kid']
               }

    elif j_obj['header']['msgtyp'] == 'GSK-DLVR':
        jwk = {
            'alg':  j_obj['payload']['keydata']['algid'],
            'k':    j_obj['payload']['keydata']['symgrp']['k'],
            'kty':  j_obj['payload']['keydata']['keytyp'],
            'kid':  j_obj['payload']['keydata']['kid']
               }

    elif j_obj['header']['msgtyp'] == 'GSK-REP':
        jwk = {
            'alg':  j_obj['payload']['keydata']['algid'],
            'k':    j_obj['payload']['keydata']['symgrp']['k'],
            'kty':  j_obj['payload']['keydata']['keytyp'],
            'kid':  j_obj['payload']['keydata']['kid']
               }
    
    elif j_obj['header']['msgtyp'] == 'GSK-REQ':
        jwk = {
            'alg':  j_obj['payload']['keydata']['algid'],
            'kty':  j_obj['payload']['keydata']['keytyp'],
            'kid':  j_obj['payload']['keydata']['kid']
               }
    else:
        print("Key type not found")
        exit()

    return jwk
	
def test():
    print "TEST FUNCTION"
    return 42


if __name__ == '__main__':
# to test the output just uncomment the following lines

    encrypt_fluffy("GSK-DLVR", "1234567891234567")
    decrypt_fluffy('ENC_GSK-DLVR 1.txt', "1234567891234567")
    print('\n\n\n')

    encrypt_fluffy("GSK-FET", "1234567891234567")
    decrypt_fluffy('ENC_GSK-FET 1.txt', "1234567891234567")
    print('\n\n\n')

    encrypt_fluffy("GSK-REP", "1234567891234567")
    decrypt_fluffy('ENC_GSK-REP 1.txt', "1234567891234567")
    print('\n\n\n')

    encrypt_fluffy("GSK-REQ", "1234567891234567")
    decrypt_fluffy('ENC_GSK-REQ 1.txt', "1234567891234567")
