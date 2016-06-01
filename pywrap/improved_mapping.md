So I went back and looked at the mappings again. I think this more accurate
way of maping fluffy to JWT/JWE:


The following should be the output of the GSK decrypt function.
It should include: 

JWE header information
JWE decrypted Ciphertext (the JWT)

------------------------

   {
		 "alg": "dir",
		 "enc": "A128CBC-HS256", 
		 "kid": "This is the Id of the key",
		 "cty": "RECEIPT", 
		 "typ": "GSK-DLVR 1"
		 "aad": {
					"aut": "security.authtime"
					"non": "security.nonce"
					"snu": "security.
				}
    }, 

    {
				"iss": "/a/Fluffy/CoolKids/MyId",		#Msg.from.name
				"sub": "/a/Fluffy/CoolKids/MyId",		#Msg.To.Name
				"aud": "/a/Fluffy/CoolKids/MyId",   #Msg.Target.name
				"exp": "payload.endtime"						#Msg.Payload.Endtime
				"iat": "payload issuetime"					#Msg.Payload IssueTime
				"kop": "skdc_options",            	#Msg.Payload.Skdc-options 	**non jwt tag**
				"pac": "pac_options", 							#Msg.Payload.pac 		**non jwt tag**
				"tpa": "tpac_options", 							#Msg.Payload.tpac 		**non jwt tag**
				"trn": "transited", 								#Msg.Payload.transited		**non jwt tag**
				"jwk": {
						"k": "A6374792E2CF8C5F3E210735A243A820"       #Msg.Payload.KeyData.SymKeyData.Symkey
						"kid": "This is the Id of the key", 	      		#Msg.Payload.KeyData.keyid
						"alg": "A128CBC-HS256", 			      					#Msg.Payload.Keydata.algid
						"kty": "oct"                                  #Msg.Payload.Keydata.keyops
				}, 
    }

# Important Observations:

* Note that the AAD (which contains authtime, nonce, seqnum,
		as per "Mapping Fluffy to JWT.docx" N.Smith) must be placed in the header (RFC7516, sec.2).
The reason for this in JWE compact serialization the AAD isn't explicity included (RFC7416 sec. 7.1) * All fluffy specific, non-jwt/jwe tags are now 3 chars, this is to be consistant with 
the JOSE charter if this mapping is adopted. 


# TODO:

	* [x] Fix the header
	* [] Map the key information into a JWK, a python dict like done with the header should do.
	* [] Map Payload into a python dict (we are currently grabbing the entire fluffy payload and saying
			that that is the JWT. We need to map the values in the payload into corresponding JWT names as shown 
			above. Basically we need to just rename the tags in the payload) Also there are some duplicated
			values that need to be cleaned up.
	* [] lets try and find a way to get that signature mismatch error to work if the msg becomes stale
